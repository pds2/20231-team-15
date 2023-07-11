
# Sistema de Gerenciamento de Playlists e Recomendação de Músicas

Este projeto foi efetuado para a disciplina de Programação e Desenvolvimento de Software II. Ele consiste em um sistema de gerenciamento de músicas que permite aos usuários criar e editar suas playlists, interagir com músicas, álbuns e artistas presentes no sistema, além de receber recomendações personalizadas.

link do git: https://github.com/pds2/20231-team-15

### Alunos

* Igor Rocha Santos                         2022037574
* Lucas Dayrell de Andrade Machado          2020035329
* Pedro Augusto Torres Bento                2022104352
* Victoria Estanislau Ramos de Oliveira     2021037490


### User Stories

1. **Como** usuário, **desejo** poder visualizar as músicas, álbuns e artistas disponíveis no sistema **para** explorar algo novo.

2. **Como** usuário, **gostaria** de poder visualizar as discografia de um artistas, **para** conhecer melhor seu trabalho.

3. **Como** usuário, **desejo** poder editar minha playlist **para** adicionar e ordenar as músicas de acordo com minha preferência.

4. **Como** usuário, **quero** navegar em minha biblioteca **para** visualizar e criar minhas playlists personalizadas.

5. **Como** usuário, **gostaria** que o sistema recomendasse uma música aleatória **para** descobrir algo novo.

6. **Como** usuário, **quero**  enviar uma música como input **para** receber uma recomendação de músicas semelhantes.

# Uso do programa

### Pré-requisitos para uso no Terminal

É preciso ter instalado em seu dispositivo um compilador de C++, o cmake e o git instalado. Após cumprir os requisitos, será preciso realizar a instalação do programa:

1. Clone o repositório:

```
git clone https://github.com/pds2/20231-team-15.git
``` 

2. Entre no diretório do repositório.

```
cd 20231-TEAM-15
```
3. Execute o comando make para gerar o projeto.

```
make terminal
```

4. (opcional) Execute o comando make test para testar o projeto.
```
make test
```

O sistema ao inicializar irá listar os comandos para o uso do sistema. Divirta-se!


# Interface

  Além do programa interativo no terminal, também há uma interface feita na biblioteca `GTK3`, onde é possível testar algumas funcionalidades.
  Os tutoriais abaixo são baseados no ambiente Debian/Ubuntu.
  
  ### Execução

  No ambiente Debian/Ubuntu, e em qualquer outra distribuição baseada no Gnome, não é necessário instalar nenhuma biblioteca extra para rodar o arquivo executável da interface. 
  Para executar este arquivo, entre no diretório do projeto e digite:
  ```
  ./main.out
  ```

  ### Compilação
  Para compilar a interface, é necessário instalar em seu computador a biblioteca de desenvolvimento do GTK3, `libgtkmm-3.0-dev`.
  Para instala-lá no ambiente Debian/Ubuntu:
  ```
  sudo apt install libgtkmm-3.0-dev
  ```

  Após isso, entre no diretório do projeto e execute o comando abaixo:
  ```
  make gui
  ```
  A interface será compilada e executada automaticamente.
    

#### Telas
   * Home (Sistema): tela central cujo usuário poderá visualizar as músicas disponíveis no sistema e receber algumas recomendações
   * Álbum (Album): tela que exibirá as musicas do album de um artista
   * Playlist (Playlist): tela que exebirá as musicas da playlist de um usuário
   * Biblioteca / Discografia (Biblioteca / Usuario / Artista): tela que listará as playlists/albuns de usuários/artistas.
   * Login / Cadastro (Sistema/Usuario/BancoUsuarios)
   * 'Telinha' de informações da Música (Musica)
