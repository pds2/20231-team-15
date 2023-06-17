#include <iostream>

// #include "../include/biblioteca.hpp"
#include "biblioteca.cpp"

int main() {

    Biblioteca biblioteca1;
    Biblioteca biblioteca2;

    int id1 = biblioteca1.get_id();
    int id2 = biblioteca2.get_id();

    std::cout << id1 << std::endl;
    std::cout << id2 << std::endl;

    return 0;
}