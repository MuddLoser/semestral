//Aca toy haciendo la PQ
//Da segmentation fault por ahora


#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class PQnodo{
  public:
    string letra;
    int cuenta;

    PQnodo(string a, int b){
      letra = a;
      cuenta = b;
    }
};

class PQheap{
    public:
		PQnodo H[50];
		int tam = -1;

    int parent(int i){ return (i - 1) / 2;}

    int left(int i){ return ((2 * i) + 1); }

    int right(int i){ return ((2 * i) + 2); }

    void upheap(int i){
        while (i > 0 && H[parent(i)].cuenta < H[i].cuenta) {
            PQnodo aux = H[parent(i)];
            H[parent(i)] = H[i];
            H[i] = aux;

            i = parent(i);
        }
    }

    void downheap(int i){
        int maxIndex = i;

        int l = left(i);

        if (l <= tam && H[l].cuenta > H[maxIndex].cuenta) { maxIndex = l; }

        int r = right(i);

        if (r <= tam && H[r].cuenta > H[maxIndex].cuenta) { maxIndex = r; }

        if (i != maxIndex) {
            swap(H[i], H[maxIndex]);
            downheap(maxIndex);
        }
    }

    void insert(int p){
      string A = "T";
      PQnodo *aux = new PQnodo(A,p);

      tam = tam + 1;
      H[tam] = *aux;

      upheap(tam);
    }

    int extractMax(){
        int result = H[0].cuenta;

        H[0] = H[tam];
        tam = tam - 1;

        downheap(0);
        return result;
    }

    
    int getMax(){ return H[0].cuenta; }

    void remove(int i){
        H[i].cuenta = getMax() + 1;

        upheap(i);

        extractMax();
    }

};

int main(){

  /*         45
          /      \
          31      14
        /  \    /  \
        13  20  7   11
      /  \
      12   7
  Create a priority queue shown in 
  example in a binary max heap form.
  Queue will be represented in the
  form of array as:
  45 31 14 13 20 7 11 12 7 */

  // Insert the element to the
  // priority queue
  cout << "Hola" << endl;
  PQheap *pq;
  cout << "Hola" << endl;
  pq->insert(45);
  pq->insert(20);
  pq->insert(14);
  pq->insert(12);
  pq->insert(31);
  pq->insert(7);
  pq->insert(11);
  pq->insert(13);
  pq->insert(7);

  int i = 0;

  // Priority queue before extracting max
  cout << "Priority Queue : ";
  while (i <= pq->tam) {
    cout << pq->H[i].cuenta << " ";
    i++;
  }

  cout << "\n";

  // Node with maximum priority
  cout << "Node with maximum priority : " << pq->extractMax() << "\n";

  // Priority queue after extracting max
  cout << "Priority queue after extracting maximum : ";
  int j = 0;
  while (j <= pq->tam) { 
  cout << pq->H[j].cuenta << " ";
  j++;
  }

  cout << "\n";

  // Remove element at index 3
  pq->remove(3);
  cout << "Priority queue after removing the element : ";
  int l = 0;
  while (l <= pq->tam) {
      cout << pq->H[l].cuenta << " ";
      l++;
  }
  return 0;
}