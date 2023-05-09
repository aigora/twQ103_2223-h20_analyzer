#include <stdio.h>
#define PARAMETROS 50
#define TAM_Datos 100

struct Tdatos {
	char parametros[50];
	float ph;
	int conductividad;
	int turbidez;
	int coliformes;
};

//Funciones para comparar datos
float CompPH(float,float);

int CompConduct(int, int);

int CompTurb(int, int);

int CompColif(int, int);

int main(){
	
	struct Tdatos datos[TAM_Datos];
	
	//Abrir el archivo
	FILE *fichero;
	fichero = fopen("202301_Lavapies.csv", "r");
	
	//Comprobar que abre
	if (fichero == NULL){
		printf("Error no se puede abrir el fichero. \n");
		return 0;
	}
	
	//Cerramos el fichero
	fclose(fichero);
}
