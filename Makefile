#Makefile for "lab4" C++ aplication
#Created by Luis Eduardo Rique

# Comandos do sistema operacional
# Linux: rm -rf
# Windows: cmd //C del
RM = rm -rf

# Compilador
CC = g++

# Variaveis para os subdiretorios
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin
DOC_DIR = ./doc
TEST_DIR = ./test

# Outras variaveis

# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: histograma doxy
debug: CFLAGS += -g -O0
debug: histograma

# Alvo (target) para a construcao do executavel histograma
# Define os arquivos histograma.o funcoes.o como dependencias
histograma: $(OBJ_DIR)/histograma.o $(OBJ_DIR)/funcoes.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel histograma criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto histograma.o
# Define os arquivos histograma.cpp e histograma.h como dependencias.
$(OBJ_DIR)/histograma.o: $(SRC_DIR)/histograma.cpp $(INC_DIR)/histograma.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto funcoes.o
# Define os arquivos funcoes.cpp e histograma.h como dependencias.
$(OBJ_DIR)/funcoes.o: $(SRC_DIR)/funcoes.cpp $(INC_DIR)/histograma.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile
	mv rtf man latex html doc

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*