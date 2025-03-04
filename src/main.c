//
// Created by lucianopinto on 20/02/25.
//

#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include "super_trunfo.h"
#include "dynamic_array.h"

int main(void) {

    const int INITIAL_CAPACITY = 2;

    // Cria o array dinâmico que conterá as cartas.
    DynamicArray *cartasArray = create_array(sizeof(CartaSuperTrunfo), INITIAL_CAPACITY);

    // Menu de controle da aplicação.
    exibir_menu_inicial_e_obter_opcao(cartasArray);


}
