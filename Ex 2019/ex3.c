#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int** creer_matrice(int n){
	int** mat;
	mat = malloc(n*sizeof(int*));
	for(int i = 0;i<n;i++){
		mat[i]=malloc(n*sizeof(int));
	}
	return mat;
}

void remplir(int** mat,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
}
void affichage(int** tab,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j<n-1){
			printf("%d ",tab[i][j]);
		}else{
			printf("%d",tab[i][j]);
		}
		}
		printf("\n");
	}
	// printf("\n");
}
double calcul_norme(int** mat,int n,int* j){
	*j=0;
	int max=0,max_temp;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			max_temp+= abs(mat[i][k]);
		}
		if(max_temp>max){
			max=max_temp;
			*j=k;
		}
		max_temp=0;
	}
	return max;
}
void free_mat(int** mat,int n){
	for(int i=0;i<n;i++){
		free(mat[i]);
	}
	free(mat);
}
int main(int argc, char* argv[]){
	if(argc!=2){
		printf("ERREUR\n");
		return 1;
	}else{
	int n = atoi(argv[1]),j,norme;
	// printf("%d",n);
	int** mat=creer_matrice(n);
	remplir(mat,n);
	affichage(mat,n);
	norme=calcul_norme(mat,n,&j);
	printf("%d@%d\n",norme,j);
	free_mat(mat,n);
}
	return 0;
}