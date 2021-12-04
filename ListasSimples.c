#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//-------------------Struct e alocação de Nó-------------------//
/**/
typedef struct No
{
    int chave;
    struct No *prox;
} TNo;
/*
Essa struct será usada de base para comparação com as próximas funções, ela contem um elemento de dado que é a chave, e um ponteiro
com o mesmo tipo da struct que está sendo criada, apontando para o proximo nó.
*/
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

/*
A função que aloca um novo nó, a função dela é receber a chave do novo nó como parametro e criar uma alocação dinamica para esse
novo nó, após isso ela verifica se a alocação foi realizada, em caso de erro, retorna nulo, em caso de sucesso, atribui a chave ao novo
nó, e nulo ao ponteiro próximo, após isso, retorna esse novo nó criado. Essa função será chamada nas funções de inserção.
*/

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
/*
Essa função de inserção no inicio, recebe como parametros, o ponteiro de ponteiro para o endereço do primeiro nó da lista e a chave do novo nó
a ser criado, ela usa a função assert da lib assert.h para verificar se esse endereço existe e é valido, caso não seja, ela para a execução do
codio, caso seja, a função cria um ponteiro auxiliar do tipo Tno, que vai receber o retorno da função de alocação, após isso ele verifica o retorno
para saber se houve sucesso, caso não tenha, ele para a execução da FUNÇÃO, caso haja sucesso, ele define o ponteiro proximo desse novo ponteiro
como o atual primeiro da lista, e coloca o primeiro da lista, como o ponteiro que acabou de ser criado, assim inserindo ele no inicio
*/

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
/*

*/

//--------------------Remoção de elemento--------------------//

// Início

// Meio

void removeMeio(TNo **lista, int pos)
{
    TNo *aux = *lista;

    for (int i = 1; i <= pos - 1; i++)
    {
        if (i == pos - 1)
        {
            TNo *p = aux->prox;
            aux->prox = p->prox;

            free(p);
            p = NULL;
        }
        aux = aux->prox;
    }
}

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
    removeMeio(&prim, 2);
    printf("------------\n");
    imprimeLista(prim);
    return 0;
}