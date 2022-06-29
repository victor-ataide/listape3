#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
	char menorTempo[15];
	int idPilo;
	
};

struct Melhorv{
    int piloid;
	int circuitoid;
	char data[11];
	char menorTempo[15];
    char equipe[32];
};

struct Pais{
	char nome[32];
};

//Menus do programa: 
void menuGeral();
void menuPilotos(struct Piloto pilotos[], int *quantidadePilotos, struct Pais paises[]);
void menuCircuitos(struct Circuito circuitos[], int *quantidadeCircuitos, struct Pais paises[], int quantidadePilotos, struct Piloto pilotos[]);
void menuMelhorv(struct Melhorv melhorvs[], int *quantidadeVoltas, int quantidadePilotos, struct Piloto pilotos[], int quantidadeCircuitos, struct Circuito circuitos[]);
void menuRelatorios(struct Melhorv melhorvs[], int quantidadeMelhorv, int quantidadePilotos, struct Piloto pilotos[], int quantidadeCircuitos, struct Circuito circuitos[]);

//Funções referentes aos pilotos --> cadastro e consulta
void recebepilo (int *quantidadePilotos, struct Piloto pilotos[], struct Pais paises[]);
void consultapilo(struct Piloto pilotos[], int quantidadePilotos);

//Funções referentes aos circuitos --> cadastro
void recebecircu(int *quantidadeCircuitos, struct Circuito circuitos[], struct Pais paises[], int quantidadePilotos, struct Piloto pilotos[]);

//funções referentes as voltas --> cadastro
void recebevolta(int *quantidadeVoltas, struct Melhorv melhorvs[], int quantidadePilotos, struct Piloto pilotos[], int quantidadeCircuitos, struct Circuito circuitos[]);



int main(){   
	
    
	
	menuGeral();
	
    return 0;
}

