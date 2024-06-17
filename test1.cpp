//Aca toy haciendo la PQ
//Creo que funciona pero no estoy seguro

//Falta la codificiacion con el trie

#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 100

class NodoH {
public:
	char letra;
	int cuenta;
	NodoH* izq;
	NodoH* der;
	NodoH(char a, int b){
		letra = a;
		cuenta = b;
		izq = der = NULL;
	}
};

class Compara {
public:
	bool operator()(NodoH* a, NodoH* b){
		return a->cuenta > b->cuenta;
	}
};

NodoH* arbol(priority_queue<NodoH*, vector<NodoH*>, Compara> pq){

	while (pq.size() != 1) {
		NodoH* izq = pq.top();

		pq.pop();

		NodoH* der = pq.top();

		pq.pop();

		NodoH* node = new NodoH('x', izq->cuenta + der->cuenta);
		node->izq = izq;
		node->der = der;

		pq.push(node);
	}

	return pq.top();
}



void printCodes(NodoH* root, int arr[], int top){

	if (root->izq) {
		arr[top] = 0;
		printCodes(root->izq, arr, top + 1);
	}

	if (root->der) {
		arr[top] = 1;
		printCodes(root->der, arr, top + 1);
	}

	if (!root->izq && !root->der) {
		cout << root->letra << " ";
		for (int i = 0; i < top; i++) {
			cout << arr[i];
		}
		cout << endl;
	}
}

int main(){
  priority_queue<NodoH*, vector<NodoH*>, Compara> datos;
	NodoH *nodo;
	int aux;
	char bux;

	//string a = "aaaaabbbbbbbbbccccccccccccdddddddddddddeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffffffffffff";
	string a = "tangananica-tanganana";
  int frec[94] = {0}; 		//cada elemento corresponde a un simbolo ascii de 32 a 126
                      			//ej: el elemento en a[65] cuenta 'a', que en ascii es 97

	for (int i = 0; i<a.size(); i++){
		aux = a[i];
		frec[aux-32] = frec[aux-32] + 1;
	}	

	for (int i = 0; i<a.size(); i++){
		aux = a[i];
		bux = a[i];
		int b = aux-32;
		if(frec[b]!=0){
			nodo = new NodoH(bux,frec[b]);
			frec[b] = 0;
      cout << nodo->letra << ": " << nodo->cuenta << endl;
			datos.push(nodo);
		}
	}

	NodoH* root = arbol(datos);

	int arr[MAX_SIZE], top = 0;
	printCodes(root, arr, top);
	return 0;
}