#include "../include/lista_musica.h"

int Lista_musica::_id = 0;

Lista_musica::Lista_musica() {
    id = _id++;
}

Lista_musica::Lista_musica(const std::string& caminho_csv) {
    std::ifstream arquivo("musicas.csv");  // Abre o arquivo CSV

    if (arquivo.is_open()) {
        std::string linha;
        bool primeira_linha = true;  // Para ignorar o cabeçalho

        while (std::getline(arquivo, linha)) {
            if (primeira_linha) {
                primeira_linha = false;
                continue;  // Ignora o cabeçalho
            }

            std::stringstream ss(linha);
            std::string coluna;

            // Separa as colunas usando vírgula como delimitador
            std::vector<std::string> colunas;
            while (std::getline(ss, coluna, ',')) {
                colunas.push_back(coluna);
            }

            if (colunas.size() >= 10) {
                // Obtém as informações da música a partir das colunas
                int id = std::stoi(colunas[0]);
                std::string artista = colunas[1];
                std::string titulo = colunas[2];
                std::string album = colunas[3];
                std::string genero = colunas[4];
                int ano = std::stoi(colunas[5]);
                double dancabilidade = std::stod(colunas[6]);
                double sentimento = std::stod(colunas[7]);
                double barulho = std::stod(colunas[8]);
                double media = std::stod(colunas[9]);

                // Cria um objeto Musica com as informações obtidas
                Musica musica(id, artista, titulo, album, genero, ano, dancabilidade, sentimento, barulho, media);

                // Adiciona a música à lista
                _lista_musica.push_back(musica);
            }
        }

        arquivo.close();  // Fecha o arquivo
    }
}

int Lista_musica::get_id() const {
    return id;
}

int Lista_musica::get_tamanho(){
    return _lista_musica.size();
}

void Lista_musica::exibe_musicas(){
    for(Musica x: _lista_musica){
        x.imprimir_detalhes();
    }
}