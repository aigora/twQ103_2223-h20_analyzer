#include <stdio.h>
#define PARAMETROS 100
#define TAM_DATOS 100

//Estructura de datos 

struct Tdatos {
    char parametros[PARAMETROS];
	float ph;    
    int conductividad;
    int turbidez;
    int coliformes;
};

//Estructura del nuevo fichero

struct Tfichero {
    int anio;
    int mes;
    char lugar[PARAMETROS];
};


//Funciones:

float calcular_media_ph(struct Tdatos datos[], int N);
float calcular_media_cond(struct Tdatos datos[], int N);
float calcular_media_turb(struct Tdatos datos[], int N);
float calcular_media_colif(struct Tdatos datos[], int N);


float calcular_desv_ph(struct Tdatos datos[], float media, int N);
float calcular_desv_cond(struct Tdatos datos[], float media, int N);
float calcular_desv_turb(struct Tdatos datos[], float media, int N);
float calcular_desv_colif(struct Tdatos datos[], float media, int N);


void obtener_mayor_menor_parametros();
void crearFicheroDatos();
void pulstarContinuar();



int main() {
	struct Tdatos datos[TAM_DATOS];
	char nombre[50],cabecera[PARAMETROS] ;
	int opcion, dato, dato2, i, numDatos, numRegistros;
	float media_val_ph, media_val_cond, media_val_turb, media_val_colif, p4;
	float desviacion_tipica_val_ph, desviacion_tipica_val_cond, desviacion_tipica_val_turb, desviacion_tipica_val_colif;
	
	FILE *fentrada;
	
    //Menu de opciones 
     
	 do {
	    printf("____Bienvenido al menu de opciones de H20_ANALYZER____\n\n\n");
	    printf("Escoja una de las siguientes opciones introduciendo el numero:\n");
	    printf("1-Calculos estadisticos\n2-Comparar parametros\n3-Crear fichero de datos\n4-Salir\n\n");
	    scanf("%d", &opcion);
		
		 switch (opcion) {
	        case 1:
	        		fflush(stdin);
	        		system("cls");
	        		printf("\nIntroduce el nombre del fichero incluyendo el txt:\n");
					gets(nombre);
					
					fentrada = fopen(nombre, "rb");
				
				    if (fentrada == NULL) {
				        printf("Error, no se puede abrir el fichero.\n");
				        return 0;
				    }
				    
				    // Leer y descartar la cabecera
				    
				    i=0;
				
	    			fscanf(fentrada, "%[^\n]%*c", cabecera);			
	    			
			    	while (fscanf(fentrada, "%s %f %d %d %d", datos[i].parametros, &datos[i].ph, &datos[i].conductividad, &datos[i].turbidez, &datos[i].coliformes) != EOF) {		 
					  		    	    		
			    		i++;
					}
					
					// obtenemos el numero de registros leidos del fichero	
								
					numRegistros = i;
										    
				    do {
				    system("cls");	
				    
	                printf("\n___Seleccione el numero del dato con el que quiere trabajar___\n\n");
	                printf("1-El pH\n2-La conductividad\n3-La turbidez\n4-Los coliformes\n\n");
	                scanf("%d", &dato);
	            	} while (dato < 1 || dato > 4);
	            	
					system("cls");
					
		            switch (dato) {
		            	
		                case 1:
		                	do {		                	 
	                        printf("\n--Para el pH seleccione la opcion que quiera realizar--\n\n");
	                        printf("1-Realizar la media\n2-Realizar la desviacion tipica\n\n");
	                        scanf("%d", &dato2);
	                    	} while (dato2 < 1 || dato2 > 2);
	                    	
	                    	switch (dato2) {
	                        case 1:
	                        	
	                        	// Validamos que no se sobrepase el numero de registros del fichero
	                        	
	                        	do{	
									system("cls");  		
												
	                       			printf("Introduce el numero de fuentes:\n");
	                       			printf("El numero de datos no debe superar el numero de registros del fichero: %d\n",numRegistros);
	      							scanf("%d", &numDatos);
				                 	
	                            }while (numDatos > numRegistros);
								                            	                        	
	                           	media_val_ph = calcular_media_ph(datos, numDatos);
	                            printf("La media es: %.2f\n\n", media_val_ph);
	                            
	                            pulstarContinuar();
	                            break;
	
	                        case 2:
	                        	
	                        	// Validamos que no se sobrepase el numero de registros del fichero
	                        	
	                        	do{	
	                        		system("cls"); 
	                        		
		                        	printf("Introduce el numero de datos:\n");
		                        	printf("El numero de datos no debe superar el numero de registros del fichero: %d\n",numRegistros);
		                        	scanf("%d", &numDatos);
		                        
	                        	}while (numDatos > numRegistros);
	                        	 
	                           	media_val_ph = calcular_media_ph(datos, numDatos);
	                        	desviacion_tipica_val_ph = calcular_desv_ph(datos, media_val_ph, numDatos);
	                        	
	                            printf("La desviacion tipica es: %.2f\n\n", desviacion_tipica_val_ph);
	                            
	                        	pulstarContinuar();
	                            break;
	                    	}
	                    
		                    break;
		
		                case 2:
		                	do {
		                	printf("\n--Para la conductividad seleccione la opcion que quiera realizar--\n\n");
	                        printf("1-Realizar la media\n2-Realizar la desviacion tipica\n\n");
	                        scanf("%d", &dato2);
	                    	} while (dato2 < 1 || dato2 > 2);
		                    
		                    switch (dato2) {
		                    	
	                        case 1:
	                        	
	                        	// Validamos que no se sobrepase el numero de registros del fichero
	                        	
	                        	do{
	                        		system("cls");  
	                        		
								    printf("Introduce el numero de datos:\n");
								    printf("El numero de datos no debe superar el numero de registros del fichero: %d\n",numRegistros);
	                        		scanf("%d", &numDatos);
		                        	
	                        	 }while (numDatos > numRegistros );	  
								                       	
	                          	media_val_cond = calcular_media_cond(datos, numDatos);
	                            printf("La media es %.2f\n\n", media_val_cond);
	                            
	                            pulstarContinuar();
	                            break;
	
	                        case 2:
	                        	
	                        	// Validamos que no se sobrepase el numero de registros del fichero
                        	
                        		do{	
	                        		system("cls"); 
	                        		
		                        	printf("Introduce el numero de datos:\n");
		                        	printf("El numero de datos no debe superar el numero de registros del fichero: %d\n",numRegistros);
		                        	scanf("%d", &numDatos);
		                        
                        		}while (numDatos > numRegistros);
	                        	
	                           	media_val_cond = calcular_media_cond(datos, numDatos);
	                        	desviacion_tipica_val_cond = calcular_desv_cond(datos, media_val_cond, numDatos);
	                        	
	                            printf("La desviacion tipica es: %.2f\n\n", desviacion_tipica_val_cond);
	                            
	                        	pulstarContinuar();
	                            break;
	                    	}
	                    
		                    break;
		
		                case 3:
		                	do {
		                	printf("\n--Para la turbidez seleccione la opcion que quiera realizar--\n\n");
	                        printf("1-Realizar la media\n2-Realizar la desviacion tipica\n\n");
	                        scanf("%d", &dato2);
	                    	} while (dato2 < 1 || dato2 > 2);
		                    
		                    switch (dato2) {
	                        case 1:
	                        	
	                        	do{
	                        		system("cls"); 
	                        		
	                        		printf("Introduce el numero de datos:\n");
	                        		printf("El numero de datos no debe superar el numero de registros del fichero: %d\n",numRegistros);
	                        		scanf("%d", &numDatos);
		                        
	                        	 }while (numDatos > numRegistros);	  	                        	
	                        	
	                           	media_val_turb = calcular_media_turb(datos, numDatos);
	                           	
	                            printf("La media es: %.2f\n\n", media_val_turb);
	                            
	                            pulstarContinuar();
	                            break;
	
	                        case 2:
	                        	do{
	                        		system("cls"); 
	                        		
	                        		printf("Introduce el numero de datos:\n");
	                        		printf("El numero de datos no debe superar el numero de registros del fichero: %d\n",numRegistros);
	                        		scanf("%d", &numDatos);
	                        		
	                        	 }while (numDatos > numRegistros);	 
	                        	 
	                           	media_val_turb = calcular_media_turb(datos, numDatos);
	                        	desviacion_tipica_val_turb = calcular_desv_turb(datos, media_val_turb, numDatos);
	                        	
	                            printf("La desviacion tipica es: %.2f\n\n", desviacion_tipica_val_turb);
	                            
	                        	pulstarContinuar();
	                            break;
	                    	}
	                    
		                    break;
		
		                case 4:
		                	do {
		                	printf("\n--Para los coliformes seleccione la opcion que quiera realizar--\n\n");
	                        printf("1-Realizar la media\n2-Realizar la desviacion tipica\n\n");
	                        scanf("%d", &dato2);
	                    	} while (dato2 < 1 || dato2 > 2);
	                    	
		                    switch (dato2) {
	                        case 1:
	                        	do{
	                        		system("cls"); 
	                        		
	                        		printf("Introduce el numero de datos:\n");
	                        		printf("El numero de datos no debe superar el numero de registros del fichero: %d\n",numRegistros);
	                        		scanf("%d", &numDatos);
	                        	
	                        	 }while (numDatos > numRegistros );	 
	                        	
	                           	media_val_colif = calcular_media_colif(datos, numDatos);
	                           	
	                            printf("La media es: %.2f\n\n", media_val_colif);
	                            
	                            pulstarContinuar();
	                            break;
	
	                        case 2:
	                        	do{
	                        		system("cls"); 
	                        		
	                        		printf("Introduce el numero de datos:\n");
	                        		printf("El numero de datos no debe superar el numero de registros del fichero: %d\n",numRegistros);
	                        		scanf("%d", &numDatos);
	                        		
	                        	 }while (numDatos > numRegistros);		                        	
	                        	
	                           	media_val_colif = calcular_media_colif(datos, numDatos);
	                        	desviacion_tipica_val_colif = calcular_desv_colif(datos, media_val_colif, numDatos);
	                        	
	                            printf("La desviacion tipica es: %.2f\n\n", desviacion_tipica_val_colif);
	                            
	                            pulstarContinuar();
	                        	
	                            break;
	                    	}
	                    
		                    break;
		            }
		            
		        fclose(fentrada);    
		            	            
	       		break;
	            
	        case 2:
	        		system("cls");
	        		
	        		fflush(stdin);
	        		printf("Introduce el nombre del fichero incluyendo el txt:\n");
					gets(nombre);
					
					fentrada = fopen(nombre, "rb");
				
				    if (fentrada == NULL) {
				        printf("Error, no se puede abrir el fichero.\n");
				        return 0;
				    }
				
	                i=0;
				
	    			fscanf(fentrada, "%[^\n]%*c", cabecera);			
	    			
			    	while (fscanf(fentrada, "%s %f %d %d %d", datos[i].parametros, &datos[i].ph, &datos[i].conductividad, &datos[i].turbidez, &datos[i].coliformes) != EOF) {		 
					  		    	    		
			    		i++;
					}
					
					// obtenemos el numero de registros leidos del fichero	
								
					numRegistros = i;
				    
				    do{	
						system("cls");  		
									
               			printf("Introduce el numero de fuentes:\n");
               			printf("El numero de datos no debe superar el numero de registros del fichero: %d\n",numRegistros);
						scanf("%d", &numDatos);
	                 	
                    }while (numDatos > numRegistros);
					
					obtener_mayor_menor_parametros(datos, numDatos);
					
					fclose(fentrada);
					pulstarContinuar();
	        	
	    		break;
	
	        case 3:
	        	system("cls");
	            crearFicheroDatos();
	            pulstarContinuar();
	            break;
	
	        case 4:
	        	system("cls");
	            printf("______Hasta la proxima_____\n");
	            return 0;
	
	        default:
	            printf("Opcion desconocida\n");
	    }
  	} while (opcion != 4);  	
  	return 0;
}

