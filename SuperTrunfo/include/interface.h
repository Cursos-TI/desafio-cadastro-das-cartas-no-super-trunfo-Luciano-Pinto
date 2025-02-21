//
// Created by lucianopinto on 21/02/25.
//

#ifndef INTERFACE_H
#define INTERFACE_H

#include "dynamic_array.h"

#define TRUE 1
#define FALSE 0

void clearBuffer();

void exibirMenuInicialEObterOpcao(DynamicArray *array);

void exibirIndiceDeCartas(const DynamicArray *array);

#endif //INTERFACE_H
