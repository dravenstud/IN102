/* Adam Gassem */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Q1
struct Guerrier{
	char* nom;
	double PV; // Points de vies
	int PA;  // Points d'atque
	double TG; //Taux de guérison
};
//Q3:
void afficher_guerrier(struct Guerrier g){
	printf("Nom : %s\n",g.nom);
	printf("Points de vies: %.2lf\n",g.PV);
/*	printf("Points d'attaque: %d\n", g.PA);
	printf("Taux de guerison: %.2lf\n", g.TG); */
}
//Q4:
void attaque(struct Guerrier* pjoueur, struct Guerrier* padversaire){
	(*padversaire).PV -= (*pjoueur).PA;
}
//Q5:
void bouclier(struct Guerrier* pjoueur){
	(*pjoueur).PV += ((*pjoueur).TG * (100 - (*pjoueur).PV));
}
//Q10:
int rand_int(int p){
	
	return rand()%(2*p)-p;
}
int main(){
	//Q2
	srand(time(0));
	struct Guerrier Aragorn, Boromir;
	Aragorn.nom="Aragorn";
	Aragorn.PV = 100.0;
	Aragorn.PA = 20;
	Aragorn.TG = 0.6;

	Boromir.nom= "Boromir";
	Boromir.PV = 100.0;
	Boromir.PA = 30;
	Boromir.TG = 0.4;
	//Q3
	afficher_guerrier(Aragorn);
	afficher_guerrier(Boromir);

	//Q4
	//attaque(&Aragorn,&Boromir);
	afficher_guerrier(Boromir);
	//Q5
	bouclier(&Boromir);
	afficher_guerrier(Boromir);
	// Q6
	struct Guerrier* pjoueur;
	struct Guerrier* padversaire;
	struct Guerrier* Temporaire;
	struct Guerrier* gagnant=0;
	int nb_tours=0;
	pjoueur=&Aragorn;
	padversaire=&Boromir;
	//Q7
	printf("\n");
	char touche='x';
	while (1){
		if(pjoueur->PV<0){
			gagnant= padversaire;
			break;
		}
		if(padversaire-> PV<0){
			gagnant=pjoueur;
			break;
		}
		nb_tours++;
		//Q10
		padversaire->PV+=rand_int(5);
		printf("C'est le tour de %s\n",(*pjoueur).nom);
		
		
		while(touche!='a' && touche!='b'){
		printf("Tappez a pour attaquer et b pour lever votre bouclier\n");
		scanf(" %c",&touche);}
		if(touche=='a'){
			attaque(pjoueur,padversaire);
		}else{
			bouclier(pjoueur);
		}
		
	
		touche='x';
		Temporaire=pjoueur;
		pjoueur= padversaire;
		padversaire=Temporaire;
		
		afficher_guerrier(Aragorn);
		afficher_guerrier(Boromir);
	}
printf("%s a gagne !\n",gagnant->nom);
printf("Nombres de Tours: %d\n",nb_tours);

	return 0;
}

/*
Q4:
On utilise les poionteurs pour pouvoir modifier la valeur
de la variable
Q9:
Aragon peut maximiser son bouclier en tappant b quand il a 
30 points de vies (car c'est egal aux points d'attque de Boromir) 
puisque s'il ne tappe pas b il va perdre dans le prochain tour.
donc Aragon peut gagner 42 points de vie a chaque fois donc
il peut jouer sans fin.

Mais cela (42 points de vies) est plus grand que les points d'attque de Boromir
d'ou Boromir ne peut pas gagner si Aragon joue les meilleurs actions

De même:
Boromir peut gagner 28 points de vies qui est plus grand que Aragon Points d'attque.
Donc Person ne peut gagner si les deux jouent les meilleurs actions. 


*/