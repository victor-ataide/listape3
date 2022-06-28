#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
1- Ja foi feito:
	Cadastramento de pilotos (conferindo nome e id)
2- Esta sendo feito: 
	Cadastramento de pilotos (conferindo o resto)
	Cadastramento de circuitos (coonferindo tudo rsrs)
*/

struct Piloto{
	int id;
	char nome[32];
	int idade;
	char sexo;
	char pais[32];
};

struct Circuito{
	int cs;
	char nomePista[32];
	char pais[32];
	float km;
	float menorTempo;
	int idPilo;
	
};

struct Melhorv{
    int piloid;
	int circuitoid;
	int dia[30];
	int mes[12];
	int ano[30];
	float tempo;
    char equipe[32];
};

void menuGeral(struct Piloto pilotos[], int quantidadePilotos, struct Circuito circuitos[], int quantidadeCircuitos, struct Melhorv melhorvs[], int quantidadeMelhorv);
void recebepilo (int *quantidadePilotos, struct Piloto pilotos[]);
void consultapilo(struct Piloto pilotos[], int quantidadePilotos);
void recebecircu(int *quantidadeCircuitos, struct Circuito circuitos[]);
void recebevolta(int *quantidadeVoltas, struct Melhorv melhorvs[]);
void menuPilotos(struct Piloto pilotos[], int *quantidadePilotos);
void menuCircuitos(struct Circuito circuitos[], int *quantidadeCircuitos);
void menuMelhorv(struct Melhorv melhorvs[], int *quantidadeVoltas);

int main(){   

    struct Piloto pilotos[50];
    struct Circuito circuitos[50];
    struct Melhorv melhorvs[50];
    int quantidadePilotos = 0, quantidadeCircuitos = 0, quantidadeMelhorv = 0;	
	
	
	menuGeral(pilotos, quantidadePilotos, circuitos, quantidadeCircuitos, melhorvs, quantidadeMelhorv);
	
    return 0;
}

void menuGeral(struct Piloto pilotos[], int quantidadePilotos, struct Circuito circuitos[], int quantidadeCircuitos, struct Melhorv melhorvs[], int quantidadeMelhorv){
	int escolhaMenu;
	int contador;
	do{
		printf("\nDe acordo com as opcoes..:");
		printf("\n[1] -> Menu Pilotos; ");
		printf("\n[2] -> Menu Circuitos; ");
		printf("\n[3]-> Menu Volta; ");
		printf("\n[0] -> Sair; ");
		printf("\nInforme a opcao escolhida: ");
		scanf("%i", &escolhaMenu);
		switch(escolhaMenu){
			case 1:
				menuPilotos(pilotos, &quantidadePilotos);
				break;
			case 2:
				menuCircuitos(circuitos, &quantidadeCircuitos);
				break;
			case 3:
				menuMelhorv(melhorvs, &quantidadeMelhorv);
				break;	
			case 0:
				printf("\nObrigado por utilizar o programa, saindo...");
				break;
			default: 
				printf("\nOpcao invalida...");
				break;
		}
	}while(escolhaMenu != 0);
}

void recebepilo(int *quantidadePilotos, struct Piloto pilotos[]){
    int i=0, j=0, c=0;
    do{
    	i=0;
        printf("\nInforme o nome do Piloto: ");
        fflush(stdin);
        gets(pilotos[*quantidadePilotos].nome);
        if (*quantidadePilotos>0){    
			for ( j = 0; j < *quantidadePilotos; j++){
				if (strcmp(pilotos[*quantidadePilotos].nome,pilotos[j].nome)==0){
					printf("\nJa existe um piloto com esse nome. ");
					i=500;
				}
			}
        }
    }while(i==500);
    
    do{
    	i=0;
        printf("\nInforme o ID do Piloto:");
        fflush(stdin);
        scanf("%d", &pilotos[*quantidadePilotos].id);
        if (*quantidadePilotos>0){    
			for ( c = 0; c < *quantidadePilotos; c++){
        		if (pilotos[*quantidadePilotos].id==pilotos[c].id){
					printf("\nJa existe um piloto com essa identificacao. ");
					i=500;  
            	}
			}
        }
        if(pilotos[*quantidadePilotos].id < 101){
			printf("\nO id do piloto nao pode ser abaixo de 100.");
			i=500;  
		}
		if(pilotos[*quantidadePilotos].id > 500){
			printf("\nO id do piloto nao pode ser acima de 500.");
			i=500;  
		}
    }while(i==500);
	
	do{
		printf("\nInforme a idade do Piloto:");
		fflush(stdin);
        scanf("%d", &pilotos[*quantidadePilotos].idade);
        if(pilotos[*quantidadePilotos].idade <= 0){
        	printf("\nPilotos com idade nula ou negativa nao serao aceitos.");
		}
	}while(pilotos[*quantidadePilotos].idade <= 0);
		
	do{
        printf("\nQual o sexo (m = masculino f = feminino): ");
        fflush(stdin);
        scanf("%c", &pilotos[*quantidadePilotos].sexo);
        if(pilotos[*quantidadePilotos].sexo !='m' && pilotos[*quantidadePilotos].sexo !='f'){
        	printf("\nPor favor, contente-se em informar apenas uma das opcoes dadas.");
		}
    }while(pilotos[*quantidadePilotos].sexo !='m' && pilotos[*quantidadePilotos].sexo !='f');
    
    printf("\nQual o pais de origem do piloto: ");
    fflush(stdin);
    gets(pilotos[*quantidadePilotos].pais);
	
	*quantidadePilotos=*quantidadePilotos+1;
}

