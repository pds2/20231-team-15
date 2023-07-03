#include "../include/Album.h"

std::string Album::get_autor(){
    return _artista.get_nome();
}

Album::Album(Artista artista): _artista(artista) {}

void Album::adicionar_musica(Musica m) {
    for (Musica x : _listamusica){
        if (m.getId() == x.getId()){
            std::cout<< "Música já existente no álbum!" << std::endl;
        }
    }
    _listamusica.push_back(m);
}
