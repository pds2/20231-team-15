#include "../include/musica.h"

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
    is_liked = false;
}

Musica::Musica() {
    _id == 0;
}

void Musica::set_is_liked(bool is_liked) {
    this->is_liked = is_liked;
}

// Função para retornar o id da música
int Musica::get_id() const {
    return _id;
}

std::string Musica::get_titulo() const {
    return _titulo;
}

std::string Musica::get_artista() const{
    return _artista;
}

std::string Musica::get_album() const {
    return _album;
}

std::string Musica::get_genero() const {
    return _genero;
}

int Musica::get_ano() const {
    return _ano;
}

int Musica::get_dancabilidade() const {
    return _dancabilidade;
}

int Musica::get_sentimento() const {
    return _sentimento;
}

int Musica::get_barulho() const {
    return _barulho;
}

double Musica::get_media() const {
    return _media;
}

bool Musica::get_is_liked() const {
    return is_liked;
}

// Função get musica
Musica Musica::get_musica() const {
    return *this;
}

void Musica::imprimir_todas_musicas(std::vector<Musica> lista_musicas) const {
    for (auto i = lista_musicas.begin(); i < lista_musicas.end(); i++) {
        i->imprimir_detalhes();
    }
}

void Musica::musica_repetida(std::vector<Musica> lista_musicas) const {
    bool encontrou_repeticao = false;
    for (auto i = lista_musicas.begin(); i < lista_musicas.end(); i++) {
        for (auto j = i + 1; j < lista_musicas.end(); j++) {
            if (i->get_titulo() == j->get_titulo()) {
                std::cout << "Música repetida: " << i->get_titulo() << std::endl;
                encontrou_repeticao = true;
            }
        }
    }
}

void Musica::imprimir_detalhes() const{
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

std::vector<Musica> Musica::ler_musicas_do_csv(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    std::string linha;
    std::vector<Musica> musicas;

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return musicas;
    }

    std::getline(arquivo, linha);

    while (std::getline(arquivo, linha)) {
        std::stringstream linhaStream(linha);
        std::string dado;
        std::vector<std::string> valores;

        while (std::getline(linhaStream, dado, ',')) {
            valores.push_back(dado);
        }

        const int NUM_VALORES_ESPERADOS = 10;
        if (valores.size() != NUM_VALORES_ESPERADOS) {
            std::cout << "Erro: linha inválida: " << linha << std::endl;
            continue;
        }

        int id;
        try {
            id = std::stoi(valores[0]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro ao converter id: " << e.what() << std::endl;
            continue;
        }

        std::string artista = valores[1];
        std::string titulo = valores[2];
        std::string album = valores[3];
        std::string genero = valores[4];

        int ano;
        try {
            ano = std::stoi(valores[5]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro ao converter ano: " << e.what() << std::endl;
            continue;
        }

        int dancabilidade;
        try {
            dancabilidade = std::stoi(valores[6]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro ao converter dancabilidade: " << e.what() << std::endl;
            continue;
        }

        int sentimento;
        try {
            sentimento = std::stoi(valores[7]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro ao converter sentimento: " << e.what() << std::endl;
            continue;
        }

        int barulho;
        try {
            barulho = std::stoi(valores[8]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro ao converter barulho: " << e.what() << std::endl;
            continue;
        }

        double media;
        try {
            media = std::stod(valores[9]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro ao converter media: " << e.what() << std::endl;
            continue;
        }

        Musica musica(id, artista, titulo, album, genero, ano, dancabilidade, sentimento, barulho, media);
        musicas.push_back(musica);
    }
    return musicas;
}

void Musica::imprimir_id_musica_artista() {
    std::cout << "Id: " << _id;
    std::cout << "  Artista: " << _artista;
    std::cout << "          Titulo: " << _titulo << std::endl;
}