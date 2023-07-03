#ifndef RECOMENDACAO_H
#define RECOMENDACAO_H

#include <vector>
#include <cmath>
#include <utility>

#include "musica.h"

class Recomendacao {
    private:
    std::vector <Musica> m_listaMusicas;
        
    public:
        Recomendacao(std::vector <Musica> listaMusica);
        auto recomendar_musicas(const Musica &musica);

};

bool comparar_diferenca_medias(const double & distancia_musica_atual, const double & distancia_musica_seguinte);

#endif