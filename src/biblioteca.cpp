#include "../include/biblioteca.h"

Biblioteca::Biblioteca() {}

void Biblioteca::listar_itens() {
    int i = 0;
    for (auto it = m_biblioteca.begin(); it != m_biblioteca.end(); ++it) {
        std::cout << ++i << ". " << it->get_nome() << " ID:" << it->get_id() << "- "
        << it->get_tamanho() << " músicas" << std::endl;
    }
};

void Biblioteca::inserir_item(Playlist &item) {
    m_biblioteca.push_back(std::move(item));
};

void Biblioteca::excluir_item(int id) {
    for (auto it = m_biblioteca.begin(); it != m_biblioteca.end(); ++it) {
        if (it->get_id() == id) {
            m_biblioteca.erase(it);
            break;
        }
    }
};

std::vector<Playlist>::iterator Biblioteca::begin(){
    return m_biblioteca.begin();
}

std::vector<Playlist>::iterator Biblioteca::end(){
    return m_biblioteca.end();
}

bool Biblioteca::ta_vazia(){
    return m_biblioteca.empty();
}

//void Biblioteca::editar_item(const Playlist &item) {
//
//};