#include "../include/sistema.h"
#include <iostream>

Usuario Sistema::login(BancoUsuarios b){
        std::string username;
        std::string senha;

        while (true) {
        std::cout << "Digite o Usuário:" << std::endl;
        std::cin >> username;
        std::cout << "Digite a Senha:" << std::endl;
        std::cin >> senha;

        try {
            if (!b.verificar_usuario(username)) {
                throw usuario_nao_existe_e();
            }
            if (b.verificar_senha(username, senha)) {
                std::cout << "Welcome!!" << std::endl;
                break;
            } else {
                throw senha_incorreta_e();
            }
        } catch (usuario_nao_existe_e &u) {
            std::cout << "Usuário não existe. Digite novamente." << std::endl;
        } catch (senha_incorreta_e &s) {
            std::cout << "Senha incorreta. Digite novamente." << std::endl;
        }
    }
    Usuario u = Usuario(username, senha);
    return u;
}