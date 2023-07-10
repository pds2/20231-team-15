#include "../include/banco_usuarios.h"

BancoUsuarios::BancoUsuarios(std::string endereco):
_endereco_arquivo(endereco)
{}
              
bool BancoUsuarios::verificar_usuario(const std::string& nome) {
    std::ifstream arquivo(_endereco_arquivo);
    std::string linha;

    if (arquivo.is_open()) {
        while (std::getline(arquivo, linha)) {
            std::istringstream iss(linha);
            std::string usuario, senha;
            std::getline(iss, usuario, ',');
            if (usuario == nome) {
                arquivo.close();
                return true;
            }
        }
        arquivo.close();
    } else {
        throw arquivo_nao_encontrado_e();
    }

    return false;
}

bool BancoUsuarios::verificar_senha(const std::string& nome, const std::string& senha) {
    std::ifstream arquivo(_endereco_arquivo);
    std::string linha;

    if (arquivo.is_open()) {
        while (std::getline(arquivo, linha)) {
            std::istringstream iss(linha);
            std::string usuario, senha_armazenada;
            std::getline(iss, usuario, ',');
            std::getline(iss, senha_armazenada);
            if (usuario == nome) {
                if (senha == senha_armazenada) {
                    arquivo.close();
                    return true;
                } else {
                    throw senha_incorreta_e();
                    arquivo.close();
                    return false;
                }
            }
        }
        arquivo.close();
    } else {
        throw arquivo_nao_encontrado_e();
    }

    throw usuario_nao_existe_e();
    return false;
}

void BancoUsuarios::adicionar_usuario(const std::string& nome, const std::string& senha) {
    std::ofstream arquivo(_endereco_arquivo);

    if (arquivo.is_open()) {
        arquivo << nome << ',' << senha << '\n';
        arquivo.close();
    } else {
        throw arquivo_nao_encontrado_e();
    }

}