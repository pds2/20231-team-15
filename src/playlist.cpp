#include "../include/playlist.h"

Playlist::Playlist(std::string nome, Usuario usuario) : _nome(nome), _usuario(usuario){}

std::string Playlist::get_usuario(){
    return _usuario.get_nome();
}

void Playlist::adicionar_musica(Musica m) {
    for (Musica x : _lista_musica){
        if (m.getId() == x.getId()){
            throw musica_repetida_playlist_e();
        }
    }
    _lista_musica.push_back(m);
}