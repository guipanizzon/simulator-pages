/*
 ============================================================================
 Name        : simulator-pages.c
 Author      : Deko
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc < 3) {
		printf("erro na quantidade de parametros.");
		return 0;
	}

	unsigned int tampag = argv[1]; //tamanho da página;
	unsigned int memfisica = argv[2]; //tamanho da memória fisica
	unsigned int memlogica = argv[3]; //tamanho da memória lógica


	//printf("%lu enderecos lidos, %lu faltas de pagina (taxa=%.1f%%)\n");
	return EXIT_SUCCESS;
}
