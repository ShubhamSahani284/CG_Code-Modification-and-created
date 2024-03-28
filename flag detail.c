// Code Blocks - program for generating Indian flag
#include<windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#define PI 3.1614


void DrawChakra();
void staticFlag();

GLdouble ya=50  , xa=10 ;   // x is for horizonttal ttransition ;
int yflag =1, xflag=1, animflag=1;


float pos=0,x=0,col=0,i,p,c,cf=0,pr,pl=0;
int screen=0;

//Introduction Page
char college[100]="EWCE";
char dept[100]="Department of Computer Science & Engineering";
char heading[100]="Made by                                                                   Guide";
char row1[100]="Shubham Sahani (1EE20CS053)                                 Prof.Kumuda Roy";
char row2[100]="";
char emsg[100]="Press LEFT Mouse Button";
char title[50]="Animating Flag.....!";
char dash[100]="--------------------------------------------------------------------------------------";

void detail(void)
{
     glPushMatrix();
     glTranslatef(50,100,0);
     glClearColor(0.8,0.8,1.0,1.0);
     int s;
     glClear(GL_COLOR_BUFFER_BIT);

     glRasterPos2i(240,480);                                                    //displays college name
     for(s=0;college[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,1.0);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,college[s]);
     }

     glRasterPos2i(95,450);                                                     //displays dept.
     for(s=0;dept[s]!='\0';s++)
     {
     glColor3f(1.0,0.0,0.0);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,dept[s]);
     }

     glRasterPos2i(205,380);                                                    //displays project name
     for(s=0;title[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,0.0);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,title[s]);
     }

     glRasterPos2i(-40,370);                                                    //displays dashes
     for(s=0;dash[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,0.0);
     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,dash[s]);
     }

     glRasterPos2i(50,340);                                                    //displays heading of table
     for(s=0;heading[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,0.0);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,heading[s]);
     }

     glRasterPos2i(-40,330);                                                    //displays dashes
     for(s=0;dash[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,0.0);
     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,dash[s]);
     }

     glRasterPos2i(-20,310);                                                    //displays 1st row in table
     for(s=0;row1[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,0.0);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,row1[s]);
     }

     glRasterPos2i(0,290);                                                    //displays 2nd row in table
     for(s=0;row2[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,0.0);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,row2[s]);
     }

     glRasterPos2i(-40,290);                                                    //displays dashes
     for(s=0;dash[s]!='\0';s++)
     {
     glColor3f(0.0,0.0,0.0);
     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,dash[s]);
     }

     glRasterPos2i(160,100);                                                    //displays "enter msg"
     for(s=0;emsg[s]!='\0';s++)
     {
     glColor3f(1.0,0.0,0.5);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,emsg[s]);
     }

     glPopMatrix();
     glFlush();
}


void  Animate()
{
  if (animflag==0)
     staticFlag();

  else if (animflag==1)
 {
    //  for y co-ordinates
    if ( ya > -50 && yflag==1)
            ya=ya-0.1 ;
    if ( ya <=-50 && yflag==1)
            yflag =0 ;
    if ( ya<50 && yflag==0)
            ya=ya+0.1 ;
    if ( ya>=50 && yflag==0)
            yflag =1 ;

    //  for x co-ordinates
    if ( xa>-10 && xflag==1)
            xa = xa-0.1 ;
    if ( xa<=-10 && xflag==1)
            xflag = 0 ;
    if ( xa<10 && xflag==0)
            xa = xa+0.1 ;
    if ( xa>=10 && xflag==0)
            xflag = 1 ;
   }  // end of animation=1 commands


    glutPostRedisplay();

}
void staticFlag()
{
    if(screen==0)
    {
    detail();
    glFlush();
    }
  else{// to view the animation effects  one needs to invoke this API
    glClear(GL_COLOR_BUFFER_BIT);
   // x1[0] = 100;  x1[1] = 350;
   //y1[0] = 550;  y1[1] = 550 ;
   // y2[0] = 500;  y2[1] = 500 ;
   // y3[0] = 450;  y3[1] = 450 ;
   //y4[0] = 400;  y4[1] = 400 ;

    // commands to dra static flag
    glRecti( 90,560,100,50);
    glColor3f(1,0,0);
    glRectf( 100, 550, 350, 500 );
    glColor3f(1,1,1);
    glRecti( 100, 500, 350, 450);
    glColor3f(0,1,0);
    glRecti( 100, 450, 350, 400 );
    // TO DRAW A POLE IN WHITE COLOR
    glColor3f(1,1,1);
    glRecti( 90,560,100,50);
    //Ashok Chakra
    DrawChakra();
  }

}

