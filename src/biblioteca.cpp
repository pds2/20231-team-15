#include "../include/biblioteca.h"

Biblioteca::Biblioteca() {}

void Biblioteca::listar_itens() {
    for (auto it = m_biblioteca.begin(); it != m_biblioteca.end(); ++it) {
        it->exibe_musicas();
    }
};

void Biblioteca::inserir_item(const Playlist &item) {
    m_biblioteca.push_back(std::move(item));
};

void Biblioteca::excluir_item(const Playlist &item) {
    for (auto it = m_biblioteca.begin(); it != m_biblioteca.end(); ++it) {
        if (it->get_id() == item.get_id()) {
            m_biblioteca.erase(it);
            break;
        }
    }
};

//void Biblioteca::editar_item(const Playlist &item) {
//
//};