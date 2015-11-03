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
	int numeroendereco = 0, faltapagina = 0,enderecos[100],i = 0;
	float taxa = 0.0;

	FILE *file;
	file = fopen("ps1.in", "r");


	fscanf (file, "%d", &enderecos[i]);
	while (!feof (file))  {
	  printf ("%d \n", enderecos[i]);
	  fscanf (file, "%d", &enderecos[i]);
	}
	fclose(file);


	printf("%lu enderecos lidos, %lu faltas de pagina (taxa=%.1f%%)\n",numeroendereco,faltapagina,taxa);
	return EXIT_SUCCESS;
}
