#ifndef ARTISTA_H
#define ARTISTA_H

#include <iostream>
#include <vector>
#include <string>
 
#include "musica.h"

class Artista {
private:
    std::string _nome;
    std::vector<Musica> artistas_musicas;

public:
    // Construtor
    Artista(const std::string& nome);

    // Construtor default
    Artista() = default;

    // Retorna nome do artista
    std::string get_nome() const;

    // Função para retornar as músicas do artista
    std::vector<Musica> get_artistas_musicas() const;

    // Função para listar as músicas do artista
    void armazenar_musicas(const std::vector<Musica>& musicas) const;

    void imprimir_discografia() const;

    void imprimir_musicas(const std::vector<Musica>& musicas) const;
};



#endif