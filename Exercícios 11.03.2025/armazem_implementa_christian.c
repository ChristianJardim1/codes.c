#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void menu() {
	printf("\n1 - Escolher quantos produtos a mais serao cadastrados");
	printf("\n2 - Inserir um produto");
	printf("\n3 - Apresentar um produto");
	printf("\n4 - Apresentar todos os produtos");
	printf("\n5 - Balanco");
	printf("\n6 - Buscar por nome");
	printf("\n7 - Buscar por setor");
	printf("\n8 - Venda");
	printf("\n9 - Carregar por arquivo");
	printf("\n10 - Gerar arquivo");
	printf("\n11 - Sair");
}

Item *realocar(Item *item) {
	int mp;

	printf("\nInsira quantos elementos a mais serao cadastrados: ");
	scanf("%d", &mp);

	item = (Item*)realloc(item,sizeof(Item*) * mp);

	return item;
}

int insere(Item *item, int qt) {
	int s;

	printf("\nDigite o nome do produto: ");
	scanf(" %[^\n]", item[qt].nome);
	printf("\nO sua quantidade: ");
	scanf("%d", &item[qt].quant);
	printf("\nO seu valor: ");
    scanf("%f", &item[qt].valor);
    printf("1-hortifruti; 2-bebidas; 3-mercearia; 4-higiene; 5-acougue; 6-laticineos; 7-frios; 8-doces;9-padaria");
	printf("\nO seu setor, dentre as opcoes acima: ");
	scanf("%d", &s);
	item[qt].setor = s;

	qt++;
	return qt;
}

void apresenta(Item *item, int i) {
	printf("\nProduto: %s", item[i].nome);
    printf("\nQuantidade: %d", item[i].quant);
    printf("\nValor: %.2f", item[i].valor);
    printf("\nSetor: ");
	switch(item[i].setor) {
	case 1:
		printf("hortifruti\n");
		break;
	case 2:
		printf("bebidas\n");
		break;
	case 3:
		printf("mercearia\n");
		break;
	case 4:
		printf("higiene\n");
		break;
	case 5:
		printf("acougue\n");
		break;
	case 6:
		printf("laticineos\n");
		break;
	case 7:
		printf("frios\n");
		break;
	case 8:
		printf("doces\n");
		break;
	case 9:
		printf("padaria\n");
		break;
	}
}

void apresenta1(Item *item, int qt) {
	char p[15];

	printf("\nDigite o nome do produto: ");
	scanf(" %[^\n]", p);

	for(int i=0; i<qt; i++) {
		if(strcmp(p, item[i].nome) == 0) {
			apresenta(item, i);
		}
	}
}

void apresentaT(Item *item, int qt) {

	for(int i=0; i<qt; i++) {
		apresenta(item, i);
	}
}

void buscaN(Item *item, int qt) {
	char p[15];

	printf("\nDigite o nome do produto: ");
	scanf(" %[^\n]", p);

	for(int i=0; i<qt; i++) {
		if(strcmp(p, item[i].nome) == 0) {
			apresenta(item,i);
		}
	}
}

void buscaS(Item *item, int qt) {
    int s;

    printf("\n\n1-hortifruti; 2-bebidas; 3-mercearia; 4-higiene; 5-acougue; 6-laticineos; 7-frios; 8-doces; 9-padaria");
	printf("\nO setor do produto, dentre as opcoes acima: ");
	scanf("%d", &s);
	
	for(int i=0; i<qt; i++) {
		if(item[i].setor == s) {
			apresenta(item,i);
		}
	}
}

void venda(Item *item, int qt) {
	char p[15];
	int qv;

	printf("\nDigite o nome do produto que foi vendido: ");
	scanf(" %[^\n]", p);
    printf("\nA quantidade que foi vendida: ");
	scanf("%d", &qv);	

	for(int i=0; i<qt; i++) {
		if(strcmp(p, item[i].nome) == 0) {
			item[i].quant = item[i].quant - qv;
		}
	}
}
