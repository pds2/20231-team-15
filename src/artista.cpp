#include "../include/artista.h"

int Artista::contador_id_artista = 0;

Artista::Artista(const std::string& nome) {
    _id_artista = ++contador_id_artista;
    _nome = nome;
}

Artista::Artista() {
    _id_artista = ++contador_id_artista;
}

std::string Artista::get_nome() const {
    return _nome;
}

int Artista::get_id() const {
    return _id_artista;
}

std::vector<Musica> Artista::get_artistas_musicas() const { 
    return artistas_musicas;
}

void Artista::armazenar_musicas(const std::vector<Musica>& musicas) {
    for (const auto& musica : musicas) {
        if (musica.get_artista() == _nome) {
            artistas_musicas.push_back(musica);
        }
    }
}

void Artista::imprimir_artista() const {
    std::cout << "Id: " << _id_artista;
    std::cout << "  Nome: " << _nome << std::endl;
}

void Artista::imprimir_discografia() const {
    std::cout << "Discografia de " << _nome << ":" << std::endl;
    for (const auto& musica : artistas_musicas) {
        std::cout << musica.get_titulo() << " - " << musica.get_album() << " (" 
            << musica.get_ano() << ")" << std::endl;
    }
}

void Artista::imprimir_musicas(const std::vector<Musica>& musicas) const {
    std::cout << "Músicas de " << _nome << ":" << std::endl;
    for (const auto& musica : musicas) {
        if (musica.get_artista() == _nome) {
            std::cout << musica.get_titulo() << " - " << musica.get_album() << " (" 
            << musica.get_ano() << ")" << std::endl;
        }
    }
}