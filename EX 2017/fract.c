#include<stdio.h>
#include "fract.h"

unsigned int pgcd(unsigned int a,unsigned int b){
	if(a==b){
		return a;
	}else if(a>b){
		return pgcd(a-b,b);
	}else if(b>a){
		return pgcd(a,b-a);
	}
}
struct fraction_t irreductible(struct fraction_t fraction){
	struct fraction_t result;
	unsigned int reduction = pgcd(fraction.num,fraction.denom);
	result.num = fraction.num/reduction;
	result.denom = fraction.denom/reduction;
	result.sign = fraction.sign;
	return result;
}
int main(){
	struct fraction_t fraction,result;
	// unsigned int a;
	// scanf("%u", &a);
	// printf("%u \n", a);
	char signe;


	scanf("%c %u %u",&signe,&fraction.num,&fraction.denom);
	
	if(signe=='+'){
		fraction.sign = S_pos;
	}else if(signe=='-'){
		fraction.sign = S_neg;
	}
	result = irreductible(fraction);
	// printf("%u \n",fraction.denom);
	// printf("%u \n",fraction.sign);
	// printf("%u \n",pgcd(fraction.num,fraction.denom));
	if(result.sign==S_neg){
		printf("-");
	}
	printf("%u/%u\n",result.num,result.denom);
	return 0;
}