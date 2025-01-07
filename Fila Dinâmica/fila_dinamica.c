/******************************************************************************
//     filaDinamica.c
// Este programa gerencia filas lineares ligadas (implementacao dinamica).
// As filas gerenciadas podem ter um numero arbitrario de elementos.
// Não usaremos sentinela ou cabeça nesta estrutura.
******************************************************************************/
#include <stdio.h>
#include <malloc.h>
#define ERRO -1
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct aux {
  REGISTRO reg;
  struct aux* prox;
} ELEMENTO, *PONT;;

typedef struct {
  PONT inicio;
  PONT fim;
} FILA;

void inicializarFila(FILA* f) {
  PONT cabeca = (PONT) malloc(sizeof(ELEMENTO)); 
  cabeca->prox = NULL;
  f->inicio = cabeca; 
  f->fim = cabeca;    
}

/* Retornar o tamanho da fila (numero de elementos) */
int tamanho(FILA* f) {
  PONT end = f->inicio;
  int tam = 0;
  while (end != NULL){
    tam++;
    end = end->prox;
  }
  return tam;
} /* tamanho */

/* Retornar o tamanho em bytes da fila. Neste caso, isto depende do numero
   de elementos que estao sendo usados.   */
int tamanhoEmBytes(FILA* f) {
  return (tamanho(f)*sizeof(ELEMENTO)) + sizeof(FILA);
} /* tamanhoEmBytes */

/* Destruição da fila 
   libera a memoria de todos os elementos da fila*/
void destruirFila(FILA* f) {
  PONT end = f->inicio;
  while (end != NULL){
    PONT apagar = end;
    end = end->prox;
    free(apagar);
  }
  f->inicio = NULL;
  f->fim = NULL;
} /* destruirFila */


/* retornarPrimeiro - retorna o endereco do primeiro elemento da fila e (caso
   a fila nao esteja vazia) retorna a chave desse elemento na memoria 
   apontada pelo ponteiro ch */
PONT retornarPrimeiro(FILA* f, TIPOCHAVE *ch){
  if (f->inicio != NULL) *ch = f->inicio->reg.chave;
  return f->inicio;
} /* retornarPrimeiro */

/* retornarUltimo - retorna o endereco do ultimo elemento da fila e (caso
   a fila nao esteja vazia) retorna a chave desse elemento na memoria 
   apontada pelo ponteiro ch */
PONT retornarUltimo(FILA* f, TIPOCHAVE* ch){
  if (f->inicio == NULL) return NULL;
  *ch = f->fim->reg.chave;
  return f->fim;
} /* retornarUltimo */


/* Inserção no fim da fila */
bool inserirNaFila(FILA* f, REGISTRO reg) {
  PONT novo = (PONT) malloc(sizeof(ELEMENTO));
  if (!novo) return false; 
  novo->reg = reg;
  novo->prox = NULL;
  f->fim->prox = novo;
  f->fim = novo;       
  return true;
}

/* Excluir  */
bool excluirDaFila(FILA* f, REGISTRO* reg) {
  if (f->inicio->prox == NULL) return false; 
  PONT apagar = f->inicio->prox;            
  *reg = apagar->reg;                       
  f->inicio->prox = apagar->prox;           
  if (f->fim == apagar) f->fim = f->inicio; 
  free(apagar);                             
  return true;
}


/* Exibição da fila sequencial */
void exibirFila(FILA* f) {
  PONT end = f->inicio->prox; 
  printf("Fila: \" ");
  while (end != NULL) {
    printf("%d ", end->reg.chave);
    end = end->prox;
  }
  printf("\"\n");
}

/* Busca sequencial */
PONT buscaSeq(FILA* f,TIPOCHAVE ch){
  PONT pos = f->inicio;
  while (pos != NULL){
    if (pos->reg.chave == ch) return pos;
    pos = pos->prox;
  }
  return NULL;
} /* buscaSeq */

/* Busca sequencial com sentinela alocado dinamicamente */
PONT buscaSeqSent1(FILA* f,TIPOCHAVE ch){
  if (!f->inicio) return NULL;
  PONT sentinela = malloc(sizeof(ELEMENTO));
  sentinela->reg.chave = ch;
  f->fim->prox = sentinela;
  PONT pos = f->inicio;
  while (pos->reg.chave != ch) pos = pos->prox;
  free(sentinela);
  f->fim->prox = NULL;
  if (pos!=sentinela) return pos;
  return NULL;
} /* buscaSeqSent1 */

/* Busca sequencial com sentinela como variavel local */
PONT buscaSeqSent2(FILA* f,TIPOCHAVE ch){
  if (!f->inicio) return NULL;
  ELEMENTO sentinela;
  sentinela.reg.chave = ch;
  f->fim->prox = &sentinela;
  PONT pos = f->inicio;
  while (pos->reg.chave != ch) pos = pos->prox;
  f->fim->prox = NULL;
  if (pos!=&sentinela) return pos;
  return NULL;
} /* buscaSeqSent1 */