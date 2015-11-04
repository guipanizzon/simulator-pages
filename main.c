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

	unsigned int tampag = atoi(argv[1]); //tamanho da página;
	unsigned int memfisica = atoi(argv[2]); //tamanho da memória fisica
	unsigned int memlogica = atoi(argv[3]); //tamanho da memória lógica
	int numeroendereco = 0, faltapagina = 0,i = 0;
	float taxa = 0.0;
	unsigned int qtdPagFisica = ((memfisica*1000)/tampag), qtdPagLogica = ((memlogica*1000)/tampag);
	unsigned int *enderecos,*vetorFisico,*vetorLogico;

	vetorLogico = (int*) malloc(sizeof(unsigned int)*qtdPagLogica);
	vetorFisico = (int*) malloc(sizeof(int)*qtdPagFisica);


	FILE *file;
	file = fopen("ps1.in", "r");

	while (!feof(file))  {
		fscanf (file, "%d", &i);
	  numeroendereco++;
	}
	printf("qtd end %d\n",numeroendereco);

	rewind(file);

	enderecos = (int*) malloc(sizeof(int)*numeroendereco);
	numeroendereco = 0;
	fscanf (file, "%d", enderecos[numeroendereco]);
	while (!feof (file))  {
	  printf ("%d \n", enderecos[numeroendereco]);
	  fscanf (file, "%d", &enderecos[numeroendereco]);
	  numeroendereco++;
	}
	fclose(file);
	i = 0;
	//while (enderecos[i] > 0) {	}


	//printf("%lu enderecos lidos, %lu faltas de pagina (taxa=%.1f%%)\n",numeroendereco,faltapagina,taxa);
	return EXIT_SUCCESS;
}
