#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto{
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
};
struct Cliente{
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
struct Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
};

int main() {
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"}, *Buff;
int cantClientes,i;

printf("Ingrese la cantidad de clientes");
scanf("%i",&cantClientes);

for (i = 0; i < cantClientes; i++)
{
    Cliente.ClienteID = i+1;
    printf("Ingrese un nombre: ");
    gets(Buff);
    Cliente.NombreCliente+i= (char *) malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(*(Cliente.NombreCliente+i),Buff);
}

return 0;
}