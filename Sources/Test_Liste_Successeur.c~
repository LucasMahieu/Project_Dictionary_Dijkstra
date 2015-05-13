#include "main.h"

int main(int argc, char** argv){
	
	T_GRAPHE G;
	int i =0;  
	int n=0;        //Permet de définir compteur pour développer l'ensemble des listes
	L_SUCC p=*(G.table);
//	if (argc<1) {
//		return 0;
//	}
	//On définit le pointeur qui permettra de visualiser les bonnes listes
	
	FILE* f1;
	if( ( f1=fopen("test_mot3.txt","r") ) == NULL ) return 1;
	
	int taille_mots = Taille_Mots(f1);
	int nombre_mots = Taille_Fichier(f1);
	
	G.table=Creer_Graphe(f1,taille_mots,nombre_mots);
	if(G.table==NULL)return 0;
	G.taille=Taille_Fichier(f1);
	
	Recherche_Successeur(G,f1,taille_mots,nombre_mots);
	
	while(1){
		printf("Quelle position dans la table ? \n");
		scanf("%d",&n); //On se a place à un certain point dans la table de hashage et on affiche l'ensemble de la liste associée
		p=*((G.table)+n);
		printf("Table de HASHAGE en n\n");
		Visualiser_Liste(p);
		while(p){
			printf("Liste %d\n",i);
			i ++;
			Visualiser_Liste((p->val)->Liste_succ);
			p=p->suiv; //On parcours l'ensemble des élements associés à une place dans la table de hashage
		}
	}	
}
