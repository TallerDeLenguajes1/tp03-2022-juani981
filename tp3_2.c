#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
char *Buff; //variable auxiliar
unsigned i, n=5;
char *V[n];
Buff= (char *) malloc(100*sizeof(char));
for (i = 0; i < n; i++)
{
    printf("Ingrese un nombre: ");
    fgets(Buff,100,stdin);
    *(V+i)= (char *) malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(*(V+i),Buff);
}
printf("Los nombres guardados son:\n");
for (i = 0; i < n; i++)
{
    puts(*(V+i));
}

free(Buff);

return 0;
}