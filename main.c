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
	int i = 0, numeroDaPagLogica = 0, flag = 0;
	float taxa = 0.0;
	long unsigned int faltapagina = 0, numeroendereco = 0, qtdPagFisica =
			((memfisica * 1000) / tampag), qtdPagLogica = ((memlogica * 1000)
			/ tampag);
	int *enderecos, *vetorFisico, *vetorLogico;

	vetorLogico = (int*) malloc(sizeof(unsigned int) * qtdPagLogica);
	vetorFisico = (int*) malloc(sizeof(int) * qtdPagFisica);

	for (int i = 0; i < qtdPagFisica; ++i) {
		vetorFisico[i] = -1;
	}

	FILE *file;
	file = fopen("ps1.in", "r");

	while (!feof(file)) {
		fscanf(file, "%d", &i);
		numeroendereco++;
	}

	rewind(file);

	enderecos = (int*) malloc(sizeof(int) * numeroendereco);
	numeroendereco = 0;
	fscanf(file, "%d", &enderecos[numeroendereco]);
	while (!feof(file)) {
		printf("%d \n", enderecos[numeroendereco]);
		numeroDaPagLogica = enderecos[numeroendereco] / tampag;
		printf("Numero da pagina logica = %d\n", numeroDaPagLogica);
		for (int j = 0; j < qtdPagFisica; ++j) {
			for (int i = 0; i < qtdPagFisica; ++i) {
				printf("vetor fisico:%d\n", vetorFisico[i]);
				if (vetorFisico[j] == numeroDaPagLogica) {
					printf("Posição na mem Fisica\n	");
					flag = 1;
				}
			}
			if (flag == 0) {
				faltapagina++;
				while (vetorFisico[j] != -1) {
					j++;
				}
				if (j > qtdPagFisica) {
					/*Aqui entra o MRU*/
					j = 0;
				}

				vetorFisico[j] = numeroDaPagLogica;
				break;
			}
		}
		flag = 0;
		numeroendereco++;
		fscanf(file, "%d", &enderecos[numeroendereco]);
	}
	fclose(file);

	printf("%lu enderecos lidos, %lu faltas de pagina (taxa=%.1f%%)\n",
			numeroendereco, faltapagina, taxa);
	return EXIT_SUCCESS;
}
