#include <stdio.h>

char identificarSexo() {
    char sexo;
    printf("Digite o sexo do assalariado (M/F): ");
    fflush(stdin);
    scanf(" %c", &sexo);
    fflush(stdin);


    while (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f') {
        printf("Sexo inválido. Digite novamente (M/F): ");
        scanf(" %c", &sexo);
    }
    return sexo;
}

float identificarSalario() {
    float salario;
    printf("Digite o salário do assalariado em reais: R$ ");
    scanf("%f", &salario);
    return salario;
}

int validaSalario(float salario) {
    return salario > 1.0;
}

void classificaSalario(float salario) {

    if (salario < 1400.0) {
        printf("Classificação do salário: Abaixo do salário mínimo\n");
    } else if (salario == 1400.0) {
        printf("Classificação do salário: Igual ao salário mínimo\n");
    } else {
        printf("Classificação do salário: Acima do salário mínimo\n");
    }
}

void mostraClassificacao(float salario, char sexo) {
    printf("Salário: R$ %.2f\n", salario);
    printf("Sexo: %s\n", (sexo == 'M' || sexo == 'm') ? "Masculino" : "Feminino");
    printf("\n");
}

void mostraResultado(int abaixoSalarioMinimo, int acimaSalarioMinimo) {

    printf("Assalariados abaixo do salário mínimo: %d\n", abaixoSalarioMinimo);
    printf("Assalariados acima do salário mínimo: %d\n", acimaSalarioMinimo);

}

main() {
    int abaixoSM = 0;
    int acimaSM = 0;
    char resp;

    do {

         char sexo = identificarSexo();
         float salario = identificarSalario();


            while (!validaSalario(salario)) {
                printf("Salário inválido. Digite um valor maior que R$1,00: ");
                salario = identificarSalario();
            }

            classificaSalario(salario);


            mostraClassificacao(salario, sexo);

            if (salario < 1400.00) {
                abaixoSM++;
            } else if (salario > 1400.0) {
                acimaSM++;
            }

            printf("\nDeseja cadastrar outro assalariado? (s/n): ");
            scanf(" %c", &resp);

            while (resp != 's' && resp != 'n') {
                printf("Entrada inválida! Digite novamente (s/n): ");
                scanf(" %c", &resp);
            }

    } while (resp == 's');

    if (abaixoSM + acimaSM > 0) {
        mostraResultado(abaixoSM, acimaSM);
    } else {
        printf("Nenhum assalariado cadastrado.\n");
    }
}