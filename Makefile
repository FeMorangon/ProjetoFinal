# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Diretórios
BIN_DIR = bin
OBJ_DIR = obj
INCLUDE_DIR = include
SRC_DIR = src

# Arquivos de origem e de objeto
SOURCES = $(SRC_DIR)/main.cpp
OBJECTS = $(OBJ_DIR)/main.o

# Executável final
EXEC = jogos_execution

# Regras
all: $(EXEC)

# Compila o executável
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC)

# Compilação dos arquivos .cpp em .o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/cabecalhos.hpp $(INCLUDE_DIR)/cadastros.hpp $(INCLUDE_DIR)/jogos.hpp $(INCLUDE_DIR)/lig4.hpp $(INCLUDE_DIR)/reversi.hpp $(INCLUDE_DIR)/velha.hpp
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

# Limpeza dos arquivos compilados
clean:
	rm -f $(OBJ_DIR)/*.o $(EXEC)

# mingw32-make.exe jogos_execution
# jogos_execution