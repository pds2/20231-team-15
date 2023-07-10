#include "../include/discografia.h"

Discografia::Discografia(const Artista& artista) {
    _artista = artista;
}

void Discografia::listar_itens() {
    int i = 0;
    std::cout << "Artista: " << _artista.get_nome() << std::endl;
    for (auto it = m_discografia.begin(); it != m_discografia.end(); ++it) {
        std::cout << ++i << ". " << it->get_nome() << " ID:" << it->get_id() << std:: endl;
    }
};

void Discografia::inserir_item(const Album &item) {
    m_discografia.push_back(std::move(item));
};