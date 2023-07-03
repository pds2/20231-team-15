#include "../include/musica.h"
 
// Construtor
Musica::Musica(int id, const std::string& artista, const std::string& titulo, const std::string& album, 
               const std::string& genero, int ano, int dancabilidade, int sentimento, int 
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
int Musica::getDancabilidade() const {
    return _dancabilidade;
}

// Função para retornar o sentimento da música
int Musica::getSentimento() const {
    return _sentimento;
}

// Função para retornar o barulho da música
int Musica::getBarulho() const {
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
std::vector<Musica> Musica::lerMusicasDoCSV(const std::string& nomeArquivo) {
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
        std::vector<std::string> valores;

        // Divide a linha em valores separados por vírgula
        while (std::getline(linhaStream, dado, ',')) {
            valores.push_back(dado);
        }

        // Verifica se a linha contém a quantidade esperada de valores
        const int NUM_VALORES_ESPERADOS = 10;
        if (valores.size() != NUM_VALORES_ESPERADOS) {
            std::cout << "Erro: linha inválida: " << linha << std::endl;
            continue;  // Pula para a próxima linha
        }

        if(!arquivo.is_open()) {
            throw MusicException("Erro ao abrir o arquivo.");
        }

        // Extrai os valores da linha
        int id;
        try {
            id = std::stoi(valores[0]);
        } catch (const std::invalid_argument& e) {
            throw MusicException("Erro ao converter id: " + std::string(e.what()));
        }

        std::string artista = valores[1];
        std::string titulo = valores[2];
        std::string album = valores[3];
        std::string genero = valores[4];

        int ano; 
        try {
            ano = std::stoi(valores[5]);
        } catch (const std::invalid_argument& e) {
            throw MusicException("Erro ao converter ano: " + std::string(e.what()));
        }

        int dancabilidade;
        try {
            dancabilidade = std::stoi(valores[6]);
        } catch (const std::invalid_argument& e) {
            throw MusicException("Erro ao converter dancabilidade: " + std::string(e.what()));
        }

        int sentimento;
        try {
            sentimento = std::stoi(valores[7]);
        } catch (const std::invalid_argument& e) {
            throw MusicException("Erro ao converter sentimento: " + std::string(e.what()));
        }

        int barulho;
        try {
            barulho = std::stoi(valores[8]);
        } catch (const std::invalid_argument& e) {
            throw MusicException("Erro ao converter barulho: " + std::string(e.what()));
        }

        double media;
        try {
            media = std::stod(valores[9]);
        } catch (const std::invalid_argument& e) {
            throw MusicException("Erro ao converter media: " + std::string(e.what()));
        }

        // Cria um objeto Musica e o adiciona ao vetor
        Musica musica(id, artista, titulo, album, genero, ano, dancabilidade, sentimento, barulho, media);
        musicas.push_back(musica);
    }

    return musicas;
}