void Draw()
{
    GLdouble  x[4], y1[4], y2[4], y3[4], y4[4]  ;
    GLdouble t, xt[400] , y1t[400] , y2t[400], y3t[400],  y4t[400];
    int  i, j;
    // to view the animation effects  one needs to invoke this API
    glClear(GL_COLOR_BUFFER_BIT);

    //assiging values to x,y coordinates of four(4) control points of the curve
    x[0] = 100;   x[1] = 200;        x[2] = 250;       x[3] = 350 ; //-xa;  //-xa to show change in x direction
    y1[0] = 550;  y1[1] = 550 + ya;  y1[2] = 550-ya;   y1[3] = 550;
    y2[0] = 500;  y2[1] = 500 + ya;  y2[2] = 500-ya;   y2[3] = 500;
    y3[0] = 450;  y3[1] = 450 + ya;  y3[2] = 450-ya;   y3[3] = 450;
    y4[0] = 400;  y4[1] = 400 + ya;  y4[2] = 400-ya;   y4[3] = 400;

    for (i=0 , t=0;  t<1;  i++, t=t+0.01)
    {
       xt[i]  = pow(1-t,3)*x[0] +  3*t*pow(1-t,2)*x[1] +  3*pow(t,2)*(1-t)*x[2] + pow(t,3)*x[3];
       y1t[i] = pow(1-t,3)*y1[0] +  3*t*pow(1-t,2)*y1[1] +  3*pow(t,2)*(1-t)*y1[2] + pow(t,3)*y1[3];
       y2t[i] = pow(1-t,3)*y2[0] +  3*t*pow(1-t,2)*y2[1] +  3*pow(t,2)*(1-t)*y2[2] + pow(t,3)*y2[3];
       y3t[i] = pow(1-t,3)*y3[0] +  3*t*pow(1-t,2)*y3[1] +  3*pow(t,2)*(1-t)*y3[2] + pow(t,3)*y3[3];
       y4t[i] = pow(1-t,3)*y4[0] +  3*t*pow(1-t,2)*y4[1] +  3*pow(t,2)*(1-t)*y4[2] + pow(t,3)*y4[3];
    }

    // FOR FIRST SET  OF CONTROL POINTS
    glPointSize (4) ;
    glColor3f(1,0,0);
    glBegin(GL_QUAD_STRIP);
   // glBegin( GL_POINTS );
    for ( i= 0; i < 100; i++ )
     {  glVertex2d( xt[i],  y1t[i] );
        glVertex2d( xt[i],  y2t[i] );
     }
    glEnd ( ) ;

    glPointSize (4) ;
    glColor3f(1,1,1);
    glBegin(GL_QUAD_STRIP);
   // glBegin( GL_POINTS );
    for ( j= 0; j < 100; j++ )
     {  glVertex2d( xt[j],  y2t[j] );
        glVertex2d( xt[j],  y3t[j] );
     }
    glEnd ( ) ;

    glPointSize(4) ;
    glColor3f(0,1,0);
    glBegin(GL_QUAD_STRIP);
   // glBegin( GL_POINTS );
    for ( int k= 0; k < 100; k++ )
     {  glVertex2d( xt[k],  y3t[k] );
        glVertex2d( xt[k],  y4t[k] );
     }
    glEnd();

    // TO DRAW A POLE IN WHITE COLOR
    glColor3f(1,1,1);
    glRecti( 90,560,100,50);
    DrawChakra();
    Animate();
    glClearColor(0, 0, 0, 1.0);
    glutPostRedisplay( ) ;

    glFlush( ) ;

}  //  end of  Draw function

