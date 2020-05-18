#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

float aplicarDescuento(float precio);
int contarCaracteres(char cadena[], char caracter);

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} eNotebook;

void ordenarNotebook(eNotebook* notebook, int len);
void mostrarNotebooks(eNotebook* notebook, int len);

int main()
{
    float precio = 100;
    float precioConDescuento;
    char cadena[] = "Pedro es el mejor";
    int cantidad;
    eNotebook notebooks[TAM] = { {1,"Intel", "HP", 25000},{2, "AMD", "Lenovo", 26000}, {3, "Intel", "Acer", 29000}, {4, "Intel", "Acer", 29500.5 }, {5, "AMD", "Lenovo", 32000.7}, {6, "AMD", "Acer", 24000},{7, "Intel", "Lenovo", 31000.5}, {8, "AMD", "Acer", 25600.4}, {9, "Intel", "HP", 24600.3}, {10, "Intel", "Acer", 35300.4 }};


    precioConDescuento = aplicarDescuento(precio);

    printf("El precio con descuento es %.2f\n",precioConDescuento);

    cantidad = contarCaracteres(cadena,'e');
    printf("La letra e aparece %d veces",cantidad);



    ordenarNotebook(notebooks,TAM);
    mostrarNotebooks(notebooks,TAM);


    return 0;
}

float aplicarDescuento(float precio)
{
    float precioNuevo;
    float descuento;

    descuento = precio /100 * 5;

    precioNuevo = precio - descuento;

    return precioNuevo;
}

int contarCaracteres(char cadena[], char caracter)
{
    int contador = 0;
    int i = 0;

    while(cadena[i] != '\0')
    {
        if(cadena[i]==caracter)
        {
            contador++;
        }
        i++;
    }
    return contador;
}

void ordenarNotebook(eNotebook* notebook, int len)
{
    int i;
    int j;
    eNotebook aux;

    for(i=0; i<len; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if( stricmp(notebook[i].marca, notebook[j].marca) < 0 )
            {
                aux = notebook[i];
                notebook[i] = notebook[j];
                notebook[j] = aux;
            }
            else if(stricmp(notebook[i].marca, notebook[j].marca) == 0 && notebook[i].precio < notebook[j].precio);
            {
                aux = notebook[i];
                notebook[i] = notebook[j];
                notebook[j] = aux;
            }
        }
    }
}

void mostrarNotebooks(eNotebook* notebook, int len)
{
    int i;
    printf("\n\nID  PROCESADOR     MARCA    PRECIO\n");
    for(i=0; i<len; i++)
    {

        printf(" %d %10s %10s    %.2f\n", notebook[i].id, notebook[i].procesador,notebook[i].marca, notebook[i].precio);
    }
}