void consultapilo(struct Piloto pilotos[], int quantidadePilotos){
	//printf("\n\n\n%i", quantidadePilotos);
	int posicao, achou=-1;
	char nome[32];
	printf("\nInforme o nome do piloto para conferir se o mesmo ja foi cadastrado: ");
	fflush(stdin);
	gets(nome);
	
	for(posicao=0;posicao<quantidadePilotos;posicao++){
		if(strcmp(pilotos[posicao].nome,nome)==0){
			achou=posicao;
		}
	}

	if(achou<0){
		printf("\nId nao encontrado em nossa base de dados, tente realizar a busca novamente ou escolha pela opcao de listagem dos pilotos cadastrados.");
	}else{
		printf("\n|	Id	|	Nome	|	Idade	|	Sexo	|	Pais	|");
		printf("\n|	%i	|	%s	|	%i	|	%c	|	%s	|", pilotos[achou].id,pilotos[achou].nome,pilotos[achou].idade,pilotos[achou].sexo, pilotos[achou].pais);
	}
	
}

void recebecircu(int *quantidadeCircuitos, struct Circuito circuitos[]){
	circuitos[*quantidadeCircuitos].cs = *quantidadeCircuitos +1;
	printf("\nInforme o nome da pista do circuito: ");
	fflush(stdin);
	gets(circuitos[*quantidadeCircuitos].nomePista);
	printf("\nInforme o nome do pais do circuito: ");
	fflush(stdin);
	gets(circuitos[*quantidadeCircuitos].pais);
	printf("\nInforme o tamanho do circuito em kilometros (utilize '.' ao inves de ',' no caso de ser uma quantidade quebrada, por exemplo '1.5' kilometros): ");
	fflush(stdin);
	scanf("%f", &circuitos[*quantidadeCircuitos].km);
	printf("\nInforme o menor tempo atual do circuito em minutos (utilize '.' ao inves de ',' no cas de ser uma quantidade quebrada, por exemplo '30,5' minutos): ");
	fflush(stdin);
	scanf("%f", &circuitos[*quantidadeCircuitos].menorTempo);
	printf("\nInforme o id do piloto que realizou o menor tempo do circuito: ");
	fflush(stdin);
	scanf("%d", &circuitos[*quantidadeCircuitos].idPilo);
	*quantidadeCircuitos = *quantidadeCircuitos+1;
}

void menuPilotos(struct Piloto pilotos[], int *quantidadePilotos){
	int escolhaMenuP, contador;
	do{
		printf("\nDe acordo com as opcoes..:");
		printf("\n[1] -> Cadastrar um novo Piloto; ");
		printf("\n[2] -> Consultar um piloto (atraves do nome); ");
		printf("\n[3] -> Listagem de todos os pilotos ja cadastrados; ");
		printf("\n[0] -> Sair; ");
		printf("\nInforme a opcao escolhida: ");
		scanf("%i", &escolhaMenuP);
		switch(escolhaMenuP){
			case 1:
				recebepilo(&(*quantidadePilotos), pilotos);
				break;
			case 2:
				consultapilo(pilotos, *quantidadePilotos);
				break;
			case 3:
				printf("\n|	Id	|	Nome	|	Idade	|	Sexo	|	Pais	|");
				for(contador=0;contador<*quantidadePilotos;contador++){
					printf("\n|	%i	|	%s	|	%i	|	%c	|	%s	|", pilotos[contador].id,pilotos[contador].nome,pilotos[contador].idade,pilotos[contador].sexo, pilotos[contador].pais);
				}
				break;
		}
	}while(escolhaMenuP != 0);
}

