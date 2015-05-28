//
//  fonctions.c
//  
//
//  Created by Mahieu Lucas on 18/04/2015.
//
//

#include "../Headers/main.h"

int Hash(char mot[], int a,int nombre_mots,int taille_mots){  // vérifié le 04/05 lucas
	int i=taille_mots-1;
	int h=1;
	while (i>0) {
		h=(h*a+((int)mot[i]))%nombre_mots;
		i--;
	}
	return h;
}

int Taille_Mots(FILE* fichier){
	int i = 0;
	char* chaine=NULL;
	char mot_fichier[30];  // 30  = taille mots max pour avoir de la marge
	int N = 30; 
//Permet de déterminer la longueur du 1er mot
	rewind(fichier);
	fgets(mot_fichier,N,fichier);	
	while((mot_fichier[i])!='\n'){
		i++;
	}
	rewind(fichier);
return i;	
}


int Taille_Fichier(FILE* fichier){
	int i=0;
	char ligne[500];
	rewind(fichier);
// tant que l'on est pas à la fin du document
	while (fgets(ligne,500,fichier)!=NULL) {
			i++;
	}
// le # de \n correspond au # de mots du fichier
	rewind(fichier);
	return i;
}


char** Remplissage_Tableau(FILE* fichier, int taille_fichier,int taille_mots){
    char** tableau;
    int i = 0,j=0,k=0; //Permet dans la boucle de remplissage d'atteindre les différentes cases du tableau
    char mot_fichier[30];
//on fait un grand tableau de taille "taille_fichier". On prend un pointeur char* pour pourvoir ranger les mots dans les cases
    tableau = (char**)calloc(taille_fichier,sizeof(*tableau));
//on alloue de la place pour tous les mots
    for(j=0;j<taille_fichier;j++){
        *(tableau+j) = (char*)calloc(taille_mots,sizeof(**tableau));
    }
//on remplit les cases du tableau lettre par lettre
    while (fgets(mot_fichier,taille_mots+2,fichier)!=NULL){
    	mot_fichier[taille_mots]='\0';
        strcpy(*(tableau+k),mot_fichier);
        k++;
    }
    return tableau;
}




char** Ajout_Mot_Tableau(char** S,int taille_mots, char* mot, int *taille_tableau){
    char** tableau_final;
    int i = 0;
    int j = 0;
// cas du 1 element à ajouter
    if(S==NULL){
    	tableau_final = (char**)calloc(*(taille_tableau)+1,sizeof(*(tableau_final)));
    	*(tableau_final)=(char*)calloc(taille_mots,sizeof(**tableau_final));
    	strcpy(*(tableau_final),mot);
    	*taille_tableau =1;
    	return tableau_final;
    }
//On alloue un nouveau que l'on retournera avec une case en plus
    tableau_final = (char**)calloc(*(taille_tableau)+1,sizeof(*(tableau_final)));
//on alloue de la place pour tous les mots
    for(j=0;j<*taille_tableau+1;j++){
        *(tableau_final+j) = (char*)calloc(taille_mots,sizeof(**tableau_final));
    }
//On recopie tous les élements du tableau initial dans le nouveau tableau
    for(i=0;i<*(taille_tableau);i++){
        strcpy(*(tableau_final+i),*(S+i));//(dest,source)
        free(*(S+i)); //On libére l'espace mémoire précedemment allloué
    }
    free(S);
//on copie le dernier mot a ajouter en fin de tableau
    strcpy(*(tableau_final+*(taille_tableau)),mot);
    
//On retourne par adresse la nouvelle taille du tableau
    *taille_tableau=*(taille_tableau)+1;
//On retourne le tableau final complété
    return tableau_final;
}



char** Recherche_Mot_Tableau(char** tableau,char* mot, int taille_tableau){
    int k = 0;
//Tant que l'on pas visité tout le tableau on continue de parcourir le tableau, si on le trouve on return.
    while(k < taille_tableau){
        if(strcmp(mot,*(tableau+k))==0) return (tableau+k);
        k++;
    }
    return NULL;
}


int Suppression_Dans_Tableau(char** tableau, char* mot_a_supprimer, int taille_tableau){
    char** i = NULL;
    char** position = NULL;
    
    position = Recherche_Mot_Tableau(tableau,mot_a_supprimer,taille_tableau);
// Si le mot n'est pas dans le tableau on sort de la fonction
    if(position == NULL) return 0;
    
    for(i=position; i<(tableau+taille_tableau-1);i++){
        strcpy(*(i),*(i+1));  // (dest,source)
    }
    *(tableau+taille_tableau-1)=NULL;
    return taille_tableau-1;// On retourne la taille du tableau orignelle à laquelle on retire -1 , pour l'élement enlever.
}

// Cette fonction est faite surtout pour etre utiliser dans la boucle de mis a Infini de tous les coups
// pourrait etre fait dirrectement dans le code. 
void Changer_Cout(T_GRAPHE G,char* mot,int new_cout,int nombre_mots,int taille_mots,int a){
int position = Hash(mot,a,nombre_mots,taille_mots);
L_SOMMET r = Rech_Chaine(mot,*((G.table)+position));
((r->val)->cout)= new_cout;
}

