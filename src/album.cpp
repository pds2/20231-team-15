#include "../include/album.h"

std::string Album::get_autor(){
    return _artista.get_nome();
}

Album::Album(Artista artista): _artista(artista) {}

void Album::adicionar_musica(Musica m) override{
    for (Musica x : _lista_musica){
        if (m.getId() == x.getId()){
            throw musica_repetida_album_e();
        }
    }
    _lista_musica.push_back(m);
}
