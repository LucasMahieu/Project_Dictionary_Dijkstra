//
//  fonctions.c
//  
//
//  Created by Mahieu Lucas on 18/04/2015.
//
//

#include "../Headers/main.h"



int hash(char mot[], int a,int n){
	int i=(strlen(mot)-2);  // Ici je fait -2 (cf. commentaire debut de main) le \n fait partie du mot et le \0 aussi donc faut en enlever 2
	int h=1;
	while (i>0) {
		h=(h*a+mot[i])%n; 
		i--;
	}
	return h;
}

int Taille_Mots(FILE* fichier){
	int i = 0;
	char* chaine=NULL;
	char* mot_fichier=NULL;
	int N = 20; /*Permet de déterminer la longueur des mots, pas de mots aussi long et seulement détection des retours à la ligne*/	
	chaine = fgets(mot_fichier,N,fichier);	
	if(mot_fichier[i]!='\n'){
		i++;
	}
fclose(fichier);
return i;	
}



int taille_fichier(FILE* fichier){
	int i=0;
	char* lettre;
	
	while (lettre[0]!=EOF) {   // tant que l'on est pas à la fin du document
		fgets(lettre,2,fichier);     // on stock UN character dans lettre donc lettre = (le char, \0) 
		if (lettre[0]=='\n') {  // si c'est un retour à la ligne alors on le comptabilise
			i++;
		}
	}
	fclose(fichier);
	return i;   // le # de \n correspond au # de mots du fichier
}



