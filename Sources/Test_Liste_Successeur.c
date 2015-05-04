

#include "main.h"

void main(int argc, char** argv){
	
	T_GRAPHE G;
	int taille_mot= 0; /*Permet de déterminer la taille d'un mot*/
	int i =0; /*Permet de définir compteur pour développer l'ensemble des listes*/
	
	/*On définit le pointeur qui permettra de visualiser les bonnes listes*/
	
	FILE* f = argv[1];
	taille_mot = Taille_Mots(f);
	
	G.table=Creer_Graphe(f,&(G.taille)); 
	Recherche_Successeur(G,taille_mot);
	
	printf("Quelle position dans la table ? \n");
	scanf("%d",&n); /*On se a place à un certain point dans la table de hashage et on affiche l'ensemble de la liste associée*/

	while(!(G.table + n)){
		Visualiser_Liste((G.table + n)->val)->Liste_succ));
		(G.table + n) = (G.table + n)->suiv; /*On parcours l'ensemble des élements associés à une place dans la table de hashage*/ 
	}
}
