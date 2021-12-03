#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int a,b,c,d,matriz_ori[10][5],matriz_resul[10][3],teorema[100];
div_t tcr,residuo; //para utilizar los residuos de divisiones
int main (){
    system("cls");
    printf("\nEste programa usa el teorema del residuo chino para resolver congruencias ");
    printf("\nde la forma: 'x' es congruente a 'm' en el modulo 'n'");
    getchar();
    do{
    int contador_N=1;
    system("cls");
    printf("\n\nDetermina el numero de congruencias que deseas introducir: ");
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
    
    c=0;
    for ( b = 0; b < a; b++){
        matriz_ori[b][4]=(matriz_ori[b][0])*(matriz_ori[b][3])*(matriz_ori[b][2]); 
        c=c+matriz_ori[b][4]; //Obtiene el valor de la multiplicacion de a, d y c   Lleva la cuenta de la suma de esos valores
    }
    residuo = div(c,contador_N); //Obtenemos el valor final
    printf("\n");
    for ( b = 0; b < a; b++){ // Lo pasamos a la otra matriz
        matriz_resul[b][0]=residuo.rem;
        matriz_resul[b][1]=matriz_ori[b][0]; // Residuoo y modulo
        matriz_resul[b][2]=matriz_ori[b][1];
        printf("%d %c %d (mod %d) \n",matriz_resul[b][0],"≡",matriz_resul[b][1],matriz_resul[b][2]);
    }
    printf("\n");
    
    do{
        printf("Si desea ingresar nuevas congruencias presione 1");
        printf("\nSi desea salir del programa presione 2: ");
        scanf("%d",&a);
    }while(a!=1&&a!=2);
    
    }while(a==1);
    return 0;
}