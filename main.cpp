#include <iostream>
#include <string>

using namespace std;

struct PQnodo{
  public:
    char letra;
    int cuenta;
    PQnodo* izq;
    PQnodo* der;
    PQnodo* padre;  
    PQnodo(char a, int b){
      letra = a;
      cuenta = b;
      izq = der = NULL;
    }
};

class PQ{
  public:
  PQnodo arr[45];
};

int main(){
  string a = "tangananica-tanganana";
  for(int i = 0; i<a.length(); i++){
    cout << a[i] << " ";
  }
}