void menuGeral(){
	//declarando structs e variaveis basicas
    struct Piloto pilotos[50];
    struct Circuito circuitos[50];
    struct Melhorv melhorvs[50];
    //criando vetor de paises
	struct Pais paises[8];
	//salvando os paises no vetor
	strcpy(paises[0].nome,"Brasil");
	strcpy(paises[1].nome,"Eua");
	strcpy(paises[2].nome,"Espanha");
	strcpy(paises[3].nome,"Italia");
	strcpy(paises[4].nome,"Australia");
	strcpy(paises[5].nome,"Austria");
	strcpy(paises[6].nome,"Arabia Saudita");
	strcpy(paises[7].nome,"Portugal");
    int quantidadePilotos = 0, quantidadeCircuitos = 0, quantidadeMelhorv = 0;	
	int escolhaMenu;
	int contador;
	
	do{
		printf("\nDe acordo com as opcoes..:");
		printf("\n[1] -> Menu Pilotos; ");
		printf("\n[2] -> Menu Circuitos; ");
		printf("\n[3] -> Menu Volta; ");
		printf("\n[4] -> Relatorios; ");
		printf("\n[0] -> Sair; ");
		printf("\nInforme a opcao escolhida: ");
		scanf("%i", &escolhaMenu);
		switch(escolhaMenu){
			case 1:
				menuPilotos(pilotos, &quantidadePilotos, paises);
				break;
			case 2:
				menuCircuitos(circuitos, &quantidadeCircuitos, paises, quantidadePilotos, pilotos);
				break;
			case 3:
				menuMelhorv(melhorvs, &quantidadeMelhorv, quantidadePilotos, pilotos, quantidadeCircuitos, circuitos);
				break;	
			case 4:
				menuRelatorios(melhorvs, quantidadeMelhorv, quantidadePilotos, pilotos, quantidadeCircuitos, circuitos);
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

void menuRelatorios(struct Melhorv melhorvs[], int quantidadeMelhorv, int quantidadePilotos, struct Piloto pilotos[], int quantidadeCircuitos, struct Circuito circuitos[]){
	int escolhaMenu;
	int escolhaCircuito;
	int achouCircuito;
	int contador;
	char escolhaTempo[15];
	do{
		printf("\nDe acordo com as opcoes..:");
		printf("\n[1] -> R1; ");
		printf("\n[2] -> R2; ");
		printf("\n[3] -> R3; ");
		printf("\n[4] -> R4; ");
		printf("\n[0] -> Sair; ");
		printf("\nInforme a opcao escolhida: ");
		scanf("%i", &escolhaMenu);
		switch(escolhaMenu){
			case 1:
				printf("\nPILOTOS\n");
				printf("\n|	Id	|	Nome	|	Idade	|	Sexo	|	Pais	|");
				for(contador=0;contador<quantidadePilotos;contador++){
					printf("\n|	%i	|	%s	|	%i	|	%c	|	%s	|", pilotos[contador].id,pilotos[contador].nome,pilotos[contador].idade,pilotos[contador].sexo, pilotos[contador].pais);
				}
				printf("\nCIRCUITOS\n");
				
				printf("\n| Cs |	Nome	|	Pais	|	Tam(km)	|	Tempo	| IdPiloto |");
				for(contador=0;contador<quantidadeCircuitos;contador++){
					printf("\n| %i |	%s	|	%s	|	%.2f	| %s	| %i |", circuitos[contador].cs,circuitos[contador].nomePista,circuitos[contador].pais,circuitos[contador].km, circuitos[contador].menorTempo, circuitos[contador].idPilo);
				}
				
				printf("\nVOLTAS\n");
				
				printf("\n|	IDC	|	IDP	|	Data		|	Tempo	|	IDE		|");
				for(contador=0;contador<quantidadeMelhorv;contador++){
					printf("\n|	%i	|	%i	|	%s	|	%s	|	%s	|", melhorvs[contador].circuitoid, melhorvs[contador].piloid, melhorvs[contador].data, melhorvs[contador].menorTempo, melhorvs[contador].equipe);
				}
				
				break;
			case 2:
				consultapilo(pilotos, quantidadePilotos);
				break;
			case 3:
				
				printf("\nInforme o codigo de um circuito para ter os dados das voltas dos pilotos dele: ");
				fflush(stdin);
				scanf("%d", &escolhaCircuito);

				if(escolhaCircuito >= 1 && escolhaCircuito <= quantidadeCircuitos){
					achouCircuito=1;
					
					printf("\n|	IDC	|	IDP	|	Data		|	Tempo	|	IDE		|");
					for(contador=0;contador<quantidadeMelhorv;contador++){
						if(melhorvs[contador].circuitoid == escolhaCircuito){
							printf("\n|	%i	|	%i	|	%s	|	%s	|	%s	|", melhorvs[contador].circuitoid, melhorvs[contador].piloid, melhorvs[contador].data, melhorvs[contador].menorTempo, melhorvs[contador].equipe);
						}
					}
				}
				if(achouCircuito<0){
					printf("\nO id do circuito informado nao foi encontrado em nossa base de dados, por favor, confira se o circuito foi cadastrado e depois retorne para cadastrar a menor volta.");
				}
				
				
				break;	
			case 4:
				
				printf("\nInforme um tempo de volta para conferir se existem voltas melhores do que ela (informe no formato 'minutos:segundos.milissegundos'): ");
				fflush(stdin);
				gets(escolhaTempo);
				
				printf("\n|	IDC	|	IDP	|	Data		|	Tempo	|	IDE		|");
				for(contador=0;contador<quantidadeMelhorv;contador++){
					if(strcmp(melhorvs[contador].menorTempo,escolhaTempo)<=0){
						printf("\n|	%i	|	%i	|	%s	|	%s	|	%s	|", melhorvs[contador].circuitoid, melhorvs[contador].piloid, melhorvs[contador].data, melhorvs[contador].menorTempo, melhorvs[contador].equipe);
					}
				}
			
				
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

void menuPilotos(struct Piloto pilotos[], int *quantidadePilotos, struct Pais paises[]){
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
				recebepilo(&(*quantidadePilotos), pilotos, paises);
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

void menuCircuitos(struct Circuito circuitos[], int *quantidadeCircuitos, struct Pais paises[], int quantidadePilotos, struct Piloto pilotos[]){
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
				recebecircu(&(*quantidadeCircuitos), circuitos, paises, quantidadePilotos, pilotos);
				break;
			case 2:
				
				printf("\n| Cs |	Nome	|	Pais	|	Tam(km)	|	Tempo	| IdPiloto |");
				for(contador=0;contador<*quantidadeCircuitos;contador++){
					printf("\n| %i |	%s	|	%s	|	%.2f	| %s	| %i |", circuitos[contador].cs,circuitos[contador].nomePista,circuitos[contador].pais,circuitos[contador].km, circuitos[contador].menorTempo, circuitos[contador].idPilo);
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

void menuMelhorv(struct Melhorv melhorvs[], int *quantidadeVoltas, int quantidadePilotos, struct Piloto pilotos[], int quantidadeCircuitos, struct Circuito circuitos[]){
	int escolhaMenuV;
	int contador;

	do{
		printf("\nDe acordo com as opcoes..:");
		printf("\n[1] -> Cadastrar uma volta; ");
		printf("\n[2] -> Amostragem de todas as voltas; ");
		printf("\n[0] -> Sair; ");
		printf("\nInforme a opcao escolhida: ");
		scanf("%i", &escolhaMenuV);
		switch(escolhaMenuV){
			case 1:
				recebevolta(&(*quantidadeVoltas), melhorvs, quantidadePilotos, pilotos, quantidadeCircuitos, circuitos);
				break;
			case 2:
				
				printf("\n|	IDC	|	IDP	|	Data		|	Tempo	|	IDE		|");
				for(contador=0;contador<*quantidadeVoltas;contador++){
					printf("\n|	%i	|	%i	|	%s	|	%s 	|	%s	|", melhorvs[contador].circuitoid, melhorvs[contador].piloid, melhorvs[contador].data, melhorvs[contador].menorTempo, melhorvs[contador].equipe);
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

void recebepilo(int *quantidadePilotos, struct Piloto pilotos[], struct Pais paises[]){
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
        printf("\nInforme o ID do Piloto: ");
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
		printf("\nInforme a idade do Piloto: ");
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
    
    int posicaoPais, escolhaPais;
    do{
    	printf("\nDe acordo com as seguintes opcoes...");
    	for(posicaoPais=0;posicaoPais<8;posicaoPais++){
    		printf("\n[%d] - %s", (posicaoPais+1), paises[posicaoPais].nome);
		}
		printf("\nInforme o codigo do pais de origem do piloto: ");
		fflush(stdin);
		scanf("%d", &escolhaPais);
		if(escolhaPais < 1){
			printf("Por favor, se atente a reponder com um dos codigos informados.");
		}
		if(escolhaPais > 8){
			printf("Por favor, se atente a reponder com um dos codigos informados.");
		}
		
	}while(escolhaPais < 1 || escolhaPais > 8);
	escolhaPais=escolhaPais-1;
    strcpy(pilotos[*quantidadePilotos].pais, paises[escolhaPais].nome);
	
	*quantidadePilotos=*quantidadePilotos+1;
}

void consultapilo(struct Piloto pilotos[], int quantidadePilotos){
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

void recebecircu(int *quantidadeCircuitos, struct Circuito circuitos[], struct Pais paises[], int quantidadePilotos, struct Piloto pilotos[]){
	circuitos[*quantidadeCircuitos].cs = *quantidadeCircuitos+1;
	int achouIgual=-1;
	
	printf("\nInforme o nome da pista do circuito: ");
	fflush(stdin);
	gets(circuitos[*quantidadeCircuitos].nomePista);
	
	int posicaoPais, escolhaPais;
    do{
    	printf("\nDe acordo com as seguintes opcoes...");
    	for(posicaoPais=0;posicaoPais<8;posicaoPais++){
    		printf("\n[%d] - %s", (posicaoPais+1), paises[posicaoPais].nome);
		}
		printf("\nInforme o codigo do pais do circuito: ");
		fflush(stdin);
		scanf("%d", &escolhaPais);
		if(escolhaPais < 1){
			printf("Por favor, se atente a reponder com um dos codigos informados.");
		}
		if(escolhaPais > 8){
			printf("Por favor, se atente a reponder com um dos codigos informados.");
		}
	}while(escolhaPais < 1 || escolhaPais > 8);
	escolhaPais=escolhaPais-1;
    strcpy(circuitos[*quantidadeCircuitos].pais, paises[escolhaPais].nome);
	
	int controleP;

	for(controleP=0;controleP<*quantidadeCircuitos;controleP++){	
		if(strcmp(circuitos[*quantidadeCircuitos].nomePista,circuitos[controleP].nomePista)==0){
			if(strcmp(circuitos[*quantidadeCircuitos].pais,circuitos[controleP].pais)==0){
				printf("Voce esta tentando realizar o cadastro de um circuito ja existente, por favor, confira a lista dos circuitos ja existentes.");
				achouIgual=1;
			}
		}
	}
	
	if(achouIgual!=1){
		printf("\nInforme o tamanho do circuito em kilometros (utilize '.' ao inves de ',' no caso de ser uma quantidade quebrada, por exemplo '1.5' kilometros): ");
		fflush(stdin);
		scanf("%f", &circuitos[*quantidadeCircuitos].km);
		printf("\nA seguir informe menor tempo atual do circuito, no seguinte formato 'minutos:segundos.milissegundos': ");
		fflush(stdin);
		gets(circuitos[*quantidadeCircuitos].menorTempo);
		
		int achou;
		achou=-1;
		printf("\nInforme o id do piloto que realizou o menor tempo do circuito: ");
			fflush(stdin);
		scanf("%d", &circuitos[*quantidadeCircuitos].idPilo);
	
		int controle;
		for(controle=0;controle<quantidadePilotos;controle++){
			if(circuitos[*quantidadeCircuitos].idPilo == pilotos[controle].id){
				achou=1;
			}
		}
		if(achou<0){
			printf("\nO id informado nao foi encontrado em nossa base de dados, por favor, confira se o piloto foi cadastrado e depois retorne para cadastrar o circuito.");
			*quantidadeCircuitos = *quantidadeCircuitos;
		}else{
			*quantidadeCircuitos = *quantidadeCircuitos+1;
		}
	}else{
		*quantidadeCircuitos = *quantidadeCircuitos;
	}
}
  
void recebevolta(int *quantidadeVoltas, struct Melhorv melhorvs[], int quantidadePilotos, struct Piloto pilotos[], int quantidadeCircuitos, struct Circuito circuitos[]){

	int achouPiloto;
	achouPiloto=-1;
	printf("\nInforme o ID do piloto: ");
	fflush(stdin);
	scanf("%d", &melhorvs[*quantidadeVoltas].piloid);
	
	int controleP;
	for(controleP=0;controleP<quantidadePilotos;controleP++){
		if(melhorvs[*quantidadeVoltas].piloid == pilotos[controleP].id){
			achouPiloto=1;
		}
	}
	
	if(achouPiloto<0){
		printf("\nO id do piloto informado nao foi encontrado em nossa base de dados, por favor, confira se o piloto foi cadastrado e depois retorne para cadastrar a menor volta.");
		*quantidadeVoltas = *quantidadeVoltas;
	}else{
		int achouCircuito;
		achouCircuito=-1;
		printf("\nInforme o ID do circuito: ");
		fflush(stdin);
		scanf("%d", &melhorvs[*quantidadeVoltas].circuitoid);
		
		if(melhorvs[*quantidadeVoltas].circuitoid >= 1 && melhorvs[*quantidadeVoltas].circuitoid <= quantidadeCircuitos){
				achouCircuito=1;
		}
		if(achouCircuito<0){
			printf("\nO id do circuito informado nao foi encontrado em nossa base de dados, por favor, confira se o circuito foi cadastrado e depois retorne para cadastrar a menor volta.");
			*quantidadeVoltas = *quantidadeVoltas;
		}else{
			printf("\nInforme a equipe do piloto: ");
			fflush(stdin);
			gets(melhorvs[*quantidadeVoltas].equipe);
			
			
			printf("\nA seguir informe a data da volta de acordo com o padrao 'dd/mm/aaaa' : ");
			fflush(stdin);
			gets(melhorvs[*quantidadeVoltas].data);
			int controleV, achouData=-1;
			
			
			for(controleV=0;controleV<*quantidadeVoltas;controleV++){
				if(melhorvs[*quantidadeVoltas].piloid == melhorvs[controleV].piloid){
					if(melhorvs[*quantidadeVoltas].circuitoid == melhorvs[controleV].circuitoid){
						if(strcmp(melhorvs[*quantidadeVoltas].data,melhorvs[controleV].data)==0){
							achouData=1;
						}	
					}
				}
			}
			
			if(achouData>0){
				printf("\nSo pode existir um unico registro para um piloto em um circuito em uma data, neste caso esta repetindo o piloto o circuito em uma data ja cadastrada.");
				*quantidadeVoltas = *quantidadeVoltas;
			}else{
				printf("\nA seguir informe o tempo da volta, no seguinte formato 'minutos:segundos.milissegundos': ");
				fflush(stdin);
				gets(melhorvs[*quantidadeVoltas].menorTempo);
			
				int controleG;
				for(controleG=0;controleG<quantidadeCircuitos;controleG++){
					if(melhorvs[*quantidadeVoltas].circuitoid == circuitos[controleG].cs){
						if(strcmp(melhorvs[*quantidadeVoltas].menorTempo,circuitos[controleG].menorTempo)<0){
							strcpy(circuitos[controleG].menorTempo, melhorvs[*quantidadeVoltas].menorTempo);
							circuitos[controleG].idPilo = melhorvs[*quantidadeVoltas].piloid;
						}
					}
				}
				
				*quantidadeVoltas = *quantidadeVoltas+1;
				
			}
		}
	}

}