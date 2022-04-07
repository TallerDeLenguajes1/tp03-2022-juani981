//Ejemplo 3 - reserva dinámica de memoria con variable auxiliar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
char *Buff; //variable auxiliar
char *V[5];
int i;
Buff= (char *) malloc(100*sizeof(char));

for (i = 0; i < 5; i++)
{
    printf("Ingrese un nombre: ");
    gets(Buff);
    *(V+i)= (char *) malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(*(V+i),Buff);
}
printf("Los nombres guardados son:\n");
for (i = 0; i < 5; i++)
{
    
    puts(*(V+i));
    printf("\t;%i",sizeof(*(V+i)));
}

free(Buff);

return 0;
}