<h1>AED_2_Trabalho_2</h1>

Apartir do conjunto de dados {10,2,7,5,3,9,16,4,11,1,6,23,14} faça: 1 2 Construa a árvore AVL a partir dos conceitos de inserção apresentados, lembre-se que a cada execução deste procedimento é preciso verificar se a estrutura está balanceada e executar os devidos procedimentos para manter a mesma de acordo com as suas especificações. Efetue a remoção dos seguintes elementos: {10,5,4,11,6}. Como fica a estrutura após cada remoção? Repita os passos acima definidos para o seguinte conjunto de dados: {78,44,67,92,22,110,16,54,23,32,37}.

<h2>Passos para execução</h2>

~~~
make clean

make 

make run
~~~

Depois: <br>

1. Digite os valores na mão!
3. Remova os valores na mão!
4. check o balanceamento que é dado na tela!
5. Adicione os últimos valores na mão!

<h2>Método utilizado para balanceamento!</h2>

1. A  altura  de  uma  árvore  binária    é  o  nível máximo  de  suas  folhas  (profundidade)<br>
2. Uma  árvore  binária  balanceada  (AVL)  é  uma árvore  binária  na  qual  as  alturas  das  duas subárvores  de  todo  nó  nunca  difere  em  mais de  1.<br>
3. O balanceamento  de  um  NÓ    é  definido  como a  altura  de  sua  subárvore  esquerda  menos  a altura  de  sua  subárvore  direita.<br>
4. Cada  nó  numa  árvore  binária balanceada  (AVL)  tem  balanceamento de  1,  -1  ou  0. <br>
5. Se  o  valor  do  balanceamento  do  nó  for diferente  de  1,  -1  e  0.  Essa  árvore  não é    balanceada  (AVL).<br>

Código:

~~~
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

  if( balance == 1 || balance == -1 || balance == 0){
    printf("árvore balanceada!\n");
  } else {
    printf("árvore não balanceada!\n");
  }

}
~~~

<h2>Reflexão sobre a atividade</h2>

A atividade proposta permite que testemos a performace da presente árvore, denominada árvore AVL. Tal árvore permite 
o balanceamento dos valores extremos da árvore, o que é um grande avanço, comparado a árvore normal, visto que a árvore AVL 
diminui o custo computacional de O(n * log n) para O(log n), por causa do balanceamento.

<h2>Custo computacional da Árvore AVL</h2>

<table>
    <tr><td>Algorítimo</td><td>Caso Médio</td><td>Pior caso</td></tr>
    <tr><td>Espaço</td><td>O(n)</td><td>O(n)</td></tr>
    <tr><td>Busca</td><td>O(log n)</td><td>O(log n)</td></tr>
    <tr><td>Inserção</td><td>O(log n)</td><td>O(log n)</td></tr>
    <tr><td>Remoção</td><td>O(log n)</td><td>O(log n)</td></tr>
</table>
