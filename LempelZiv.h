#include "Trie.h"
#include <vector>

class LempelZiv{

    private:


    public:
        LempelZiv();
        vector<int> Compression(string key);
        string Decompression(vector<int> key);
        string Decompression_UnorderedMap(vector<int> key);

};