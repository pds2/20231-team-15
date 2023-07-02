#include "../include/ListaMusica.h"

int ListaMusica::get_tamanho(){
    return _listamusica.size();
}
void ListaMusica::exibe_musicas(){
    for(Musica x: _listamusica){
        x.imprimirMusica();
    }
}