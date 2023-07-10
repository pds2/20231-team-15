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

    std::string get_titulo() const;

    std::string get_artista() const;

    std::string get_album() const;

    std::string get_genero() const;

    int get_ano() const;

    int get_id() const;

    int get_dancabilidade() const;

    int get_sentimento() const;

    int get_barulho() const;

    double get_media() const;

    // Função get musica
    //Musica get_musica() const;

    // Função para imprimir os detalhes da música
    void imprimir_detalhes() const;

    void imprimir_todas_musicas(std::vector<Musica>) const;

    void musica_repetida(std::vector<Musica>) const;

    // Função para ler as músicas de um arquivo CSV e armazená-las em um vetor
    std::vector<Musica> ler_musicas_do_csv(const std::string& nomeArquivo);

    void imprimir_id_musica_artista();

};

#endif
