#include "../include/lista_musica.h"

int Lista_musica::_id = 0;

Lista_musica::Lista_musica() {
    id = ++_id;    
}

Lista_musica::get_id() {
    return id;
}

int Lista_musica::get_tamanho(){
    return _lista_musica.size();
}
void Lista_musica::exibe_musicas(){
    for(Musica x: _lista_musica){
        x.imprimir_detalhes();
    }
}