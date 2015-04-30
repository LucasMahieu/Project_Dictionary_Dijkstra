
#include "../Headers/main.h" 

int main(int argc,char** argv){ // le main va prendre 2 arg. le fichier de mots et la tailles max des mots
  	T_GRAPHE G;
  	int n;
	if (argc<1) {
		return 0;
	}
	FILE* f1=fopen(argv[1],"r");
	
	int taille_mots = Taille_Mots(f1);
	G.table=creer_graphe(f1,&(G.taille),taille_mots);  
	
	  while(1){
	
    	printf("Quelle position dans la table ? \n");
    	scanf("%d",&n); /*On se a place à un certain point dans la table de hashage et on affiche l'ensemble de la liste associée*/

     visualiser_liste(*(G.table+n));
     
    getchar();
	  }
	return 0;
}

