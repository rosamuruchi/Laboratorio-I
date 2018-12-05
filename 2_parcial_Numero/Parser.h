#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "numeroNatural.h"

int parser_NumerosFromText(FILE* pFile, LinkedList* listaNumeros);
int parser_NumerosFromBinary(FILE* pFile, LinkedList* pArrayListEmployee);
////
void parserRead(LinkedList* this);

#endif // PARSER_H_INCLUDED
