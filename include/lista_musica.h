#ifndef LISTAMUSICA_H
#define LISTAMUSICA_H

#include <vector>

#include "musica.h"

/**

    @class Lista_musica

    @brief Classe abstrata que representa uma lista de músicas.

    A classe Lista_musica serve como uma base para implementação de classes de listas de músicas específicas.
**/
    class Lista_musica{
    private:
    static int _id; // Contador de IDs das listas de músicas 
    int id; // ID da lista de músicas 
    public:
    /*
        @brief Construtor da classe Lista_musica.
    */
        Lista_musica();

    /**
        @brief Construtor da classe Lista_musica que carrega as músicas a partir de um arquivo CSV.
        @param caminho_csv O caminho para o arquivo CSV contendo as músicas.
        */
        Lista_musica(const std::string& caminho_csv);

    /**
        @brief Retorna o tamanho da lista de músicas.
        @return O tamanho da lista de músicas.
        */
        int get_tamanho();

    /**
        @brief Exibe as músicas da lista.
        */
        void exibe_musicas();

    /**
        @brief Função puramente virtual para adicionar uma música à lista.
        @param musica A música a ser adicionada.
        */
        virtual void adicionar_musica(Musica musica) = 0;

    /**
        @brief Retorna o ID da lista de músicas.
        @return O ID da lista de músicas.
        */
        int get_id() const;

    protected:
        std::vector<Musica> _lista_musica; /**< Vetor contendo as músicas da lista */

};

#endif // LISTAMUSICA_H