#include "../include/recomendacao.h"

Recomendacao::Recomendacao(std::vector<Musica> listaMusicas) {
    m_listaMusicas = listaMusicas;
};

// Musica Recomendacao::retornarSemelhante(const Musica musica) {
//   Musica semelhante = m_musicas[0];
//   int distancia_semelhante = std::abs(musica.media - semelhante.media);

//   for (const auto& musica_a_comparar : m_musicas) {
//     if (musica_a_comparar.id == musica.id) {
//       continue;
//     }
    
//     int distancia = std::abs(musica.media - musica_a_comparar.media);

//     if (distancia < distancia_semelhante) {
//       semelhante = musica_a_comparar;
//       distancia_semelhante = distancia;
//     }
//   }

//   return semelhante;
// }

// std::map<int, float> Recomendacao::ordenarMusicas(Musica musica) {
//   // map -> key: id, value: distancia
//   std::map<int, float> musicas_ordenadas_distancia;

//   for (auto& musica_a_comparar : m_musicas) {
//     float distancia = std::abs(musica.media - musica_a_comparar.media);
//     musicas_ordenadas_distancia[musica_a_comparar.id] = distancia;
//   }

  
// }

auto Recomendacao::recomendar_musicas(const Musica &musica) {

    std::vector<std::pair<double, Musica>> diferencas;

    for (Musica musica_a_comparar : m_listaMusicas) {

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