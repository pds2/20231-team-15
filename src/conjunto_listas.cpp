#include "../include/conjunto_listas.h"

int Conjunto_listas::contador_id_conjunto_listas = 0;

Conjunto_listas::Conjunto_listas() {
    _id_conjunto_listas = ++contador_id_conjunto_listas;
};

int Conjunto_listas::get_id() const {
    return _id_conjunto_listas;
};