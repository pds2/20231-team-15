#include "../include/playlist.h"

Playlist::Playlist(std::string nome, std::string username) : _nome(nome), _username(username){}

Playlist::~Playlist(){}

std::string Playlist::get_nome(){
    return _nome;
}

std::string Playlist::get_usuario(){
    return _username;
}

void Playlist::adicionar_musica(Musica &m) {
    _lista_musica.push_back(std::move(m));
}

 void Playlist::remover_musica(Musica m) {
    auto it = std::find_if(_lista_musica.begin(), _lista_musica.end(), [&](const Musica& x) {
         return x.get_id() == m.get_id();
     });
     if (it != _lista_musica.end()) {
         _lista_musica.erase(it);
     }
 }

void Playlist::trocar_musica (int musica1, int musica2){
    if (musica1< 0 || musica1 >= this->get_tamanho() ||
        musica2 < 0 || musica2 >= this->get_tamanho()) {
        std::cout << "Posições inválidas!" << std::endl;
        return;
    } else {
        Musica aux = _lista_musica[musica1];
        _lista_musica[musica1] = _lista_musica[musica2];
        _lista_musica[musica2] = aux;
    }
}

void Playlist:: mostrar_playlist(){
    if (_lista_musica.empty()){
        std::cout << "Playlist vazia."<< std::endl;
    } else {
        int i = 0;
        for (auto it = _lista_musica.begin(); it != _lista_musica.end(); ++it) {
        std::cout << ++i << "." << it->get_artista() << " - " << it ->get_titulo() << " ID:" << it->get_id() << std::endl;
        }
    }
}

Musica Playlist::get_musica_da_posicao(int pos){
    return _lista_musica[pos];
}

std::vector<Musica>::iterator Playlist::begin(){
    return _lista_musica.begin();
}

std::vector<Musica>::iterator Playlist::end(){
    return _lista_musica.end();
}

void Playlist::erase(std::vector<Musica>::iterator it){
    _lista_musica.erase(it);
}