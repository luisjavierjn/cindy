// Cindy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct campos
{
    int numero;
};
 
struct nodo
{
    struct campos dato;
    struct nodo *proximo;
};
 
struct nodo *nuevonodo();
int colavacia(struct nodo *);
struct nodo *creacola(struct nodo *, struct campos);
void mostrar(struct nodo *);

int _tmain(int argc, _TCHAR* argv[])
{
	struct nodo *pri=NULL, *ult=NULL;
    struct campos x;

	int n, opcion;

	do
    {
        printf( "\n   1. Insertar pila" );
        printf( "\n   2. Borrar en pila" );
        printf( "\n   3. Listar pila" );
        printf( "\n   4. Salir" );
        printf( "\n\n   Introduzca opci%cn (1-4): ", 162 );

        scanf( "%d", &opcion );

        switch ( opcion )
        {
            case 1: printf( "\n   Introduzca un n%cmero entero: ", 163 );
                    scanf( "%d", &n );
					x.numero = n;

					ult=creacola(ult,x);
					if(pri==NULL) pri=ult; // Si es la 1º pasada pongo en pri el valor del primer nodo

                    printf( "\n   El n%cmero %d ha sido insertado\n\n", 163, x.numero );
                    break;

            case 2: printf( "\n   Funci%cn no implementada\n", 162 );
                    break;

            case 3: if(colavacia(pri)==1) { printf("No se ingresaron registros"); getch(); }
					else mostrar(pri);
					break;
         }

    } while ( opcion != 4 );

	return 0;
}

struct nodo *nuevonodo()
{
    struct nodo *p;
    p=(struct nodo *)malloc(sizeof(struct nodo));
    if(p==NULL)
    {
        printf("Memoria RAM Llena");
        getch();
        exit(0);
    }
    return p;
}
 
struct nodo *creacola(struct nodo *ult, struct campos x)
{
    struct nodo *p;
    p=nuevonodo();
    (*p).dato=x;
    (*p).proximo=NULL;
    if(ult!=NULL) (*ult).proximo=p;
    return p;
}
 
int colavacia(struct nodo *pri)
{
    if(pri==NULL) return 1;
    else return 0;
}
 
void mostrar(struct nodo *pri)
{
    struct nodo *aux;
    while(pri!=NULL)
    {
		printf("   %d \n",pri->dato.numero);
        aux=pri;
        pri=(*pri).proximo;
    }
	pri=aux;
}

