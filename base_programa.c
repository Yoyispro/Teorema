#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a,b,c,d,contador_N=1,matriz_ori[10][4],matriz_resul[10][3],teorema[100];
div_t tcr,residuo; //para utilizar los residuos de divisiones
int main (){
    printf("\nEste programa usa el teorema del residuo chino para resolver congruencias ");
    printf("\nde la forma: 'x' es congruente a 'm' en el modulo 'n'");
    printf("\nDetermina el numero de congruencias que deseas introducir: ");
    scanf("%d",&a);
    for ( b = 0; b < a; b++){
        printf("\nResiduo m %d: ",b+1); scanf("%d",&matriz_ori[b][0]);
        printf("Modulo n %d:  ",b+1); scanf("%d",&matriz_ori[b][1]);
        contador_N=matriz_ori[b][1]*contador_N;        
    }
    for ( b = 0; b < a; b++){
        matriz_ori[b][2]=contador_N/matriz_ori[b][1];   //obtiene la tercera columna del teorema
    }
    d=0;  //contador del arreglo teorema
    for ( b = 0; b < a; b++){
        for ( c = 0; c < matriz_ori[b][1]; c++){
            teorema[d]=matriz_ori[b][2]*c;
            tcr = div(teorema[d]-1,matriz_ori[b][1]);
            if (tcr.rem==0){ //Determina en que valor de la tercera columna el residuo se hace 0
                matriz_ori[b][3]=c;
            }
            ++d;
        }
    }
    
    for (b = 0; b < a; b++){ //Imprime la primera matriz
        for ( c = 0; c < 4; c++){
            printf(" %d ",matriz_ori[b][c]); 
        }
        printf("\n");
    }
    printf("\n");

    c=0;
    for ( b = 0; b < a; b++){
        matriz_ori[b][4]=matriz_ori[b][0]*matriz_ori[b][3]*matriz_ori[b][2]; 
        c=c+matriz_ori[b][4]; //Obtiene el valor de la multiplicacion de a, d y c   Lleva la cuenta de la suma de esos valores
    }
    residuo = div(c,contador_N); //Obtenemos el valor final

    for ( b = 0; b < a; b++){ // Lo pasamos a la otra matriz
        matriz_resul[b][0]=residuo.rem;
        matriz_resul[b][1]=matriz_ori[b][0]; // Residuoo y modulo
        matriz_resul[b][2]=matriz_ori[b][1];
    }

    for ( b = 0; b < a; b++){
        for ( c = 0; c < 3; c++){
            printf(" %d ",matriz_resul[b][c]); 
        }
        printf("\n");
    }
    
    return 0;
}