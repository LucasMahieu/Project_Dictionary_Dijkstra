

#include "main.h"

void main(int argc, char** argv){
	
	T_GRAPHE G;
	
	FILE* f = argv[1];
	
	G.table=creer_graphe(f,&(G.taille)); 
	recherche_successeur(G,int taille_mot)
