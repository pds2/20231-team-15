#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <memory>
#include <vector>

#include "conjunto_listas.h"
#include "playlist.h"

/**
 * @class Biblioteca
 * @brief Representa a biblioteca de playlists.
 * 
 * A classe Biblioteca é derivada da classe Conjunto_listas e contém uma coleção de playlists.
 */
class Biblioteca : public Conjunto_listas {
public:
    /**
     * @brief Construtor da classe Biblioteca.
     */
    Biblioteca();

    /**
     * @brief Lista todos os itens da biblioteca.
     */
    void listar_itens();

    /**
     * @brief Insere um item (playlist) na biblioteca.
     * @param item A playlist a ser inserida.
     */
    void inserir_item(const Playlist &item);

    /**
     * @brief Exclui um item (playlist) da biblioteca com base em seu ID.
     * @param id O ID do item a ser excluído.
     */
    void excluir_item(int id);

    /**
     * @brief Retorna um iterador para o início da biblioteca.
     * @return Um iterador para o início da biblioteca.
     */
    std::vector<Playlist>::iterator begin();

    /**
     * @brief Retorna um iterador para o final da biblioteca.
     * @return Um iterador para o final da biblioteca.
     */
    std::vector<Playlist>::iterator end();

    /**
     * @brief Verifica se a biblioteca está vazia.
     * @return `true` se a biblioteca estiver vazia, caso contrário, retorna `false`.
     */
    bool ta_vazia();

private:
    std::vector<Playlist> m_biblioteca; /**< Coleção de playlists da biblioteca */
};

#endif