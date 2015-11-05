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

struct memfisica{
	int posicaoNaMemoriaFisica;
	int numeroDaPagina;
	int qtdJaAlocadaNaPagina;
	int flag;
};

int main(int argc, char **argv) {
	if (argc < 3) {
		printf("erro na quantidade de parametros.");
		return 0;
	}

	unsigned int tampag = atoi(argv[1]); //tamanho da página;
	unsigned int memfisica = atoi(argv[2]); //tamanho da memória fisica
	//unsigned int memlogica = atoi(argv[3]); //tamanho da memória lógica
	int i = 0, numeroDaPagLogica = 0,j,qtdJaAlocada = 0;
	float taxa = 0.0;
	long unsigned int faltapagina = 0, numeroendereco = 0, qtdPagFisica =
			((memfisica * 1000) / tampag);
	int *enderecos;
	struct memfisica *vetMemfisica = NULL;

	vetMemfisica = (struct memfisica*) malloc(sizeof(struct memfisica) * qtdPagFisica);

	//vetorFisico = (int*) malloc(sizeof(int) * qtdPagFisica);

	for (i = 0; i < qtdPagFisica; ++i) {
		vetMemfisica[i].flag = 0;
		vetMemfisica[i].posicaoNaMemoriaFisica = 0;
		vetMemfisica[i].qtdJaAlocadaNaPagina = 0;
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
		//printf("Numero da pagina logica = %d\n", numeroDaPagLogica);
		for (j = 0; j < qtdPagFisica; ++j) {
			/*for (i = 0; i < qtdPagFisica; ++i) {
				//printf("vetor fisico:%d\n", vetorFisico[i]);
				if (vetMemfisica[i].posicaoNaMemoriaFisica == numeroDaPagLogica) {

				}
			}*/
			if ((numeroDaPagLogica == vetMemfisica[j].numeroDaPagina) && (vetMemfisica[j].flag == 1)) {
				printf("mem Fisica %d \n", (enderecos[numeroendereco]-(vetMemfisica[j].numeroDaPagina*1024))+(vetMemfisica[j].posicaoNaMemoriaFisica*1024));

			}

			if (vetMemfisica[j].flag == 0) {
				faltapagina++;
				vetMemfisica[j].numeroDaPagina = enderecos[numeroendereco]/tampag;
				//printf("Posição na mem Fisica %d valor de j:%d\n",vetMemfisica[j].posicaoNaMemoriaFisica+1,j);
				printf("mem Fisica %d \n", (enderecos[numeroendereco]-(vetMemfisica[j].numeroDaPagina*1024))+(vetMemfisica[j].posicaoNaMemoriaFisica*1024));
				vetMemfisica[j+1].posicaoNaMemoriaFisica = vetMemfisica[j].posicaoNaMemoriaFisica + 1;
				/*if (j > qtdPagFisica) {
					Aqui entra o MRU
					j = 0;
				}*/

				vetMemfisica[j].numeroDaPagina = numeroDaPagLogica;

				qtdJaAlocada += enderecos[numeroendereco]-(vetMemfisica[j].numeroDaPagina*1024);
				//printf("ja alocada%d \n",vetMemfisica[j].qtdJaAlocada);
				vetMemfisica[j].flag = 1;
				break;
			}

		}
		numeroendereco++;
		fscanf(file, "%d", &enderecos[numeroendereco]);
	}
	fclose(file);

	printf("%lu enderecos lidos, %lu faltas de pagina (taxa=%.1f%%)\n",
			numeroendereco, faltapagina, taxa);
	return EXIT_SUCCESS;
}
