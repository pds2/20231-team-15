#include "../include/recomendacao.h"

Recomendacao::Recomendacao(std::vector<Musica> lista_musicas) {
    m_lista_musicas = lista_musicas;
};

std::vector<std::pair<double, Musica>> Recomendacao::ordenar_musicas(const Musica &musica) {

    std::vector<std::pair<double, Musica>> diferencas;

    for (Musica musica_a_comparar : m_lista_musicas) {

        if (musica_a_comparar.get_id() == musica.get_id()) {
            continue;
        }

        double diferenca = std::abs(musica.get_media() - musica_a_comparar.get_media());
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

std::vector <Musica> Recomendacao::recomendar_n_musicas(int numero_de_musicas, const Musica &musica) {

    if (numero_de_musicas > m_lista_musicas.size()) {
        throw numero_de_musicas_superior_ao_existente();
    }

    auto ordenadas = ordenar_musicas(musica);
    std::vector <Musica> n_recomendadas;
    for (int i = 0; i < numero_de_musicas; i++) {
        n_recomendadas.push_back(ordenadas[i].second);
    }

    return n_recomendadas;
}