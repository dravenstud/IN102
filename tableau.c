#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int** creer_mat(int n, int m){
	int** mat;
	mat = malloc (n* sizeof(int*));
	for(int i=0;i<n;i++){
		mat[i]=malloc(m*sizeof(int));
	}
	return mat;
}
void free_mat(int** mat,int n, int m){
	for(int i=0;i<n;i++){
		free(mat[i]);
	}
	free(mat);
}
void fill(int** tab,int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			tab[i][j]=i+j;
		}
	}
}
void affichage(int** tab,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main(){
	int stat[3][4];
	int** tab = creer_mat(3,4);
	char nom[30];
	gets(nom);	
	printf("%s \n",nom);
	// fill(stat,3,4);
	fill(tab,3,5);
	// affichage(stat,3,4);
	affichage(tab,3,5);
	free_mat(tab,3,5);

	return 0;
}