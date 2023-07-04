#include "../include/biblioteca.h"

int Biblioteca::contador_id_biblioteca = 0;

Biblioteca::Biblioteca() {
    _id_biblioteca = ++contador_id_biblioteca;
};

int Biblioteca::get_id() const {
    return _id_biblioteca;
};

void Biblioteca::listar_itens() {
    for (int it = 0; it < m_biblioteca.size(); ++it) {
        m_biblioteca[it].exibe_musicas();
    }
};

void Biblioteca::inserir_item(const Lista_musica &item) {
    m_biblioteca.push_back(std::move(item));
};

void Biblioteca::excluir_item(const Lista_musica &item) {
    for (int it = 0; it < m_biblioteca.size(); ++it) {
        if (m_biblioteca[it].get_id() == item.get_id()) {
            m_biblioteca.erase(m_biblioteca.begin()+it);
            break;
        }
    }
};

void Biblioteca::editar_item(const Lista_musica &item) {

};