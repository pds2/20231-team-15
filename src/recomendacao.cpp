#include "../include/recomendacao.h"

Recomendacao::Recomendacao(std::vector<Musica> lista_musicas) {
    m_lista_musicas = lista_musicas;
};

void ordenar_diferencas(std::vector<std::pair<double, Musica>>& diferencas) {
    std::sort(diferencas.begin(), diferencas.end(),
        [](const auto& a, const auto& b) {
            return a.first < b.first;
    });
}

bool comparar_diferenca_medias(const double & distancia_musica_atual, const double & distancia_musica_seguinte) {
    return distancia_musica_atual < distancia_musica_seguinte;
};

std::vector <Musica> Recomendacao::recomendar_n_musicas(int numero_de_musicas, const Musica &musica, std::string parametro) {
    if (numero_de_musicas > m_lista_musicas.size()) {
        throw numero_de_musicas_superior_ao_existente();
    }

    std::vector<std::pair<double, Musica>> ordenadas;

    if (parametro == "media") {
        ordenadas = ordenar_musicas_media(musica);
    } else if (parametro == "dancabilidade") {
        ordenadas = ordenar_musicas_dancabilidade(musica);
    } else if (parametro == "barulho") {
        ordenadas = ordenar_musicas_barulho(musica);
    } else if (parametro == "ano") {
        ordenadas = ordenar_musicas_ano(musica);
    }
    
    std::vector <Musica> n_recomendadas;
    for (int i = 0; i < numero_de_musicas; i++) {
        n_recomendadas.push_back(ordenadas[i].second);
    }
    return n_recomendadas;
}

std::vector<std::pair<double, Musica>> Recomendacao::ordenar_musicas_media(const Musica &musica) {

    std::vector<std::pair<double, Musica>> diferencas;

    for (const Musica& musica_a_comparar : m_lista_musicas) {

        if (musica_a_comparar.get_id() == musica.get_id()) {
            continue;
        }

        double diferenca = std::abs(musica.get_media() - musica_a_comparar.get_media());
        diferencas.push_back(std::make_pair(diferenca, musica_a_comparar));

        if (diferencas.size() > 1) {
            ordenar_diferencas(diferencas);
        }
    }

    return diferencas;
};

std::vector<std::pair<double, Musica>> Recomendacao::ordenar_musicas_dancabilidade(const Musica &musica) {

    std::vector<std::pair<double, Musica>> diferencas;

    for (const Musica& musica_a_comparar : m_lista_musicas) {

        if (musica_a_comparar.get_id() == musica.get_id()) {
            continue;
        }

        double diferenca = std::abs(musica.get_dancabilidade() - musica_a_comparar.get_dancabilidade());
        diferencas.push_back(std::make_pair(diferenca, musica_a_comparar));

        if (diferencas.size() > 1) {
            ordenar_diferencas(diferencas);
        }
    }
    return diferencas;
}

std::vector<std::pair<double, Musica>> Recomendacao::ordenar_musicas_barulho(const Musica &musica) {

    std::vector<std::pair<double, Musica>> diferencas;

    for (const Musica& musica_a_comparar : m_lista_musicas) {

        if (musica_a_comparar.get_id() == musica.get_id()) {
            continue;
        }

        double diferenca = std::abs(musica.get_barulho() - musica_a_comparar.get_barulho());
        diferencas.push_back(std::make_pair(diferenca, musica_a_comparar));

        if (diferencas.size() > 1) {
            ordenar_diferencas(diferencas);
        }
    }
    return diferencas;
}

std::vector<std::pair<double, Musica>> Recomendacao::ordenar_musicas_ano(const Musica &musica) {

    std::vector<std::pair<double, Musica>> diferencas;

    for (const Musica& musica_a_comparar : m_lista_musicas) {

        if (musica_a_comparar.get_id() == musica.get_id()) {
            continue;
        }

        double diferenca = std::abs(musica.get_ano() - musica_a_comparar.get_ano());
        diferencas.push_back(std::make_pair(diferenca, musica_a_comparar));

        if (diferencas.size() > 1) {
            ordenar_diferencas(diferencas);
        }
    }
    return diferencas;
}

Musica Recomendacao::recomendar_aleatoria() {
    std::srand(std::time(nullptr)); // Inicializa a semente randômica com base no tempo atual

    int indice_aleatorio = std::rand() % m_lista_musicas.size(); // Gera um índice aleatório dentro do tamanho da lista de músicas
    return m_lista_musicas[indice_aleatorio];
}