void menuCircuitos(struct Circuito circuitos[], int *quantidadeCircuitos){
	int escolhaMenuC;
	int contador;
	do{
		printf("\nDe acordo com as opcoes..:");
		printf("\n[1] -> Cadastrar um novo circuito; ");
		printf("\n[2] -> Listagem de todos os circuitos ja cadastrados; ");
		printf("\n[0] -> Sair; ");
		printf("\nInforme a opcao escolhida: ");
		scanf("%i", &escolhaMenuC);
		switch(escolhaMenuC){
			case 1:
				recebecircu(&(*quantidadeCircuitos), circuitos);
				break;
			case 2:
				printf("\n|	Cs	|	Nome	|	Pais	|	Tam(km)	|	Tempo	|	IdPiloto	|");
				for(contador=0;contador<*quantidadeCircuitos;contador++){
					printf("\n|	%i	|	%s	|	%s	|	%.2f	|	%.2f	|	%i	|", circuitos[contador].cs,circuitos[contador].nomePista,circuitos[contador].pais,circuitos[contador].km, circuitos[contador].menorTempo, circuitos[contador].idPilo);
				}
				break;
			case 0:
				printf("\n...saindo...");
				break;
			default: 
				printf("\nOpcao invalida...");
				break;
		}
	}while(escolhaMenuC != 0);
}
void menuMelhorv(struct Melhorv melhorvs[], int *quantidadeVoltas){
	int escolhaMenuV;
	int contador;

	do{
		printf("\nDe acordo com as opcoes..:");
		printf("\n[1] -> Cadastrar uma volta; ");
		printf("\n[2] -> ; ");
		printf("\n[0] -> Sair; ");
		printf("\nInforme a opcao escolhida: ");
		scanf("%i", &escolhaMenuV);
		switch(escolhaMenuV){
			case 1:
				recebevolta(&(*quantidadeVoltas), melhorvs);
				break;
			case 2:
				printf("\n|	IDC	|	Nome	|	Pais	|	Tam(km)	|	Tempo	|	ID Equipe	|");
				for(contador=0;contador<*quantidadeVoltas;contador++){
					printf("\n|	%i	|	%s	|	%s	|	%.2f	|	%.2f	|	%i	|", melhorvs[contador].circuitoid,melhorvs[contador].piloid,melhorvs[contador].equipe,melhorvs[contador].tempo);
				}
				break;
			case 0:
				printf("\n...saindo...");
				break;
			default: 
				printf("\nOpcao invalida...");
				break;
		}
	} while (escolhaMenuV != 0);	
}
  
void recebevolta(int *quantidadeVoltas, struct Melhorv melhorvs[]){
	printf("\n Informe o ID do piloto;\n");
	fflush(stdin);
	gets(melhorvs[*quantidadeVoltas].piloid);
	printf("\n Informe o ID do circuito;\n");
	fflush(stdin);
	gets(melhorvs[*quantidadeVoltas].circuitoid);
	printf("\n Informe a equipe do piloto;\n");
	fflush(stdin);
	gets(melhorvs[*quantidadeVoltas].equipe);
	printf("\n A seguir informe a data da volta...");
	print("\nInforme o dia da volta: ");
	fflush(stdin);
	gets(melhorvs[*quantidadeVoltas].dia[*quantidadeVoltas]);
	print("\nInforme o mes da volta: ");
	fflush(stdin);	
	gets(melhorvs[*quantidadeVoltas].mes[*quantidadeVoltas]);
	print("\nInforme o ano da volta: ");
	fflush(stdin);	
	gets(melhorvs[*quantidadeVoltas].ano[*quantidadeVoltas]);
	printf("\n Informe o tempo da melhor volta;(utilize esse exemplo min.seg.mls)\n");
	fflush(stdin);
	scanf("%f", melhorvs[*quantidadeVoltas].tempo);
}

