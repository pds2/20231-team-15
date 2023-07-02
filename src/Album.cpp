#include "../include/Album.h"

std::string Album::get_autor(){
    return _artista.getNome();
}

Album::Album(Artista artista): _artista(artista) {}

void Album::adicionar_musica(Musica m) override{
    for (Musica x : _listamusica){
        if (m == x){
            std::cout<< "Música já existente no álbum!" << std::endl
        }
    }
    _listamusica.push_back(m);
}
