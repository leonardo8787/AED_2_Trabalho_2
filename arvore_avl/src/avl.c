#include "avl.h"

Tree* CreateTree(){
  return NULL;
}

void insertTree(Tree **t, Record r){

  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq    = NULL; 
    (*t)->dir    = NULL; 
    (*t)->weight = 0;
    (*t)->reg    = r; 

  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree(&(*t)->esq, r);
      if ((getWeight(&(*t)->esq) - getWeight(&(*t)->dir)) == 2){
        if(r.key < (*t)->esq->reg.key)
          rotacaoSimplesDireita(t);
        else
          rotacaoDuplaDireita(t);
      }
    }
    
    if(r.key > (*t)->reg.key){
      insertTree(&(*t)->dir, r);
      if ((getWeight(&(*t)->dir) - getWeight(&(*t)->esq)) == 2){
        if(r.key > (*t)->dir->reg.key)
          rotacaoSimplesEsquerda(t);
        else
          rotacaoDuplaEsquerda(t);
      }
    }
  
  }

  (*t)->weight = getMaxWeight(getWeight(&(*t)->esq), getWeight(&(*t)->dir)) + 1;
}


void pesquisa(Tree **t, Tree **aux, Record r){

  if(*t == NULL){
    printf("[ERROR]: Node not found!");
    return;
  }

  if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r); return;}
  if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r); return;}

  *aux = *t;
}

int isInTree(Tree *t, Record r){
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}


void antecessor(Tree **t, Tree *aux){ 

  if ((*t)->dir != NULL){ 
    antecessor(&(*t)->dir, aux);
    return;
    }
    
    aux->reg = (*t)->reg;
    aux = *t; 
    *t = (*t)->esq;
    free(aux);
} 

void rebalanceTree(Tree **t){
  int balance;
    int left = 0;
    int right = 0;

  balance = getWeight(&(*t)->esq) - getWeight(&(*t)->dir);
  if((*t)->esq)
    left = getWeight(&(*t)->esq->esq) - getWeight(&(*t)->esq->dir);
  if((*t)->dir)
    right = getWeight(&(*t)->dir->esq) - getWeight(&(*t)->dir->dir);

  printf("Item:%d, peso:%d, peso esq:%d, peso dir:%d\n", (*t)->reg.key, balance, left, right);

  if(balance == 2 && left >= 0)
    rotacaoSimplesDireita(t);
  if(balance == 2 && left < 0)
    rotacaoDuplaDireita(t);

  if(balance == -2 && right <= 0)
    rotacaoSimplesEsquerda(t);
  if(balance == -2 && right > 0)
    rotacaoDuplaEsquerda(t);  

  balance = getWeight(&(*t)->esq) - getWeight(&(*t)->dir);
  if( balance == 1 || balance == -1 || balance == 0){
    printf("árvore balanceada!\n");
  } else {
    //preordem(*t);
    printf("árvore não balanceada!\n");
  }

}

void removeTree(Tree **t, Tree **f, Record r){
  Tree *aux;
    
    if (*t == NULL){ 
      printf("[ERROR]: Record not found!!!\n");
      return;
    }

    if (r.key < (*t)->reg.key){ removeTree(&(*t)->esq, t, r); return;}
    if (r.key > (*t)->reg.key){ removeTree(&(*t)->dir, t, r); return;}

    if ((*t)->dir == NULL){ 
      aux = *t;  
      *t = (*t)->esq;
      free(aux);
      rebalanceTree(f);
      return;
    }

    if ((*t)->esq != NULL){ 
      antecessor(&(*t)->esq, *t);
      rebalanceTree(f);
      rebalanceTree(t);
      return;
    }

    aux = *t;  
    *t = (*t)->dir;
    free(aux);
    rebalanceTree(f);
    rebalanceTree(t);   
    
}

void preordem(Tree *t)
{
  if(!(t == NULL)){
    printf("%d:%d\t", t->reg.key, t->weight);
    preordem(t->esq); 
    preordem(t->dir); 
  }
}


void central(Tree *t)
{
  if(!(t == NULL)){
    central(t->esq); 
    printf("%d, ", t->reg.key);
    central(t->dir); 
  }
}

void posordem(Tree *t)
{
  if(!(t == NULL)){
    posordem(t->esq); 
    posordem(t->dir); 
    printf("%d\t", t->reg.key);
  }
}


int getWeight(Tree **t){
  if(*t == NULL)
    return -1;
  return (*t)->weight;
}

int getMaxWeight(int left, int right){
  if(left > right)
    return left;
  return right;
}

void rotacaoSimplesDireita(Tree **t){
  Tree *aux;
  aux = (*t)->esq;
  (*t)->esq = aux->dir;
  aux->dir = (*t);
  (*t)->weight = getMaxWeight(getWeight(&(*t)->esq), getWeight(&(*t)->dir)) + 1;
  aux->weight  = getMaxWeight(getWeight(&aux->esq), (*t)->weight) + 1;
  (*t) = aux;
}

void rotacaoSimplesEsquerda(Tree **t){
  Tree *aux;
  aux = (*t)->dir;
  (*t)->dir = aux->esq;
  aux->esq = (*t);
  (*t)->weight = getMaxWeight(getWeight(&(*t)->esq), getWeight(&(*t)->dir)) + 1;
  aux->weight  = getMaxWeight(getWeight(&aux->esq), (*t)->weight) + 1;
  (*t) = aux;
}

void rotacaoDuplaDireita(Tree **t){
  rotacaoSimplesEsquerda(&(*t)->esq);
  rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(Tree **t){
  rotacaoSimplesDireita(&(*t)->dir);
  rotacaoSimplesEsquerda(t);
}