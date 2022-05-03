#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct{
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}Cliente;

//Declaracion de funciones
void cargarClientes(Cliente *clientes, int cantClientes);
void mostrarTodo(Cliente *clientes, int cantClientes);
float costoTotalDeUnProducto(int cantidad, float precio);

int main() {
    int cantClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d",&cantClientes);
    fflush(stdin);
    Cliente *clientes;
	clientes = (Cliente *) malloc(sizeof(Cliente) * cantClientes);
    cargarClientes(clientes,cantClientes);
    mostrarTodo(clientes,cantClientes);
return 0;
}

void cargarClientes(Cliente *clientes, int cantClientes){

	char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
	char *Buffer = (char *) malloc(100*sizeof(char)); //Buffer para cargar un nombre

	for(int i=0; i<cantClientes; i++)
    {
		clientes[i].ClienteID = i; //id del cliente
		
		printf("Ingrese el nombre del cliente: ");
		fgets(Buffer,99,stdin);
		clientes[i].NombreCliente = (char *) malloc(sizeof(char) * (strlen(Buffer) + 1)); 
		strcpy(clientes[i].NombreCliente, Buffer); //Se carga lo que hay en Buffer a NombreCliente 
            
        clientes[i].CantidadProductosAPedir = (rand()%5+1);//Se asigna una cantidad aleatoria de productos a pedir
		 

		clientes[i].Productos = (Producto *) malloc(sizeof(Producto) * (clientes[i].CantidadProductosAPedir)+1); // La cantidad de memoria reservada para una struct Producto se multiplica por la cantidad de productos a pedir

		for(int j=0; j<clientes[i].CantidadProductosAPedir; j++){
			clientes[i].Productos[j].ProductoID = j; //id del producto
			clientes[i].Productos[j].Cantidad = (rand()%10+1); //Cantidad aleatoria hasta 10
			
			int posProducto = (rand()%4+1); //posicion aleatoria para elegir el producto

			clientes[i].Productos[j].TipoProducto = (char *) malloc(sizeof(char) * (strlen(TiposProductos[posProducto]) + 1)); 
			strcpy(clientes[i].Productos[j].TipoProducto, TiposProductos[posProducto]); 

			clientes[i].Productos[j].PrecioUnitario = ((rand()%7+1)*4); //precio aleatorio de cada producto
	    }
	
	    
    }
    free(Buffer); //Se libera el Buffer
}
//Funcion pedida en el punto v)
void mostrarTodo(Cliente *clientes, int cantClientes){
	for(int i=0; i<cantClientes; i++){
		float totalPorProducto = 0, totalaPagar = 0;

		//Informacion del CLiente
		printf("\t\t-Cliente %d-\n", i+1);
		printf("ID del cliente: %d\n", clientes[i].ClienteID);
		printf("Nombre del cliente: ");
		puts(clientes[i].NombreCliente);
		printf("Cantidad de productos: %d\n", clientes[i].CantidadProductosAPedir);

		for(int j=0; j<clientes[i].CantidadProductosAPedir; j++){
			//Informacion de cada producto
			printf("\tProducto %d\n", j+1);
			printf("ID del producto: %d\n", clientes[i].Productos[j].ProductoID);
			printf("Tipo de producto: ");
			puts(clientes[i].Productos[j].TipoProducto);
			printf("Cantidad del producto: %d\n", clientes[i].Productos[j].Cantidad);
			printf("Precio unitario: $%.2f\n", clientes[i].Productos[j].PrecioUnitario);
			totalPorProducto = costoTotalDeUnProducto(clientes[i].Productos[j].Cantidad, clientes[i].Productos[j].PrecioUnitario); 
			printf("Total a pagar del producto: $%.2f\n", totalPorProducto);
			totalaPagar += totalPorProducto; 

            free(clientes[i].Productos[j].TipoProducto);
		}

		printf("\t-Total a pagar por el cliente %d: $%.2f -\n",clientes[i].ClienteID+1, totalaPagar);
        free(clientes[i].Productos);
	}
	
	/*//liberamos memoria
	for(int i=0; i<cantClientes; i++){
		for(int j=0; j<clientes[i].CantidadProductosAPedir; j++){
			free(clientes[i].Productos[j].TipoProducto);
		}
		free(clientes[i].Productos);
	}*/
	free(clientes);
}
//Funcion pedida en el punto iv)
float costoTotalDeUnProducto(int cantidad, float precio){
	return cantidad * precio;
}
