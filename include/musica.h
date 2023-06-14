#ifndef MUSICA_H
#define MUSICA_H

#include <string>
#include <vector>

class Musica {
private:
    std::string artista;
    std::string titulo;
    std::string album;
    std::string genero;
    int dancabilidade;
    int sentimento;
    int barulho;
    int ano;

public:
    // Construtor da classe Musica
    Musica(const std::string& artista, const std::string& titulo, const std::string& album, const std::string& genero,
           int dancabilidade, int sentimento, int barulho, int ano);

    // Construtor padrão da classe Musica
    Musica();       
    
    // Função para imprimir as informações de uma música
    void imprimirMusica() const;

    // Função para carregar as músicas de um arquivo CSV e armazená-las em um vetor
    static std::vector<Musica> carregarMusicas(const std::string& arquivo);

    // Função para imprimir as informações de uma música a partir do seu título
    static void imprimirDetalhesPorTitulo(const std::vector<Musica>& musicas, const std::string& tituloBuscado);


    std::string getArtista() const;
    std::string getTitulo() const;
    std::string getAlbum() const;
    std::string getGenero() const;
    int getDancabilidade() const;
    int getSentimento() const;
    int getBarulho() const;
    int getAno() const;

};

#endif
