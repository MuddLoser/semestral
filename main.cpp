#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include "huff.cpp"
#include "LempelZiv.h"

using namespace std;

int main(){
	nodo* a;
	string b = "tangananica-tanganana";
	string huffcode = codificar(a, b);
	cout << huffcode << endl;
	
	string c = "11110101101010010110011100011101111101011010100100";
	string huffdecode = decodificar(a,huffcode);
	cout << huffdecode << endl;

	
    LempelZiv* LZW;
    ifstream file;
    file.open("english.50MB");

    string line;
    string texto = "";

    while (getline(file, line)){
        texto+= line;
    }

    file.close();

    // Experimentación

    /*for(int i=0;i<20;i++){

        auto start = chrono::high_resolution_clock::now();
        LZW->Compression(texto);
        auto end = chrono::high_resolution_clock::now();
        double running_time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        running_time *= 1e-9;
        cout<<running_time<<" LZW "<<i<<'\n';

    }
    */

    //Guardar el vector en un archivo Binario

    vector<int> owo = LZW->Compression(texto);
    ofstream resultados("LZWComprimido.bin",ios::binary); 
    size_t size = owo.size();
    resultados.write(reinterpret_cast<const char*>(&size), sizeof(size));
    resultados.write(reinterpret_cast<const char*>(owo.data()), size * sizeof(int));
    resultados.close();
    

    //Pasar el vector de un archivo Binario y descomprimirlo
    
    ifstream leer("LZWComprimido.bin",ios::binary);
    leer.seekg(0,ios::end);
    std::streampos fileSize = leer.tellg();
    leer.seekg(0,ios::beg);

    size_t numInts;
    leer.read(reinterpret_cast<char*>(&numInts), sizeof(numInts));
    std::vector<int> lectura(numInts);
    leer.read(reinterpret_cast<char*>(lectura.data()), numInts * sizeof(int));
    leer.close();

    //cout<<lectura.size()<<'\n';
    //cout<<LZW->Decompression_UnorderedMap(lectura);

}