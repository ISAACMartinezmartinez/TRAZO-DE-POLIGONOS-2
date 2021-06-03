#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

int DDA();
int BRE();
int main(){
	float n;
	printf ("Ingresa 1 para el algoritmo DDA o 2 para el algoritmo BRESENHAM: ");
	scanf("%f",&n);
	if(n==1){
		DDA();
	}else{
		BRE();
	}
	return 0;
}


int DDA() {
        /* request auto detection */
        int gdriver = DETECT, gmode, err;
        float i, x1, y1, x2, y2, x3, y3,x4,y4, x5, y5,x6,y6, dx, dy, steps, al, al1, w;
        float x, y, xincr, yincr;
        
        printf ("Cordenadas de inicio de la base: ");
		scanf("%f%f",&x1,&y1);
	 	printf ("Cordenadas final de la base: ");
		scanf("%f%f",&x2,&y2);
		printf ("Ingresa los lados del poligono: ");
		scanf("%f",&al);

        /* initialize graphic mode */
        initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");

        err = graphresult();

        if (err != grOk) {
                /* error occurred */
                printf("Graphic Error: %s\n",
                                grapherrormsg(err));
                getch();
                return 0;
        }

        /* draw line from (0, 0) to x-axis & y-axis maximum */
        
        dx = x2 - x1;
        printf("dx: %f", dx);
        printf("\n");
        dy = y2 - y1;
        printf("dy: %f", dy);
        printf("\n");

        x = x1, y = y1;
        x3 = x2, y3 = y2;
        x4 = x2, y4 = x2;
        x5 = x1 ,y5 = al+x1;;
        x6 = al+x1 ,y6 = al+x1;
        al1=al+x1;

        steps = abs(dx) > abs(dy) ? dx : dy;
        	printf("steps: %f", steps);	
        	printf("\n");

        xincr = (1.0 * dx) / steps;
        printf("Xinc: %f", xincr);
        printf("\n");
        yincr = (1.0 * dy) / steps;
        printf("Yinc: %f", yincr);
		printf("\n");
        putpixel((int) x, (int) y, WHITE);
        printf("X: %f ", x);
        printf("Y: %f", y);
        printf("\n");
        /* find the x and y successors and plot the pixels */
        for (w = 0; w<=al; w++){
        for (i = 0; i < steps; i++) {
        	printf("\n");
            x = x + xincr;
            printf("X: %f ", x);
            y = y + yincr;
            printf("Y: %f", y);
            putpixel((int) x, (int) y, WHITE);
    	}
					}
                 
                 
                 

                /* put a pixel at the given postion(x, y) */
                //putpixel((int) x, (int) y, WHITE);

        /* deallocate memory allocated fro graphic screen */
        getchar();
		getchar();
        closegraph();
        
        return 0;
        
  }
  
  
int BRE() {
        /* request auto detection */
        int gdriver = DETECT, gmode;
       	float x1 , y1 , x2, y2, x3, y3, x4,y4, x5, y5, x6, y6,xx, yy, al, al1;
        float err, x, y, dx, dy, dp, xEnd, p;
        float twody, twodxdy;
        
        printf ("Cordenadas inicial de la base: ");
		scanf("%f%f",&x1,&y1);
	 	printf ("Cordenadas final de la base :");
		scanf("%f%f",&x2,&y2);
		printf ("Ingresa los lados del poligono: ");
		scanf("%f",&al);

        /* initialize graphic driver */
        initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
        err = graphresult();

        if (err != grOk) {
                /* error occurred */
                printf("Graphics Error: %s\n",
                                grapherrormsg(err));
                return 0;
        }

        /* draws line from (0, 0) to (x2, y2) */
        dx = x2 - x1;
        dy = y2 - y1;

        twody = 2 * dy;
        p = 2 * (dy - dx);

        dp = twody - dx;

                x = x1;
                y = y1;
                
                 xx = x1;
                yy = y1;
    
        x3 = y2, y3 = x2;
        x4 = x2, y4 = x2;
        x5 = x1 ,y5 = x2;
        al1=al+x1;
        x6=al1, y6= al1;
        /* put a dot at the position (x, y) */
        putpixel(x, y, WHITE);

        /* calculate x and y successor and plot the points */
        			printf("\n");
        			
        for(w=0; w<=al;w++){
        while (x < x2) {
        		 putpixel(x, y, WHITE);
                x = x + 1;
                printf("X: %f ", x);
                if (p < 0) {
                        p = p + 2*dy;
                } else {
                        p = p + (2*dy) - (2*dx);
                        y = y + 1;
                         printf("Y: %f", y);	
                        printf("\n");
                }
                /* put a dot at the given position(x, y) */
       
    }
}
		            		
		            	

        getch();

        /* deallocate memory allocated for graphic screen */
        getchar();
		getchar();
        closegraph();
        
	return 0;
}
  
  
