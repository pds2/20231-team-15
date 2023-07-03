#ifndef ARTISTA_H
#define ARTISTA_H

#include "musica.h"

#include <iostream>
#include <vector>
#include <string>
 
class Artista {
private:
    std::string _nome;

public:
    // Construtor
    Artista(const std::string& nome);

    // Construtor default
    Artista() = default;

    // Retorna nome do artista
    std::string get_nome() const;

    // Função para listar as músicas do artista
    void armazenarMusicas(const std::vector<Musica>& musicas) const;

    void imprimirDiscografia() const;
};


#endif