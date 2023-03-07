#include <stdio.h>

struct No {
    int dado;
    struct No *prox;
} *inicio = NULL;


int inserirInicio(int valor){
    struct No *novaStruct;

    novaStruct = new struct No;
    novaStruct -> dado = valor;
    novaStruct -> prox = inicio;
    inicio = novaStruct;

    return 0;
}

int imprimir(){
    struct No *aux = inicio;

    if (aux == NULL){
        printf("\nLista vazia!");
        return 0;
    }

    while (aux != NULL){
        printf(" %d ", aux -> dado);

        aux = aux -> prox;
    }

    return 0;
}

int inserirFinal(int valor){
    struct No *novaStruct, *aux = inicio;

    novaStruct = new struct No;
    novaStruct -> dado = valor;
    novaStruct -> prox = NULL;

    if (inicio == NULL){
        inicio = novaStruct;
    }
    else{
        while (aux -> prox != NULL){
            aux = aux -> prox;
        }

        aux -> prox = novaStruct;
    }

    return 0;
}

struct No *buscar(int valor){
    struct No *aux = inicio;

    if (aux == NULL){
        printf("\nLista vazia!");
    }
    else{
      while (aux != NULL){
        if (aux -> dado == valor){
            return aux;
        }

        aux = aux -> prox;
      }
    }
}

int alterar (int valorSubstituido){
    struct No *temporario = buscar(valorSubstituido);
    int novoValor;

    if (temporario == NULL){
        printf("\nValor nao encontrado!");
        return 0;
    }

    printf("\nInsira um novo valor para substituir o numero %d: ", valorSubstituido);
    scanf("%d", &novoValor);

    temporario -> dado = novoValor;
    return 0;
}

int deletarTudo(){
    struct No *aux = inicio;

    if (aux ==  NULL){
        printf("\nLista ja esta vazia!");
        return 0;
    }

    while (aux != NULL){
        inicio = aux -> prox;
        delete aux;
        aux = inicio;
    }

    return 0;
}

int deletarUmElemento(int valor){
    struct No *temporario = buscar(valor), *aux = inicio;

    if (temporario == NULL){
        printf("\nElemento nao encontrado!");
        return 0;
    }

    if (inicio == temporario){
        inicio = temporario -> prox;
    }
    else{
        while (aux -> prox != temporario){
            aux = aux -> prox;
        }

        aux -> prox = temporario -> prox;
    }

    delete temporario;
    return 0;
}

int inserirOrdenado(int valor){
    struct No *novaStruct, *aux = inicio, *aux2 = inicio;

    novaStruct = new struct No;
    novaStruct -> dado = valor;

    if (aux == NULL){
        inicio = novaStruct;
        novaStruct -> prox = NULL;
        return 0;
    }

    while (aux != NULL){
        if (valor < aux -> dado && inicio == aux){
            novaStruct -> prox = aux;
            inicio = novaStruct;
            return 0;
        }
        else if (valor < aux -> dado){
            novaStruct -> prox = aux;

            while (aux2 -> prox != aux){
                aux2 = aux2 -> prox;
            }

            aux2 -> prox = novaStruct;
            return 0;
        }

        aux = aux -> prox;
    }

    novaStruct -> prox = NULL;

    while (aux2 -> prox != aux){
        aux2 = aux2 -> prox;
    }

    aux2 -> prox = novaStruct;
    return 0;
}

int main(){


    int opcao, numero;
    struct No *temp;

    do{

        printf("\n====================================\nEscolha a opcao desejada\n====================================\n");
        printf("\n1 - Inserir no inicio\n2 - Inserir no final\n3 - Imprimir\n4 - Buscar\n5 - Alterar\n6 - Deletar tudo\n7 - Deletar um elemento\n8 - Inserir ordenado\n9 - Finalizar\n");
        printf("====================================\nSua opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\nInsira o elemento que deseja inserir: ");
            scanf("%d", &numero);
            inserirInicio(numero);
            break;
        case 2:
            printf("\nInsira o elemento que deseja inserir: ");
            scanf("%d", &numero);
            inserirFinal(numero);
            break;
        case 3:
            imprimir();
            break;
        case 4:
            printf("\nQual elemento deseja buscar? ");
            scanf("%d", &numero);

            temp = buscar(numero);

            if (temp == NULL){
                printf("\nElemento nao encontrado.");
            }
            else{
                printf("\nO valor %d foi encontrado na posicao %p.", numero, temp);
            }
            break;
        case 5:
            printf("\nInsira o valor a ser subtituido: ");
            scanf("%d", &numero);
            alterar(numero);
            break;
        case 6:
            deletarTudo();
            break;
        case 7:
            printf("\nInsira o elemento a ser deletado: ");
            scanf("%d", &numero);

            deletarUmElemento(numero);
            break;
        case 8:
            printf("\nInsira o elemento que deseja inserir: ");
            scanf("%d", &numero);

            inserirOrdenado(numero);
            break;
        case 9:
            printf("\nFinalizando!");
            break;
        default:
            printf("Opcao invalida! Por favor, tente novamente.");
        }

    }while(opcao != 9);

    return 0;
}
