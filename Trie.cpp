#include "Trie.h"

Trie::Trie(){

    root = new TrieNodo;
}

void Trie::insert(string key,int valor){

    TrieNodo* actual = root;

        for (char c : key) {
            int indice = static_cast<unsigned char>(c);
            if (actual->hijos[indice] == nullptr) {
                actual->hijos[indice] = new TrieNodo();
            }
            actual = actual->hijos[indice];
        }

        // Marcar la última hoja como esHoja = true
        actual->esHoja = true;
        actual->valor = valor; // Opcional: asignar el valor completo al nodo hoja
}

int Trie::search(string key){

   TrieNodo* actual = root;

    for (char c : key) {
        int indice = static_cast<unsigned char>(c);
        if (actual->hijos[indice] == nullptr) {
            return -1; // No se encontró la cadena en el trie
        }
        actual = actual->hijos[indice];
    }

    return actual->valor;
}

string Trie::search_char(int key){

    return search_char_recursivo(root,key,"");
}

string Trie::search_char_recursivo(TrieNodo* nodo, int valor, string currentStr){
    if (nodo == nullptr) {
        return "";
    }
    if (nodo->esHoja && nodo->valor == valor) {
        return currentStr;
    }
    for (int i = 0; i < 256; i++) {
        if (nodo->hijos[i] != nullptr) {
            string result = search_char_recursivo(nodo->hijos[i], valor, currentStr + char(i));
            if (!result.empty()) {
                return result;
            }
        }
    }
    return "";
}

