#ifndef MUSICA_H
#define MUSICA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
 

//teste

class Musica {
private:
    std::string _titulo;    
    std::string _artista;
    std::string _album;
    std::string _genero;
    int _ano;

public:
    Musica();

    // Construtor
    Musica(const std::string& titulo, const std::string& artista, const std::string& album,
           const std::string& genero, int ano);

    std::string getTitulo() const;

    std::string getArtista() const;

    std::string getAlbum() const;

    std::string getGenero() const;

    int getAno() const;

    // Função para imprimir os detalhes da música
    void imprimirDetalhes() const;

    // Função para ler as músicas de um arquivo CSV e armazená-las em um vetor
    std::vector<Musica> lerMusicasDoCSV(const std::string& nomeArquivo) const;

};

#endif
