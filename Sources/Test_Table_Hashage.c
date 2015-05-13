
#include "../Headers/main.h" 

int main(int argc,char** argv){ // le main va prendre 2 arg. le fichier de mots et la tailles max des mots
  	T_GRAPHE G;
  	int n;
	if (argc<1) {
		return 0;
	}
	FILE* f1;
	if( ( f1=fopen(argv[1],"r") ) == NULL ) return 1;
	
	int taille_mots = Taille_Mots(f1);
	int nombre_mots = Taille_Fichier(f1);
	
	printf("taille des mots = %d \n",taille_mots);
	G.table=Creer_Graphe(f1,taille_mots,nombre_mots);
	if(G.table==NULL)return 0;
	G.taille=Taille_Fichier(f1);
	
	  while(1){
	
    	printf("Quelle position dans la table ? \n");
    	scanf("%d",&n); //On se a place à un certain point dans la table de hashage et on affiche l'ensemble de la liste associée
    	
     Visualiser_Liste(*((G.table)+n));
     printf("n choisi est: %d \n",n);
    getchar();
	  }
	if((fclose(f1))==0)  return 1; 
	return 0;
}
