#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a,b,c,d,contador_N=1,matriz_ori[10][4],matriz_resul[10][3],teorema[100];
div_t tcr;
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
        matriz_ori[b][2]=contador_N/matriz_ori[b][1];
    }
    d=0;
    for ( b = 0; b < a; b++){
        for ( c = 0; c < matriz_ori[b][1]; c++){
            teorema[d]=matriz_ori[b][2]*c;
            tcr = div(teorema[d]-1,matriz_ori[b][1]);
            if (tcr.rem==0){
                matriz_ori[b][3]=c;
            }
            ++d;
        }
    }
    
    for (b = 0; b < a; b++){
        for ( c = 0; c < 4; c++){
            printf(" %d ",matriz_ori[b][c]);
        }
        printf("\n");
    }
    
    return 0;
}