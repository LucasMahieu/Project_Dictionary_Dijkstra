//  main.c
//  Created by Mahieu Lucas on 18/04/2015.

#include "./Headers/main.h"


int main (int argc,char** argv){  // le main va prendre 2 arg. le fichier de mots et la tailles max des mots
// si pas d'argument avec le main = erreur	
  	if (argc<1) {
  		printf("Pas assez d'argument pour le main \n");
		return 1;
	}
// si pas reussi a ouvrir erreur	
	FILE* f1;
//	if( ( f1=fopen(argv[1],"r") ) == NULL ) return 1;
	if( ( f1=fopen("test_mot3.txt","r") ) == NULL ) return 1;
// calcul du nombre de mots dans le fichier et la taille des mots	
	int taille_mots = Taille_Mots(f1);
	int nombre_mots = Taille_Fichier(f1);

// Allocation de la memoire pour les deux mots de depart et d'arrive
	char* mot_depart;
	char* mot_arrive;
	if((mot_depart=(char*)calloc(taille_mots,sizeof(*mot_depart)))==NULL) return 1;
	if((mot_arrive=(char*)calloc(taille_mots,sizeof(*mot_arrive)))==NULL) return 1;
	
// Init de differentes variables
T_GRAPHE G;
int loop=1;
char answer_loop;
int pos=0;
// cration du graphe, si G.table == NULL -> erreur à la creation
	G.table=Creer_Graphe(f1,taille_mots,nombre_mots);
	if(G.table==NULL)return 1;
// maj de sa taille
	G.taille=Taille_Fichier(f1);
// Creation des listes de succ
	Recherche_Successeur(G,f1,taille_mots,nombre_mots);
	
while(1){
	do{	
		printf("Voulez-vous trouver un chemin ? (o/n)ou(y/n)\n");
		scanf("%c",&answer_loop);
		if(answer_loop=='n') return 0;
		if(answer_loop=='N') return 0;
	}while ((answer_loop !='o')&&(answer_loop !='y')&&(answer_loop !='O')&&(answer_loop !='Y'));
	
//Choix des mots de depart et d'arrive, si il existe pas on sort du programme
	printf("entrer le mot de depart de %d lettres:\n",taille_mots);
	getchar();
	fgets(mot_depart,sizeof(mot_depart),stdin);
	mot_depart[taille_mots]='\0'; // on enlève le \n
	pos=Hash(mot_depart,CODE_HACHAGE,nombre_mots,taille_mots);
	if(Rech_Chaine(mot_depart,*(G.table+pos))==NULL) {
		printf("Ce mot n'existe pas\n");
		return 1;
	}
	printf("entrer le mot d'arrive de %d lettres:\n",taille_mots);	
	fgets(mot_arrive,sizeof(mot_arrive),stdin);
	mot_arrive[taille_mots]='\0'; // on enlève le \n
	pos=Hash(mot_arrive,CODE_HACHAGE,nombre_mots,taille_mots);
	if(Rech_Chaine(mot_arrive,*(G.table+pos))==NULL) {
		printf("Ce mot n'existe pas\n");
		return 1;
	}
	
	if (Dijkstra(G,f1,mot_depart,mot_arrive,taille_mots,nombre_mots)==0){
		Affiche_Chemin(G,mot_depart,mot_arrive,nombre_mots,taille_mots);
	}
	else{
	printf("Ce chemin est n'existe pas !\n");
	}
}
free(mot_depart);
free(mot_arrive);
for (l=0;l<nombre_mots;l++) free(G.table[l]);
free(G.table);
return 0;
}
