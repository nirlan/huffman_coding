#include <stdio.h>
#include <stdlib.h>
#include "arrlength.h"
#include "modelo.h"

void criaArrLength(float prob[])
{
	//int workArray[ALPHABET]={0};
	agrupaNos(prob);
}

//agrupamento de nós e gravação de ponteiros do pai
static void agrupaNos(float prob[])
{
	int folha=0;
	int noInterno=0;
	
	for(int prox=0;prox<ALPHABET-1;prox++)
	{	
		int filho1, filho1_eh_folha;
		int filho2, filho2_eh_folha;

		//seleciona o primeiro nó de menor peso entre folhas e nós internos
		if(folha<ALPHABET&&(noInterno>=prox||prob[folha]<=prob[noInterno]))
		{
			filho1=folha++;
			filho1_eh_folha=1;
		} else {
			filho1=noInterno++;
			filho1_eh_folha=0;
		}
		
		//seleciona o segundo nó de menor peso 
		if(folha<ALPHABET&&(noInterno>=prox||prob[folha]<=prob[noInterno]))
		{
			filho2=folha++;
			filho2_eh_folha=1;
		} else {
			filho2=noInterno++;
			filho2_eh_folha=0;
		}

		float somaPesos=prob[filho1]+prob[filho2];		
		
		//se os filhos forem nós internos, grava o índice do pai (prox) na posição do filho
		if(!filho1_eh_folha)
		{
			prob[filho1]=(float)prox;
		}
		if(!filho2_eh_folha)
		{
			prob[filho2]=(float)prox;
		}

		//grava a soma no índice do novo nó interno
		prob[prox]=somaPesos;
		printf("\nsomaPesos: %.6f", somaPesos);
	}
	/* int i=0;
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
	printf("\nMenor probabilidade: indice %d e %d => %.6f e %.6f",imax1,imax2,lowest1,lowest2); */
}