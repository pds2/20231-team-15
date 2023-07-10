#ifndef RECOMENDACAO_H
#define RECOMENDACAO_H

#include <vector>
#include <cmath>
#include <utility>

#include "musica.h"

class numero_de_musicas_superior_ao_existente{};

class Recomendacao {
    private:
    std::vector <Musica> m_lista_musicas;
        
    public:
        Recomendacao(std::vector <Musica> lista_musicas);
        auto ordenar_musicas(const Musica &musica);
        std::vector <Musica> recomendar_n_musicas(int numero_de_musicas, const Musica &musica);

};

bool comparar_diferenca_medias(const double & distancia_musica_atual, const double & distancia_musica_seguinte);

#endif