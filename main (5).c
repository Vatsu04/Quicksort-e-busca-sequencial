#include <stdio.h>
// Complete o programa - 
// dado determinado vetor - procure um elemento x
// o elemento x digitado pelo usuário
// busca sequencial
// "número não encontrado".
// refazer o programa utilizando a busca binário recursiva
// atenção ordenar o vetor antes de chamar a função recursiva 

int search(int vet[], int tam, int x) {
    int i;
    for (i = 0; i < tam; i++) {
        if (vet[i] == x) {
            return i;
        }
    }
    return -1;
}


int particiona(int vet[], int inicio, int fim) {  // Essa é a função que decide qual será o pivo,  usamos a regra do "median of three", basicamente o que acontece é que o programa analisa o primeiro elemento do vetay, o centro, e o último elemento e escolhe o que está mais peto da 
  int esq, dir, pivo, troca; 
  esq = inicio + 1; // esq = esquerda
  dir = fim; // dir = direita 
  pivo = vet[inicio];
  while (esq <= dir) {
    while (esq <= dir && vet[esq] <= pivo) {
      esq++;
    }
    while (dir > inicio && vet[dir] > pivo) {
      dir--;
    }
    if (esq < dir) {
      troca = vet[esq];
      vet[esq] = vet[dir];
      vet[dir] = troca;
    }
  }
  vet[inicio] = vet[dir];
  vet[dir] = pivo;
  return dir;
}
void quicksort(int vet[], int inicio, int fim) {
  int pivo;
  if (inicio < fim) {
    pivo = particiona(vet, inicio, fim);
    quicksort(vet, inicio, pivo - 1);
    quicksort(vet, pivo + 1, fim);
  }
}

int main(void) {
  int vet[] = {25, 40, 55, 20, 44, 35, 38, 99, 10, 65, 50};
  int tam = sizeof(vet) / sizeof(int);
  int x = 0; 
	printf("Por qual número você gostaria de checar pela existência?");
		scanf("%i", &x);
quicksort(vet, 0, tam -1);
 int result = search(vet, tam, x);
    if (result == -1) {
        printf("Elemento não encontrado no array.\n");
    } else {
        printf("Elemento encontrado na posição %d do array.\n", result);
    }
	
}
