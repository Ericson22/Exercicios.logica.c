#include <stdio.h>

main ( ) {

float t, h;

printf("Qual altura em metros");

scanf("%f%", &h);

if (h<0) {

printf ("escreva a altura sem sina");

scanf ("%f%", &h);

}

if (h>0) {

t = (2/9.8)(2h/9.8);

printf ("o corpo leva  %.2f segundos para atingir o solo",t);

} 
sistem ("pause");


}
