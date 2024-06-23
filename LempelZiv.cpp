#include "LempelZiv.h"
#include <sstream>
#include <unordered_map>

LempelZiv::LempelZiv(){
}

vector<int> LempelZiv::Compression(string key){

    Trie* arbol = new Trie;
    string p = "", c ="";
    int code = 256;
    p += key[0];
    vector<int> output;

    for(int i=0;i<256;i++){

        string actual = "";
        actual+= static_cast<unsigned char>(i);
        arbol->insert(actual,i);
    }

    for(int i=0; i<key.length();i++){

        if(i!=key.length()-1){

            c+=key[i+1];
        }

        string pc = p+c;
        int valor_pc = arbol->search(pc);

        if(valor_pc != -1){
            p=pc;
        }

        else{

            output.push_back(arbol->search(p));
            arbol->insert(pc,code++);
            p=c;
        }

        c="";    
    }

    output.push_back(arbol->search(p));

    return output;
}

string LempelZiv::Decompression(vector<int> key) {
    
    Trie* arbol = new Trie;
    int old = key[0], n;

    for (int i = 0; i < 256; i++) {
        string ch = "";
        ch += char(i);
        arbol->insert(ch, i);
    }

    string s = arbol->search_char(old);
    string c = "";
    c += s[0];
    string decompress = s;
    int count = 256;

    for (int i = 0; i < key.size() - 1; i++) {
        n = key[i + 1];
        string entrada;
        if ((entrada = arbol->search_char(n)).empty()) {
            s = arbol->search_char(old);
            s = s + c;
        } else {
            s = entrada;
        }
        decompress += s;
        c = "";
        c += s[0];
        arbol->insert(arbol->search_char(old) + c, count);
        count++;
        old = n;

       cout<<i<<'\n';
    }

    return decompress;
}

string LempelZiv::Decompression_UnorderedMap(vector<int> key) {
    
    unordered_map<int, string> dictionary;
    int old = key[0], n;

    for (int i = 0; i < 256; i++) {
        string ch = "";
        ch += char(i);
        dictionary[i] = ch;
    }

    string s = dictionary[old];
    string c = "";
    c += s[0];
    string decompress = s;
    int count = 256;

    for (int i = 0; i < key.size() - 1; i++) {
        n = key[i + 1];
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
        dictionary[count++] = dictionary[old] + c;
        old = n;

        cout<<i<<"\n";
    }

    return decompress;
}