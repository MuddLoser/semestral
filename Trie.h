#include <iostream>
#include <string>

using namespace std;

// Struct para los nodos del Trie
struct TrieNodo {
    TrieNodo** hijos = new TrieNodo*[256];  // Array de punteros a TrieNodo para los 256 caracteres ASCII
    bool esHoja;  // Bool para saber si es hoja
    int valor;    // Valor asociado al nodo (por defecto -1)

    // Constructor del nodo
    TrieNodo() {
        esHoja = false;
        valor = -1;

        // Inicializa los hijos a NULL
        for (int i = 0; i < 256; i++) {
            hijos[i] = NULL;
        }
    }

    // Destructor del nodo
    ~TrieNodo() {
        for (int i = 0; i < 256; i++) {
            delete hijos[i];
        }
        delete[] hijos;
    }
};

class Trie {
    private:
        TrieNodo* root;  // Puntero al nodo raíz

    public:
        //Constructor 
        Trie();
        // Destructor      
        ~Trie();
        // Función recursiva para destruir el Trie
        void destructorRecursivo(TrieNodo* nodo);
        // Función para insertar un string y asociarle un valor
        void insert(string key, int valor);
        // Función para buscar el valor asociado a una cadena
        int search(string key);
        // Función para buscar caracteres específicos
        string search_char(int key);
        // Función recursiva para buscar caracteres
        string search_char_recursivo(TrieNodo* nodo, int key, string currentStr);
};
