#include <stdio.h>

struct No {
    int dado;
    struct No *prox;
} *inicio = NULL;


int inserirInicio(int valor){
    struct No *novaStruct, *aux = inicio;

    novaStruct = new struct No();
    novaStruct -> dado = valor;

    if (inicio == NULL){
        inicio = novaStruct;
        novaStruct -> prox = inicio;
        return 0;
    }

    while (aux -> prox != inicio){
        aux = aux -> prox;
    }

    aux -> prox = novaStruct;
    novaStruct -> prox = inicio;
    inicio = novaStruct;

    return 0;
}

int inserirFinal(int valor){
    struct No *novaStruct, *aux = inicio;

    novaStruct = new struct No();
    novaStruct -> dado = valor;

    if (inicio == NULL){
        inicio = novaStruct;
        novaStruct -> prox = inicio;
        return 0;
    }

    while (aux -> prox != inicio){
        aux = aux -> prox;
    }

    aux -> prox = novaStruct;
    novaStruct -> prox = inicio;
    return 0;
}

int imprimir(){
    struct No *aux = inicio;

    if (aux == NULL){
        printf("\nLista vazia!");
        return 0;
    }

    while (aux -> prox != inicio){
        printf(" %d ", aux -> dado);

        aux = aux -> prox;
    }

    printf(" %d ", aux -> dado);
    return 0;
}

struct No *buscar(int valor){
    struct No *aux = inicio;

    if (aux == NULL){
        printf("\nLista vazia!");
        return 0;
    }

    while (aux -> prox != inicio){
        if (aux -> dado == valor){
            return aux;
        }

        aux = aux -> prox;
    }

    if (aux -> dado == valor){
        return aux;
    }

    return NULL;
}

int alterar(int valorSubstituido){
    struct No *temp = buscar(valorSubstituido);
    int novoValor;

    if (temp == NULL){
        printf("\nNumero nao encontrado!");
        return 0;
    }

    printf("\nInsira um valor para substituir o numero %d: ", valorSubstituido);
    scanf("%d", &novoValor);

    temp -> dado = novoValor;
    return 0;
}

int deletarUmElemento(int valor){
    struct No *temp = buscar(valor), *aux = inicio;

    if (temp == NULL){
        printf("\nValor nao encontrado!");
        return 0;
    }

    if (inicio == temp && temp -> prox == inicio){
        inicio = NULL;
    }
    else if (inicio == temp){
        while (aux -> prox != inicio){
            aux = aux -> prox;
        }

        inicio = temp -> prox;
        aux -> prox = inicio;
    }
    else{
        while (aux -> prox != temp){
            aux = aux -> prox;
        }

        aux -> prox = temp -> prox;
    }

    delete temp;
    return 0;
}

int deletarTudo(){
    struct No *inicio2 = inicio, *inicioTemporario = inicio;

    if (inicio2 == NULL){
        printf("\nLista vazia!");
        return 0;
    }

    if (inicio2 -> prox == inicio){
        inicio = NULL;
    }
    else{
        inicio2 = inicio2 -> prox;

        while (inicio2 -> prox != inicioTemporario){
            inicio = inicio2 -> prox;
            delete inicio2;
            inicio2 = inicio;
        }

        delete inicioTemporario;
        inicio = NULL;
    }

    delete inicio2;
    return 0;
}

int main(){

     int opcao, numero;
    struct No *temp;

    do{
        printf("\n=========================\nEscolha a opcao desejada\n=========================\n");
        printf("1- Inserir no inicio\n2- Inserir no final\n3- Imprimir\n4- Buscar\n5- Alterar\n6- Deletar um elemento\n7- Deletar lista\n8- Finalizar\n=========================\nSua opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Insira o dado: ");
            scanf("%d", &numero);
            inserirInicio(numero);
            break;
        case 2:
            printf("Insira o dado: ");
            scanf("%d", &numero);

            inserirFinal(numero);
            break;
        case 3:
            imprimir();
            break;
        case 4:
            printf("\nInsira o valor a ser buscado: ");
            scanf("%d", &numero);

            temp = buscar(numero);

            if (temp == NULL){
                printf("\nValor nao encontrado");
            }
            else{
               printf("\nO valor %d foi encontrado na posicao %p", numero, temp);
            }
            break;
        case 5:
            printf("\nInsira o numero a ser substituido: ");
            scanf("%d", &numero);

            alterar(numero);
            break;
        case 6:
            printf("\nInsira o elemento a ser deletado: ");
            scanf("%d", &numero);

            deletarUmElemento(numero);
            break;
        case 7:
            deletarTudo();
            break;
        case 8:
            printf("\nFinalizado!");
            break;
        default:
            printf("\nOpcao invalida!");
        }
    } while (opcao != 8);

    return 0;
}







