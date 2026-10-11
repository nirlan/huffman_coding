#ifndef MODELO_H
#define MODELO_H

//quantidade de letras do alfabeto A = {a1,....an}
#define ALPHABET 33 // {A,B,C,...,X,Z, ,0,1,...9} - não tem K, W, nem Y porque não tem na bíblia!
#define LETTERS {'A','B','C','D','E','F','G','H','I','J','L','M','N','O','P','Q','R','S','T','U','V','X','Z',' ','1','2','3','4','5','6','7','8','9','0'}

void criaModelo(float prob[]);

#endif