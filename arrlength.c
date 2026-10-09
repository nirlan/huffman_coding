#include <stdio.h>
#include <stdlib.h>
#include "arrlength.h"
#include "modelo.h"

void criaArrLength(float prob[])
{
	int workArray[ALPHABET]={0};
	alocaMenoresPesos(prob,workArray);
}

//encontra os dois menores números com maior índice
static MenoresPesos calculaMenoresPesos(float prob[])
{		
	int i=0;
	int imax1=0;
	int imax2=0;
	float lowest1=1.0;
	float lowest2=1.0;	
	while(i!=ALPHABET)
	{
		//encontra o primeiro menor número com maior índice
		if(lowest1>=prob[i]&&prob[i]!=0)
		{
			lowest2=lowest1;
			imax2=imax1;
			lowest1=prob[i];
			imax1=i;
			//se ambos os números são iguais e o próximo é maior, encerra
			if(lowest1==lowest2&&i<ALPHABET-1&&prob[i+1]>lowest1)
			{
				printf("\nHello!");
				break;
			}			
		}
		//rastreia o segundo menor número com maior índice
		else if(lowest2>=prob[i]&&prob[i]!=0)
		{
			lowest2=prob[i];
			imax2=i;
		}
		i++;
	}
	
	//soma as duas menores probabilidades com maior índice e aloca 
	printf("\nMenor probabilidade: indice %d e %d => %.6f e %.6f",imax1,imax2,lowest1,lowest2);
	
	MenoresPesos resultado;
	resultado.prob1 = lowest1;
	resultado.prob2 = lowest2;
	resultado.ind1 = imax1;
	resultado.ind2 = imax2;	
	
	return resultado;
}

static void alocaMenoresPesos(float prob[],int workArray[])
{
	int flag = 0;
	int i = 0;
	MenoresPesos resultado = calculaMenoresPesos(prob);	
	printf("\nSoma dos menores pesos com maior indice: %.6f", resultado.prob1+resultado.prob2);
	while(i!=ALPHABET)
	{	
		//ignora probabilidades 0 no início da array
		if(prob[i]==0&&flag==0)
		{
			//printf("\n%d ",i);
			i++;
			continue;
		}		
		flag = 1;
		
		//se for a primeira iteração não nula, aloca o resultado da soma no menor índice não nulo
		printf("\n indice %d, ind1 %d e ind2 %d",i,resultado.ind1,resultado.ind2);
		if(i==resultado.ind1&&i+1==resultado.ind2)
		{
			prob[i] = resultado.prob1 + resultado.prob2;
			prob[i+1] = 0;
			workArray[i] = 1;			
		}
		
		//calcula os novos menores pesos e índices
		resultado = calculaMenoresPesos(prob);
		
		//aloca a soma no primeiro índice nulo (exceto índices iniciais)
		if(prob[i]==0)
		{
			prob[i] = resultado.prob1 + resultado.prob2;
			workArray[i] = 1;
		}				
		i++;
		printf("\n%d ",i);
	}
}