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


