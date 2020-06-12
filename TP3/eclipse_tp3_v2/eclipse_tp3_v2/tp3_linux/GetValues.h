#ifndef GETVALUES_H_
#define GETVALUES_H_

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

void inputArray (char* arrayChar,int longitudMaxima, char* mensajeIngreso);
void quitarSaltosArray(char* arrayChar);
int inputInt(char* mensajeIngreso, int* number);
int inputPositiveInt(char* mensajeIngreso, int* number);
void arrayToLower(char* arrayChar);
void upperFirstLetters(char* arrayChar);
void pausa(char* mensaje);
int msjConfirm(char* mensaje);

#endif /* GETVALUES_H_ */
