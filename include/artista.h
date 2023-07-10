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
    std::vector<Musica> artistas_musicas;

public:
    // Construtor
    Artista(const std::string& nome);

    // Construtor default
    Artista();

    // Retorna nome do artista
    std::string get_nome() const;
    
    int get_id() const;

    // Função para retornar as músicas do artista
    std::vector<Musica> get_artistas_musicas() const;

    // Função para listar as músicas do artista
    void armazenar_musicas(const std::vector<Musica>& musicas);

    void imprimir_artista() const;

    void imprimir_discografia() const;

    void imprimir_musicas(const std::vector<Musica>& musicas) const;
};



#endif