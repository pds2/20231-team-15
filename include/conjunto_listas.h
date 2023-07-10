#ifndef CONJUNTO_LISTAS_H
#define CONJUNTO_LISTAS_H

#include <memory>
#include <vector>

/*
    @class Conjunto_listas

    @brief Classe abstrata que representa um conjunto de listas.
    A classe Conjunto_listas serve como uma base para implementação de classes de conjuntos de listas específicas.
*/

class Conjunto_listas {
    public:
/*
        @brief Construtor da classe Conjunto_listas.
*/
        Conjunto_listas();

    /**
        @brief Retorna o ID do conjunto de listas.
        @return O ID do conjunto de listas.
        */
        int get_id() const;

    /**
        @brief Função puramente virtual para listar os itens do conjunto de listas.
        */
        virtual void listar_itens() = 0;

    private:
        static int contador_id_conjunto_listas; // Contador de IDs dos conjuntos de listas */
        int _id_conjunto_listas; // ID do conjunto de listas */
};

#endif // CONJUNTO_LISTAS_H