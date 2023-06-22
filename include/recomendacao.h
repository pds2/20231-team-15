#ifndef RECOMENDACAO_H
#define RECOMENDACAO_H

#include <vector>
#include <map>

#include "./musica.h"

class Recomendacao {

  Recomendacao(std::vector<Musica>& musicas);

  // Ordena músicas pela distância em relação à musica do parâmetro.
  std::map<int, float> ordenarMusicas(Musica musica);

  private:
    std::vector<Musica> m_musicas;
};

#endif