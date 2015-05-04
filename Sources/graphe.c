//
//  graph.c
//  
//
//  Created by Mahieu Lucas on 18/04/2015.
//

#include "../Headers/main.h"

L_SOMMET* Creer_Graphe(FILE* fichier,int taille_mots, int nombre_mots){ // on va retourner en adresse la taille de la table
	char mot_fichier[20];  // 20 = taille max d'un mots avec de la marge
	int position=0;
	L_SOMMET* Table_hachage;
	rewind(fichier);
	
	if((Table_hachage=(L_SOMMET*)calloc(nombre_mots,sizeof(*Table_hachage)))==NULL) return NULL;  // il faudra faire une fonction qui calcule le # de mots
	
	printf("test1 graphe \n");
	
	// ici on va remplir notre tableau avec les listes. La position est déterminer par la sortie du hachoire AH AH AH (sadique)
	while (fgets(mot_fichier,taille_mots+2,fichier)!=NULL){   
	//fgets = null quand on a EOF. Il arrete la saise de charactere lorsqu'il rencontre un retour à la ligne. c'est pourquoi j'ai mis +2, comme ça il va aller lui meme 'buter' contre le retour à la ligne, et au coup	d'après il sera en bonne position.
		
		printf("mot: %c %c %c \n",mot_fichier[0],mot_fichier[1],mot_fichier[2]);		
		
		position=Hash(mot_fichier,CODE_HACHAGE,nombre_mots,taille_mots); //calcul de la position dans la table par fct de hachage 
	printf("test calc position hash \n");
		Ajout_Tete_L_SUCC(Ajout_Tete(mot_fichier,NULL,taille_mots),*(Table_hachage+position));       // puis on l'ajoute en tete de liste pour ne pas deranger les éventuels mots deja présents
	};
	rewind(fichier);
	return (Table_hachage);
}


void Recherche_Successeur(T_GRAPHE G,FILE* f1,int taille_mots, int nombre_mots,int taille_table){
	int i=0,j=0,m=0,k=0;
	int position = 0;
	char* mot_remplissage;  // char* ici 
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";/*On utilisera cette chaine de caractère pour mofifier les charactères dans le mot "mot"*/
	L_SOMMET* p = NULL;/* On prend un pointeur pour pouvoir parcourir les listes associées à la table de hachage*/
	L_SOMMET* q = NULL;  //-> pointeur qui va nous permettre de se déplacer dans la table de hash 
	q = G.table;
	L_SOMMET r =NULL;
	rewind(f1);
	/*On parcours la table de hashage pour chaque mot formé avec la variable "mot_remplissage". Ce mot "mot_remplisssage" est formé à partir 
	de des mots déjà présent dans la table de hashage. Et si on trouve ce nouveau mot_remplissage dans la table de hashage on peut l'ajouter en tête*/
	
	for(k=0;k<taille_mots;k++){
		for(m=0;m<taille_table;m++){		/*On initialise le "mot_remplissage"*/
			p = G.table;
			while(p){
				mot_remplissage=(p[m]->val)->mot;  // je pense que c'est .mot 
				for(j=0;j<26;j++){
					mot_remplissage[k]=alphabet[j];	/*On modifie mot_remplissage avec le tableua alphabet*/
					position=Hash(mot_remplissage,CODE_HACHAGE,nombre_mots,taille_mots);/*On hash le mot_remplissage et on regarde si il appartient à la table de hasgae*/
						while(q+position){ /*On parcours l'ensemble des L_SOMMET de la table de hashage*/
							r=Rech_Chaine(mot_remplissage,*(q+position));/*On recherche si le mot_remplissage est bien présent dans la table hashage*/
							if(!r){/*Si mot_remplissage est présent dans la table de hashage, on peut faire un ajout en tête*/
								Ajout_Tete(mot_remplissage,((*p)->val)->Liste_succ,taille_mots);
							}/*On ajoute en tête si le mot est bien un métagramme présent dans la table de hashage*/
							*(q+position)= (*(q+position))->suiv;
						}
				}
				*p=(*p)->suiv;
			}
		}
	}
	rewind(f1);
}



/*0n applique l'algorithme de Dijkstra*/

void plus_court_chemin(char* depart, char* arrive, int nombre_mots, T_GRAPHE G, FILE* fichier, int taille_mots){

	int i; 
	int* pcc;
	int infini = INT_MAX;
	int position; /*Utilisé pour localiser le mot depart dans la table de hashage*/ 
	
	T_GRAPHE C ; /*On définit le tableau C des sommets à visiter. EST CE QUE POINTEUR SUR L_SOMMET PEUT SUFFIR ?*/
	L_SOMMET* S; /*On définit le tableau S des sommets visités*/
	L_SUCC pointeur_sur_depart;


	C =Creer_Graphe(fichier,taille_mots);/*On crée un graphe avec tous les mots du fichier*/
	Recherche_Successeur(C,fichier,taille_mots,nombre_mots,taille_fichier);/* On recomplète l'ensemble des successeurs associé à chacun des mots du fichier*/ 


	pcc = calloc(nombre_mots,sizeof(*pcc));/*On alloue un tableau pour retenir toutes les valeurs de cout, valeur de PCC*/

	/**************On initialise l'ensemble des élements de PCC************/ 
	pcc[0]=0;/*La distance du mot "départ" à lui même est de zéro*/
	for(i=1,i<nombre_mots,i++){
		pcc[i]=infini;
	}


	/**************On applique l'algorithme************/ 
	position = Hash(depart,CODE_HASHAGE,nombre_mots);/*On regarde où se situe notre mot de "départ" dans la table de hashage*/ 
	/*On va chercher dans les successeurs de mot "départ" pour déterminer le départ du chemin suivant, voir graphe.On se positionne dans la table de hashage là où se trouve le mot "depart" et on regarde la liste de successeur*/ 
	pointeur_sur_depart = Rech_Chaine(mot_remplissage,*(C.table+position));/*Retourne un pointeur sur où se trouve le mot dans la liste associé à l'endroit où se trouve mot "depart" dans la table de hashage. C'est un pointeur sur un l-succ*/
	/*On va parcourir l'ensemble de la table des successeurs associé à "depart". De cette manière on peut parcourir tous les élements qui sont à plus proche distance de depart*/
	q = pointeur_sur_depart;
	while(!q){
		positionq
		q = q->suiv;