//Funciones para calcular la media

float calcular_media_ph(struct Tdatos datos[], int N) {
    float suma = 0, media = 0;
    int i;

    for (i = 0; i < N; i++) {
        suma += datos[i].ph;
    }

    media = (float)suma / N;

    return media;
}

float calcular_media_cond(struct Tdatos datos[], int N) {
    float suma = 0, media = 0;
    int i;

    for (i = 0; i < N; i++) {
        suma += datos[i].conductividad;
    }

    media = (float)suma / N;

    return media;
}

float calcular_media_turb(struct Tdatos datos[], int N) {
    float suma = 0, media = 0;
    int i;

    for (i = 0; i < N; i++) {
        suma += datos[i].turbidez;
    }

    media = (float)suma / N;

    return media;
}

float calcular_media_colif(struct Tdatos datos[], int N) {
    float suma = 0, media = 0;
    int i;

    for (i = 0; i < N; i++) {
        suma += datos[i].coliformes;
    }

    media = (float)suma / N;

    return media;
}

//Funcion para calcular la desviacion tipica 

float calcular_desv_ph(struct Tdatos datos[], float media, int N) {
    float suma = 0, desviacion_tipica = 0;
    int i;

    for (i = 0; i < N; i++) {
        suma += (float)pow(datos[i].ph - media, 2);
    }

    desviacion_tipica = (float)sqrt(suma / (N - 1));

    return desviacion_tipica;
}

