#include "../include/recomendacao.h"

Recomendacao::Recomendacao(std::vector<Musica> lista_musicas) {
    m_lista_musicas = lista_musicas;
};

auto Recomendacao::recomendar_musicas(const Musica &musica) {

    std::vector<std::pair<double, Musica>> diferencas;

    for (Musica musica_a_comparar : m_lista_musicas) {

        if (musica_a_comparar.getId() == musica.getId()) {
            continue;
        }

        double diferenca = std::abs(musica.getMedia() - musica_a_comparar.getMedia());
        diferencas.push_back(std::make_pair(diferenca, musica_a_comparar));

        if (diferencas.size() > 1) {

            int n = diferencas.size();
            for (int i = 0; i < n-1; ++i) {
                for (int j = 0; j < n-i-1; ++j) {
                    if (comparar_diferenca_medias(diferencas[j+1].first, diferencas[j].first)) {
                        std::swap(diferencas[j], diferencas[j+1]);
                    }
                }
            }
        }
    }

    return diferencas;
};

bool comparar_diferenca_medias(const double & distancia_musica_atual, const double & distancia_musica_seguinte) {
    return distancia_musica_atual < distancia_musica_seguinte;
};