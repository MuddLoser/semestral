#include "LempelZiv.h"  
#include <sstream>      
#include <unordered_map>  

// Constructor LempelZiv
LempelZiv::LempelZiv() {
}

// Función para la compresión con Lempel-Ziv-Welch
vector<int> LempelZiv::Compression(string key) {
    Trie* arbol = new Trie;  // Crear una instancia de Trie
    string p = "", c = "";   // Strings para almacenar prefijo y sufijo
    int code = 256;          // Código inicial para los nuevos símbolos en el Trie (256 porque se está usando ASCII)
    p += key[0];             // Inicializar el primer prefijo
    vector<int> output;      // Vector para almacenar la salida

    // Inicializar el Trie con los caracteres ASCII
    for (int i = 0; i < 256; i++) {
        string actual = "";
        actual += static_cast<unsigned char>(i);
        arbol->insert(actual, i);
    }

    // Compresión
    for (int i = 0; i < key.length(); i++) {
        if (i != key.length() - 1) {
            c += key[i + 1];  // Agregar el siguiente caracter al sufijo
        }

        string pc = p + c;  // Concatenar prefijo y sufijo actual
        int valor_pc = arbol->search(pc);  // Buscar en el Trie el string de prefijo+sufijo

        if (valor_pc != -1) {
            p = pc;  // Si se encuentra en el Trie, actualizar el prefijo
        } else {
            output.push_back(arbol->search(p));  // Agrega el valor asociado al prefijo a la salida
            arbol->insert(pc, code++);  // Insertar la nueva cadena (prefijo + sufijo) en el Trie con un nuevo código
            p = c;  // Actualizar el prefijo al sufijo actual
        }

        c = "";  // Reiniciar el sufijo
    }

    output.push_back(arbol->search(p));  // Agregar el último valor asociado al último prefijo a la salida
    delete arbol;  // Liberar la memoria del Trie
    return output;  // Devuelve el vector de la compresión
}

// Función para la descompresión con Lempel-Ziv-Welch
string LempelZiv::Decompression(vector<int> key) {
    Trie* arbol = new Trie;  // Crear una instancia de Trie
    int old = key[0], n; //Obtiene el primer valor del vector

    // Inicializar el Trie con los caracteres ASCII
    for (int i = 0; i < 256; i++) {
        string ch = "";
        ch += char(i);
        arbol->insert(ch, i);
    }

    string s = arbol->search_char(old);  // Obtener el string asociado al primer valor del Trie
    string c = "";
    c += s[0];  // Obtener el primer caracter del string
    string decompress = s;  // Se agrega el primer elemento del string original
    int code = 256;  // Inicializar el contador para los nuevos códigos en el Trie

    // Decompresión
    for (int i = 0; i < key.size() - 1; i++) {
        n = key[i + 1];  // Obtener el siguiente código del vector

        string entrada;
        if ((entrada = arbol->search_char(n)).empty()) {  // Si la cadena asociada al código no se encuentra
            s = arbol->search_char(old);  // Obtener string asociado al código anterior
            s = s + c;  // Agregar el primer caracter del string encontrado al resultado
        } else {
            s = entrada;  // Usar la cadena encontrada en el Trie como parte del resultado
        }

        decompress += s;  // Agregar el string a la salida
        c = "";  // Reiniciar el sufijo
        c += s[0];  // Obtener el primer caracter del string
        arbol->insert(arbol->search_char(old) + c, code++);  // Insertar la nueva cadena en el Trie con un nuevo código
        old = n;  // Actualizar el código anterior al código actual
    }

    delete arbol;  // Liberar la memoria del Trie
    return decompress;  // Devolver el string original
}

// Función para la descompresión con Lempel-Ziv-Welch y unordered_map
string LempelZiv::Decompression_UnorderedMap(vector<int> key) {
    unordered_map<int, string> dictionary;  // Crear un unordered_map para almacenar strings y codigos asociados
    int old = key[0], n;

    // Inicializar el unordered_map conlos caracteres ASCII
    for (int i = 0; i < 256; i++) {
        string ch = "";
        ch += char(i); 
        dictionary[i] = ch;  
    }

    string s = dictionary[old];  // Obtener la cadena asociada al primer código en el unordered_map
    string c = "";
    c += s[0];  // Obtener el primer caracter del string
    string decompress = s;  // Se agrega el primer elemento del string original
    int code = 256;  // Inicializar el contador para los nuevos códigos en el Trie

    // Decompresión (Funciona igual que con el Trie, pero implementado con unordered_map)
    for (int i = 0; i < key.size() - 1; i++) {
        n = key[i + 1];  // Obtener el siguiente código del vector

        string entrada;
        if (dictionary.find(n) == dictionary.end()) {
            s = dictionary[old];
            s = s + c;  
        } else {
            s = dictionary[n];
        }

        decompress += s;
        c = ""; 
        c += s[0];  
        dictionary[code++] = dictionary[old] + c;  // Insertar la nueva cadena en el unordered_map con un nuevo código
        old = n;  
    }

    return decompress;  // Devolver la cadena descomprimida
}