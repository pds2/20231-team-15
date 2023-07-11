#include "../include/album.h"

Album::Album(std::string nome, Artista artista): _artista(artista) {
    _nome = nome;
}

std::string Album::get_nome() const {
    return _nome;
}

std::string Album::get_autor() const {
    return _artista.get_nome();
}

Artista Album::get_artista() const {
    return _artista;
}

void Album::adicionar_musica(Musica &m) {
    for (Musica x : _lista_musica){
        if (m.get_id() == x.get_id()){
            throw musica_repetida_album_e();
        }
    }
    _lista_musica.push_back(m);
}

void Album::imprimir_informacoes() {
    std::cout << "Id: " << Lista_musica::get_id();
    std::cout << "  Nome: " << _nome;
    std::cout << "          Artista: " << get_autor() << std::endl;
}

void Album::exibe_musicas() {
    Lista_musica::exibe_musicas();
}