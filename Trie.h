#include <iostream>
#include <string>

using namespace std;

struct TrieNodo{

    TrieNodo** hijos = new TrieNodo*[256];
    bool esHoja;
    int valor;

    TrieNodo(){

        esHoja = false;
        valor = -1;

        for(int i=0; i<256;i++){

            hijos[i] = NULL;
        }
    }

    int getValor(){
        return valor;
    }
};

class Trie {
    
    public:
        TrieNodo* root;

    public:

        Trie();
        void insert(string key,int valor);
        int search(string key);
        string search_char(int key);
        string search_char_recursivo(TrieNodo* nodo, int valor, string currentStr);
};