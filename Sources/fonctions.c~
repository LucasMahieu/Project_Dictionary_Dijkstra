//
//  fonctions.c
//  
//
//  Created by Mahieu Lucas on 18/04/2015.
//
//

#include "../Headers/main.h"



int Hash(char mot[], int a,int n,int taille_mots){  // vérifié le 04/05 lucas
	int i=taille_mots-1;
	int h=1;
	while (i>0) {
		h=(h*a+((int)mot[i]))%n;
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


