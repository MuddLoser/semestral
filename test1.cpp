//Aca toy haciendo la PQ
//Creo que funciona pero no estoy seguro

//Falta la codificiacion con el trie

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct nodo {
public:
	char letra;
	int cuenta;
	nodo* izq;
	nodo* der;
	nodo(char a, int b, nodo* L, nodo* R){
		letra = a;
		cuenta = b;
		izq = L;
		der = R;
	}
};

class Compara {
public:
	bool operator()(nodo* a, nodo* b){
		return a->cuenta > b->cuenta;
	}
};

void cod(nodo* a, string txt, unordered_map<char, string> &Huff) {
    if (a == nullptr) return;

    if (!a->izq && !a->der)  Huff[a->letra] = txt;

    cod(a->izq, txt + "0", Huff);
    cod(a->der, txt + "1", Huff);
}

string coding(nodo* &a, string txt) {
    unordered_map<char, int> frec;
    priority_queue<nodo*, vector<nodo*>, Compara> pq;
	nodo* aux;

	for(int i = 0; i<txt.size(); i++){
		char ch = txt[i];
        frec[ch]++;
    }

    for (pair<char, int> par : frec) {
		aux = new nodo(par.first, par.second, nullptr, nullptr);
        pq.push(aux);
    }

    while (pq.size() != 1) {
        nodo* izq = pq.top(); 
		pq.pop();
        nodo* der = pq.top(); 
		pq.pop();

        int suma = izq->cuenta + der->cuenta;
		aux = new nodo('\0', suma, izq, der);
        pq.push(aux);
    }

    a = pq.top();
    unordered_map<char, string> Huff;
    cod(a, "", Huff);

    string coded = "";
    for(int i = 0; i<txt.size(); i++){
		char ch = txt[i];
        coded = coded + Huff[ch];
    }

    return coded;
}

string decoding(nodo* a, string txt){
	string out;
	nodo *temp = a;

	for(int i = 0; i<txt.size(); i++){
		char ch = txt[i];
        if (ch == '0') temp = temp->izq;
        else 		   temp = temp->der;
        if (!temp->izq && !temp->der) {
            out = out + temp->letra;
            temp = a;
        }
    }
    return out;
}


int main(){
	nodo* a;
	string b = "tangananica-tanganana";
	string huffcode = coding(a, b);
	cout << huffcode << endl;
	
	string c = "11110101101010010110011100011101111101011010100100";
	string huffdecode = decoding(a,huffcode);
	cout << huffdecode << endl;

}