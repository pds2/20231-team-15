#include "../include/artista.h"
#include "../include/musica.h"

int Artista::contador_id_artista = 0;


// Construtor
Artista::Artista(const std::string& nome) {
    _id_artista = ++contador_id_artista;
    _nome = nome;
}

// Retorna nome do artista
std::string Artista::get_nome() const {
    return _nome;
}

int Artista::get_id() const {
    return _id_artista;
}

// Função para retornar as músicas do artista
std::vector<Musica> Artista::get_artistas_musicas() const { 
    return artistas_musicas;
}
 
// Função para armazenar as músicas do artista
void Artista::armazenar_musicas(const std::vector<Musica>& musicas) const{
    std::vector<Musica> artistasMusicas;
    for (const auto& musica : musicas) {
        if (Musica().get_artista() == _nome) {
            artistasMusicas.push_back(musica);
        }
    }
}

void Artista::imprimir_artista() const {
    std::cout << "Id: " << _id_artista;
    std::cout << "  Nome: " << _nome << std::endl;
}

void Artista::imprimir_discografia() const {
    std::cout << "Discografia de " << _nome << ":" << std::endl;
    for (const auto& musica : Musica().ler_musicas_do_csv("/home/pedroaugtb/codes/vscode/20231-team-15/spotify/musicas.csv")) {
        if (musica.get_artista() == _nome) {
            std::cout << musica.get_titulo() << " - " << musica.get_album() << " (" 
            << musica.get_ano() << ")" << std::endl;
        }
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