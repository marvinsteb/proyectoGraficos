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
            setcolor(RED);        
            rectangle(100, 100,alto ,ancho );
            floodfill(101,101,RED);
            getch();   
            closegraph(); 
        };
    protected:
        double alto,ancho;
};

class Rectangulo : public  Cuadrado {
        public:
        void setLados(double p_alto,double p_ancho){
              alto = p_alto;
              ancho = p_ancho;
        };
};
class Circulo : public figuraGeometrica{
    public:
    void setRadio(double p_radio){
        radio = p_radio;
        diametro = radio * 2; 
    }
    double calculaArea(){
        area = M_PI * pow(radio,2);
        return area;
    };
    double calculaPerimetro(){
        perimetro = diametro * M_PI ;
        return perimetro;
    };
    void dibujar(){
        int gd = DETECT, gm; 
        initgraph(&gd, &gm, NULL);         
        fillellipse(320,200,100,100); 
        getch();   
        closegraph(); 
        
    };
    private:
    double diametro, radio;
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
            initgraph(&gd, &gm, NULL); 
            drawpoly(4, arr);    
            getch();  
            closegraph(); 
        };
    private:
    double ladoA,ladoB,ladoC,base,altura;
};

class Rombo : public figuraGeometrica{
    public:
        Rombo(double p_diagonalMayor, double p_diagonalMenor){
            diagonalMayor = p_diagonalMayor;
            diagonalMenor = p_diagonalMenor;
        };
        double calculaArea(){
            area = (diagonalMayor * diagonalMenor) / 2;
            return area;
        };
        double calculaPerimetro(){
           perimetro =  (4 * sqrt((pow((diagonalMayor/2),2) + pow((diagonalMenor/2),2)))); 
           return perimetro;
        };
        void dibujar(){
            int gd=DETECT, gm,array[]={300,300
                                      ,400,450
                                      ,500,300
                                      ,400,150
                                      ,300,300};
             initgraph(&gd, &gm, NULL);
            drawpoly(5,array);
            getch();
            closegraph();
        };
    private:
    double diagonalMayor,diagonalMenor,lado;

};

class Hexagono : public figuraGeometrica {
    public:
        Hexagono(double p_lado){
            lado = p_lado;
            perimetro = lado * 6;
        }
        double calculaArea(){
            apotema = sqrt((pow((lado),2) + pow((lado/2),2)));
            area = (perimetro * apotema)/ 2; 
            return area;
        }
        double calculaPerimetro(){
            return perimetro;
        }
        void dibujar(){
             int gd=DETECT, gm,array[]={200,300
                                      ,200,400
                                      ,300,500
                                      ,400,400
                                      ,400,300
                                      ,300,200
                                      ,200,300};
             initgraph(&gd, &gm, NULL);
            fillpoly(7,array);
            getch();
            closegraph();
        }
    private:
    double lado,apotema;    
};

class Pentagono : public figuraGeometrica {
    public:
        Pentagono(double p_lado){
            lado = p_lado;
            perimetro = lado * 5;
        }
        double calculaArea(){
            // 36 grados a radianes es 0.628319
            apotema = lado / (2 * tan ( 36 * M_PI / 180.0 ));
            area = (perimetro * apotema)/ 2; 
            return area;
        }
        double calculaPerimetro(){
            return perimetro;
        }
        void dibujar(){
             int gd=DETECT, gm,array[]={320,240,340,220,360,240,360,280,320,280,320,240};
             initgraph(&gd, &gm, NULL);
            fillpoly(6,array);
            getch();
            closegraph();
        };
    private:
    double lado,apotema;    
};

class Trapecio : public figuraGeometrica {
    public: 
        Trapecio(double p_ladoA, double p_ladoB, double p_altura){
            ladoA = p_ladoA;
            ladoB = p_ladoB;
            altura = p_altura;
        };
        double calculaArea(){
            area = altura * ((ladoA + ladoB)/ 2 );
            return area;
        };
        void dibujar(){
            int gd=DETECT, gm,array[]={200,300
                                      ,200,400
                                      ,400,500
                                      ,400,200
                                      ,200,300};
             initgraph(&gd, &gm, NULL);
            fillpoly(5,array);
            getch();
            closegraph();

        };
    private:
    double ladoA, ladoB, altura;
};