void DrawChakra()
{
 glColor3f(0.0, 0.0, 1.0);  // Blue color
    glBegin(GL_TRIANGLE_FAN);

    // Specify the center of the inner circle
    float innerCircleCenterX = 220;
    float innerCircleCenterY = 475.5;

    // Specify the radius of the inner circle
    float innerCircleRadius = 1;

    // Draw the vertices for the inner circle
    glVertex2f(innerCircleCenterX, innerCircleCenterY);
    for (int i = 0; i <= 360; i += 5)
    {
        float angle = i * 3.14159 / 180;
        float x = innerCircleCenterX + innerCircleRadius * cos(angle);
        float y = innerCircleCenterY + innerCircleRadius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Set the properties for the outer circle
    glColor3f(0.0, 0.0, 1.0);  // Blue color
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);

    // Specify the center of the outer circle
    float outerCircleCenterX = 220;
    float outerCircleCenterY = 475.5;

    // Specify the radius of the outer circle
    float outerCircleRadius = 15;

    // Draw the vertices for the outer circle
    for (int i = 0; i <= 360; i += 5)
    {
        float angle = i * 3.14159 / 180;
        float x = outerCircleCenterX + outerCircleRadius * cos(angle);
        float y = outerCircleCenterY + outerCircleRadius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Set the properties for the spokes
    glColor3f(0.0, 0.0, 1.0);  // Blue color
    glLineWidth(1.0);
    glBegin(GL_LINES);

    // Draw the spokes
    for (int i = 0; i < 24; i++)
    {
        float angle = i * 15 * 3.14159 / 180;
        float innerX = innerCircleCenterX + innerCircleRadius * cos(angle);
        float innerY = innerCircleCenterY + innerCircleRadius * sin(angle);
        float outerX = outerCircleCenterX + outerCircleRadius * cos(angle);
        float outerY = outerCircleCenterY + outerCircleRadius * sin(angle);
        glVertex2f(innerX, innerY);
        glVertex2f(outerX, outerY);
    }
    glEnd();
}
void Menu(int n)
{
    if(n== 0){
        detail();
    }

    if (n == 1) {
        animflag = 1; // Start Animation Indian Flag
    }
    else if (n == 2) {
        animflag = 0; // Stop Animation
         staticFlag();
    }
    else if (n == 3) {
        animflag = 1; // Start Animation Karnataka Flag
        // Add code here to handle Karnataka flag animation
        // You can call a separate function to draw the Karnataka flag
    }
    else if (n == 4) {
        animflag = 0; // Stop Animation
        // Add code here to handle stopping the Karnataka flag animation
    }
    else if (n == 5) {
        exit(0); // Exit the program
    }
}

void myinit( )
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );
    gluOrtho2D(0, 600, 0, 600) ;
    glMatrixMode(GL_MODELVIEW);

    glutCreateMenu(Menu);
        glutAddMenuEntry("Details", 4);
    glutAddMenuEntry("Start Animation Indian Flag", 1);
    glutAddMenuEntry("Stop Animation Indian Flag", 2);
    glutAddMenuEntry("Start Animation Karnataka Flag", 3); // Add the Karnataka flag option
    glutAddMenuEntry("Stop Animation Karnataka Flag", 0); // Add the stop Karnataka flag option
    glutAddMenuEntry("Exit", 5);
    glutAttachMenu(GLUT_LEFT_BUTTON);

}

int main( int argc , char* argv[] )
{
    glutInit( &argc ,  argv );
    glutInitWindowSize(800, 800) ;
    glutInitWindowPosition(100, 100) ;
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Animate Flag");
    myinit();
    glutDisplayFunc(staticFlag);
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;

}
// Code Blocks - program for generating Indian flag
