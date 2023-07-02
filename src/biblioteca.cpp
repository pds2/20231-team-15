#include "../include/biblioteca.hpp"

int Biblioteca::contador_id_biblioteca = 0;

Biblioteca::Biblioteca() {
    _id_biblioteca = ++contador_id_biblioteca;
};

int Biblioteca::get_id() const {
    return _id_biblioteca;
};

void Biblioteca::listar_itens() {
    for (int it = 0; it < m_biblioteca.size(); ++it) {
        m_biblioteca[it].printar();
    }
};

void Biblioteca::inserir_item(const ListaMusicas &item) {
    m_biblioteca.push_back(std::move(item));
};

void Biblioteca::excluir_item(const ListaMusicas &item) {
    for (int it = 0; it < m_biblioteca.size(); ++it) {
        if (m_biblioteca[it].get_id_lista_musicas() == item.get_id_lista_musicas()) {
            m_biblioteca.erase(m_biblioteca.begin()+it);
            break;
        }
    }
};

void Biblioteca::editar_item(const ListaMusicas &item) {

};