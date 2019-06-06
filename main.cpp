#include <iostream>
#include <graphics.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, NULL); 
  
    circle(50, 50, 30); 
  
    delay(500000); 
    closegraph(); 
    return 0; 
}
