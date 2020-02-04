/** 
 * @file learn.cpp
 * @author Francisco Javier Bolívar Expósito  y  Samuel Jiménez Piñero
*/

#include <iostream>
#include <cstring>
#include <Bigrama.h>
#include <Idioma.h>
#include <ContadorBigramas.h>

using namespace std;

int main(int argc, char *argv[]) 
{
	string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF"; 
	
	ContadorBigramas cbg(valid), cbgaux(valid);
	Idioma iaux;
	char *salida="out.bgr", *entrada="unknow";
	bool crear= false;
	int cont=2;

	if(strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-a") == 0){

		if(strcmp(argv[1], "-c") == 0){
			crear=true;
		}

		for(int i=cont; i < 5; i++){

			if(strcmp(argv[i], "-f") == 0){

				salida=argv[i+1];
				i++;
				cont += 2;
			}

			if(strcmp(argv[i], "-l") == 0){
					
				entrada=argv[i+1];
				i++;
				cont += 2;
	
			}
		}

		if(crear){

			cbg.calcularFrecuenciasBigramas(argv[cont]);
			
			for(int i=cont+1; i < argc; i++){

				cbgaux.calcularFrecuenciasBigramas(argv[i]);
				cbg += cbgaux;
			}
			
			iaux = cbg.toIdioma();
			iaux.setIdioma(entrada);
			iaux.salvarAFichero(salida);
		
		}else{

			iaux.cargarDeFichero(salida);
			cbg.fromIdioma(iaux);
			
			for(int i= cont; i < argc; i++){
				cbgaux.calcularFrecuenciasBigramas(argv[i]);
				cbg += cbgaux;
			}
			
			iaux = cbg.toIdioma();
			iaux.setIdioma(entrada);
			iaux.salvarAFichero(salida);
		}
	}
	else
	{
		cout << "ERROR: Parámetros introducidos incorrectos.\nSintaxis: learn {-c|-a} [-l nombreIdioma] [-f ficheroSalida] texto1.txt {texto2.txt texto3.txt}";
	}

	return 0;
}