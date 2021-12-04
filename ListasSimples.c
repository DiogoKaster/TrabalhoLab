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
Essa função envolve um pouco mais de complexidade, ela recebe os mesmos dados de parametro da insereInicio, porém com um a mais, a posição do elemento
que o usuário quer inserir depois, com essa informação ela faz a mesma verificação com assert e cria um ponteiro auxiliar para receber o retorno
da função de alocação, e outro ponteiro auxiliar para podermos percorrer a lista ja existente. Criamos um laço for, para percorrer a lista
até a posição desejada, caso ele encontre a posição desejada antes de chegar ao fim da lista, ele define o proximo do meu novo nó, como o proximo da
minha posição atual, e define o proximo da minha posição atual, como o novo nó, inserindo assim, após o nó desejado. Caso ele chegue ao fim da lista
e não encontre a posição desejada, ele dirá que a lista é pequena demais para o valor desejado.
*/

//--------------------Remoção de elemento--------------------//

// Início

// Meio

void removeMeio(TNo **lista, int pos)
{
    TNo *aux = *lista;

    for (int i = 1; i <= pos - 1; i++)
    {
        if (aux != NULL)
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
        else
        {
            printf("Posição inválida, ou muito grande para a lista atual!\n");
            break;
        }
    }
}
/*
Essa função de remoção no meio recebe como parametros, o ponteiro de ponteiro para o primeiro nó da lista, e a posição desejada a ser removida,
a principio ela cria um nó auxiliar que recebe o primeiro da lista, após isso, cria um laço for que percorre a lista até a posição anterior a desejada
caso ele encontre essa posição na lista, ele verifica se está na posição desejada e cria um nó auxiliar que recebe o proximo do nó atual, e faz com que o 
proximo do atual nó, seja o próximo do proximo (que foi guardado no ponteiro auxiliar), após isso libera a memória do nó desejado. Caso ele não encontre
essa posição na lista, imprime uma mensagem de erro e para o laço de repetição.
*/

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
/*
Essa função recebe como parametro o ponteiro do primeiro nó da lista, caso a lista esteja vazia, ele imprime "Lista vazia!" e para a execução,
caso não, ele inicia um while que percorre a lista até que ela seja nula, e imprime a chave de cada nó.
*/

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