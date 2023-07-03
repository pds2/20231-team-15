#ifndef MUSICA_H
#define MUSICA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
 

class Musica {
private:
    int _id;
    std::string _titulo;    
    std::string _artista;
    std::string _album;
    std::string _genero;
    int _ano;
    int _dancabilidade;
    int _sentimento;
    int _barulho;
    double _media;


public:
    Musica();

    // Construtor
    Musica(int id, const std::string& artista, const std::string& titulo, const std::string& album,
           const std::string& genero, int ano, int dancabilidade, int sentimento, int barulho, double media);

    std::string getTitulo() const;

    std::string getArtista() const;

    std::string getAlbum() const;

    std::string getGenero() const;

    int getAno() const;

    int getId() const;

    int getDancabilidade() const;

    int getSentimento() const;

    int getBarulho() const;

    double getMedia() const;

    // Função para imprimir os detalhes da música
    void imprimir_detalhes() const;

    // Função para ler as músicas de um arquivo CSV e armazená-las em um vetor
    std::vector<Musica> lerMusicasDoCSV(const std::string& nomeArquivo);

};

#endif
