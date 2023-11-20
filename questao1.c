#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define tam 1000

  typedef struct{
    char nome[20];
    int  quantidade;
    int id;
    float salario;

  }Operario;


void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarOperario(Operario operario[tam], int indice){
  operario[indice].id = indice +1;
  printf("Digite o nome do funcionario:\n");
  limparBuffer();
  fgets(operario[indice].nome, sizeof(operario[indice].nome), stdin);
  operario[indice].nome[strcspn(operario[indice].nome, "\n")] = '\0';  // Remover a quebra de linha
  printf("Digite a Quantidade de pecas vendidas pelo operario:\n");
  scanf("%d", &operario[indice].quantidade);
  operario[indice].salario = 600;

}

int  validarQuantidade(Operario operario[tam], int indice){
  int quantidade1=0;
  if(operario[indice].quantidade  < 51 ){
    quantidade1 = 0;
  }else if (operario[indice].quantidade > 50 && operario[indice].quantidade < 81 ){
    quantidade1= operario[indice].quantidade - 50;

  }else if (operario[indice].quantidade > 80){ 
    quantidade1= operario[indice].quantidade - 50;

  }
  return quantidade1;
}

float calcularSalario(Operario operario[tam], int indice){
  int quantidade1 = validarQuantidade(operario, indice);
  float salario = operario[indice].salario;

  if(quantidade1 < 0){
    salario = salario;
  }else if(quantidade1 > 0 && quantidade1 < 31){
    salario = salario + (quantidade1 * 0.5);
  }else if (quantidade1 >30){
    quantidade1 = quantidade1 - 30;
    salario = salario + (quantidade1 * 0.75) + (30 * 0.5);
  }
  return salario;
}

void listaroperario(Operario operario[tam], int indice){

  if(indice == 0 ){
    printf("\n Não existem registros na lista!");
  }else{
     for(int i = 0; i < indice; i++){
      float salario = calcularSalario(operario, i);
      printf("\nId: %d", operario[i].id);
      printf("\nnome: %s", operario[i].nome);
      printf("\nO salario do operario é: %.2f\n", salario);
      printf("\n\n");
    }
    printf("\n");
  }
} 

int main(void){
  Operario operario[tam];
  int totalCadastrados = 0 ,opcao ;

  do{

      printf("\nDigite 1 para cadastrar;");
      printf("\nDigite 2 para acessar o salario atualizado;");
      printf("\nDigite 0 para sair do sistema;");
      printf("\nDigite a opção escolhida:\n");
      scanf("%d",&opcao);
      printf("\n");

      switch(opcao){
        case 1:
          cadastrarOperario(operario, totalCadastrados );
          totalCadastrados++;
        break;
        case 2:
          listaroperario(operario, totalCadastrados);
        break; 
      }
    }while(opcao!=0);

    return 0;
} 
