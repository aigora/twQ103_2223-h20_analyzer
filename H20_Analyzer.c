#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define PARAMETROS 50
#define TAM_Datos 100

struct Tdatos{
	std::string parametros;
	float ph;
	int conductividad;
	int turbidez;
	int coliformes;
};

struct Tfichero{
	int anio;
	int mes;
	std::string lugar;
};

void media(float Tdatos datos[], int numDatos);

void desviacion_tipica(float Tdatos datos[], int media, int numDatos);

void crearFicheroDatos();

int main(){
	
	int opcion, dato, numDatos;
	float media, desviacion_tipica;
	
	FILE *fichero;
	
	fichero = fopen("202301_Lavapies.txt", "r");
	
	if(fichero == NULL) {
		printf("Error, no se puede abrir el fichero.\n");
		return 0;
	}	
	
	printf("Bienvenido al menu de opciones de H20_ANALYZER \n");
	printf("Escoja una de las siguientes opciones:\n");
	printf("1): Calculos estadisticos\n 2): Crear fichero de datos\n 3): Salir \n");
	scanf("%d", &opcion);
	
  	switch(opcion){
                case 1: do{
			   printf("Seleccione los datos a tratar:\n 1)El  pH\n 2) La conductividad\n 3) La turbidez\n 4) Los coliformes\n"); 
			   scanf("%d", &dato); 
			}while (dato<1 || dato>4); 
						
					switch(dato){
						case 1: printf("Para el pH:\n");
							media=media(float Tdatos datos[].ph, int numDatos);
							printf("La media es: %.2f", media);
							desviacion_tipica=desviacion_tipica(float Tdatos datos[].ph, media, int numDatos);
							printf("La deviacion tipica es: %.2f", desviacion_tipica);
							break;
							
						case 2: printf("Para la conductividad:\n");
							media=media(float Tdatos datos[].conductividad, int numDatos);
							printf("La media es %.2f", media);
							desviacion_tipica=desviacion_tipica(float Tdatos datos[].conductividad, media, int numDatos);
							printf("La deviacion tipica es: %.2f", desviacion_tipica);
							break;	
							
						case 3: printf("Para la turbidez:\n");
							media=media(float Tdatos datos[].turbidez, int numDatos);
							printf("La media es: %.2f", media);
							desviacion_tipica=desviacion_tipica(float Tdatos datos[].turbidez, media, int numDatos);
							printf("La deviacion tipica es: %.2f", desviacion_tipica);
							break;	
							
					        case 4: printf("Para los coliformes:\n");
							media=media(float Tdatos datos[].coliformes, int numDatos);
							printf("La media es: %.2f", media);
							desviacion_tipica=desviacion_tipica(float Tdatos datos[].coliformes, media, int numDatos);
							printf("La deviacion tipica es: %.2f", desviacion_tipica);
							break;
							
					}	
			break;
						 
                 case 2 : crearFicheroDatos();
                        break;
                       
                 case 3 : printf("______Hasta la proxima_____\n");
                         return 0;
                 default : printf("Opcion desconocida\n");
    }


	
return 0;
}

   
void media(float Tdatos datos[], int numDatos){
	int suma = 0, i; 
	float media = 0;
	for(i = 0; i < numDatos; i++){
		suma += datos[i];
	}	
	
	media = suma / numDatos;
	return media;
}

void desviacion_tipica(float Tdatos datos[], media, int numDatos){
	int suma = 0, i;
	float desviacion_tipica = 0;
	for(i = 0; i < numDatos; i++){
		suma += pow(datos[i] - media,2);
	}	
	
	desviacion_tipica = pow(suma/(numDatos*(numDatos-1)) ,1/2);
	return desviacion_tipica;
}

void crearFicheroDatos(){
	char nomArchivo[50];
	struct Tdatos datos[TAM_Datos];
	struct Tfichero nomFichero;
	FILE *datosin;
	FILE *datosout;
	int i,j,n;
	
	printf("INDIQUE A CONTINUACION LOS DATOS DEL FICHERO \n");
        printf("Introduzca los cuatro numeros del anio del estudio:\n");
	scanf("%d", &nomFichero.anio);

	printf("Introduzca el mes (01-12):\n");
	scanf("%d", &nomFichero.mes);

	printf("Introduzca el nombre del lugar en minusculas empezando con mayuscula:\n");
	scanf("%s", &nomFichero.lugar);
	
	sprintf(nomArchivo, "%d%d_%s.txt",nomFichero.anio,nomFichero.mes,nomFichero.lugar);

	datosin= fopen(nomArchivo,"w");
	
	if (datosin== NULL){
	   printf("\nERROR AL ABRIR EL ARCHIVO\n");
	   return 1;
	}
	
	else  printf("\nArchivo creado con exito\n");
	
	printf("Introduzca el numero de fuentes de su estudio:\n");
	scanf("%d", &n);
	fprintf(datosin,"Parametros\t\tpH\t\tConductividad\t\tTurbidez\t\tColiformes\n");
	
	for(i=0;i<n;i++){
		printf("introduzca el PH de la fuente%d\n",i+1);
		scanf("%f",&datos[i].ph);
		printf("Introduzca la conductividad %d\n",i+1);
		scanf("%d",&datos[i].conductividad);
		printf("Introduzca la turbidez%d\n",i+1);
		scanf("%d",&datos[i].turbidez);
		printf("Introduzca los coliformes%d\n",i+1);
		scanf("%d",&datos[i].coliformes);
		fprintf(datosin,"fuente_%d\t\t%f\t\t%d\t\t%d\t\t%d\n",i+1,datos[i].ph,datos[i].conductividad,datos[i].turbidez,datos[i].coliformes);
		}
	fclose(datosin);
}	



