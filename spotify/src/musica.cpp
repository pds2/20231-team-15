#include "../include/musica.h"

// Construtor
Musica::Musica(int id, const std::string& artista, const std::string& titulo, const std::string& album, 
               const std::string& genero, int ano, double dancabilidade, double sentimento, double 
               barulho, double media) {
    _id = id;
    _artista = artista;
    _titulo = titulo;
    _album = album;
    _genero = genero;
    _ano = ano;
    _dancabilidade = dancabilidade;
    _sentimento = sentimento;
    _barulho = barulho;
    _media = media;
}
 
//Construtor padrão
Musica::Musica() {
}

// Função para retornar o id da música
int Musica::getId() const {
    return _id;
}

std::string Musica::getTitulo() const {
    return _titulo;
}

// Função para retornar o artista da música
std::string Musica::getArtista() const{
    return _artista;
}

// Função para retornar o álbum da música
std::string Musica::getAlbum() const {
    return _album;
}

// Função para retornar o gênero da música
std::string Musica::getGenero() const {
    return _genero;
}

// Função para retornar o ano da música
int Musica::getAno() const {
    return _ano;
}

// Função para retornar a dancabilidade da música   
double Musica::getDancabilidade() const {
    return _dancabilidade;
}

// Função para retornar o sentimento da música
double Musica::getSentimento() const {
    return _sentimento;
}

// Função para retornar o barulho da música
double Musica::getBarulho() const {
    return _barulho;
}

// Função para retornar a média da música
double Musica::getMedia() const {
    return _media;
}

// Função para imprimir os detalhes da música
void Musica::imprimirDetalhes() const{
    std::cout << "Id: " << _id << std::endl;
    std::cout << "Artista: " << _artista << std::endl;
    std::cout << "Título: " << _titulo << std::endl;
    std::cout << "Álbum: " << _album << std::endl;
    std::cout << "Gênero: " << _genero << std::endl;
    std::cout << "Ano: " << _ano << std::endl;
    std::cout << "Dancabilidade: " << _dancabilidade << std::endl;
    std::cout << "Sentimento: " << _sentimento << std::endl;
    std::cout << "Barulho: " << _barulho << std::endl;
    std::cout << "Média: " << _media << std::endl;

}

// Função para ler as músicas de um arquivo CSV e armazená-las em um vetor
std::vector<Musica> Musica::lerMusicasDoCSV(const std::string& nomeArquivo) const {
    std::ifstream arquivo(nomeArquivo);
    std::string linha;
    std::vector<Musica> musicas;

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return musicas;
    }

    // Ignora a primeira linha do arquivo
    std::getline(arquivo, linha);

    // Lê cada linha do arquivo
    while (std::getline(arquivo, linha)) {
        std::stringstream linhaStream(linha);
        std::string dado;

        std::getline(linhaStream, dado, ',');
        int id = 0;
        try {
            id = std::stoi(dado);
        } catch (const std::exception& e) {
            std::cout << "Erro ao converter id: " << e.what() << std::endl;
            continue;  // Pula para a próxima linha
        }

        std::getline(linhaStream, dado, ',');
        std::string artista = dado;

        std::getline(linhaStream, dado, ',');
        std::string titulo = dado;

        std::getline(linhaStream, dado, ',');
        std::string album = dado;

        std::getline(linhaStream, dado, ',');
        std::string genero = dado;

        std::getline(linhaStream, dado, ',');
        int ano = 0;
        if (!dado.empty()) {
            try {
                ano = std::stoi(dado);
            } catch (const std::exception& e) {
                std::cout << "Erro ao converter ano: " << e.what() << std::endl;
                continue;  // Pula para a próxima linha
            }
        }

        std::getline(linhaStream, dado, ',');
        double dancabilidade = 0.0;
        if (!dado.empty()) {
            try {
                dancabilidade = std::stod(dado);
            } catch (const std::exception& e) {
                std::cout << "Erro ao converter dancabilidade: " << e.what() << std::endl;
                continue;  // Pula para a próxima linha
            }
        }

        std::getline(linhaStream, dado, ',');
        double sentimento = 0.0;
        if (!dado.empty()) {
            try {
                sentimento = std::stod(dado);
            } catch (const std::exception& e) {
                std::cout << "Erro ao converter sentimento: " << e.what() << std::endl;
                continue;  // Pula para a próxima linha
            }
        }

        std::getline(linhaStream, dado, ',');
        double barulho = 0.0;
        if (!dado.empty()) {
            try {
                barulho = std::stod(dado);
            } catch (const std::exception& e) {
                std::cout << "Erro ao converter barulho: " << e.what() << std::endl;
                continue;  // Pula para a próxima linha
            }
        }

        std::getline(linhaStream, dado, ',');
        double media = 0.0;
        if (!dado.empty()) {
            try {
                media = std::stod(dado);
            } catch (const std::exception& e) {
                std::cout << "Erro ao converter media: " << e.what() << std::endl;
                continue;  // Pula para a próxima linha
            }
        }

        // Cria um objeto Musica e o adiciona ao vetor
        Musica musica(id, artista, titulo, album, genero, ano, dancabilidade, sentimento, barulho, media);
        musicas.push_back(musica);
    }

    return musicas;
}