float calcular_desv_cond(struct Tdatos datos[], float media, int N) {
    float suma = 0, desviacion_tipica = 0;
    int i;

    for (i = 0; i < N; i++) {
        suma += (float)pow(datos[i].conductividad - media, 2);
    }

    desviacion_tipica = (float)sqrt(suma / (N - 1));

    return desviacion_tipica;
}

float calcular_desv_turb(struct Tdatos datos[], float media, int N) {
    float suma = 0, desviacion_tipica = 0;
    int i;

    for (i = 0; i < N; i++) {
        suma += (float)pow(datos[i].turbidez - media, 2);
    }

    desviacion_tipica = (float)sqrt(suma / (N - 1));

    return desviacion_tipica;
}

float calcular_desv_colif(struct Tdatos datos[], float media, int N) {
    float suma = 0, desviacion_tipica = 0;
    int i;

    for (i = 0; i < N; i++) {
        suma += (float)pow(datos[i].coliformes - media, 2);
    }

    desviacion_tipica = (float)sqrt(suma / (N - 1));

    return desviacion_tipica;
}

//Funcion para obtener el parametro mayor y menor

void obtener_mayor_menor_parametros(struct Tdatos datos[], int N) {
    int i;
    int max_ph = 0, min_ph = 0;
    int max_conductividad = 0, min_conductividad = 0;
    int max_turbidez = 0, min_turbidez = 0;
    int max_coliformes = 0, min_coliformes = 0;

    for (i = 0; i < N; i++) {

        if (datos[i].ph > datos[max_ph].ph){
            max_ph = i;
    	}else{
            min_ph = i;
    	}

        if (datos[i].conductividad > datos[max_conductividad].conductividad){
            max_conductividad = i;
        }else{
            min_conductividad = i;
        }

        if (datos[i].turbidez > datos[max_turbidez].turbidez){
            max_turbidez = i;
        }else{
            min_turbidez = i;
        }

        if (datos[i].coliformes > datos[max_coliformes].coliformes){
            max_coliformes = i;
        }else{
            min_coliformes = i;
        }
    }

    printf("Numero mayor y menor de cada parametro:\n\n");
    printf("pH: Mayor = %.2f (fuente_%d), Menor = %.2f (fuente_%d)\n\n", datos[max_ph].ph, max_ph, datos[min_ph].ph, min_ph);
    printf("Conductividad: Mayor = %d (fuente_%d), Menor = %d (fuente_%d)\n\n", datos[max_conductividad].conductividad, max_conductividad, datos[min_conductividad].conductividad, min_conductividad);
    printf("Turbidez: Mayor = %d (fuente_%d), Menor = %d (fuente_%d)\n\n", datos[max_turbidez].turbidez, max_turbidez, datos[min_turbidez].turbidez, min_turbidez);
    printf("Coliformes: Mayor = %d (fuente_%d), Menor = %d (fuente_%d)\n\n", datos[max_coliformes].coliformes, max_coliformes, datos[min_coliformes].coliformes, min_coliformes);
}

