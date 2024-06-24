#include "Trie.h"  

// Constructor Trie
Trie::Trie() {
    root = new TrieNodo;  // Crear el nodo raíz
}

// Destructor Trie
Trie::~Trie() {
    destructorRecursivo(root);  // Llama a la función recursiva
    root = nullptr;  // La raíz pasa a ser un nullptr
}

// Función recursiva para liberar la memoria
void Trie::destructorRecursivo(TrieNodo* nodo) {
    if (nodo != nullptr) {
        // Liberar recursivamente cada hijo
        for (int i = 0; i < 256; i++) {
            if (nodo->hijos[i] != nullptr) {
                TrieNodo* actual = nodo->hijos[i];
                destructorRecursivo(actual);  
                nodo->hijos[i] = nullptr;  
            }
        }
        delete nodo;  // Libera el nodo
    }
}

// Función para insertar una cadena y asociarle un valor
void Trie::insert(string key, int valor) {
    TrieNodo* actual = root;

    // Recorrer cada caracter de la cadena
    for (char c : key) {
        int indice = static_cast<unsigned char>(c);  // Obtener el índice del caracter en el array hijos
        if (actual->hijos[indice] == nullptr) {
            actual->hijos[indice] = new TrieNodo();  // Crear un nuevo nodo si no existe
        }
        actual = actual->hijos[indice];  // Moverse al siguiente nodo
    }

    // Marcar la última hoja como esHoja = true y asignarle el valor
    actual->esHoja = true;
    actual->valor = valor;
}

// Función para buscar el valor asociado a una cadena
int Trie::search(string key) {
    TrieNodo* actual = root;

    // Recorrer cada caracter de la cadena
    for (char c : key) {
        int indice = static_cast<unsigned char>(c);  // Obtener el índice del caracter en el array hijos
        if (actual->hijos[indice] == nullptr) {
            return -1;  // Si no existe el prefijo en el Trie, retornar -1
        }
        actual = actual->hijos[indice];  // Moverse al siguiente nodo
    }

    return actual->valor;  // Retornar el valor asociado al prefijo encontrado
}

// Función para buscar caracteres
string Trie::search_char(int key) {
    return search_char_recursivo(root, key, "");
}

// Función recursiva para buscar caracteres
string Trie::search_char_recursivo(TrieNodo* nodo, int valor, string currentStr) {
    if (nodo == nullptr) {
        return "";  // Si nodo es nullptr, retorna un string vacío
    }
    if (nodo->esHoja && nodo->valor == valor) {
        return currentStr;  // Si se encontró un nodo hoja, retorna el string
    }
    // Se recorren todos los hijos y se hace recursivamente hasta encontrar una hoja
    for (int i = 0; i < 256; i++) {
        if (nodo->hijos[i] != nullptr) {
            string result = search_char_recursivo(nodo->hijos[i], valor, currentStr + char(i));  
            if (!result.empty()) {
                return result;  // Si se encontró la cadena, retornarla
            }
        }
    }
    return "";  // Si no se encontró nada, regresa un string vacio
}