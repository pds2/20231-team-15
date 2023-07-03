#include "../include/ListaMusica.h"

int ListaMusica::_id = 0;

ListaMusica::ListaMusica(int id){
    _id = ++id;
}

int ListaMusica::get_tamanho(){
    return _listamusica.size();
}
void ListaMusica::exibe_musicas(){
    for(Musica x: _listamusica){
        x.imprimirDetalhes();
    }
}