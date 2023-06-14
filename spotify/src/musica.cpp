#include "../include/musica.h"

// Construtor
Musica::Musica(const std::string& titulo, const std::string& artista, const std::string& album, const std::string& genero, int ano) {
    _titulo = titulo;
    _artista = artista;
    _album = album;
    _genero = genero;
    _ano = ano;
}
 
//Construtor padrão
Musica::Musica() {
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

// Função para imprimir os detalhes da música
void Musica::imprimirDetalhes() const{
    std::cout << "Título: " << _titulo << std::endl;
    std::cout << "Artista: " << _artista << std::endl;
    std::cout << "Álbum: " << _album << std::endl;
    std::cout << "Gênero: " << _genero << std::endl;
    std::cout << "Ano: " << _ano << std::endl;
}

// Função para ler as músicas de um arquivo CSV e armazená-las em um vetor
std::vector<Musica> Musica::lerMusicasDoCSV(const std::string& nomeArquivo) const{
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

        // Lê cada dado da linha
        std::getline(linhaStream, dado, ',');
        std::string titulo = dado;

        std::getline(linhaStream, dado, ',');
        std::string artista = dado;

        std::getline(linhaStream, dado, ',');
        std::string album = dado;

        std::getline(linhaStream, dado, ',');
        std::string genero = dado;

        std::getline(linhaStream, dado, ',');
         int ano = 0;
        try {
            ano = std::stoi(dado);
        } catch (const std::exception& e) {
            std::cout << "Erro ao converter ano: " << e.what() << std::endl;
        }


        // Cria um objeto Musica e o adiciona ao vetor
        Musica musica(titulo, artista, album, genero, ano);
        musicas.push_back(musica);
    }

    return musicas;
}