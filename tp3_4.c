#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
char *Buffer; //variable auxiliar
int i=0, n=0;
char **V;

printf("Ingrese una cantidad de nombres a cargar: ");
scanf("%d",&n);


Buffer=(char *) malloc(100*sizeof(char));
V=(char **) malloc(sizeof(char *)* n);


for (i=0; i < n; i++)
{
    printf("Ingrese un nombre: ");
fflush(stdin);
    fgets(Buffer,100,stdin);
    *(V+i)= (char *) malloc(sizeof(char)*(strlen(Buffer)+1));
    strcpy(*(V+i),Buffer);
}
printf("Los nombres guardados son:\n");
for (i = 0; i < n; i++)
{
    puts(*(V+i));
}

free(Buffer);

return 0;
}