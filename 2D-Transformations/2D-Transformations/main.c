//
//  main.c
//  2D-Transformations
//
//  Created by B Raghu Ram Reddy  on 06/02/17.
//  Copyright © 2017 B Raghu Ram Reddy . All rights reserved.
//

#include <stdio.h>
#include<GLUT/glut.h>
#include <OpenGL/gl.h>
#include <stdlib.h>
#include <math.h>

#define ROUND(x) ((int)(x+0.5))

int matrix[4];
int a,b;


void mM(int xxx,int yyy){
    a = (xxx)*(matrix[0]) + (yyy)*(matrix[1]);
    b = (xxx)*(matrix[2]) + (yyy)*(matrix[3]);
}


void drawPolygon(void)
{
  
////inputs
    int choice,n;
    int scale;
    printf("Enter the number of points");
    scanf("%d", &n);
    printf("%d", n);
    int xx[n], xarr[n];
    int yy[n], yarr[n];
    
    printf("Enter the points\n");
    for(int i = 0; i<n; i++){
        scanf("%d",&xx[i]);
        scanf("%d",&yy[i]);
    }
    
//choice for transformation
    printf("Enter the Choice\n");
    printf("\t 1.Scaling \n\t 2.Reflection \n\t 3.Shear \n\t 4.Rotation \n\t5.Translation");
    scanf("%d", &choice);
    

//scaling
    if(choice == 1){
        printf("Enter the scale \n");
        scanf("%d",&scale);
            matrix[0] = scale;
            matrix[1] = 0;
            matrix[2] = 0;
            matrix[3] = scale;
        for(int i = 0; i<n; i++){
            mM(xx[i],yy[i]);
            printf("%d - - %d \n",a,b);
            xarr[i] = a; yarr[i] = b;
        }
        
        
    }
    
//Reflection
    else if(choice == 2){
        printf("Select the axis \n\t 1.About x-axis \n\t 2.About y-axis \n");
        int ax;
        scanf("%d",&ax);
        if(ax == 1){
            matrix[0] = 1;
            matrix[1] = 0;
            matrix[2] = 0;
            matrix[3] = -1;
        }
        else if(ax == 2){
            matrix[0] = -1;
            matrix[1] = 0;
            matrix[2] = 0;
            matrix[3] = 1;
        }
        else{
            return;
        }
        for(int i = 0; i<n; i++){
            mM(xx[i],yy[i]);
            printf("%d - - %d \n",a,b);
            xarr[i] = a; yarr[i] = b;
        }
        
    }
    
//Shear
    else if(choice == 3){
        printf("Select the axis \n\t 1.Along x-axis \n\t 2.Along y-axis \n");
        int ax;
        printf("Enter the shear amount");
        scanf("%d",&scale);
        if(ax == 1){
            matrix[0] = 1;
            matrix[1] = 0;
            matrix[2] = scale;
            matrix[3] = 1;
        }
        else if(ax == 2){
            matrix[0] = 1;
            matrix[1] = scale;
            matrix[2] = 0;
            matrix[3] = 1;
        }
        else{
            return;
        }
        for(int i = 0; i<n; i++){
            mM(xx[i],yy[i]);
            printf("%d - - %d \n",a,b);
            xarr[i] = a; yarr[i] = b;
        }

        
    }
    
//Rotation
    else if(choice == 4){
        printf("Enter the degree of rotation(0<input<360) \nNotice: Rotation is assumed to be about the origin");
        int degree;
        scanf("%d",&degree);
        float degree2 = degree*((3.14)/180);
        
        for(int i = 0; i<n; i++){
            
            xarr[i] = (cosf(degree2)*xx[i])-(sinf(degree2)*yy[i]);
            yarr[i] = (sinf(degree2)*xx[i])+(cosf(degree2)*yy[i]);
        }
        
        
    }
    
//Translation
    else if(choice == 5){
        int dx, dy;
        printf("Enter the values of delta-x and delta-y: \nNotice: \n\t new-x = x+ (delta-x) \n\t new-y = y+ (delta-y)");
        scanf("%d",&dx);
        scanf("%d",&dy);
        
        for(int i = 0; i<n; i++){
            xarr[i] = xx[i]+dx;
            yarr[i] = yy[i]+dy;
            
        }
        
    }
    
    else{
        return;
    }
    
    
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    
    
    
    for(int i=0; i<n; i++){
        printf("%d - %d \n",xarr[i],yarr[i]);
        glVertex2s(xarr[i],yarr[i]);
    }
    
    
    
    
    glEnd();
    
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    for(int i=0; i<n; i++){
        printf("%d - %d \n",xarr[i],yarr[i]);
        glVertex2s(xx[i],yy[i]);
    }
    glEnd();
    

    glFlush();


    
}


void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}


int main(int argc, const char * argv[]) {

    // insert code here...
    //int choice;
    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Transformations");
    init ();
    glutDisplayFunc(drawPolygon);
    glutMainLoop();
    
    return 0;
}




