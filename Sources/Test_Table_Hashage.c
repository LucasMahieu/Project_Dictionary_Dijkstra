
#include "main.h" 

void main(FILE *f){ // le main va prendre 2 arg. le fichier de mots et la tailles max des mots
  	T_GRAPHE G;
  	int n; 
	
  	G.table=creer_graphe(f,&(G.taille));  
	
	  while(1){
	
    	printf("Quelle valeur pour n ? \n");
    	scanf("%d",&n); /*On se a place à un certain point dans la table de hashage et on affiche l'ensemble de la liste associée*/

     visualiser_liste(G.table + n);
     
    getchar();
	  }

}

