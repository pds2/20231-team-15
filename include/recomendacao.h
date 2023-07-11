#ifndef RECOMENDACAO_H
#define RECOMENDACAO_H

#include <vector>
#include <cmath>
#include <utility>
#include <random>

#include "musica.h"

class numero_de_musicas_superior_ao_existente{};

class Recomendacao {
    private:
    std::vector <Musica> m_lista_musicas;
        
    public:
        Recomendacao(std::vector <Musica> lista_musicas);
        std::vector<std::pair<double, Musica>> ordenar_musicas_media(const Musica &musica);
        std::vector<std::pair<double, Musica>> ordenar_musicas_dancabilidade(const Musica &musica);
        std::vector<std::pair<double, Musica>> ordenar_musicas_barulho(const Musica &musica);
        std::vector<std::pair<double, Musica>> ordenar_musicas_ano(const Musica &musica);
        std::vector <Musica> recomendar_n_musicas(int numero_de_musicas, const Musica &musica, std::string parametro);
        Musica recomendar_aleatoria();
};

void ordenar_diferencas(std::vector<std::pair<double, Musica>>& diferencas);
bool comparar_diferenca_medias(const double & distancia_musica_atual, const double & distancia_musica_seguinte);

#endif