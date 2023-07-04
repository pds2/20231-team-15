#include "../include/sistema.h"

Usuario Sistema::login(BancoUsuarios b){
        while (true) {
        std::cout << "Digite o Usuário:" << std::endl;
        std::cin >> user;
        std::cout << "Digite a Senha:" << std::endl;
        std::cin >> senha;

        try {
            if (!b.verificar_usuario(user)) {
                throw usuario_nao_existe_e();
            }
            if (b.verificar_senha(user, senha)) {
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
    Usuario u = Usuario(user, senha);
    return u;
}