#include <iostream>

#include <assert.h>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

	int pos = 3;
	string ola = "Hola";
	
	for (pos; pos < 10; pos++)
		cout << pos;
	
	for (pos; pos < 20; pos++)
		cout << pos;
	
	cout << ola;
	
	return 0;
}