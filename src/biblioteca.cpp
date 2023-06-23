#include "../include/biblioteca.hpp"

int Biblioteca::contador_id_biblioteca = 0;

Biblioteca::Biblioteca(std::vector<ListaMusicas> v_biblioteca) {
    _id_biblioteca = ++contador_id_biblioteca;
};

int Biblioteca::get_id() const {
    return _id_biblioteca;
};

void listar_itens() {

};

void Biblioteca::inserir_item(std::unique_ptr<ListaMusicas> item) {
    _v_biblioteca.push_back(std::move(item));
};

void Biblioteca::excluir_item(std::unique_ptr<ListaMusicas> item) {
    for (auto it = 0; it != _v_biblioteca.end(); ++it) {
        if (_v_biblioteca[it] == item) {
            _v_biblioteca.erase(it); 
        }
    }
    
};

void editar_item(std::unique_ptr<ListaMusicas> item) {

};