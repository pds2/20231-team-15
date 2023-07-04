#include "../include/album.h"

std::string Album::get_autor(){
    return _artista.get_nome();
}

Album::Album(Artista artista): _artista(artista) {}

void Album::adicionar_musica(Musica m) {
    for (Musica x : _lista_musica){
        if (m.get_id() == x.get_id()){
            throw musica_repetida_album_e();
        }
    }
    _lista_musica.push_back(m);
}
