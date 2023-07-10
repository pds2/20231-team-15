#include "../include/discografia.h"

Discografia::Discografia(const Artista& artista) {
    _artista = artista;
}

void Discografia::listar_itens() {
    for (auto it = m_discografia.begin(); it != m_discografia.end(); ++it) {
        it->exibe_musicas();
    }
};

void Discografia::inserir_item(const Album &item) {
    m_discografia.push_back(std::move(item));
};

void Discografia::excluir_item(const Album &item) {
    for (auto it = m_discografia.begin(); it != m_discografia.end(); ++it) {
        if (it->get_id() == item.get_id()) {
            m_discografia.erase(it);
            break;
        }
    }
};