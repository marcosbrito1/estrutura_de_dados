#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct lista {
	int num;
	char nome[20];
	int cod;
	float preco;
	struct lista *prox;
	struct lista *ant;
}l;
l *ini=NULL,*fim,*novo,*tmp,*ant=NULL;
l *aux,*m=NULL,*n=NULL;

int inserir (){
	novo=(l*)malloc(1*sizeof(l));
	printf("-----------------------------Cadastro do Instrumento------------------------------");
	printf("\nInforme o código do instrumento musical!\n");
	scanf("%d",&novo->cod);
	printf("Informe o nome do instrumento musical!\n");
	scanf("%s",&novo->nome);
	printf("Informe o preço do instrumento musical!\n");
	scanf("%f",&novo->preco);
	novo->prox=NULL;
	if(ini==NULL){
		ini=novo;
	}else{
		int cont=0,a=0,b=0;
		tmp=ini;
		
		while(novo->nome[a]==tmp->nome[b]){
			cont=cont+1;
			a=a+1;
			b=b+1;
			
		}
	while(tmp!=NULL && novo->nome[a] > tmp->nome[b]){
       ant=tmp;
       tmp=tmp->prox;
       			}
		if(tmp==ini){
			novo->prox=ini;
			ini=novo;
		}else{
		ant->prox=novo;
		novo->prox=tmp;	
		}
		}
		return(0);
		}
		
int mostrar(){
	if(ini==NULL){
		printf("Vázia!\n");
	}else{
	aux=ini;	
	printf("----------------------------Instrumentos Cadastrados------------------------------\n");
		while(aux!=NULL){
			printf("Nome: %s\n",aux->nome);
			printf("Código: %d\n",aux->cod);
			printf("Preço: %f\n\n",aux->preco);
			aux=aux->prox;
		}
	}	
	return(0);
}

int remover(){
	int mat;
	if(ini==NULL){
		printf("Vazia!\n");
		}else{
	aux=ini;
	printf("-------------------------Remover Registros de Instrumento-------------------------");
	printf("\nInforme o codigo!\n");
	scanf("%d",&mat);
	while(aux!=NULL && aux->cod!=mat){
	ant=aux;
	aux=aux->prox;
}
if(aux==NULL){
return (0);	
} 
if(aux==ini){
	ini=aux->prox;
}else{
	ant->prox=aux->prox;
	free(aux);
	}
	printf("Remoção feita com sucesso!\n");
}
	return(0);
}

buscar(){
	int n,cont=1;
	if(ini==NULL){
		printf("Vázia!\n");
	}else{
	aux=ini;
	m=(l*)malloc(1*sizeof(l));
	printf("------------------------------Busca de Instrumento--------------------------------");
	printf("\nInforme o nome do instrumento!\n");
	scanf("%s",m->nome);
	printf("\n");	
		while(aux!=NULL){
			if(strcmp(m->nome,aux->nome)==0){
				cont=1;
			printf("Nome: %s\n",aux->nome);
			printf("Código: %d\n",aux->cod);
			printf("Preço: %f\n",aux->preco);
			n=1;
   }else{
   	cont=0;
   }
aux=aux->prox;
		}
	}	
	if(cont==0) { printf("Não há instrumentos com esse nome!\n");	}
	return(0);
}
int main(){
	int op=0;
	
	do{
		printf("\n1-Inserir\n2-Mostrar\n3-Remover\n4-Buscar\n0-Finalizar\n");
	printf    ("-----------------------------Informe o seu pedido!------------------------------");
	scanf("%d",&op);
	switch(op){
		case 1: inserir();break;
		case 2: mostrar();break;
		case 3: remover();break;
		case 4: buscar();break;
	}
	}while(op!=0);
	printf("\nObrigado, Volte Sempre!\n");
	return(0);
}
