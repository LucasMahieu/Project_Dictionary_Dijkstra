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
	char mot_fichier[30];  // 20  = taille mots max
	int N = 30; /*Permet de déterminer la longueur des mots, pas de mots aussi long et seulement détection des retours à la ligne*/	
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
	while (fgets(ligne,500,fichier)!=NULL) {   // tant que l'on est pas à la fin du document
			i++;
	}
	rewind(fichier);
	return i;   // le # de \n correspond au # de mots du fichier
}


char** Remplissage_Tableau(FILE* fichier, int taille_fichier,int taille_mots){
    char** tableau;
    int i = 0;
    int j = 0;
    int k = 0;//Permet dans la boucle de remplissage d'atteindre les différentes cases du tableau
    char mot_fichier[30];
    tableau = (char**)calloc(taille_fichier,sizeof(*tableau));//on fait un grand tableau de taille "taille_fichier". On prend un pointeur de pointeur sur un char pour pourvoir ensuite ranger les mots dans les cases
    
    for(j=0;j<taille_fichier;j++){
        *(tableau+j) = (char*)calloc(taille_mots,sizeof(**tableau));//on alloue de la place pour tous les mots
    }
  
    while (fgets(mot_fichier,taille_mots+2,fichier)!=NULL){
    	mot_fichier[taille_mots]='\0';
        strcpy(*(tableau+k),mot_fichier); //on remplit les cases du tableau lettre par lettre
        k++;
    }
    return tableau;
}




char** Ajout_Mot_Tableau(char** S,int taille_mots, char* mot, int *taille_tableau){
    char** tableau_final;
    int i = 0;
    int j = 0;
    
    if(S==NULL){
    	tableau_final = (char**)calloc(*(taille_tableau)+1,sizeof(*(tableau_final)));
    	*(tableau_final)=(char*)calloc(taille_mots,sizeof(**tableau_final));
    	strcpy(*(tableau_final),mot);
    	*taille_tableau =1;
    	return tableau_final;
    }
    
    tableau_final = (char**)calloc(*(taille_tableau)+1,sizeof(*(tableau_final)));//On alloue un nouveau que l'on retournera avec une case en plus
    for(j=0;j<*taille_tableau+1;j++){
        *(tableau_final+j) = (char*)calloc(taille_mots,sizeof(**tableau_final));//on alloue de la place pour tous les mots
    }
    
    for(i=0;i<*(taille_tableau);i++){
        strcpy(*(tableau_final+i),*(S+i));//(dest,source)On recopie tous les élements du tableau initial dans le nouveau tableau
        free(*(S+i));//On libére l'espace mémoire précedemment allloué
    }
    free(S);
    strcpy(*(tableau_final+*(taille_tableau)),mot);//"taille_tableau" pour ce placer en fin de tableau, on copie le mot en fin de tableau

    *taille_tableau=*(taille_tableau)+1;//On retourne par adresse la nouvelle taille du tableau
    return tableau_final;//On retourne le tableau final complété
}





char** Recherche_Mot_Tableau(char** tableau,char* mot, int taille_tableau){
    int i = 0;
    int k = 0;
    
    while((i == 0) && (k < taille_tableau)){//Tant qu'on a pas trouvé le mot dans le tableau (c'est à dire i=0) et que l'on pas visité tout le tableau on continue de parcourir le tableau.
        if(strcmp(mot,*(tableau+k))==0) return (tableau+k);
        k++;
    }
    return NULL;
}


int Suppression_Dans_Tableau(char** tableau, char* mot_a_supprimer, int taille_tableau){
    char** i = NULL;
    char** position = NULL;
    
    position = Recherche_Mot_Tableau(tableau,mot_a_supprimer,taille_tableau);
    
    if(position == NULL) return 0; // Si le mot n'est pas dans le tableau on sort de la fonction
    
    for(i=position; i<(tableau+taille_tableau-1);i++){
        strcpy(*(i),*(i+1));  // (dest,source)
    }
    *(tableau+taille_tableau-1) = NULL;
    return taille_tableau-1;// On retourne la taille du tableau orignelle à laquelle on retire -1 , pour l'élement enlever.
}




