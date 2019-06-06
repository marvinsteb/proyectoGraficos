#include <stdio.h>
#include <graphics.h>
#include <math.h>

/* prototipo de funciones */
void crearCuadrado();
void crearCirculo();

void despliegaMenu();


// Clase base figuraGeometrica:
class figuraGeometrica {
  public:
   double calculaArea();
   double calculaPerimetro();
   void dibujar();
  protected:
   double area,perimetro;
};



class Cuadrado : public figuraGeometrica {
    public:
        Cuadrado(double tamanio){
            
            alto = tamanio;
            ancho = tamanio;
        }; 
        double calculaArea(){
             
            return pow(alto,2);
        };
        double calcularPerimetro(){
            return 0.00;
        };
        dibujar(){
            int gd = DETECT, gm; 
            initgraph(&gd, &gm, NULL);         
            rectangle(5, 5,alto ,ancho ); 
            delay(500000); 
            closegraph(); 
        };
    private:
        double alto,ancho;
};




int main(int argc, char** argv) {
    despliegaMenu();
    system("PAUSE");
    return 0; 
}


void despliegaMenu(){

     int n, opcion;

    do
    {   
        system("cls");
        printf("\n Proyecto Calculadora de Areas para Figuras Geometricas");
        printf( "\n   1. Calcular el Area y el perimetro de un cuadrado.", 163 );
        
        printf( "\n   4. Salir." );
        printf( "\n\n   Introduzca opci%cn (1-4): ", 162 );

        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1:
            		crearCuadrado();
                    break;

            case 2: 
                    crearCirculo();
                    break;
         }

         /* Fin del anidamiento */

    } while ( opcion != 4 );

}
void crearCuadrado(){
     double ladoCuadrado;
     printf( "\n   Ingrese el tama%co del lado del cuadrado ", 164 );
     scanf( "%lf", &ladoCuadrado );

     Cuadrado nuevoCuadrado(ladoCuadrado);
     printf("\n   El Area del cuadrado es: %f", nuevoCuadrado.calculaArea());
     nuevoCuadrado.dibujar();
     printf("\n");
     system("PAUSE");
}
void crearCirculo(){

    int gd = DETECT, gm; 
    initgraph(&gd, &gm, NULL); 
  
    circle(50, 50, 30); 
  
    delay(500000); 
    closegraph(); 
}

