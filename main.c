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

struct memfisica {
	int posicaoNaMemoriaFisica;
	int numeroDaPagina;
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
	int i = 0, k = 0, numeroDaPagLogica = 0, j;
	long unsigned int faltapagina = 0, numeroendereco = 0, qtdPagFisica =
			((memfisica * 1000) / tampag);
	int *enderecos, *MRU, indexMRU = 0;
	struct memfisica *vetMemfisica = NULL;
	int t;

	vetMemfisica = (struct memfisica*) malloc(
			sizeof(struct memfisica) * qtdPagFisica);
	MRU = (int*) malloc(sizeof(int) * qtdPagFisica);

	//vetorFisico = (int*) malloc(sizeof(int) * qtdPagFisica);

	for (i = 0; i < qtdPagFisica; ++i) {
		vetMemfisica[i].flag = 0;
		vetMemfisica[i].posicaoNaMemoriaFisica = 0;
		MRU[i] = -1;
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
		//printf("%d \n", enderecos[numeroendereco]);
		numeroDaPagLogica = enderecos[numeroendereco] / tampag;
		for (j = 0; j < qtdPagFisica; ++j) {
			printf("MRU:%d--\n", MRU[indexMRU]);
			/*for (i = 0; i < qtdPagFisica; ++i) {
			 //printf("vetor fisico:%d\n", vetorFisico[i]);
			 if (vetMemfisica[i].posicaoNaMemoriaFisica == numeroDaPagLogica) {

			 }
			 }*/
			if ((numeroDaPagLogica == vetMemfisica[j].numeroDaPagina)
					&& (vetMemfisica[j].flag == 1)) {
				//Quando vai usar uma página já existente.
				printf("%d\n",
						(enderecos[numeroendereco]
								- (vetMemfisica[j].numeroDaPagina * 1024))
								+ (vetMemfisica[j].posicaoNaMemoriaFisica * 1024));
				//Atualização do MRU
				if (MRU[indexMRU] == vetMemfisica[j].numeroDaPagina) {
					//já é a ultima
				} else {
					//atualizar a posição
					printf("++k:%d++%d e %d index:%d\n",k,MRU[k],vetMemfisica[j].numeroDaPagina,indexMRU);
					while (MRU[k] != vetMemfisica[j].numeroDaPagina) {
						k++;
					}
					while (k != qtdPagFisica-1) {
						MRU[k] = vetMemfisica[k + 1].numeroDaPagina;
						k++;
						printf("loop");
					}
					MRU[indexMRU-1] = vetMemfisica[j].numeroDaPagina;

				}

				k = 0;
				break;
			}
			for (t = 0; t < 3; ++t) {
								printf("==%d==\n",MRU[t]);
							}

			if (vetMemfisica[j].flag == 0) {
				//MRU[faltapagina] = enderecos[numeroendereco] / tampag;
				faltapagina++;
				vetMemfisica[j].numeroDaPagina = enderecos[numeroendereco]
						/ tampag;
				//printf("Posição na mem Fisica %d valor de j:%d\n",vetMemfisica[j].posicaoNaMemoriaFisica+1,j);
				printf("%d\n",
						(enderecos[numeroendereco]
								- (vetMemfisica[j].numeroDaPagina * 1024))
								+ (vetMemfisica[j].posicaoNaMemoriaFisica * 1024));
				vetMemfisica[j + 1].posicaoNaMemoriaFisica =
						vetMemfisica[j].posicaoNaMemoriaFisica + 1;
				vetMemfisica[j].numeroDaPagina = numeroDaPagLogica;
				vetMemfisica[j].flag = 1;
				MRU[indexMRU] = vetMemfisica[j].numeroDaPagina;
				indexMRU++;
				break;
			}

			if (vetMemfisica[j].flag == 1 && (j == qtdPagFisica - 1)) {
				//Hora que vai puxar do MRU
				faltapagina++;
				//printf("MRU:%d e: %d--\n", MRU[indexMRU],enderecos[numeroendereco] / tampag);

				int valorMRU = MRU[0];
				printf("**%d**Pag:%d\n",valorMRU,enderecos[numeroendereco]/ tampag);
				vetMemfisica[valorMRU].numeroDaPagina = enderecos[numeroendereco]
						/ tampag;
printf("%d\n",(enderecos[numeroendereco]- (vetMemfisica[valorMRU].numeroDaPagina * 1024))+ (valorMRU * 1024));
				vetMemfisica[valorMRU + 1].posicaoNaMemoriaFisica =
						vetMemfisica[valorMRU].posicaoNaMemoriaFisica + 1;
				vetMemfisica[valorMRU].numeroDaPagina = numeroDaPagLogica;
				MRU[indexMRU] = vetMemfisica[j].posicaoNaMemoriaFisica;
				break;
			}
		}
		numeroendereco++;
		fscanf(file, "%d", &enderecos[numeroendereco]);
	}

	fclose(file);
	printf("%lu enderecos lidos, %lu faltas de pagina (taxa=%.1f%%)\n",
			numeroendereco, faltapagina,
			((double) faltapagina / numeroendereco) * 100);
	return EXIT_SUCCESS;
}
