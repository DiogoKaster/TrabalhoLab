#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

TNo *criaNoCabeca()
{
  TNo *cabeca = alocaNo(-1);
  if (cabeca == NULL)
  {
    return NULL;
  }
  return cabeca;
}

void *insereInicio(TNo *lista, int k)
{
  TNo *novoNo = alocaNo(k);
  if (novoNo == NULL)
  {
    return;
  }
  else
  {
    novoNo->prox = lista->prox;
    lista->prox = novoNo;
  }
}

void insereMeioListaCabeca(TNo *prim, int k, int elem)
{
  assert(prim);
  TNo *aux = alocaNo(k), *paux = prim;
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
TNo *buscaNo(TNo *lista, int chave)
{
  TNo *aux = lista;
  while (aux != NULL)
  {
    if (aux->chave == chave)
    {
      return aux;
    }
    aux = aux->prox;
  }
  return NULL;
}
void removeInicio(TNo *lista)
{
  assert(lista);
  TNo *aux = lista->prox;
  if (lista == NULL)
  {
    return;
  }
  else
  {
    lista->prox = aux->prox;
    free(aux);
  }
}
void removeMeio(TNo *lista, int pos)
{
  TNo *aux = lista->prox;

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
void imprimeLista(TNo *lista)
{
  while (lista != NULL)
  {
    printf("%d\n", lista->chave);
    lista = lista->prox;
  }
}

int main()
{
  TNo *primCabeca = criaNoCabeca();
  insereInicio(primCabeca, 1);
  insereInicio(primCabeca, 2);
  insereInicio(primCabeca, 3);
  imprimeLista(primCabeca->prox);
  printf("-------------------\n");
  insereMeioListaCabeca(primCabeca->prox, 5, 2);
  removeInicio(primCabeca);
  imprimeLista(primCabeca->prox);
  removeMeio(primCabeca, 2);
  printf("-------------------\n");
  imprimeLista(primCabeca->prox);
  TNo *recebeBusca = buscaNo(primCabeca, 5);
  if (recebeBusca != NULL)
  {
    printf("chave: %d\n", recebeBusca->chave);
  }
  else
  {
    printf("Nó não encontrado.\n");
  }
  return 0;
}