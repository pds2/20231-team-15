# Variáveis de compilação
CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude

# Pasta de inclusão
INCLUDE_DIR = include

# Pasta de arquivos de origem
SRC_DIR = src

# Obter todos os arquivos de origem
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Obter todos os arquivos de objeto
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, %.o, $(SOURCES))

# Nome do executável
EXECUTABLE = main.exe

# Regra de compilação padrão
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra para compilar cada arquivo de objeto
%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
