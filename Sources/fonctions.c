//
//  fonctions.c
//  
//
//  Created by Mahieu Lucas on 18/04/2015.
//
//

#include "./Header/main.h"



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
	char* chaine =NULL;
	int N = 20; /*Permet de déterminer la longueur des mots, pas de mots aussi long et seulement détection des retours à la ligne*/

	FILE* f1 = fopen(fichier,"r");
	if (f1==NULL) return 1;
	
	chaine = fgets(mot_fichier,N,f1);	
	if(mot_fichier[i]!='\n'){
		i++;
	}
return i;	
}





