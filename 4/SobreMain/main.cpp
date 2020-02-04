/*
 * File:   main.cpp
 * Author: jakerxd
 *
 * Created on 19 de marzo de 2018, 11:55
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
	cout << "Se han introducido " << argc << " argumentos.";
	for (int i = 0; i < argc; i++)
	{
		cout << "Argumento " << i << ": ";
		cout << argv[i] << endl;
	}
}