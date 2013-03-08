CC=gcc
CFLAGS=-Wall -Wextra -g -O3 
BUILD_DIR=./bin
SRC_DIR=./Graphs

all: bfs dfs CaminhoMinimo GrafoNOrientado GrafoQuadrado 	

bfs: dir_bin 
	${CC} ${CFLAGS} ${SRC_DIR}/BFS.c ${SRC_DIR}/Fila/Fila.c ${SRC_DIR}/Lista\ ADJ/ListaAdjacencia.c -o ${BUILD_DIR}/bfs

dfs: dir_bin
	${CC} ${CFLAGS} ${SRC_DIR}/DFS.c ${SRC_DIR}/Pilha/Pilha.c ${SRC_DIR}/Lista\ ADJ/ListaAdjacencia.c -o ${BUILD_DIR}/dfs  

CaminhoMinimo: dir_bin
	${CC} ${CFLAGS} ${SRC_DIR}/CaminhoMinimo.c ${SRC_DIR}/Lista\ ADJ/ListaAdjacencia.c -o ${BUILD_DIR}/CaminhoMinimo 
GrafoNOrientado: dir_bin
	${CC} ${CFLAGS} ${SRC_DIR}/GrafoNOrientado.c ${SRC_DIR}/Lista\ ADJ/ListaAdjacencia.c -o ${BUILD_DIR}/GrafoNOrientado
GrafoQuadrado: dir_bin
	${CC} ${CFLAGS} ${SRC_DIR}/GrafoQuadrado.c ${SRC_DIR}/Lista\ ADJ/ListaAdjacencia.c ${SRC_DIR}/GrauSE.c -o ${BUILD_DIR}/GrafoQuadrado

dir_bin:
	mkdir -p ${BUILD_DIR} 
clean:
	rm -rf bin
	rm -rf *.o 
