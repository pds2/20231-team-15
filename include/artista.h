#ifndef ARTISTA_H
#define ARTISTA_H

#include <iostream>
#include <vector>
#include <string>
 
#include "musica.h"

class Artista {
private:
    static int contador_id_artista;
    int _id_artista;
    std::string _nome;

public:
    // Construtor
    Artista(const std::string& nome);

    // Construtor default
    Artista() = default;

    // Retorna nome do artista
    std::string get_nome() const;
    
    int get_id() const;

    // Função para listar as músicas do artista
    void armazenar_musicas(const std::vector<Musica>& musicas) const;

    void imprimir_artista() const;

    void imprimir_discografia() const;
};


#endif