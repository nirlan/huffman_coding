#include <stdio.h>
#include <stdlib.h>
#include "modelo.h"
#include "arrlength.h"

int main() {
	float prob[ALPHABET];
	criaModelo(prob);	
	criaArrLength(prob);
	exit(0);	
}