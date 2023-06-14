#include <fstream>
#include <sstream>
#include <vector>
#include "../include/musica.h"

// Construtor da classe Musica
Musica::Musica(const std::string& artista, const std::string& titulo, const std::string& album, const std::string& genero,
               int dancabilidade, int sentimento, int barulho, int ano) {
    this->artista = artista;
    this->titulo = titulo;
    this->album = album;
    this->genero = genero;
    this->dancabilidade = dancabilidade;
    this->sentimento = sentimento;
    this->barulho = barulho;
    this->ano = ano;
}

Musica::Musica() {
}

std::string Musica::getArtista() const { return artista; }
std::string Musica::getTitulo() const { return titulo; }
std::string Musica::getAlbum() const { return album; }
std::string Musica::getGenero() const { return genero; }
int Musica::getDancabilidade() const { return dancabilidade; }
int Musica::getSentimento() const { return sentimento; }
int Musica::getBarulho() const { return barulho; }
int Musica::getAno() const { return ano; }

// Função para imprimir as informações de uma música
void Musica::imprimirMusica() const {
    std::cout << "Artista: " << this->artista << std::endl;
    std::cout << "Título: " << this->titulo << std::endl;
    std::cout << "Álbum: " << this->album << std::endl;
    std::cout << "Gênero: " << this->genero << std::endl;
    std::cout << "Dancabilidade: " << this->dancabilidade << std::endl;
    std::cout << "Sentimento: " << this->sentimento << std::endl;
    std::cout << "Barulho: " << this->barulho << std::endl;
    std::cout << "Ano: " << this->ano << std::endl;
}

// Função para carregar as músicas de um arquivo CSV e armazená-las em um vetor
std::vector<Musica> Musica::carregarMusicas(const std::string& nomeArquivo) {
    std::vector<Musica> musicas;
    std::ifstream arquivo(nomeArquivo);

    if (arquivo) {
        std::string linha;

        // Ignorar a primeira linha (cabeçalho)
        std::getline(arquivo, linha);

        while (std::getline(arquivo, linha)) {
            std::istringstream iss(linha);
            std::string artista, titulo, album, genero;
            int dancabilidade, sentimento, barulho, ano;

            if (std::getline(iss, artista, ',') &&
                std::getline(iss, titulo, ',') &&
                std::getline(iss, album, ',') &&
                std::getline(iss, genero, ',') &&
                iss >> dancabilidade &&
                iss.ignore() >> sentimento &&
                iss.ignore() >> barulho &&
                iss.ignore() >> ano) {
                musicas.push_back({artista, titulo, album, genero, dancabilidade, sentimento, barulho, ano});
            }
        }
    }

    return musicas;
}


void Musica::imprimirDetalhesPorTitulo(const std::vector<Musica>& musicas, const std::string& tituloBuscado) {
    bool encontrada = false;
    for (const Musica& musica : musicas) {
        if (musica.titulo == tituloBuscado) {
            encontrada = true;
            std::cout << "Artista: " << musica.artista << std::endl;
            std::cout << "Título: " << musica.titulo << std::endl;
            std::cout << "Álbum: " << musica.album << std::endl;
            std::cout << "Gênero: " << musica.genero << std::endl;
            std::cout << "Dancabilidade: " << musica.dancabilidade << std::endl;
            std::cout << "Sentimento: " << musica.sentimento << std::endl;
            std::cout << "Barulho: " << musica.barulho << std::endl;
            std::cout << "Ano: " << musica.ano << std::endl;
            std::cout << std::endl;
            break;
        }
    }

    if (!encontrada) {
        std::cout << "Música não encontrada." << std::endl;
    }
}

// Path: spotify/src/artista.cpp