#ifndef ARRLENGTH_H
#define ARRLENGTH_H

typedef struct
{
	float prob1;
	float prob2;
	int ind1;
	int ind2;
} MenoresPesos;

void criaArrLength(float prob[]);
static MenoresPesos calculaMenoresPesos(float prob[]);
static void alocaMenoresPesos(float prob[],int workArray[]);

#endif