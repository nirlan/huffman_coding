#include <stdio.h>
#include <stdlib.h>

//quantidade de letras do alfabeto A = {a1,....an}
#define ALPHABET 37 // {A,B,C,...,W,X,Y,Z, ,0,1,...9}
#define LETTERS {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ','1','2','3','4','5','6','7','8','9','0'}

int main() {
	FILE *fh;
	int ch;
	int count[ALPHABET]={0};	
	
	//abre o texto para a modelagem
	fh=fopen("biblia.txt","r");
	if(fh==NULL)
	{
		puts("Nao foi possivel abrir o arquivo!");
		exit(1);
	}
	while((ch=fgetc(fh))!=EOF)
	{
		//putchar(ch);
		switch(ch)
		{
			case 'A':
				count[0]++;
				break;
			case 'B':
				count[1]++;
				break;
			case 'C':
				count[2]++;
				break;
			case 'D':
				count[3]++;
				break;
			case 'E':
				count[4]++;
				break;
			case 'F':
				count[5]++;
				break;
			case 'G':
				count[6]++;
				break;
			case 'H':
				count[7]++;
				break;
			case 'I':
				count[8]++;
				break;
			case 'J':
				count[9]++;
				break;
			case 'K':
				count[10]++;
				break;
			case 'L':
				count[11]++;
				break;
			case 'M':
				count[12]++;
				break;
			case 'N':
				count[13]++;
				break;
			case 'O':
				count[14]++;
				break;
			case 'P':
				count[15]++;
				break;
			case 'Q':
				count[16]++;
				break;
			case 'R':
				count[17]++;
				break;
			case 'S':
				count[18]++;
				break;
			case 'T':
				count[19]++;
				break;
			case 'U':
				count[20]++;
				break;
			case 'V':
				count[21]++;
				break;
			case 'W':
				count[22]++;
				break;
			case 'X':
				count[23]++;
				break;
			case 'Y':
				count[24]++;
				break;
			case 'Z':
				count[25]++;
				break;
			case ' ':
				count[26]++;
				break;
			case '0':
				count[27]++;
				break;
			case '1':
				count[28]++;
				break;
			case '2':
				count[29]++;
				break;
			case '3':			
				count[30]++;
				break;
			case '4':
				count[31]++;
				break;
			case '5':
				count[32]++;
				break;
			case '6':
				count[33]++;
				break;
			case '7':
				count[34]++;
				break;
			case '8':
				count[35]++;
				break;
			case '9':
				count[36]++;
				break;
			default:							
		}		
	}
	
	//exibe quantos simbolos de cada letra do alfabeto foram encontrados
	printf("Valor absoluto de cada simbolo do modelo:\n");		
	int i=0;		
	while(i!=ALPHABET)
	{
		printf("\nLetter %d: %d",i,count[i]);
		i++;	
	}
	
	//calcula o total de simbolos encontrados
	int j=0;
	int totalSimbolos=0;	
	while(j!=ALPHABET)
	{
		totalSimbolos+=count[j];
		j++;
	}
	
	//exibe a contagem de simbolos por letra e o total absoluto no texto
	printf("\n\nTotal de letras: %d",i);
	printf("\nTotal de simbolos no texto: %d", totalSimbolos);
	
	//calcula a probabilidade de cada simbolo no texto
	int k=0;
	float prob[ALPHABET];	
	while(k!=ALPHABET)
	{
		prob[k]=(float)count[k]/(float)totalSimbolos;
		k++;
	}
	
	//exibe a probabilidade de cada de cada letra do alfabeto no texto 
	printf("\n\nDistribuicao de probabilidade do modelo:\n");
	int l=0;
	float checkSump=0;	
	while(l!=ALPHABET)
	{
		printf("\nLetter %d: %.6f",l,prob[l]);
		checkSump+=prob[l];
		l++;	
	}
	
	//checa se o somatório das probabilidade de cada letra é igual a 1
	printf("\n\nChecksum: %.6f", checkSump);
	
	//faz a ordenacao por Bubble Sort do array de probabilidade
	char letterArr[]=LETTERS;
	int w=0;
	int x=0;
	float floattemp=.0;
	char chartemp;
	while(w!=ALPHABET-1)
	{		
		x=w+1;
		while(x!=ALPHABET)
		{
			if(prob[w]>prob[x])
			{
				//ordena as probabilidades
				floattemp=prob[w];
				prob[w]=prob[x];
				prob[x]=floattemp;
				
				//atualiza o array de letras para que os índices de prob correspondam aos índices de letterArr
				chartemp=letterArr[w];
				letterArr[w]=letterArr[x];
				letterArr[x]=chartemp;
			}
			x++;
		}
		w++;
	}
	
	//exibe a probabilidade de cada de cada letra em ordem crescente 
	printf("\n\nDistribuicao de probabilidade do modelo em ordem crescente:\n");
	int z=0;
	float checkSumpo=.0;	
	while(z!=ALPHABET)
	{
		printf("\nLetter %c: %.6f",letterArr[z],prob[z]);
		checkSumpo+=prob[z];
		z++;	
	}
	
	//checa novamente se o somatório das probabilidade de cada letra é igual a 1
	printf("\n\nChecksum: %.6f", checkSumpo);
	
	fclose(fh);
	exit(0);	
}