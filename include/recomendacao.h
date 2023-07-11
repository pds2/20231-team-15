#ifndef RECOMENDACAO_H
#define RECOMENDACAO_H

#include <vector>
#include <cmath>
#include <utility>
#include <random>

#include "musica.h"

/**

    @class numero_de_musicas_superior_ao_existente
    @brief Exceção para o caso em que o número de músicas solicitado para recomendação é superior ao número de músicas existentes.
    */
class numero_de_musicas_superior_ao_existente{};

/**

    @class Recomendacao
    @brief Classe que representa um sistema de recomendação de músicas.
    A classe Recomendacao recebe uma lista de músicas e é capaz de recomendar músicas com base em uma música de referência.
    */
class Recomendacao {
    private:
        std::vector<Musica> m_lista_musicas; /**< Lista de músicas disponíveis para recomendação */

    public:
/**
* @brief Construtor da classe Recomendacao.
* @param lista_musicas A lista de músicas disponíveis para recomendação.
*/
        Recomendacao(std::vector<Musica> lista_musicas);

/**
 * @brief Ordena as músicas com base na diferença média em relação a uma música de referência.
 * @param musica A música de referência para a recomendação.
 * @return Um vetor de pares contendo a diferença média e a música correspondente, ordenados pela diferença média.
 */
        std::vector<std::pair<double, Musica>> ordenar_musicas(const Musica &musica);

/**
 * @brief Recomenda um determinado número de músicas com base em uma música de referência.
 * @param numero_de_musicas O número de músicas a serem recomendadas.
 * @param musica A música de referência para a recomendação.
 * @return Um vetor de músicas recomendadas.
 * @throw numero_de_musicas_superior_ao_existente se o número de músicas solicitado for superior ao número de músicas existentes.
 */

        Recomendacao(std::vector <Musica> lista_musicas);
        std::vector<std::pair<double, Musica>> ordenar_musicas_media(const Musica &musica);
        std::vector<std::pair<double, Musica>> ordenar_musicas_dancabilidade(const Musica &musica);
        std::vector<std::pair<double, Musica>> ordenar_musicas_barulho(const Musica &musica);
        std::vector<std::pair<double, Musica>> ordenar_musicas_ano(const Musica &musica);
        std::vector <Musica> recomendar_n_musicas(int numero_de_musicas, const Musica &musica, std::string parametro);
        Musica recomendar_aleatoria();
};

void ordenar_diferencas(std::vector<std::pair<double, Musica>>& diferencas);
    /*
     * @brief Função de comparação utilizada para ordenar as músicas com base na diferença média.
     * @param distancia_musica_atual A diferença média da música atual.
     * @param distancia_musica_seguinte A diferença média da música seguinte.
     * @return true se a diferença média da música atual for menor que a diferença média da música seguinte, caso contrário, false.
     */
bool comparar_diferenca_medias(const double & distancia_musica_atual, const double & distancia_musica_seguinte);


#endif // RECOMENDACAO_H