// idem changer_cout, sert à lire le cout d'un mot, juste question d'estetisme
int Trouver_Pcc_(T_GRAPHE G,char* mot,int nombre_mots,int taille_mots,int a){
int position = Hash(mot,a,nombre_mots,taille_mots);
L_SOMMET r = Rech_Chaine(mot,*((G.table)+position));
return ((r->val)->cout);
}

// fonction qui calcule le plus court chemin entre deux mots
int Dijkstra(T_GRAPHE G,FILE* f1,char* mot_depart,char* mot_arrive,int taille_mots,int nombre_mots){
// init de variables
	int PCCJ=0,PCCK=0,PCC=0;
	int Infini=INT_MAX;
	L_SUCC p=NULL,r=NULL,q=NULL;
	int position_j=0;
	int i=0,k=0,l=0;
	int taille_c=nombre_mots,taille_s=0;
	char* mot_j;
	if((mot_j=(char*)calloc(taille_mots,sizeof(*mot_j)))==NULL) return 1;
// on init notre liste de mots C contenant tous les mots de G. idem avec S vide.
	char** 	C=Remplissage_Tableau(f1,taille_c,taille_mots);
	char**  S=NULL;
// tous les PCC à infini
	for (i=0;i<taille_c;i++) Changer_Cout(G,*(C+i),Infini,taille_c,taille_mots,CODE_HACHAGE);
// sauf le dernier à 0		
	Changer_Cout(G,mot_depart,0,taille_c,taille_mots,CODE_HACHAGE);
// ENTREE DANS LA BOUCLE et faire TANTQUE mot_arriver n'est pas dans S et PCCJ != inf	
	do{	
		PCCJ=Trouver_Pcc_(G,*(C),nombre_mots,taille_mots,CODE_HACHAGE);
		strcpy(mot_j,*C);
// cette boucle for selection la plus petite valeur de PCCJ et donne le sommet dans mot-J
		for(i=1;i<taille_c;i++){
			if((PCC=Trouver_Pcc_(G,*(C+i),nombre_mots,taille_mots,CODE_HACHAGE))<PCCJ) {
			PCCJ=PCC;
			strcpy(mot_j,C[i]);  //strcpy(dest,src)
			}
		}
// maj de S et C
		S = Ajout_Mot_Tableau(S,taille_mots,mot_j,&taille_s); // ajout de J dans S
		taille_c=Suppression_Dans_Tableau(C,mot_j,taille_c);  // suppression de J dans C
//On positionne un pointeur P sur la liste de succ du mot j J il faut donc : la position, puis le trouver, puis faire pointer p
		position_j=Hash(mot_j,CODE_HACHAGE,nombre_mots,taille_mots);
		r=Rech_Chaine(mot_j,*(G.table+position_j));
		p=((r->val)->Liste_succ);	
// on va parcourir la liste de succ de j c-a-d les k tant que l'on est pas à la fin de la liste => p==NULL
		while(p){
// Si le PCCK du mots pointé par p est plus grand que le PCCJ+1 alors on met à jour son pere et son cout
			if( (PCCK=Trouver_Pcc_(G,((p->val)->mot),nombre_mots,taille_mots,CODE_HACHAGE))>(PCCJ+1) ){  
				PCCK=(PCCJ+1); // c(j,k) tjs égale à 1 car on travailel sur des métagrame
				((p->val)->cout)=PCCK;// maj du cout
				((p->val)->pere)=((r)->val); // maj du pere
			}
		p=p->suiv; // deplace p sur le suivant pour continuer la meme opération avec le succ
		}
	} while( (Recherche_Mot_Tableau(S,mot_arrive,taille_s)==NULL)&&(PCCJ!=Infini) );
	free(mot_j);
// On libere les tableaux C et S 
	for (l=0;l<nombre_mots;l++) free(*(C+l));
	free(C);
	for (l=0;l<taille_s;l++) free(*(S+l));
	free(S);
// on test si c'est le PCCJ!=Inf qi a fait sortir du while 
	if(PCCJ==Infini) return 1; // si le chemin ne peut pas se prolonger, alors on retourn 1
	return 0; // sinon 0
}


void Affiche_Chemin(T_GRAPHE G,char* mot_depart,char* mot_arrive,int nombre_mots,int taille_mots){
T_SUCC t=NULL;
L_SUCC q=NULL;
int position_arrive=0;
	position_arrive=Hash(mot_arrive,CODE_HACHAGE,nombre_mots,taille_mots);
	q=Rech_Chaine(mot_arrive,*(G.table+position_arrive));
	t=q->val;
//t se trouve donc sur le mot d'arriver, en allant voir son champ pere on conait le mot suivant à afficher.
	printf("\nChemin possible en %d metagramme(s)\n",t->cout);
	do{	printf("%s << ",t->mot);
		t=t->pere; // on recommence avec t qui est mtn égale au pere de l'arriver, etc ...
	} while(strcmp(t->mot,mot_depart)!=0);  // jusu'au mot de depart 
	printf("%s << \n\n",t->mot);
}

