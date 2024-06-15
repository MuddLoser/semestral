//Aca toy haciendo la PQ

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

int H[50];
int MAX_SIZE = 100;

class PQnodo{
  public:
    char letra;
    int cuenta;
    PQnodo* izq;
    PQnodo* der;
    PQnodo* padre;  
    PQnodo(char a, int b){
      letra = a;
      cuenta = b;
      izq = der = NULL;
    }
};

// Custom comparator class
class Compare {
public:
	bool operator()(PQnodo* a,
					PQnodo* b)
	{
		// derining priority on
		// the basis of cuentauency
		return a->cuenta > b->cuenta;
	}
};

// Function to generate Huffman
// Encoding Tree
PQnodo* generateTree(priority_queue<PQnodo*,
							vector<PQnodo*>,
											Compare> pq)
{

	// We keep on looping till
	// only one node remains in
	// the Priority Queue
	while (pq.size() != 1) {

		// Node which has least
		// cuentauency
		PQnodo* izq = pq.top();

		// Remove node from
		// Priority Queue
		pq.pop();

		// Node which has least
		// cuentauency
		PQnodo* der = pq.top();

		// Remove node from
		// Priority Queue
		pq.pop();

		// A new node is formed
		// with cuentauency izq->cuenta
		// + der->cuenta

		// We take data as '$'
		// because we are only
		// concerned with the
		// cuentauency
		PQnodo* node = new PQnodo('$',
								izq->cuenta + der->cuenta);
		node->izq = izq;
		node->der = der;

		// Push back node
		// created to the
		// Priority Queue
		pq.push(node);
	}

	return pq.top();
}

// Function to print the
// huffman code for each
// character.

// It uses arr to store the codes
void printCodes(PQnodo* root,
				int arr[], int top)
{
	// Assign 0 to the izq node
	// and recur
	if (root->izq) {
		arr[top] = 0;
		printCodes(root->izq,
				arr, top + 1);
	}

	// Assign 1 to the der
	// node and recur
	if (root->der) {
		arr[top] = 1;
		printCodes(root->der, arr, top + 1);
	}

	// If this is a leaf node,
	// then we print root->data

	// We also print the code
	// for this character from arr
	if (!root->izq && !root->der) {
		cout << root->letra << " ";
		for (int i = 0; i < top; i++) {
			cout << arr[i];
		}
		cout << endl;
	}
}

void HuffmanCodes(char data[],
				int cuenta[], int size)
{

	// Declaring priority queue
	// using custom comparator
	priority_queue<PQnodo*,
				vector<PQnodo*>,
				Compare>
		pq;

	// Populating the priority
	// queue
	for (int i = 0; i < size; i++) {
		PQnodo* newNode
			= new PQnodo(data[i], cuenta[i]);
		pq.push(newNode);
	}

	// Generate Huffman Encoding
	// Tree and get the root node
	PQnodo* root = generateTree(pq);

	// Print Huffman Codes
	int arr[MAX_SIZE], top = 0;
	printCodes(root, arr, top);
}

// Driver Code
int main()
{
	char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int cuenta[] = { 5, 9, 12, 13, 16, 45 };
	int size = sizeof(data) / sizeof(data[0]);

	HuffmanCodes(data, cuenta, size);
	return 0;
}
