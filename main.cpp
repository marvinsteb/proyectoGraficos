#include <stdio.h>
#include <graphics.h>
#include <math.h>

/* prototipo de funciones */
void crearCuadrado();
void crearCirculo();
void crearTriangulo();
void crearRectangulo();
void crearRombo();
void crearPentagono();
void crearHexagono();
void crearTrapecio();
void CrearParalelogramo();
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
        void setLado(double tamanio){
            alto = tamanio;
            ancho = tamanio;
        }
        double calculaArea(){
            area = pow(alto,2);
            return area;
        };
        double calculaPerimetro(){
            perimetro = alto * 4.00;
            return perimetro;
        };
        dibujar(){
            int gd = DETECT, gm; 
            initgraph(&gd, &gm, NULL);         
            rectangle(5, 5,alto ,ancho ); 
            delay(500000); 
            closegraph(); 
        };
    protected:
        double alto,ancho;
};

class Triangulo : public figuraGeometrica {
    public: 
        Triangulo(double p_ladoA, double p_ladoB, double  p_ladoC, double p_base, double p_altura){
            ladoA = p_ladoA;
            ladoB = p_ladoB;
            ladoC = p_ladoC;
            base = p_base;
            altura = p_altura;
        };
        double calculaArea(){
             area = ((base * altura )/2);
            return area;
        };
        double calculaPerimetro(){
            perimetro = ladoA + ladoB + ladoC;
            return perimetro;
        };
        void dibujar(){
            
             int gd = DETECT, gm; 
            int arr[] = {320, 150, 400, 250,270, 250, 320, 150}; 
            initgraph(&gd, &gm, ""); 
            drawpoly(4, arr);    
            getch();  
            closegraph(); 
        };
    private:
    double ladoA,ladoB,ladoC,base,altura;
};


class Rectangulo : public  Cuadrado {
        public:
        void setLados(double p_alto,double p_ancho){
              alto = p_alto;
              ancho = p_ancho;
        };
};
int main(int argc, char** argv) {
    while (true) {
        despliegaMenu();
    }
    
    return 0; 
}


void despliegaMenu(){

     int n, opcion;

    do
    {   
        printf("\n Proyecto Calculadora de Areas para Figuras Geometricas");
        printf("\n   1. Calcular el Area y el perimetro de un cuadrado.", 163 );
        printf("\n   2. Calcular el area y el perimetro de un triangulo");
        printf("\n   3. Calcular el area y el perimetro de un rectangulo");
        printf("\n   4. Salir." );
        printf("\n\n   Introduzca opci%cn (1-4): ", 162 );

        scanf("%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1:
            	crearCuadrado();
                break;
            case 2: 
                crearTriangulo();
                break;
            case 3:
                crearRectangulo();
                break;
         }

         /* Fin del anidamiento */

    } while ( opcion != 4 );

}
void crearCuadrado(){
     double ladoCuadrado;
     printf( "\n   Ingrese el tama%co del lado del cuadrado ", 164 );
     scanf( "%lf", &ladoCuadrado );

     Cuadrado nuevoCuadrado;
     nuevoCuadrado.setLado(ladoCuadrado);
     printf("\n   El Area del cuadrado es: %.2f", nuevoCuadrado.calculaArea());
     printf("\n   El perimetro del cuadrado es: %.2f", nuevoCuadrado.calculaPerimetro());
      nuevoCuadrado.dibujar();
     printf("\n");
}

void crearTriangulo(){
    double ladoA,ladoB,ladoC,base,altura;
    printf("\n   Ingresa el lado A ");
    scanf("%lf",&ladoA);
    printf("\n   Ingresa el lado B ");
    scanf("%lf",&ladoB);
    printf("\n   Ingresa el lado C ");
    scanf("%lf",&ladoC);
    printf("\n   Ingresa el base ");
    scanf("%lf",&base);
    printf("\n   Ingresa el altura ");
    scanf("%lf",&altura);
    Triangulo nuevoTriangulo(ladoA,ladoB,ladoC,base,altura);
    printf("\n\n\n   El area del triangulo es: %.2f",nuevoTriangulo.calculaArea());
    printf("\n   El perimetro del triangulo es:  %.2f",nuevoTriangulo.calculaPerimetro());
    nuevoTriangulo.dibujar();


}


void crearRectangulo(){
     double alto, ancho;
     printf( "\n   Ingrese el alto del rectangulo ");
     scanf( "%lf", &alto);
     printf( "\n   Ingrese el ancho del rectangulo ");
     scanf( "%lf", &ancho);
     Rectangulo nuevoRectangulo;
     nuevoRectangulo.setLados(alto,ancho);
     printf("\n   El Area del rectangulo es: %.2f", nuevoRectangulo.calculaArea());
     printf("\n   El perimetro del rectangulo es: %.2f", nuevoRectangulo.calculaPerimetro());
     nuevoRectangulo.dibujar();
}

void crearCirculo(){

    int gd = DETECT, gm; 
    initgraph(&gd, &gm, NULL); 
  
    circle(50, 50, 30); 
  
    delay(500000); 
    closegraph(); 
}

