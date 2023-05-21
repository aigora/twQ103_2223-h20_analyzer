#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define PARAMETROS 50
#define TAM_DATOS 100
#define numDatos 25

struct Tdatos {
    char parametros[PARAMETROS];
    float ph;
    int conductividad;
    int turbidez;
    int coliformes;
};

struct Tfichero {
    int anio;
    int mes;
    char lugar[PARAMETROS];
};

float calcular_media(float datos[], int numDatos);
float calcular_desviacion_tipica(float datos[], float media, int numDatos);
void crearFicheroDatos();

int main() {
    struct Tdatos datos[TAM_DATOS];
    int opcion, dato, numDatos, dato2, i;
    float media_val, desviacion_tipica_val;

    FILE* fichero;
    FILE* fsalida;

    fichero = fopen("202301_Lavapies.txt", "r");

    if (fichero == NULL) {
        printf("Error, no se puede abrir el fichero.\n");
        return 0;
    }

    printf("Bienvenido al menú de opciones de H20_ANALYZER\n");
    printf("Escoja una de las siguientes opciones:\n");
    printf("1) Cálculos estadísticos\n2) Crear fichero de datos\n3) Salir\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            do {
                printf("Seleccione los datos a tratar:\n");
                printf("1) El pH\n2) La conductividad\n3) La turbidez\n4) Los coliformes\n");
                scanf("%d", &dato);
            } while (dato < 1 || dato > 4);

            switch (dato) {
                case 1:
                    do {
                        printf("Para el pH seleccione la opción que quiera realizar:\n");
                        printf("1) Realizar media\n2) Realizar desviacion tipica\n");
                        scanf("%d", &dato2);
                    } while (dato2 < 1 || dato2 > 2);

                    switch (dato2) {
                        case 1:
                            media_val = calcular_media(datos[numDatos].ph, numDatos);
                            printf("La media es: %.2f", media_val);
                            break;

                        case 2:
                            desviacion_tipica_val = calcular_desviacion_tipica(datos[numDatos].ph, media_val, numDatos);
                            printf("La desviación típica es: %.2f", desviacion_tipica_val);
                            break;
                    }
                    break;

                case 2:
                    do {
                        printf("Para la conductividad seleccione la opción que quiera realizar:\n");
                        printf("1) Realizar media\n2) Realizar desviacion tipica\n");
                        scanf("%d", &dato2);
                    } while (dato2 < 1 || dato2 > 2);

                    switch (dato2) {
                        case 1:
                            media_val = calcular_media(datos[numDatos].conductividad, numDatos);
                            printf("La media es %.2f", media_val);
                            break;

                        case 2:
                            desviacion_tipica_val = calcular_desviacion_tipica(datos[numDatos].conductividad, media_val, numDatos);
                            printf("La desviación típica es: %.2f", desviacion_tipica_val);
                            break;
                    }
                    break;

                case 3:
                    do {
                        printf("Para la turbidez seleccione la opción que quiera realizar:\n");
                        printf("1) Realizar media\n2) Realizar desviacion tipica\n");
                        scanf("%d", &dato2);
                    } while (dato2 < 1 || dato2 > 2);

                    switch (dato2) {
                        case 1:
                            media_val = calcular_media(datos[numDatos].turbidez, numDatos);
                            printf("La media es: %.2f", media_val);
                            break;

                        case 2:
                            desviacion_tipica_val = calcular_desviacion_tipica(datos[numDatos].turbidez, media_val, numDatos);
                            printf("La desviación típica es: %.2f", desviacion_tipica_val);
                            break;
                    }
                    break;

                case 4:
                    do {
                        printf("Para los coliformes seleccione la opción que quiera realizar:\n");
                        printf("1) Realizar media\n2) Realizar desviacion tipica\n");
                        scanf("%d", &dato2);
                    } while (dato2 < 1 || dato2 > 2);

                    switch (dato2) {
                        case 1:
                            media_val = calcular_media(datos[numDatos].coliformes, numDatos);
                            printf("La media es: %.2f", media_val);
                            break;

                        case 2:
                            desviacion_tipica_val = calcular_desviacion_tipica(datos[numDatos].coliformes, media_val, numDatos);
                            printf("La desviación típica es: %.2f", desviacion_tipica_val);
                            break;
                    }
                    break;
            }
            break;

        case 2:
            crearFicheroDatos();
            break;

        case 3:
            printf("______Hasta la próxima_____\n");
            return 0;

        default:
            printf("Opcion desconocida\n");
    }

    return 0;
}

float calcular_media(float datos[], int numDatos) {
    float suma = 0;
    float media = 0;
    int i;

    for (i = 2; i <= numDatos+1; i++) {
        suma += datos[i];
    }

    media = suma / numDatos;

    return media;
}

float calcular_desviacion_tipica(float datos[], float media, int numDatos) {
    float suma = 0;
    int i;
    float desviacion_tipica = 0;

    for (i = 2; i <= numDatos+1; i++) {
        suma += pow(datos[i] - media, 2);
    }

    desviacion_tipica = sqrt(suma / (numDatos * (numDatos - 1)));

    return desviacion_tipica;
}

void crearFicheroDatos() {
    char nomArchivo[50];
    struct Tdatos datos[TAM_DATOS];
    struct Tfichero nomFichero;
    FILE* datosin;
    FILE* datosout;
    int i, j, n;

    printf("INDIQUE A CONTINUACION LOS DATOS DEL FICHERO\n");
    printf("Introduzca los cuatro numeros del año del estudio:\n");
    scanf("%d", &nomFichero.anio);

    printf("Introduzca el mes (01-12):\n");
    scanf("%d", &nomFichero.mes);

    printf("Introduzca el nombre del lugar en minúsculas empezando con mayúscula:\n");
    scanf("%s", nomFichero.lugar);

    sprintf(nomArchivo, "%d%d_%s.txt", nomFichero.anio, nomFichero.mes, nomFichero.lugar);

    datosin = fopen(nomArchivo, "w");

    if (datosin == NULL) {
        printf("\nERROR AL ABRIR EL ARCHIVO\n");
        return;
    } else
        printf("\nArchivo creado con éxito\n");

    printf("Introduzca el número de fuentes de su estudio:\n");
    scanf("%d", &n);
    fprintf(datosin, "Parametros\t\tpH\t\tConductividad\t\tTurbidez\t\tColiformes\n");

    for (i = 0; i < n; i++) {
        printf("Introduzca el pH de la fuente %d:\n", i + 1);
        scanf("%f", &datos[i].ph);
        printf("Introduzca la conductividad %d:\n", i + 1);
        scanf("%d", &datos[i].conductividad);
        printf("Introduzca la turbidez %d:\n", i + 1);
        scanf("%d", &datos[i].turbidez);
        printf("Introduzca los coliformes %d:\n", i + 1);
        scanf("%d", &datos[i].coliformes);
        fprintf(datosin, "fuente_%d\t\t%.2f\t\t%d\t\t%d\t\t%d\n", i + 1, datos[i].ph, datos[i].conductividad, datos[i].turbidez, datos[i].coliformes);
    }
    fclose(datosin);
}