class Paralelogramo : public figuraGeometrica{
    public:
        Paralelogramo(double p_base, double p_altura){
            base = p_base;
            altura = p_altura;
        };
        double calculaArea(){
            area = base * altura;
            return area;
        };
     void dibujar(){
            int gd=DETECT, gm,array[]={100,400
                                      ,200,600
                                      ,400,400
                                      ,300,200
                                      ,200,300};
             initgraph(&gd, &gm, NULL);
            fillpoly(5,array);
            getch();
            closegraph();

        };
    private:
    double base,altura;
};


int main(int argc, char** argv) {
        despliegaMenu();
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
        printf("\n   4. Calcular el area y el perimetro de un ciruclo");
        printf("\n   5. Calcular el area y el perimetro de un rombo");
        printf("\n   6. Calcular el area y el perimetro de un pentagono");
        printf("\n   7. Calcular el area y el perimetro de un Hexagono");
        printf("\n   8. Calcular el area y el perimetro de un Trapecio");
        printf("\n   9. Calcular el area y el perimetro de un Paralelogramo");
        printf("\n   0. Salir." );
        printf("\n\n   Introduzca opci%cn (1-9): ", 162 );

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
            case 4:
                crearCirculo();
                break;
            case 5:
                crearRombo();
                break;
            case 6:
                crearPentagono();
                break;
            case 7:
                crearHexagono();
                break;
            case 8:
                crearTrapecio();
                break;
            case 9:
                CrearParalelogramo();
                break;
         }

         /* Fin del anidamiento */

    } while ( opcion != 10 );

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
    double radio;
    printf( "\n   Ingrese el radio del circulo");
    scanf( "%lf", &radio);
    Circulo nuevoCirculo;
    nuevoCirculo.setRadio(radio);
    printf("\n   El Area del circulo es: %.2f", nuevoCirculo.calculaArea());
    printf("\n   El perimetro del circulo es: %.2f", nuevoCirculo.calculaPerimetro());
    nuevoCirculo.dibujar();
}

void crearRombo(){
     double diagonalMayor, diagonalMenor;
     printf( "\n   Ingrese el diagonal mayor del rombo ");
     scanf( "%lf", &diagonalMayor);
     printf( "\n   Ingrese el diagonal menor del rombo ");
     scanf( "%lf", &diagonalMenor);
     Rombo nuevoRombo(diagonalMayor,diagonalMenor);
     printf("\n   El Area del rombo es: %.2f", nuevoRombo.calculaArea());
     printf("\n   El perimetro del rombo es: %.2f", nuevoRombo.calculaPerimetro());
     nuevoRombo.dibujar();
}

void crearPentagono(){
     double largoPentagono;
     printf( "\n   Ingrese el tama%co de un lado del pentagono ", 164 );
     scanf( "%lf", &largoPentagono );
     Pentagono nuevoPentagono(largoPentagono);
     printf("\n   El Area del pentagono es: %.2f", nuevoPentagono.calculaArea());
     printf("\n   El perimetro del pentagono es: %.2f", nuevoPentagono.calculaPerimetro());
     nuevoPentagono.dibujar();
     printf("\n");
}

void crearHexagono(){
     double lagoHexagono;
     printf( "\n   Ingrese el tama%co de un lado del hexagono ", 164 );
     scanf( "%lf", &lagoHexagono );
     Hexagono nuevoHexagono(lagoHexagono);
     printf("\n   El Area del hexagono es: %.2f", nuevoHexagono.calculaArea());
     printf("\n   El perimetro del hexagono es: %.2f", nuevoHexagono.calculaPerimetro());
     nuevoHexagono.dibujar();
     printf("\n");
}

void crearTrapecio(){
    double ladoA, ladoB,altura;
     printf( "\n   Ingrese el lado A del trapecio ");
     scanf( "%lf", &ladoA);
     printf( "\n   Ingrese el lado B del trapecio ");
     scanf( "%lf", &ladoB);
     printf( "\n   Ingrese la altura del traecio ");
     scanf( "%lf", &altura);
     Trapecio nuevTrapecio(ladoA,ladoB,altura);
     printf("\n   El Area del trapecio es: %.2f", nuevTrapecio.calculaArea());
     nuevTrapecio.dibujar();   
}


void CrearParalelogramo(){
    double base ,altura;
     printf( "\n   Ingrese la base del paralelogramo ");
     scanf( "%lf", &base);
     printf( "\n   Ingrese la altura del paralelogramo ");
     scanf( "%lf", &altura);
     Paralelogramo nuevoParalelogramo(base,altura);
     printf("\n   El Area del paralelogramo es: %.2f", nuevoParalelogramo.calculaArea());
     nuevoParalelogramo.dibujar();   
}
