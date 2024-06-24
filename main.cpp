#include <iostream>
#include <string>
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

}