#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//-------------------Struct e alocação de Nó-------------------//

typedef struct No
{
    int chave;
    struct No *prox;
} TNo;

TNo *alocaNo(int k)
{
    TNo *no;
    no = (TNo *)malloc(sizeof(TNo));
    if (no == NULL)
    {
        return NULL;
    }
    no->chave = k;
    no->prox = NULL;
    return no;
}

//-------------------Insere início--------------------//

void insereInicioListaSimples(TNo **p, int k)
{
    assert(p);
    TNo *paux;
    paux = alocaNo(k);
    if (paux == NULL)
    {
        return;
    }
    paux->prox = *p;
    *p = paux;
}

//-------------------Inserir um novo elemento após um elemento definido pelo usuario--------------------//

void insereMeioListaSimples(TNo **prim, int k, int elem)
{
    assert(prim);
    TNo *aux = alocaNo(k), *paux = *prim;
    int i = 0;
    for (i = 1; i <= elem; i++)
    {
        if (paux != NULL)
        {
            if (i == elem)
            {
                aux->prox = paux->prox;
                paux->prox = aux;
            }
            else
            {
                paux = paux->prox;
            }
        }
        else
        {
            printf("Lista muito pequena para essa posicao\n");
            return;
        }
    }
}

//--------------------Remoção de elemento--------------------//

// Início

// Meio

//-------------------Busca de elemento--------------------//

//--------------------Imprime lista---------------------//

void imprimeLista(TNo *lista)
{
    if (lista == NULL)
    {
        printf("Lista Vazia!");
        return;
    }

    while (lista != NULL)
    {
        printf("%d\n", lista->chave);
        lista = lista->prox;
    }
}

//--------------------Função Main-----------------------//

int main()
{
    TNo *prim = NULL;

    insereInicioListaSimples(&prim, 10);
    insereInicioListaSimples(&prim, 5);
    imprimeLista(prim);
    printf("------------\n");
    insereMeioListaSimples(&prim, 2, 1);
    imprimeLista(prim);

    return 0;
}