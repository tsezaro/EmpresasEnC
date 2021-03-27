#include <stdio.h>

void funcion1(float *, float *, char * , int *);
void funcion2(char , float  ,float *, int *,float *, int *,float *, int *);



void funcion1(float *ptotalimporte, float *max , char *mejclase , int *ptotalcant){

    int N,ventas,i,cantventasc,cantventasm,cantventasg;
    float importe,acumimpc,acumimpg,acumimpm, totalc = 0,totalm = 0 , totalg = 0;
    char clase;


    printf ("Ingrese la cantidad de consesionarias \n");
    scanf("%d",&N);
    fflush(stdin);

    for (i=1; i<=N ; i++){

    acumimpc = 0;
    acumimpg = 0;
    acumimpm = 0;
    cantventasc = 0;
    cantventasg = 0;
    cantventasm = 0;


        printf("Ingrese numero de venta%d \n",i);
        scanf("%d",&ventas);
        fflush(stdin);

        while (ventas!=0){

                (*ptotalcant)++;


            do{

                printf("Ingrese la clase a la que pertenece: \n");
                scanf("%c",&clase);
                fflush(stdin);

            }while(clase !='c' && clase != 'm' && clase != 'g' && clase !='C' && clase != 'M' && clase != 'G');

            printf("Ingrese el importe de la venta \n");
            scanf("%f",&importe);
            fflush(stdin);

            *ptotalimporte += importe;


            funcion2(clase,importe,&acumimpc,&cantventasc,&acumimpg,&cantventasg,&acumimpm,&cantventasm);

            printf("Ingrese numero de venta %d \n",i);
            scanf("%d",&ventas);
            fflush(stdin);

        }


        printf("Consesionaria: %d \n",i);
        printf("CLASE C: Importe acumulado $%.2f - %d Ventas \n",acumimpc, cantventasc );
        printf("CLASE M: Importe acumulado $%.2f - %d Ventas \n",acumimpm, cantventasm );
        printf("CLASE G: Importe acumulado $%.2f - %d Ventas \n",acumimpg, cantventasg );




    totalc += acumimpc;
    totalm += acumimpm;
    totalg += acumimpg;

    }


    if(totalc > *max){
        *max = totalc ;
        *mejclase = 'C';
    }
    if(totalm > *max){
        *max = totalm ;
        *mejclase = 'M';
    }
    if(totalg > *max){
        *max = totalg;
        *mejclase = 'G';
    }

}


void funcion2(char clase, float importe,float *acumimpc, int *cantventasc,float *acumimpg, int *cantventasg,float *acumimpm, int *cantventasm){


    if ((clase == 'c') || (clase == 'C')){

                *acumimpc += importe;
                (*cantventasc)++;
    }



    if ((clase == 'g') || (clase == 'G')){
                *acumimpg += importe;
                (*cantventasg)++;
    }


    if ((clase == 'm') || (clase == 'M')){
                    *acumimpm += importe;
                    (*cantventasm)++;
    }


}



int main (){

int totalcant= 0;
float max, totalimp=0;
char mejclase;

funcion1(&totalimp,&max,&mejclase,&totalcant);


printf("La cantidad total de ventas procesadas es de: %d\n",totalcant);
printf("La clase que mas facturo es %c con un total de %.2f \n",mejclase, max);
printf("el total general facturado entre todas las clases es de %.2f\n",totalimp);




return 0;
}

