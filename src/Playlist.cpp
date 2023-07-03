#include "../include/Playlist.h"

Playlist::Playlist(std::string nome, Usuario usuario) : _nome(nome), _usuario(usuario){}

std::string Playlist::get_usuario(){
    return _usuario.get_nome();
}

void Playlist::adicionar_musica(Musica m) {
    for (Musica x : _listamusica){
        if (m.getId() == x.getId()){
            std::cout<< "Música já existente na playlist!" << std::endl;
        }
    }
    _listamusica.push_back(m);
}