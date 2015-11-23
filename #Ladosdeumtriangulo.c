/*Só i´ra existir um triângulo se, somente se, os seus lados obedeceram á seguinte regra:
um de seus lados deve ser maior que o valor absoluto (modulo) da diferença dos outros dois lados e menor que a soma dos outros dois lados:*/


#include <stdio.h> 


|b-c| < a < b + c
|a-c| < b < a + c
|a-b| < c < a + b

main () {

float a,b,c;

printf ("Digite o valor dos lados");

scanf ("%f%f%f", &a, &b, &c);

if (a >|b-c| && a < b+c && b > |a-c| && a < a=c && c> |b-a| && c < b=a) {

printf ("O triangulo existe");

}

if (a < |b-c| || a > b=c || b < |a-c| || b < a+c || c < |b-a| || c > b+a) {

printf ("O Triangulo nao existe");

}

system ("pause");

}