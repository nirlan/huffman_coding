#include <stdio.h>
#include <stdlib.h>
#include "arrlength.h"
#include "modelo.h"

void criaArrLength(float prob[])
{
	//encontra os dois menores números com maior índice
	int workArray[ALPHABET]={0};
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
	printf("\nMenor probabilidade: indice %d e %d => %.6f e %.6f",imax1,imax2,lowest1,lowest2);
}