//Funcion para crear un nuevo fichero

void crearFicheroDatos() {
    char nomArchivo[50];
    struct Tdatos datos;
    struct Tfichero nomFichero;
    FILE* datosin;
    int i, j, n;

    printf("__INDIQUE A CONTINUACION LOS DATOS DEL FICHERO__\n\n");
    printf("Introduzca el anyo de creacion del fichero:\n");
    scanf("%d", &nomFichero.anio);

    printf("Introduzca el mes (01-12):\n");
    scanf("%d", &nomFichero.mes);

    printf("Introduzca el nombre del lugar en minusculas empezando con mayuscula:\n");
    scanf("%s", nomFichero.lugar);

    sprintf(nomArchivo, "%d%d_%s.txt", nomFichero.anio, nomFichero.mes, nomFichero.lugar);

    datosin = fopen(nomArchivo, "w");  
    
	system("cls");
    if (datosin == NULL) {
        printf("\n-ERROR AL ABRIR EL ARCHIVO-\n");
        return;
    } else
        printf("\n-Archivo creado con exito-\n");

    printf("Introduzca el numero de fuentes de su estudio:\n\n");
    scanf("%d", &n);
    
    fprintf(datosin, "Parametros\t\tPH\t\tConductividad\t\tTurbidez\t\tColiformes\n");
    
    system("cls");

    for (i = 0; i < n; i++) {
        printf("Introduzca el pH de la fuente %d:\n", i + 1);
        scanf("%f", &datos.ph);
        printf("Introduzca la conductividad %d:\n", i + 1);
        scanf("%d", &datos.conductividad);
        printf("Introduzca la turbidez %d:\n", i + 1);
        scanf("%d", &datos.turbidez);
        printf("Introduzca los coliformes %d:\n", i + 1);
        scanf("%d", &datos.coliformes);
        
	    fprintf(datosin, "fuente_%d\t\t%.2f\t\t%d\t\t\t%d\t\t\t%d\n", i + 1, datos.ph, datos.conductividad, datos.turbidez, datos.coliformes);

		system("cls");
      
    }
    fclose(datosin);
    printf("Fichero creado correctamente:\n");
    pulstarContinuar();
}

// funcion para incluir un tiempo de espera en pantalla

void pulstarContinuar() {
    
    printf("Introduzca cualquier tecla y pulse intro para continuar ...");
    scanf(" %*c");  // Lee un caracter del usuario y descarta su valor
    

	system("cls");
      
   
}
