
#include<stdio.h>
#define MAX 20
#define TAM 500

struct Clientes
{
	char nome[MAX];
	float saldo;
	int numero;
};

int transferencia(int conta1, int conta2, float valor, int n, Clientes clientes[TAM])
{
	int i,j;
	for(i = 0; i < n; i++)
	{
		if(clientes[i].numero == conta1){
			if(clientes[i].saldo >= valor){
				for(j = 0; j < n;j++){
					if(clientes[j].numero == conta2){
						clientes[j].saldo = clientes[j].saldo+valor;
						clientes[i].saldo = clientes[i].saldo  - valor;
						return 0;
					}
				}
			}else{
				return -1;
			}
		}
	}
	return -1;
}
void ordenacao(int n, Clientes clientes[TAM]){
	int i, j ;
	Clientes aux;
	for (i = 0; i < n; i++){
		aux = clientes[i];
		for(j=i-1; j>=0 && clientes[j].saldo > aux.saldo; j--){
			clientes[j+1] = clientes[j];
		}
			clientes[j+1] = aux;
	}
	for(i = 0; i < n; i++)
					printf("%s %d %f \n ", clientes[i].nome, clientes[i].numero, clientes[i].saldo);

}void ordenacaoalfa(int n, Clientes clientes[TAM]){
	int i, j ;
	Clientes aux;
	for (i = 0; i < n; i++){
		aux = clientes[i];
		for(j=i-1; j>=0 && clientes[j].nome > aux.nome; j--){
			clientes[j+1] = clientes[j];
		}
			clientes[j+1] = aux;
	}
	for(i = 0; i < n; i++)
					printf("%s %d %f \n ", clientes[i].nome, clientes[i].numero, clientes[i].saldo);
}

int main()
{
	Clientes clientes[TAM];
	int i;
	int n;
	int conta1, conta2;
	int opcao;
	float valor;
	// numero de pessoas a cadastrar
    printf("\n Digite a quantidade de clientes");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
        printf("\n Digite o nome do clientes o numero e o saldo  %d  ", i+1);
		scanf(" %[^\n]", clientes[i].nome);
		scanf("%d", &clientes[i].numero);
		scanf("%.2f ", &clientes[i].saldo);
	}
	do{
		printf("\n 1 - Transferir");
		printf("\n 2 - Listar pessoas ");
		printf("\n 3 - Ordenar por saldo ");
		printf("\n 4 - Ordenar por ordem alfabetica");
		printf("\n 5 - Sair");
		scanf("%d", &opcao);
		if(opcao == 1)
		{
			// leitura de um cpf para consulta
			printf("\n numero das constas para trasferencia  ");
			scanf("%d", &conta1);
			scanf("%d", &conta2);
			printf("\n O valor que quer transferir  ");
			scanf("%f", &valor);
			int transfe = transferencia(conta1,conta2, valor, n, clientes);
			if(transfe == -1)
				printf("Erro na trasferencia\n");
			else
				printf("Transferencia completa");
		}
		if(opcao == 2)
		{

			for(i = 0; i < n; i++)
					printf("%s %d %f \n ", clientes[i].nome, clientes[i].numero, clientes[i].saldo);
		}
		if(opcao == 3)
		{
			ordenacao(n, clientes);
		}
		if(opcao == 4)
		{
			ordenacaoalfa(n, clientes);
		}
	}while(opcao != 5);
	return 0;
}
