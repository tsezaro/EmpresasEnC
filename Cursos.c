#include <stdio.h>


void funcion2(char *cursof , float *notaf , float *sumatotal, int *totalalumnos,int *cantA , int *cantB){


    *sumatotal += *notaf;

    if (*cantA == 'A'){

        *cantA++;
    }
    else{
        *cantB++;

    }

    *totalalumnos = *cantA + *cantB;


return ;
}


void funcion1(int *alumnosfinal , int *mejoranio , char *mejorcurso) {

    int i,legajo,alumnos,cantA=0,cantB=0,totalalumnos=0,totalnotasA=0,totalnotasB=0;
    char curso;
    float nota, promedioA,promedioB, maxprom=0.0, sumA,sumB, totalnotas=0.0;

    for (i=1;i<3;i++){

        alumnos=0;
        totalnotasA=0;
        totalnotasB=0;
        sumA=0;
        sumB=0;


        do {
        printf("Ingrese su legajo \n");
        scanf ("%d",&legajo);
        fflush(stdin);
        }while(legajo<0);




        while(legajo!=0){

        alumnos ++;

        if (alumnos != 0){

            (*alumnosfinal)++;
        }




            do{
            printf("Ingrese la letra de su curso \n");
            scanf("%c",&curso);
            fflush(stdin);
            }while (curso != 'A' && curso != 'B');

            do{
            printf("Ingrese su nota\n");
            scanf("%f",&nota);
            fflush(stdin);
            }while(nota<0 || nota >10);



            if (curso == 'A'){
                sumA +=nota;
                totalnotasA++ ;

            }
            else{
                sumB += nota;
                totalnotasB++ ;
            }


            funcion2 (&curso,&nota,&totalnotas,&totalalumnos,&totalnotasA,&totalnotasB);


            do{
            printf("Ingrese su legajo \n");
            scanf ("%d",&legajo);
            fflush(stdin);
            }while(legajo<0);


        }

            promedioA = sumA/totalnotasA;
            promedioB = sumB/totalnotasB;

            if (promedioA>maxprom){
                maxprom=promedioA;
                *mejoranio = i;
                *mejorcurso = 'A';
            }
            else{
                if (promedioB > maxprom){
                    maxprom=promedioB;
                    *mejoranio = i;
                    *mejorcurso = 'B';

                }
            }

            printf("El promedio del curso A en el a%co %d es de %.2f \n",164,i,promedioA);
            printf("El promedio del curso B en el a%co %d es de %.2f \n",164,i,promedioB);



        }



return ;
}












int main () {

    int alumnosfinal ;
    int mejoranio ;
    char mejorcurso;



    funcion1(&alumnosfinal, &mejoranio , &mejorcurso);



    printf("El mejor promedio es del año %d y del curso %c \n", mejoranio ,mejorcurso);
    printf("La cantidad de legajos es de %d",alumnosfinal);







return 0;
}



