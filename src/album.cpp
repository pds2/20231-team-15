#include "../include/Album.h"

std::string Album::get_autor(){
    return _artista.get_nome();
}

Album::Album(Artista artista): _artista(artista) {}

void Album::adicionar_musica(Musica m) {
    for (Musica x : _lista_musica){
        if (m == x){
            std::cout<< "Música já existente no álbum!" << std::endl
        }
    }
    _lista_musica.push_back(m);
}
