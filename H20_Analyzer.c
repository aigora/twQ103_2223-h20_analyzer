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
	char parametros[PARAMETROS];
	float ph;
	int conductividad;
	int turbidez;
	int coliformes;
};

struct Tfichero{
	int anio;
	int mes;
	char lugar[PARAMETROS];
};

float media(struct Tdatos datos[], int numDatos);

float desviacion_tipica(struct Tdatos datos[], float media, int numDatos);

void crearFicheroDatos();

int main(){
	struct Tdatos datos[TAM_Datos];
	int opcion, dato, numDatos, dato2, i;
	float medias, desviacion_tipica;
	
	FILE *fichero;
	FILE *fsalida;
	
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
			  	printf("Seleccione los datos a tratar:\n 1) El  pH\n 2) La conductividad\n 3) La turbidez\n 4) Los coliformes\n"); 
				scanf("%d", &dato); 
				}while (dato<1 || dato>4); 
						
					switch(dato){
						case 1: do{
							printf("Para el pH seleccione la opcion que quiera realizar:\n 1) Realizar media\n 2) Realizar desviacion tipica\n");
							scanf("%d", &dato2);
							}while (dato2<1 || dato2>2);
								switch(dato2){
									case 1: 
										media = media(datos[numDatos].ph, numDatos);
										printf("La media es: %.2f", media);
									break;
										
									case 2:
										desviacion_tipica = desviacion_tipica(datos[numDatos].ph, media, numDatos);
										printf("La deviacion tipica es: %.2f", desviacion_tipica);
									break;
							 	}
		
						case 2: do{
							printf("Para la conductividad seleccione la opcion que quiera realizar:\n 1) Realizar media\n 2) Realizar desviacion tipica\n");
							scanf("%d", &dato2);
							}while (dato2<1 || dato2>2);
								switch(dato2){
									case 1:
										media=media(datos[TAM_Datos].conductividad, numDatos);
										printf("La media es %.2f", media);
									break;
										
									case 2:
										desviacion_tipica = desviacion_tipica(datos[TAM_Datos].conductividad, media, numDatos);
										printf("La deviacion tipica es: %.2f", desviacion_tipica);
									break;	
								}
							
						case 3: do{
							printf("Para la turbidez seleccione la opcion que quiera realizar:\n 1) Realizar media\n 2) Realizar desviacion tipica\n");
							scanf("%d", &dato2);
							}while (dato2<1 || dato2>2);
								switch(dato2){
									case 1:
										media=media(datos[TAM_Datos].turbidez, numDatos);
										printf("La media es: %.2f", media);
									break;
										
									case 2:
										desviacion_tipica=desviacion_tipica(datos[TAM_Datos].turbidez, media, numDatos);
										printf("La deviacion tipica es: %.2f", desviacion_tipica);
									break;	
								}
							
					        case 4: do{
							printf("Para los coliformes seleccione la opcion que quiera realizar:\n 1) Realizar media\n 2) Realizar desviacion tipica\n");
							scanf("%d", &dato2);
							}while (dato2<1 || dato2>2);
								switch(dato2){
									case 1:
										media=media(datos[TAM_Datos].coliformes, numDatos);
										printf("La media es: %.2f", media);
									break;
											
									case 2:
										desviacion_tipica=desviacion_tipica(datos[TAM_Datos].coliformes, media, numDatos);
										printf("La deviacion tipica es: %.2f", desviacion_tipica);
									break;
								}
							
					}	
			break;
						 
        	case 2 : 
					crearFicheroDatos();
                    break;
                       
            case 3 : printf("______Hasta la proxima_____\n");
                    return 0;
            default : printf("Opcion desconocida\n");
    }


	
return 0;
}

   
float media(struct Tdatos datos[], int numDatos){
	
	float suma=0; 
	float media = 0;
	int i;
	
	
	for(i = 0; i < numDatos; i++){
		suma += datos[i];
	}	
	
	media = (float)(suma / numDatos);
	
	return media;
}

float desviacion_tipica(struct Tdatos datos[], float media, int numDatos){

	float suma = 0;
	int i;
	float desviacion_tipica = 0;
	
	for(i = 0; i < numDatos; i++){
		suma += (float)((pow(datos[i] - media,2));
	}	
	
	desviacion_tipica = (float)((pow(suma/(numDatos*(numDatos-1)) ,1/2));
	
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


