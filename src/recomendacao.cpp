#include "../include/recomendacao.h"
#include <vector>
#include <utility>
#include <map>
#include <cmath>

/*
  TODO
  - Adicionar campos no arquivo csv: id, média
  - Criar comparador para o map
*/

Recomendacao::Recomendacao(std::vector<Musica>& musicas) :
  m_musicas{musicas}
{}

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



std::map<int, float> Recomendacao::ordenarMusicas(Musica musica) {
  // map -> key: id, value: distancia
  std::map<int, float> musicas_ordenadas_distancia;

  for (auto& musica_a_comparar : m_musicas) {
    float distancia = std::abs(musica.media - musica_a_comparar.media);
    musicas_ordenadas_distancia[musica_a_comparar.id] = distancia;
  }

  
}

