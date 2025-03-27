#include <stdio.h>
#include <string.h>

enum gen{rock=1, samba, metal, sertanejo, jazz};

typedef struct {
	char nome[30];
	enum gen tipo;
	int rank;
	int integ;
}Band;

void load(Band band[]);
void print(Band band[]);
void ran(Band band[], int r);
void est(Band band[], gen g);
void banVeri(Band band[], char ver[20]);

int main() {
	int r,g;
	char genfav[10],ver[20];
	Band band[5];
	load(band);
	print(band);
	scanf("%d",&r);
	ran(band, r);
	scanf("%d", &g);
	est(band, g);
	scanf(" %[^\n]", &ver);
	banVeri(band, ver); 
}

void load(Band band[]) {
	for(int i=0; i<5; i++) {
		printf("\nDigite o nome de uma banda favorita: ");
		scanf(" %[^\n]", &band[i].nome);
		int tipoinf;
		printf("\nSeu estilo musical, dentro desta opcoes: 1 - rock, 2 - samba, 3 - metal, 4 - sertanejo, 5 - jazz");
		scanf("%d", &tipoinf);
		band[i].tipo = tipoinf;
		printf("\nQuantidade de membros: );
		scanf("%d",&band[i].integ);
		printf("\nA posicao dela no seu ranking: ");
		scanf("%d",&band[i].rank);
	}
}

void print(Band band) {
	for(int i=0; i<5; i++){
		printf("\nBanda:%s\n",band[i].nome);
			printf("Estilo musical: ");
			switch(band[i].tipo) {
			
			printf("Quantidade de integrantes:%d\n", band[i].integ);
printf("Lugar no ranking:%d\n",band[i].rank);
}

void ran(Band band[], int r) {
	for(int i=0; i<5; i++) {
		if(band[i].rank == r) {
			printf("\nBanda:%s\n",band[i].nome);
			printf("Estilo musical: %s\n", band[i].tipo);
			printf("Quantidade de integrantes:%d\n", band[i].integ);
printf("Lugar no ranking:%d\n",band[i].rank);
		}
	}
}

void est(Band band[], int g) {
	printf("Estas são as suas bandas favoritas desse estilo:\n");
	for(int i=0; i<5; i++) {
		if(band[i].tipo == g) {
			printf("%s\n",band[i].nome);
		}
	}
}

void ban(Band band[], char ver[20]) {
	int y;
	for(int i=0; i<5; i++) {
		if(strcmp(ver, band[i].nome) == 0) {
			printf("Esta banda é uma das suas favoritas.");
			y=1;}
		if(y=0) {
			printf("Esta banda não está entre as suas favoritas.");
		}
	}
}