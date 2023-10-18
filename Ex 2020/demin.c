#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum cases{INCONNUS_SANS,INCONNU_AVEC,DEMINE,MINE};
int* creer_grille(int N, int M){
	int* grille;
	grille = (int*)malloc(sizeof(int)*(N*M));
	for(int i=0;i<N*M;i++){
		grille[i]=INCONNUS_SANS;
	}
	return grille;
}
int afficher(int* grille,int N, int M){
	int X=0,Y=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			// printf("%d\n",i*N+j);
			switch(grille[i*M+j]){

				case INCONNUS_SANS:printf("?");break;
				case INCONNU_AVEC:printf("?");Y++;break;
				case DEMINE:printf(".");break;
				case MINE:printf("*");X++;break;
			}
		}
		printf("\n");
	}
	printf("\n");
	return X;
}
int miner(int c, int* grille, int N , int M){
	if(grille[c]==INCONNU_AVEC){
		return 0;
	}else{
		grille[c]=INCONNU_AVEC;
		return 1;
	}
}

void test_affichage(){
	int* grille=creer_grille(3,4);
	grille[4]=DEMINE;
	grille[2]=INCONNU_AVEC;
	grille[6]=INCONNU_AVEC;
	grille[8]=MINE;
	afficher(grille,3,4);
}

void miner_alea(int* grille, int N , int M){
	int c = rand()%(N*M);
	while(miner(c,grille,N,M)==0){
		c =rand()%(N*M);
	}
}
void miner_alea_k(int* grille, int N, int M, int K){
	for(int i=0;i<K;i++){
		miner_alea(grille,N,M);
	}
}
int* test_miner(){
	int* grille = creer_grille(3,4);
	afficher(grille,3,4);
	miner(0,grille,3,4);
	miner(4,grille,3,4);
	miner(8,grille,3,4);
	miner(11,grille,3,4);
	// miner_alea_k(grille, 3,4,4);
	afficher(grille,3,4);
	return grille;
}
void transformer(int c , int* grille, int N , int M){
	switch(grille[c]){
		case INCONNU_AVEC:grille[c]=MINE;break;
		case INCONNUS_SANS:grille[c]=DEMINE;break;
	}
}
int jouer(int c, int* grille, int N, int M){
	int l,k;
	if(grille[c]==INCONNU_AVEC){
		return 0;
	}else{
		transformer(c,grille,N,M);
		// %M => colonne /M => ligne
		l = c/M;
		k = c%M;
		if(l>0){
			transformer((l-1)*M+k,grille,N,M);
		}
		if(l<N-1){
			transformer((l+1)*M+k,grille,N,M);
		}
		if(k<M-1){
			transformer((l)*M+k+1,grille,N,M);
		}
		if(k>0){
			transformer((l)*M+k-1,grille,N,M);
		}
		return 1;
	}
}
void test_joueur(){
	int* grille=test_miner();
	jouer(7,grille,3,4);
	afficher(grille,3,4);
	jouer(9,grille,3,4);
	afficher(grille,3,4);
	jouer(2,grille,3,4);
	afficher(grille,3,4);
}
int main(){
	srand(time(0));
	// N=3 M=4 K=3
	int N=5,M=5, K=10,X=0,c,stop,tours=0;
	int* grille=creer_grille(N,M);
	miner_alea_k(grille, N,M,K);
	while(1){
		X=afficher(grille, N,M);
		if(X==K){
			break;
		}
		
		printf("%d trouvees, %d restantes\n",X,K-X);
		printf("numero : ");
		scanf("%d",&c);
		tours++;
		stop=jouer(c,grille, N,M);
		if(stop==0){
			afficher(grille,N,M);
			printf("Perdu en %d tours.",tours);
			break;
		}
	}
	if(X==K){
	printf("Gagne en %d tours.\n",tours);
	}
	// test_affichage();
	// test_miner();
	// test_joueur();
	return 0;
}