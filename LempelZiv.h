#include "Trie.h"  
#include <vector>  

class LempelZiv {
private:

public:
    LempelZiv();  // Constructor
    vector<int> Compression(string key);  // Función para comprimir un string con Lempel-Ziv-Welch
    string Decompression(vector<int> key);  // Función para descomprimir un string con Lempel-Ziv-Welch
    string Decompression_UnorderedMap(vector<int> key);  // Función para descomprimir un string con Lempel-Ziv-Welch implementado con unordered map
};