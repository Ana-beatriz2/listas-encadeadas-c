#include <stdio.h>

struct No {
    int dado;
    struct No *prox, *ant;
} *inicio = NULL, *fim = NULL;

int inserirInicio(int valor){
    struct No *novaStruct;

    novaStruct = new struct No;
    novaStruct -> dado = valor;
    novaStruct -> ant = NULL;

   if (inicio == NULL){
        inicio = novaStruct;
        fim = novaStruct;
        novaStruct -> prox = NULL;
        return 0;
   }

   novaStruct -> prox = inicio;
   inicio -> ant = novaStruct;
   inicio = novaStruct;
   return 0;
}

int inserirFinal(int valor){
    struct No *novaStruct;

    novaStruct = new struct No;
    novaStruct -> dado = valor;
    novaStruct -> prox = NULL;

    if (inicio == NULL){
        inicio = novaStruct;
        fim = novaStruct;
        novaStruct -> ant = NULL;
        return 0;
    }

    novaStruct -> ant = fim;
    fim -> prox = novaStruct;
    fim = novaStruct;
    return 0;
}

int imprimir(){
    struct No *aux = inicio;
    int opcao;

    if (aux == NULL){
        printf("\nLista vazia!");
        return 0;
    }

    printf("\nDigite [0] para imprimir do inicio ao final e [1] de tras para frente: ");
    scanf("%d", &opcao);

    switch(opcao){
    case 0:

        while (aux != NULL){
            printf(" %d ", aux -> dado);

            aux = aux -> prox;
        }

        break;
    case 1:
        aux = fim;

        while (aux != NULL){
            printf(" %d ", aux -> dado);

            aux = aux -> ant;
        }
        break;
    default:
        printf("\nOpcao invalida!");
    }

    return 0;
}

struct No *buscar(int valor){
    struct No *inicio2 = inicio, *fim2 = fim;

    if (inicio2 == NULL){
        printf("\nLista vazia!");
    }
    else{
        while (inicio2 != fim2 && inicio2 -> ant != fim2){
            if (inicio2 -> dado == valor){
                return inicio2;
            }

            if (fim2 -> dado == valor){
                return fim2;
            }

            inicio2 = inicio2 -> prox;
            fim2 = fim2 -> ant;
        }

        if (inicio2 == fim2 && inicio2 -> dado == valor){
            return inicio2;
        }
    }

    return NULL;
}

int alterar(int valorSubstituido){
    struct No *temp = buscar(valorSubstituido);
    int novoValor;

    if (temp == NULL){
        printf("\nValor nao encontrado!");
        return 0;
    }

    printf("\nInsira o valor que ira substituir o %d: ", valorSubstituido);
    scanf("%d", &novoValor);

    temp -> dado = novoValor;
    return 0;
}

int deletarUmElemento(int valor){
    struct No *temp = buscar(valor);

    if (temp == NULL){
        printf("\nValor nao encontrado!");
        return 0;
    }

    if (inicio == fim){
        inicio = NULL;
        fim = NULL;
    }
    else if(inicio == temp){
        inicio = temp -> prox;
        temp -> prox -> ant = NULL;
    }
    else if(fim == temp){
        fim = temp -> ant;
        temp -> ant -> prox = NULL;
    }
    else{
        temp -> ant -> prox = temp -> prox;
        temp -> prox -> ant = temp -> ant;
    }

    delete temp;
    return 0;
}

int deletarTudo(){
    struct No *inicio2 = inicio, *fim2 = fim;

    if (inicio2 == NULL){
        printf("\nLista vazia!");
        return 0;
    }

    while (inicio2 != fim2 && inicio2 -> prox != fim2){
        inicio = inicio2 -> prox;
        fim = fim2 -> ant;
        delete inicio2;
        delete fim2;
        inicio2 = inicio;
        fim2 = fim;
    }

    if (inicio2 == fim2){
        delete inicio2;
    }
    else if(inicio2 -> prox == fim2){
        delete inicio2;
        delete fim2;
    }

    inicio = NULL;
    fim = NULL;

    return 0;
}

int inserirOrdenado(int valor){
        struct No *novaStruct, *aux = inicio;

        novaStruct = new struct No();
        novaStruct -> dado = valor;

        if (inicio == NULL){
            inicio = novaStruct;
            fim = novaStruct;
            novaStruct -> prox = NULL;
            novaStruct -> ant = NULL;
            return 0;
        }

        while (aux != NULL){
            if (valor < aux -> dado && inicio == aux){
                inicio = novaStruct;
                novaStruct -> prox = aux;
                novaStruct -> ant = NULL;
                aux -> ant = novaStruct;
                return 0;
            }
            else if (valor < aux -> dado){
                novaStruct -> ant = aux -> ant;
                novaStruct -> prox = aux;
                aux -> ant -> prox = novaStruct;
                aux -> ant = novaStruct;
                return 0;
            }

          aux = aux -> prox;
        }

        novaStruct -> ant = fim;
        novaStruct -> prox = NULL;
        fim -> prox = novaStruct;
        fim = novaStruct;
        return 0;
}

int main(){
    int opcao, numero;
    struct No *temp;

    do {
        printf("\n====================================\nLista duplamente encadeada\n====================================\n");
        printf("Escolha a opcao desejada: \n");
        printf("1 - Inserir no inicio\n2 - inserir no final\n3 - Imprimir\n4 - Buscar\n5 - Alterar\n6 - Excluir um elemento\n7 - Deletar lista\n8 - Inserir ordenadamente\n9 - Finalizar\n");
        printf("====================================\nSua opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Qual numero deseja inserir? ");
            scanf("%d", &numero);

            inserirInicio(numero);
            break;
        case 2:
            printf("Qual numero deseja inserir? ");
            scanf("%d", &numero);

            inserirFinal(numero);
            break;
        case 3:
            imprimir();
            break;
        case 4:
            printf("\nInsira o numero que deseja buscar: ");
            scanf("%d", &numero);

            temp = buscar(numero);

            if (temp == NULL){
                printf("Numero nao encontrado.");
            }
            else{
                printf("\nO numero %d foi encontrado na posicao: %p", numero, temp);
            }
            break;
        case 5:
            printf("\nInsira o valor para ser substituido: ");
            scanf("%d", &numero);

            alterar(numero);
            break;
        case 6:
            printf("\nInsira o numero que sera deletado: ");
            scanf("%d", &numero);

            deletarUmElemento(numero);
            break;
        case 7:
            deletarTudo();
            break;
        case 8:
            printf("\nQual numero deseja inserir? ");
            scanf("%d", &numero);

            inserirOrdenado(numero);
            break;
        case 9:
            printf("Finalizado!");
            break;
         default:
            printf("Opcao invalida!");
        }
    }while(opcao != 9);

    return 0;
}
