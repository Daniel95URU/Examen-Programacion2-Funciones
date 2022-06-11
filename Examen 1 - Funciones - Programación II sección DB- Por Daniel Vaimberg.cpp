/*Escriba un programa que muestre tres opciones al usuario entre las cuales este podr� elegir
una opci�n de c�lculo. 
La primara de estas opciones ser� calcular las ra�ces de un polinomio de grado 2 mediante la ecuaci�n de segundo grado, esta operaci�n debe mostrar 
las dos ra�ces reales (x1 y x2) despu�s de ser ingresados los valores de A, B y C respectivamente, el programa debe mostrar un mensaje de error 
cuando las ra�ces sean complejas.
La segunda opoci�n ser� el c�lculo del Volumen de una esfera, el programa debe mostrar el
resultado una vez introducido el valor del radio de la misma, el programa debe ser capaz de Mostar un mensaje de error si el radio es menor o igual a cero.
La tercera opci�n ser� el c�lculo del desplazamiento de un m�vil en movimiento rectil�neo uniforme variado,
 el programa debe pedirle al usuario el desplazamiento inicial, la velocidad inicial, el tiempo de desplazamiento y la aceleraci�n en este intervalo.
Los tres c�lculos planteados deben realizarse con el llamado a funciones con paso de par�metros.*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void EcuacionGrad2 ();
float VolEsfera (float R);
float Desplazamiento(float VelInicial, float Aceleracion, float tiempo);

int opcion;
float A, B, C, R, VelInicial, Aceleracion, tiempo;  

int main(){
  
	setlocale(LC_CTYPE, "Spanish"); 
	
		printf("Bienvenido, este programa te mostr� un men� de operaciones que podr� ejecutar seg�n los d�gitos que introduzcas.");
		printf ("\n\tMen� de operaciones, elige la que necesites.\n\n");
  
		printf (" 1. Calcular las ra�ces de un polinomio de grado 2. \n 2. Calcular el volumen de una esfera. \n 3. Calcular el desplazamiento de un m�vil con MRUV.\n\n");
		scanf ("%d", &opcion);
		
		system("cls");
	switch (opcion){
    
    case 1: 
    	printf("\n\tSeleccion�:C�lculo de ra�ces de un polinomio de grado 2.\n");
        EcuacionGrad2();
    break;
    case 2: 
		printf ("\n\tSeleccion�: C�lculo del vol�men de una esfera.\n");
        printf ("Ingrese el valor del Radio: "); 
		scanf("%f", &R); 
        printf ("\nEl valor del vol�men redondeado quedar�a = %.2f\n\n", round(VolEsfera(R)));
    break;
    case 3: 
		printf ("\n\tSeleccion�: Desplazamiento de un m�vil con MRUV\n\n");
        printf ("\n\nDesplazamiento = %.2f\n\n", Desplazamiento(VelInicial, Aceleracion,tiempo));
    break;
    default: printf("\n\n\n\tPor favor, ingrese una opci�n v�lida.\n\n\n\n");
	}  
  
	system ("pause");
	return 0;
}

void EcuacionGrad2(){
	
	float A, B, C, D;
	
		printf("\nIntroduzca los d�gitos de la ecuaci�n de segundo grado\n\n");
		
		printf("Introduce valor de a: ");
		scanf("%f", &A);
		
		printf("Introduce valor de b: ");
		scanf("%f", &B);
		
		printf("Introduce valor de c: ");
		scanf("%f", &C);
	
		D = (B*B)-(4.0*A*C);
	
			if (D == 0.0){
				printf("\nSoluci�n �nica: = %.2f\n", -B/(2.0*A));
			}else if(D > 0.0){
				printf("x1 = %.2f\n", (-B+sqrt(D))/(2.0*A));
				printf("x2 = %.2f\n", (-B-sqrt(D))/(2.0*A));
			}else if(D < 0.0){
				printf("\n\tError\n\t------\nLa ecuaci�n introducida origina un n�mero complejo.\n\n");
			}	
 		}
 		
	float VolEsfera (float R){
  	float Radio = R, Volumen = (4.0/3.0)*3.141592*pow(R, 3);
  
  		if (Volumen > 0){
  			printf ("\nEl vol�men de la esfera de radio %.2f es: %.2f\n", Radio, Volumen);
  
  		}else if(Volumen <= 0){
  			printf ("\n\tError encontrado\n\t-----------------\nEl radio introducido es menor o igual a 0, int�ntalo de neuvo.\n");
  			exit(0);
  		}
	return Volumen;
}

float Desplazamiento(float VelInicial, float Aceleracion, float tiempo){
	
	printf ("Ingrese la velocidad inicial: "); 
	scanf ("%f", &VelInicial);
	
	printf ("Ingrese el tiempo: "); 
	scanf ("%f", &tiempo);
	
 	printf ("Ingrese la aceleraci�n: "); 
	scanf ("%f", &Aceleracion);
	
	float desplazamiento = VelInicial*tiempo+(1.0/2.0*Aceleracion*pow(tiempo, 2));
return desplazamiento;
}

