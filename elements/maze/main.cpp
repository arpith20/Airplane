#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<iostream>
using namespace std;
//#include "src/SOIL.h"
//GLuint tex_2d;
int x,y;
int i,count,sc=0,var=1,var1=1;
char t[2],score[50];
float px=0.0,py=175.0,ax=48,ay=120,cx,cy,r,a,b,theta;             //change py back to 175.0
int flag=1, df=101,ii,specular,diffuse,emissive,flag1=1;
clock_t start,end;
//GLuint linktex;
//GLfloat ambient = {.2,.2,.2,1};

int score2;
void update_score()
{
        //cout<<px<<" "<<py<<endl;
        if(py==175&&px==100||py==100&&px==105)



        //write other coordinates/conditions here
        {
                score2++;
                cout<<"passed!"<<score2<<" Coordinates: "<<py<<" "<<px<<endl;
        }
}

GLfloat redDiffuseMaterial[] = {1.0, 0.0, 0.0}; //set the
//material to red
GLfloat whiteSpecularMaterial[] = {1.0, 1.0, 1.0}; //set
//the material to white
GLfloat greenEmissiveMaterial[] = {0.0, 1.0, 0.0}; //set
//the material to green
GLfloat whiteSpecularLight[] = {1.0, 1.0, 1.0}; //set the
//light specular to white
GLfloat blackAmbientLight[] = {0.0, 0.0, 0.0}; //set the
//light ambient to black
GLfloat whiteDiffuseLight[] = {1.0, 1.0, 1.0}; //set the
//diffuse light to white
GLfloat blankMaterial[] = {0.0, 0.0, 0.0}; //set the diffuse
 //light to white
GLfloat mShininess[] = {128}; //set the shininess of the
//material

//bool diffuse = 0;
//bool emissive = 0;
//bool specular = 0;



void point()               //remove comment
{

 glColor3f(0.0,0.7,1.0);
 glBegin(GL_POINTS);
 glVertex2f(px,py);
 glEnd();
}
/*void point1()
{                                 //comment

 glColor3f(0.6,1.0,0.3);
 glBegin(GL_POINTS);
 glVertex2f(ax,ay);
 glEnd();
}*/
void point2()
{                                             //remove comment

/*GLfloat diffuse[] = {.5,1,.4,0};
GLfloat ambient[] = {.5,1,1,0};
GLfloat specular[] = {.5,1,.2,0};
GLfloat light0_pos[] = {1,4,6,8};*/

 glColor3f(1.0,0.0,.0);
   /*  glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
glLightfv(GL_LIGHT0, GL_SPECULAR, specular);*/

 glBegin(GL_POINTS);
 glVertex2f(px,py);
 glEnd();
}


void draw_circle(float ax, float ay, float r, int num_segments)     //
{

    glColor3f(0.,0.0,1.0);

    glBegin(GL_POLYGON);
    for( ii = 0; ii < num_segments; ii++)
    {
         theta = 2.0f * 3.1415926f * (ii) /(num_segments);//get the current angle

         a = r * cosf(theta);//calculate the x component
         b = r * sinf(theta);//calculate the y component

        glVertex2f(a + ax, b + ay);//output vertex

    }
    glEnd();
}




void output(int x, int y, char *string)
{
      int len, i;

           glRasterPos2f(x,y);
           len=(int) strlen(string);
           for (i = 0; i < len; i++)
            {
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
            }
}

void drawstring(int x, int y, char *string,void *font)
{
      int len, i;

           glRasterPos2f(x,y);
           len=(int) strlen(string);
           for (i = 0; i < len; i++)
            {
             glutBitmapCharacter(font,string[i]);
            }
}

/*void score()
{
    int sc=0;
    if(px==125 && py==70)
    {
        sc+=1;
    }
    printf("score is:%d",sc);

}*/





 void frontscreen(void)
{



    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1,0,0);
    //drawstring(150,55," Press ENTER ",GLUT_BITMAP_HELVETICA_18);   //change
    glColor3f(0.7,1,0.3);
    output(67,130,"The Amazing Race");
    glColor3f(1,0,1);
    output(180,25,"By :");
    glColor3f(1,1,0);
    output(190,25,"Deepak Muddebihal ");
    output(190,20,"Dattatreya Biswas");
                        //circle
    //poly();

   /* GLuint tex_2d = SOIL_load_OGL_texture
	(
		"img.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	if( 0 == tex_2d )
{
	printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
}*/
                                                 //change

    glColor3f(0.0,1.0,0.0);
    //output(25,140,"The Amazing Race");                         //change
    output(70,85,"1.Start new game");
    output(70,75,"2.Instructions");
    output(70,65,"3.Quit game");
    glFlush();


}

 void winningscreen()
 {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0.0,1.0,0.0);
    output(55,120,"Congratulations!!!");
    glColor3f(1.0,0.0,1.0);

     //score();
     sprintf(score,"%d",sc/2);
        output(35,75,score);


     output(35,60,"-> Press Esc to goto main");
     //output(35,45,"-> Press 1 to restart game");           //change
    glFlush();
 }
/*void startscreen()                                         //change
{

glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,1.0,0.0);
output(25,140,"The Amazing Race");
output(50,100,"1.Start new game");
output(50,80,"2.Instructions");
output(50,60,"3.Quit game");
glFlush();




}*/

void instructions()
{
  glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    output(60,130,"INSTRUCTIONS:");
    glBegin(GL_LINES);
    glVertex2f(59,128);
    glVertex2f(107,128);
    glEnd();
    glColor3f(0,1,0);
  output(40,100,"-> Use arrow keys to move");
  output(40,90,"-> Blue colored cube is the starting point");
  output(40,80,"-> Red colored cube is the destination");
  output(40,70,"-> Count down of 1 minute");
  output(40,60,"-> Press Esc to goto main menu");
   glFlush();
}

void timeover()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,0,0);
 output(70,110,"Time up");                                    // change
 glColor3f(0,1,0);
 output(40,40,"-> Press Esc to goto main");
 //output(40,30,"-> Press 1 to restart game");                 //change
 glFlush();
}

void idle()
{
  if(df==1)
  {
    end=clock();
    count=(end-start)/CLOCKS_PER_SEC;
    if(count==60)
    {
       df=4;                             //timeup
    }
    else
    if((count<60) && (((px>=0 && px<=4) && (py>=162 && py<=168)) || ((px>=-9 && px<=1) && (py>=-6 && py<=6))) )
    {
        df=5;
    }
  }

   glutPostRedisplay();
}

void wall(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2,GLfloat x3,GLfloat y3,GLfloat x4,GLfloat y4)
{

  glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
  glEnd();

}

void SpecialKey(int key, int x, int y)
{
  switch (key)
  {
    case GLUT_KEY_UP:
       // flag=0;
        if(py<175)
        if(!((px>=8 && px<=12) && (py>=145 && py<=162)))
        if(!((px>=168 && px<=172) && (py>=5 && py<=22)))
        if(!((px>=132 && px<=172) && (py>=15 && py<=22)))
        if(!((px>=128 && px<=132) && (py>=5 && py<=32)))
        if(!((px>=142 && px<=162) && (py>=5 && py<=12)))
        if(!((px>=118 && px<=152) && (py>=25 && py<=32)))
        if(!((px>=88 && px<=122) && (py>=5 && py<=12)))
        if(!((px>=48 && px<=82) && (py>=5 && py<=12)))
        if(!((px>=62 && px<=82) && (py>=15 && py<=22)))
        if(!((px>=8 && px<=12) && (py>=5 && py<=18)))
        if(!((px>=0 && px<=12) && (py>=15 && py<=22)))
        if(!((px>=42 && px<=52) && (py>=25 && py<=32)))
        if(!((px>=18 && px<=42) && (py>=5 && py<=12)))
        if(!((px>=0 && px<=8) && (py>=155 && py<=162)))
        if(!((px>=0 && px<=72) && (py>=165 && py<=172)))       //PY>=165
        if(!((px>=18 && px<=62) && (py>=155 && py<=162)))

        if(!((px>=68 && px<=73) && (py>=150 && py<=158)))       //extra addition

        if(!((px>=48 && px<=52) && (py>=125 && py<=158)))
        if(!((px>=18 && px<=48) && (py>=145 && py<=152)))
        if(!((px>=18 && px<=38) && (py>=135 && py<=142)))
        if(!((px>=68 && px<=112) && (py>=145 && py<=152)))
        if(!((px>=88 && px<=118) && (py>=135 && py<=142)))
        if(!((px>=132 && px<=138) && (py>=155 && py<=162)))
        if(!((px>=138 && px<=142) && (py>=135 && py<=162)))
        if(!((px>=128 && px<=162) && (py>=125 && py<=132)))
        if(!((px>=78 && px<=122) && (py>=155 && py<=162)))
        if(!((px>=78 && px<=102) && (py>=165 && py<=172)))
        if(!((px>=108 && px<=142) && (py>=165 && py<=172)))
        if(!((px>=148 && px<=180) && (py>=165 && py<=172)))
        if(!((px>=138 && px<=152) && (py>=65 && py<=72)))
        if(!((px>=148 && px<=172) && (py>=155 && py<=162)))
        if(!((px>=148 && px<=172) && (py>=165 && py<=172)))
        if(!((px>=148 && px<=172) && (py>=95 && py<=102)))
        if(!((px>=158 && px<=168) && (py>=145 && py<=152)))
        if(!((px>=158 && px<=168) && (py>=135 && py<=142)))
        if(!((px>=168 && px<=172) && (py>=119 && py<=162)))
        if(!((px>=152 && px<=172) && (py>=115 && py<=122)))
        if(!((px>=138 && px<=148) && (py>=105 && py<=112)))
        if(!((px>=148 && px<=152) && (py>=95 && py<=122)))
        if(!((px>=158 && px<=172) && (py>=105 && py<=112)))
        if(!((px>=162 && px<=172) && (py>=105 && py<=112)))
        if(!((px>=158 && px<=162) && (py>=89 && py<=112)))
        if(!((px>=158 && px<=180) && (py>=85 && py<=92)))
        if(!((px>=132 && px<=142) && (py>=115 && py<=122)))
        if(!((px>=128 && px<=132) && (py>=109 && py<=122)))
        if(!((px>=122 && px<=132) && (py>=105 && py<=112)))
        if(!((px>=118 && px<=122) && (py>=99 && py<=162)))
        if(!((px>=108 && px<=142) && (py>=95 && py<=102)))
        if(!((px>=128 && px<=132) && (py>=89 && py<=98)))
        if(!((px>=128 && px<=152) && (py>=85 && py<=92)))
        if(!((px>=148 && px<=152) && (py>=79 && py<=88)))
        if(!((px>=118 && px<=152) && (py>=75 && py<=82)))
        if(!((px>=92 && px<=122) && (py>=85 && py<=92)))
        if(!((px>=92 && px<=102) && (py>=95 && py<=102)))
        if(!((px>=118 && px<=122) && (py>=75 && py<=88)))
        if(!((px>=88 && px<=92) && (py>=85 && py<=118)))
        if(!((px>=58 && px<=62) && (py>=125 && py<=152)))
        if(!((px>=108 && px<=112) && (py>=109 && py<=128)))
        if(!((px>=58 && px<=112) && (py>=125 && py<=132)))
        if(!((px>=98 && px<=102) && (py>=109 && py<=118)))
        if(!((px>=48 && px<=52) && (py>=15 && py<=32)))
        if(!((px>=32 && px<=42) && (py>=105 && py<=112)))
        if(!((px>=12 && px<=28) && (py>=125 && py<=132)))
        if(!((px>=28 && px<=32) && (py>=105 && py<=132)))
        if(!((px>=8 && px<=12) && (py>=119 && py<=132)))
        if(!((px>=0 && px<=22) && (py>=115 && py<=122)))
        if(!((px>=18 && px<=22) && (py>=109 && py<=122)))
        if(!((px>=12 && px<=22) && (py>=105 && py<=112)))
        if(!((px>=8 && px<=12) && (py>=85 && py<=112)))
        if(!((px>=98 && px<=112) && (py>=105 && py<=112)))
        if(!((px>=38 && px<=102) && (py>=115 && py<=122)))
        if(!((px>=48 && px<=52) && (py>=109 && py<=118)))
        if(!((px>=48 && px<=78) && (py>=105 && py<=112)))
        if(!((px>=82 && px<=102) && (py>=75 && py<=82)))
        if(!((px>=78 && px<=82) && (py>=65 && py<=112)))
        if(!((px>=72 && px<=78) && (py>=95 && py<=102)))
        if(!((px>=62 && px<=72) && (py>=65 && py<=72)))
        if(!((px>=28 && px<=32) && (py>=119 && py<=152)))
        if(!((px>=92 && px<=108) && (py>=65 && py<=72)))
        if(!((px>=88 && px<=92) && (py>=59 && py<=72)))
        if(!((px>=62 && px<=92) && (py>=55 && py<=62)))
        if(!((px>=38 && px<=58) && (py>=75 && py<=82)))
        if(!((px>=68 && px<=72) && (py>=45 && py<=62)))
        if(!((px>=8 && px<=12) && (py>=65 && py<=82)))
        if(!((px>=32 && px<=62) && (py>=85 && py<=92)))
        if(!((px>=28 && px<=52) && (py>=65 && py<=72)))
        if(!((px>=32 && px<=52) && (py>=55 && py<=62)))
        if(!((px>=28 && px<=32) && (py>=55 && py<=98)))
        if(!((px>=18 && px<=62) && (py>=95 && py<=102)))
        if(!((px>=0 && px<=18) && (py>=75 && py<=82)))
        if(!((px>=18 && px<=22) && (py>=59 && py<=92)))
        if(!((px>=12 && px<=22) && (py>=55 && py<=62)))
        if(!((px>=8 && px<=52) && (py>=45 && py<=52)))
        if(!((px>=18 && px<=22) && (py>=39 && py<=48)))
        if(!((px>=12 && px<=22) && (py>=35 && py<=42)))
        if(!((px>=8 && px<=12) && (py>=25 && py<=42)))
        if(!((px>=118 && px<=122) && (py>=59 && py<=72)))
        if(!((px>=112 && px<=122) && (py>=55 && py<=62)))
        if(!((px>=138 && px<=152) && (py>=55 && py<=62)))
        if(!((px>=148 && px<=158) && (py>=45 && py<=52)))
        if(!((px>=138 && px<=142) && (py>=39 && py<=72)))
        if(!((px>=128 && px<=132) && (py>=49 && py<=72)))
        if(!((px>=122 && px<=132) && (py>=45 && py<=52)))
        if(!((px>=118 && px<=122) && (py>=35 && py<=52)))
        if(!((px>=118 && px<=158) && (py>=35 && py<=42)))
        if(!((px>=158 && px<=162) && (py>=35 && py<=78)))
        if(!((px>=158 && px<=168) && (py>=75 && py<=82)))
        if(!((px>=168 && px<=172) && (py>=29 && py<=82)))
        if(!((px>=168 && px<=180) && (py>=25 && py<=32)))
        if(!((px>=98 && px<=108) && (py>=15 && py<=22)))
        if(!((px>=108 && px<=112) && (py>=15 && py<=82)))
        if(!((px>=88 && px<=92) && (py>=35 && py<=48)))
        if(!((px>=68 && px<=92) && (py>=45 && py<=52)))
        if(!((px>=98 && px<=102) && (py>=29 && py<=62)))
        if(!((px>=78 && px<=82) && (py>=25 && py<=48)))
        if(!((px>=68 && px<=72) && (py>=25 && py<=38)))
        if(!((px>=32 && px<=72) && (py>=35 && py<=42)))
        if(!((px>=22 && px<=32) && (py>=19 && py<=22)))
        if(!((px>=22 && px<=32) && (py>=15 && py<=22)))
        if(!((px>=18 && px<=22) && (py>=15 && py<=32)))
        if(!((px>=78 && px<=102) && (py>=25 && py<=32)))
        if(!((px>=88 && px<=92) && (py>=9 && py<=28)))


        py=py+5;
update_score();
        if((py==70 || py==175 || py==155  || py==10) && flag1==1)
        {
            if(var<=4)
            {
               sc+=1;
               var+=1;
            }
            else { flag1=0;}


        }


        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:

   // flag=0;
        if(py>5)
        if(!((px>=0 && px<=8) && (py>=158 && py<=165)))
        if(!((px>=8 && px<=12) && (py>=148 && py<=165)))
        if(!((px>=0 && px<=72) && (py>=168 && py<=175)))
        if(!((px>=18 && px<=62) && (py>=158 && py<=165)))
        if(!((px>=18 && px<=48) && (py>=148 && py<=155)))
        if(!((px>=18 && px<=38) && (py>=138 && py<=145)))
        if(!((px>=72 && px<=82) && (py>=138 && py<=145)))
        if(!((px>=68 && px<=112) && (py>=148 && py<=155)))
        if(!((px>=88 && px<=118) && (py>=138 && py<=145)))
        if(!((px>=132 && px<=138) && (py>=158 && py<=165)))
        if(!((px>=138 && px<=152) && (py>=68 && py<=75)))
        if(!((px>=108 && px<=142) && (py>=168 && py<=175)))
        if(!((px>=128 && px<=162) && (py>=128 && py<=135)))
        if(!((px>=68 && px<=72) && (py>=158 && py<=175)))
        if(!((px>=78 && px<=122) && (py>=158 && py<=165)))
        if(!((px>=78 && px<=102) && (py>=168 && py<=175)))
        if(!((px>=148 && px<=180) && (py>=168 && py<=175)))
        if(!((px>=148 && px<=172) && (py>=158 && py<=165)))
        if(!((px>=148 && px<=172) && (py>=168 && py<=175)))
        if(!((px>=148 && px<=172) && (py>=98 && py<=105)))
        if(!((px>=158 && px<=168) && (py>=148 && py<=155)))
        if(!((px>=158 && px<=168) && (py>=138 && py<=145)))
        if(!((px>=148 && px<=172) && (py>=118 && py<=125)))
        if(!((px>=138 && px<=148) && (py>=108 && py<=115)))
        if(!((px>=158 && px<=172) && (py>=108 && py<=115)))
        if(!((px>=162 && px<=172) && (py>=108 && py<=115)))
        if(!((px>=158 && px<=180) && (py>=88 && py<=95)))
        if(!((px>=132 && px<=142) && (py>=118 && py<=125)))
        if(!((px>=122 && px<=132) && (py>=108 && py<=115)))
        if(!((px>=108 && px<=142) && (py>=98 && py<=105)))
        if(!((px>=128 && px<=152) && (py>=88 && py<=95)))
        if(!((px>=118 && px<=152) && (py>=78 && py<=85)))
        if(!((px>=92 && px<=122) && (py>=88 && py<=95)))
        if(!((px>=92 && px<=102) && (py>=98 && py<=105)))
        if(!((px>=118 && px<=152) && (py>=28 && py<=35)))
        if(!((px>=88 && px<=92) && (py>=88 && py<=121)))
        if(!((px>=58 && px<=62) && (py>=128 && py<=155)))
        if(!((px>=108 && px<=112) && (py>=112 && py<=131)))
        if(!((px>=58 && px<=112) && (py>=128 && py<=135)))
        if(!((px>=98 && px<=102) && (py>=112 && py<=121)))
        if(!((px>=38 && px<=42) && (py>=102 && py<=115)))
        if(!((px>=32 && px<=42) && (py>=108 && py<=115)))
        if(!((px>=12 && px<=28) && (py>=128 && py<=135)))
        if(!((px>=28 && px<=32) && (py>=108 && py<=135)))
        if(!((px>=8 && px<=12) && (py>=122 && py<=135)))
        if(!((px>=0 && px<=22) && (py>=118 && py<=125)))
        if(!((px>=18 && px<=22) && (py>=112 && py<=125)))
        if(!((px>=12 && px<=22) && (py>=108 && py<=115)))
        if(!((px>=8 && px<=12) && (py>=88 && py<=115)))
        if(!((px>=98 && px<=112) && (py>=108 && py<=115)))
        if(!((px>=38 && px<=102) && (py>=118 && py<=125)))
        if(!((px>=48 && px<=52) && (py>=112 && py<=118)))
        if(!((px>=48 && px<=78) && (py>=108 && py<=115)))
        if(!((px>=82 && px<=102) && (py>=78 && py<=85)))
        if(!((px>=78 && px<=82) && (py>=68 && py<=115)))
        if(!((px>=72 && px<=78) && (py>=98 && py<=105)))
        if(!((px>=68 && px<=72) && (py>=72 && py<=105)))
        if(!((px>=62 && px<=72) && (py>=68 && py<=75)))
        if(!((px>=28 && px<=32) && (py>=122 && py<=155)))
        if(!((px>=92 && px<=108) && (py>=68 && py<=75)))
        if(!((px>=88 && px<=92) && (py>=62 && py<=75)))
        if(!((px>=62 && px<=92) && (py>=58 && py<=65)))
        if(!((px>=38 && px<=58) && (py>=78 && py<=85)))
        if(!((px>=68 && px<=72) && (py>=48 && py<=65)))
        if(!((px>=8 && px<=12) && (py>=68 && py<=85)))
        if(!((px>=32 && px<=62) && (py>=88 && py<=95)))
        if(!((px>=28 && px<=52) && (py>=68 && py<=75)))
        if(!((px>=32 && px<=52) && (py>=58 && py<=65)))
        if(!((px>=28 && px<=32) && (py>=58 && py<=101)))
        if(!((px>=18 && px<=62) && (py>=98 && py<=105)))
        if(!((px>=0 && px<=18) && (py>=78 && py<=85)))
        if(!((px>=18 && px<=22) && (py>=62 && py<=95)))
        if(!((px>=12 && px<=22) && (py>=58 && py<=65)))
        if(!((px>=8 && px<=12) && (py>=52 && py<=65)))
        if(!((px>=8 && px<=52) && (py>=48 && py<=55)))
        if(!((px>=18 && px<=22) && (py>=42 && py<=51)))
        if(!((px>=12 && px<=22) && (py>=38 && py<=45)))
        if(!((px>=8 && px<=12) && (py>=28 && py<=45)))
        if(!((px>=118 && px<=122) && (py>=62 && py<=75)))
        if(!((px>=112 && px<=122) && (py>=58 && py<=65)))
        if(!((px>=142 && px<=152) && (py>=58 && py<=65)))
        if(!((px>=148 && px<=158) && (py>=48 && py<=55)))
        if(!((px>=138 && px<=142) && (py>=42 && py<=75)))
        if(!((px>=128 && px<=132) && (py>=52 && py<=75)))
        if(!((px>=122 && px<=132) && (py>=48 && py<=55)))
        if(!((px>=118 && px<=122) && (py>=38 && py<=55)))
        if(!((px>=118 && px<=158) && (py>=38 && py<=45)))
        if(!((px>=158 && px<=162) && (py>=38 && py<=78)))
        if(!((px>=158 && px<=168) && (py>=78 && py<=85)))
        if(!((px>=168 && px<=172) && (py>=32 && py<=85)))
        if(!((px>=168 && px<=180) && (py>=28 && py<=35)))
        if(!((px>=98 && px<=108) && (py>=18 && py<=25)))
        if(!((px>=108 && px<=112) && (py>=18 && py<=85)))
        if(!((px>=88 && px<=92) && (py>=38 && py<=53)))
        if(!((px>=68 && px<=92) && (py>=48 && py<=55)))
        if(!((px>=98 && px<=102) && (py>=32 && py<=65)))
        if(!((px>=78 && px<=82) && (py>=28 && py<=53)))
        if(!((px>=68 && px<=72) && (py>=28 && py<=43)))
        if(!((px>=32 && px<=72) && (py>=38 && py<=45)))
        if(!((px>=28 && px<=32) && (py>=18 && py<=45)))
        if(!((px>=22 && px<=32) && (py>=18 && py<=25)))
        if(!((px>=18 && px<=22) && (py>=18 && py<=35)))
        if(!((px>=78 && px<=102) && (py>=28 && py<=35)))
        if(!((px>=88 && px<=92) && (py>=12 && py<=31)))
        if(!((px>=118 && px<=122) && (py>=8 && py<=35)))
        if(!((px>=158 && px<=162) && (py>=22 && py<=35)))
        if(!((px>=168 && px<=172) && (py>=8 && py<=25)))
        if(!((px>=132 && px<=172) && (py>=18 && py<=25)))
        if(!((px>=128 && px<=132) && (py>=8 && py<=35)))
        if(!((px>=142 && px<=162) && (py>=8 && py<=15)))
        if(!((px>=138 && px<=142) && (py>=0 && py<=15)))
        if(!((px>=88 && px<=122) && (py>=8 && py<=15)))
        if(!((px>=48 && px<=82) && (py>=8 && py<=15)))
        if(!((px>=62 && px<=82) && (py>=18 && py<=25)))
        if(!((px>=8 && px<=12) && (py>=8 && py<=21)))
        if(!((px>=0 && px<=12) && (py>=18 && py<=25)))
        if(!((px>=58 && px<=62) && (py>=8 && py<=85)))
        if(!((px>=48 && px<=52) && (py>=18 && py<=31)))
        if(!((px>=42 && px<=52) && (py>=28 && py<=35)))
        if(!((px>=38 && px<=42) && (py>=0 && py<=35)))
        if(!((px>=18 && px<=42) && (py>=8 && py<=15)))



        py=py-5;
update_score();
          if((py==70 || py==175 || py==155 || py==10) && flag1==1)
          {

            if(var<=4)
            {
               sc+=1;
               var+=1;
            }
            else { flag1=0;}


        }
        glutPostRedisplay();
        break;

    case GLUT_KEY_LEFT:
       // flag=0;
        if(px>-4)                                          //change px>0
        if(!((px>=8 && px<=15) && (py>=148 && py<=162)))
        if(!((px>=68 && px<=75) && (py>=158 && py<=168)))
        if(!((px>=138 && px<=155) && (py>=68 && py<=72)))
        if(!((px>=18 && px<=25) && (py>=162 && py<=168)))
        if(!((px>=18 && px<=65) && (py>=58 && py<=62)))
        if(!((px>=48 && px<=55) && (py>=128 && py<=158)))
        if(!((px>=18 && px<=25) && (py>=142 && py<=148)))
        if(!((px>=38 && px<=45) && (py>=122 && py<=142)))
        if(!((px>=72 && px<=85) && (py>=138 && py<=142)))
        if(!((px>=68 && px<=75) && (py>=132 && py<=148)))
        if(!((px>=68 && px<=115) && (py>=148 && py<=152)))
        if(!((px>=138 && px<=145) && (py>=138 && py<=162)))
        if(!((px>=18 && px<=145) && (py>=168 && py<=172)))
        if(!((px>=128 && px<=135) && (py>=132 && py<=172)))
        if(!((px>=128 && px<=165) && (py>=128 && py<=132)))
        if(!((px>=68 && px<=75) && (py>=158 && py<=172)))
        if(!((px>=78 && px<=125) && (py>=158 && py<=162)))
        if(!((px>=98 && px<=105) && (py>=162 && py<=172)))
        if(!((px>=78 && px<=105) && (py>=168 && py<=172)))
        if(!((px>=108 && px<=145) && (py>=168 && py<=172)))
        if(!((px>=148 && px<=180) && (py>=168 && py<=172)))
        if(!((px>=148 && px<=155) && (py>=132 && py<=162)))
        if(!((px>=148 && px<=175) && (py>=158 && py<=162)))
        if(!((px>=148 && px<=175) && (py>=168 && py<=172)))
        if(!((px>=148 && px<=175) && (py>=98 && py<=102)))
        if(!((px>=168 && px<=175) && (py>=122 && py<=162)))
        if(!((px>=152 && px<=175) && (py>=118 && py<=122)))
        if(!((px>=148 && px<=155) && (py>=98 && py<=122)))
        if(!((px>=158 && px<=175) && (py>=108 && py<=112)))
        if(!((px>=162 && px<=175) && (py>=108 && py<=112)))
        if(!((px>=158 && px<=165) && (py>=92 && py<=112)))
        if(!((px>=158 && px<=180) && (py>=88 && py<=92)))
        if(!((px>=132 && px<=145) && (py>=118 && py<=122)))
        if(!((px>=128 && px<=135) && (py>=112 && py<=122)))
        if(!((px>=122 && px<=135) && (py>=108 && py<=112)))
        if(!((px>=118 && px<=125) && (py>=102 && py<=162)))
        if(!((px>=108 && px<=145) && (py>=98 && py<=102)))
        if(!((px>=128 && px<=135) && (py>=92 && py<=98)))
        if(!((px>=128 && px<=155) && (py>=88 && py<=92)))
        if(!((px>=148 && px<=155) && (py>=82 && py<=88)))
        if(!((px>=118 && px<=155) && (py>=78 && py<=82)))
        if(!((px>=92 && px<=125) && (py>=88 && py<=92)))
        if(!((px>=92 && px<=105) && (py>=98 && py<=102)))
        if(!((px>=118 && px<=125) && (py>=78 && py<=88)))
        if(!((px>=88 && px<=95) && (py>=88 && py<=118)))
        if(!((px>=58 && px<=65) && (py>=128 && py<=152)))
        if(!((px>=108 && px<=115) && (py>=112 && py<=128)))
        if(!((px>=58 && px<=115) && (py>=128 && py<=132)))
        if(!((px>=98 && px<=105) && (py>=112 && py<=118)))
        if(!((px>=38 && px<=45) && (py>=102 && py<=108)))
        if(!((px>=32 && px<=45) && (py>=108 && py<=112)))
        if(!((px>=28 && px<=35) && (py>=108 && py<=132)))
        if(!((px>=8 && px<=15) && (py>=122 && py<=132)))
        if(!((px>=0 && px<=25) && (py>=118 && py<=122)))
        if(!((px>=18 && px<=25) && (py>=112 && py<=122)))
        if(!((px>=12 && px<=25) && (py>=108 && py<=112)))
        if(!((px>=8 && px<=15) && (py>=88 && py<=112)))
        if(!((px>=98 && px<=115) && (py>=108 && py<=112)))
        if(!((px>=38 && px<=105) && (py>=118 && py<=122)))
        if(!((px>=48 && px<=55) && (py>=112 && py<=118)))
        if(!((px>=82 && px<=105) && (py>=78 && py<=82)))
        if(!((px>=78 && px<=85) && (py>=68 && py<=112)))
        if(!((px>=68 && px<=75) && (py>=72 && py<=102)))
        if(!((px>=62 && px<=75) && (py>=68 && py<=72)))
        if(!((px>=28 && px<=35) && (py>=108 && py<=132)))
        if(!((px>=88 && px<=95) && (py>=62 && py<=72)))
        if(!((px>=62 && px<=95) && (py>=58 && py<=62)))
        if(!((px>=68 && px<=75) && (py>=48 && py<=62)))
        if(!((px>=8 && px<=15) && (py>=68 && py<=82)))
        if(!((px>=32 && px<=65) && (py>=88 && py<=92)))
        if(!((px>=28 && px<=55) && (py>=68 && py<=72)))
        if(!((px>=32 && px<=55) && (py>=58 && py<=62)))
        if(!((px>=28 && px<=35) && (py>=58 && py<=98)))
        if(!((px>=18 && px<=65) && (py>=98 && py<=102)))    //for test
        if(!((px>=18 && px<=25) && (py>=62 && py<=92)))
        if(!((px>=12 && px<=25) && (py>=58 && py<=62)))
        if(!((px>=8 && px<=15) && (py>=52 && py<=62)))
        if(!((px>=8 && px<=55) && (py>=48 && py<=52)))
        if(!((px>=18 && px<=25) && (py>=42 && py<=48)))
        if(!((px>=12 && px<=25) && (py>=38 && py<=42)))
        if(!((px>=8 && px<=15) && (py>=28 && py<=42)))
        if(!((px>=118 && px<=125) && (py>=62 && py<=72)))
        if(!((px>=112 && px<=125) && (py>=58 && py<=62)))
        if(!((px>=142 && px<=155) && (py>=58 && py<=62)))
        if(!((px>=138 && px<=145) && (py>=42 && py<=72)))
        if(!((px>=128 && px<=135) && (py>=52 && py<=72)))
        if(!((px>=122 && px<=135) && (py>=48 && py<=52)))
        if(!((px>=118 && px<=125) && (py>=38 && py<=52)))
        if(!((px>=118 && px<=155) && (py>=28 && py<=32)))
        if(!((px>=158 && px<=165) && (py>=38 && py<=78)))
        if(!((px>=168 && px<=175) && (py>=32 && py<=82)))
        if(!((px>=168 && px<=180) && (py>=28 && py<=32)))
        if(!((px>=98 && px<=108) && (py>=18 && py<=22)))
        if(!((px>=108 && px<=115) && (py>=18 && py<=82)))
        if(!((px>=88 && px<=95) && (py>=38 && py<=48)))
        if(!((px>=68 && px<=95) && (py>=48 && py<=52)))
        if(!((px>=98 && px<=105) && (py>=32 && py<=62)))
        if(!((px>=78 && px<=85) && (py>=28 && py<=48)))
        if(!((px>=68 && px<=75) && (py>=28 && py<=38)))
        if(!((px>=32 && px<=75) && (py>=38 && py<=42)))
        if(!((px>=28 && px<=35) && (py>=22 && py<=42)))
        if(!((px>=22 && px<=35) && (py>=18 && py<=22)))
        if(!((px>=18 && px<=25) && (py>=18 && py<=32)))
        if(!((px>=78 && px<=105) && (py>=28 && py<=32)))
        if(!((px>=88 && px<=95) && (py>=12 && py<=28)))
        if(!((px>=118 && px<=125) && (py>=8 && py<=32)))
        if(!((px>=158 && px<=165) && (py>=22 && py<=32)))
        if(!((px>=168 && px<=175) && (py>=8 && py<=22)))
        if(!((px>=132 && px<=175) && (py>=18 && py<=22)))
        if(!((px>=128 && px<=135) && (py>=8 && py<=32)))
        if(!((px>=142 && px<=165) && (py>=8 && py<=12)))
        if(!((px>=138 && px<=145) && (py>=0 && py<=12)))
        if(!((px>=88 && px<=125) && (py>=8 && py<=12)))
        if(!((px>=48 && px<=85) && (py>=8 && py<=12)))
        if(!((px>=62 && px<=85) && (py>=18 && py<=22)))
        if(!((px>=8 && px<=15) && (py>=8 && py<=18)))
        if(!((px>=0 && px<=15) && (py>=18 && py<=22)))
        if(!((px>=58 && px<=65) && (py>=8 && py<=82)))
        if(!((px>=48 && px<=55) && (py>=18 && py<=28)))
        if(!((px>=42 && px<=55) && (py>=28 && py<=32)))
        if(!((px>=38 && px<=45) && (py>=0 && py<=32)))




        px=px-5;
update_score();
               if((px==125 || px==100 || px==176 || px==15) && flag==1)
        {
            if(var1<=4)
            {
                sc+=1;
               var1+=1;
            }

            else{flag=0;}
        }

        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
      //  flag=0;
        if(px<175)
        if(!((px>=115 && px<=122) && (py>=98 && py<=162)))
        if(!((px>=5 && px<=12) && (py>=148 && py<=162)))
        if(!((px>=65 && px<=72) && (py>=158 && py<=168)))
        if(!((px>=15 && px<=22) && (py>=162 && py<=168)))
        if(!((px>=45 && px<=52) && (py>=128 && py<=158)))
        if(!((px>=15 && px<=22) && (py>=138 && py<=152)))
        if(!((px>=35 && px<=42) && (py>=122 && py<=142)))
        if(!((px>=65 && px<=72) && (py>=132 && py<=148)))
        if(!((px>=65 && px<=112) && (py>=148 && py<=152)))
        if(!((px>=85 && px<=118) && (py>=138 && py<=142)))
        if(!((px>=135 && px<=142) && (py>=138 && py<=162)))
        if(!((px>=105 && px<=142) && (py>=168 && py<=172)))
        if(!((px>=125 && px<=132) && (py>=132 && py<=172)))
        if(!((px>=125 && px<=162) && (py>=128 && py<=132)))
        if(!((px>=65 && px<=72) && (py>=158 && py<=172)))
        if(!((px>=75 && px<=122) && (py>=158 && py<=162)))
        if(!((px>=95 && px<=102) && (py>=162 && py<=172)))
        if(!((px>=75 && px<=102) && (py>=168 && py<=172)))
        if(!((px>=145 && px<=180) && (py>=168 && py<=172)))
        if(!((px>=145 && px<=152) && (py>=132 && py<=162)))
        if(!((px>=145 && px<=172) && (py>=158 && py<=162)))
        if(!((px>=145 && px<=172) && (py>=168 && py<=172)))
        if(!((px>=145 && px<=172) && (py>=98 && py<=102)))
        if(!((px>=155 && px<=168) && (py>=148 && py<=152)))
        if(!((px>=155 && px<=168) && (py>=138 && py<=142)))
        if(!((px>=165 && px<=172) && (py>=122 && py<=162)))
        if(!((px>=149 && px<=172) && (py>=118 && py<=122)))
        if(!((px>=135 && px<=148) && (py>=108 && py<=112)))
        if(!((px>=145 && px<=152) && (py>=98 && py<=122)))
        if(!((px>=155 && px<=172) && (py>=108 && py<=112)))
        if(!((px>=159 && px<=172) && (py>=108 && py<=112)))
        if(!((px>=155 && px<=162) && (py>=92 && py<=112)))
        if(!((px>=155 && px<=180) && (py>=88 && py<=92)))
        if(!((px>=129 && px<=142) && (py>=118 && py<=122)))
        if(!((px>=125 && px<=132) && (py>=112 && py<=122)))
        if(!((px>=119 && px<=132) && (py>=108 && py<=112)))
        if(!((px>=119 && px<=118) && (py>=102 && py<=162)))
        if(!((px>=105 && px<=142) && (py>=98 && py<=102)))
        if(!((px>=125 && px<=132) && (py>=92 && py<=98)))
        if(!((px>=125 && px<=152) && (py>=88 && py<=92)))
        if(!((px>=145 && px<=152) && (py>=82 && py<=88)))
        if(!((px>=115 && px<=152) && (py>=78 && py<=82)))
        if(!((px>=89 && px<=122) && (py>=88 && py<=92)))
        if(!((px>=89 && px<=102) && (py>=98 && py<=102)))
        if(!((px>=115 && px<=122) && (py>=78 && py<=88)))
        if(!((px>=85 && px<=92) && (py>=88 && py<=118)))
        if(!((px>=55 && px<=62) && (py>=128 && py<=152)))
        if(!((px>=105 && px<=112) && (py>=112 && py<=128)))
        if(!((px>=55 && px<=112) && (py>=128 && py<=132)))
        if(!((px>=95 && px<=102) && (py>=112 && py<=118)))
        if(!((px>=35 && px<=42) && (py>=102 && py<=108)))
        if(!((px>=29 && px<=42) && (py>=108 && py<=112)))
        if(!((px>=9 && px<=28) && (py>=128 && py<=132)))
        if(!((px>=25 && px<=32) && (py>=108 && py<=132)))
        if(!((px>=5 && px<=12) && (py>=122 && py<=132)))
        if(!((px>=-3 && px<=22) && (py>=118 && py<=122)))
        if(!((px>=15 && px<=22) && (py>=112 && py<=122)))
        if(!((px>=9 && px<=22) && (py>=108 && py<=112)))
        if(!((px>=5 && px<=12) && (py>=88 && py<=112)))
        if(!((px>=95 && px<=112) && (py>=108 && py<=112)))
        if(!((px>=35 && px<=102) && (py>=118 && py<=122)))
        if(!((px>=45 && px<=52) && (py>=112 && py<=118)))
        if(!((px>=45 && px<=78) && (py>=108 && py<=112)))
        if(!((px>=75 && px<=82) && (py>=68 && py<=112)))
        if(!((px>=65 && px<=72) && (py>=72 && py<=102)))
        if(!((px>=25 && px<=32) && (py>=108 && py<=132)))
        if(!((px>=85 && px<=92) && (py>=62 && py<=72)))
        if(!((px>=35 && px<=58) && (py>=78 && py<=82)))
        if(!((px>=65 && px<=72) && (py>=48 && py<=62)))
        if(!((px>=5 && px<=12) && (py>=68 && py<=82)))
        if(!((px>=25 && px<=52) && (py>=68 && py<=72)))
        if(!((px>=25 && px<=32) && (py>=58 && py<=98)))
        if(!((px>=15 && px<=62) && (py>=98 && py<=102)))
        if(!((px>=0 && px<=18) && (py>=78 && py<=82)))
        if(!((px>=15 && px<=22) && (py>=62 && py<=92)))
        if(!((px>=5 && px<=12) && (py>=52 && py<=62)))
        if(!((px>=5 && px<=52) && (py>=48 && py<=52)))
        if(!((px>=15 && px<=22) && (py>=42 && py<=48)))
        if(!((px>=5 && px<=12) && (py>=28 && py<=42)))
        if(!((px>=115 && px<=122) && (py>=62 && py<=72)))
        if(!((px>=109 && px<=122) && (py>=58 && py<=62)))
        if(!((px>=145 && px<=158) && (py>=48 && py<=52)))
        if(!((px>=135 && px<=142) && (py>=42 && py<=72)))
        if(!((px>=125 && px<=132) && (py>=52 && py<=72)))
        if(!((px>=115 && px<=122) && (py>=38 && py<=52)))
        if(!((px>=115 && px<=158) && (py>=38 && py<=42)))
        if(!((px>=155 && px<=162) && (py>=38 && py<=78)))
        if(!((px>=155 && px<=168) && (py>=78 && py<=82)))
        if(!((px>=165 && px<=172) && (py>=32 && py<=82)))
        if(!((px>=165 && px<=180) && (py>=28 && py<=32)))
        if(!((px>=95 && px<=108) && (py>=18 && py<=22)))
        if(!((px>=105 && px<=112) && (py>=18 && py<=82)))
        if(!((px>=85 && px<=92) && (py>=38 && py<=48)))
        if(!((px>=65 && px<=92) && (py>=48 && py<=52)))
        if(!((px>=95 && px<=102) && (py>=32 && py<=62)))
        if(!((px>=75 && px<=82) && (py>=28 && py<=48)))
        if(!((px>=65 && px<=72) && (py>=28 && py<=38)))
        if(!((px>=25 && px<=32) && (py>=22 && py<=42)))
        if(!((px>=15 && px<=22) && (py>=18 && py<=32)))
        if(!((px>=75 && px<=102) && (py>=28 && py<=32)))
        if(!((px>=85 && px<=92) && (py>=12 && py<=28)))
        if(!((px>=115 && px<=122) && (py>=8 && py<=32)))
        if(!((px>=155 && px<=162) && (py>=22 && py<=32)))
        if(!((px>=165 && px<=172) && (py>=8 && py<=22)))
        if(!((px>=125 && px<=132) && (py>=8 && py<=32)))
        if(!((px>=139 && px<=162) && (py>=8 && py<=12)))
        if(!((px>=135 && px<=142) && (py>=0 && py<=12)))
        if(!((px>=85 && px<=122) && (py>=8 && py<=12)))
        if(!((px>=45 && px<=82) && (py>=8 && py<=12)))
        if(!((px>=5 && px<=12) && (py>=8 && py<=18)))
        if(!((px>=0 && px<=12) && (py>=18 && py<=22)))
        if(!((px>=55 && px<=62) && (py>=8 && py<=82)))
        if(!((px>=45 && px<=52) && (py>=18 && py<=28)))
        if(!((px>=35 && px<=42) && (py>=0 && py<=32)))
        if(!((px>=15 && px<=42) && (py>=8 && py<=12)))



        px=px+5;
update_score();
                 if((px==125 || px==100 || px==176 || px==15) && flag==1)
        {
            if(var1<=4)
            {
                sc+=1;
               var1+=1;
            }

            else{flag=0;}
        }

        glutPostRedisplay();
        break;
  }
}

void display()
{

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
if(df==101)
frontscreen();

//else  if(df==0)
//     startscreen();                                          //change
    else if(df==1)
     {
        glColor3f(0.0,0.0,1.0);
        output(-28,172,"Start:-->");
        output(-45,163,"Destination:<--");
        //output(0,163,"test");                                      //remove extra
        glColor3f(0.0,0.0,1.0);
        output(-65,105,"Time Remaining : ");
        drawstring(-45,100,"Hurry!!",GLUT_BITMAP_9_BY_15);
        glColor3f(1,0,0);
        //drawstring(190,140,"Time is running out",GLUT_BITMAP_HELVETICA_18);
        sprintf(t,"%d",60-count);
        output(-18,105,t);
        glutPostRedisplay();
//        point();   //remove comment
//        point1();
        point2();    //remove comment
        //line();
         draw_circle(45,120.0,2.5,100);
         draw_circle(105,100.0,2.5,100);
         draw_circle(90,95.0,2.5,100);
         draw_circle(125,80.0,2.5,100);
         draw_circle(125,70.0,2.5,100);
         draw_circle(100,175.0,2.5,100);
         draw_circle(176,155.0,2.5,100);
         draw_circle(15,10.0,2.5,100);

        glColor3f(0.3,0.1,0.3);
        wall(-4,8,0,8,0,162,-4,162);         //actual (-4,-4,0,-4,0,162,-4,162)
           wall(-4,178,-4,184,184,184,184,178);
        wall(180,178,184,178,184,-4,180,-4);
        wall(180,0,180,-4,-4,-4,-4,0);      //actual wall(180,0,180,-4,-4,-4,0,0)
        wall(18,8,42,8,42,12,18,12);
        wall(38,0,38,32,42,32,42,0);
        wall(42,28,42,32,52,32,52,28);
        wall(48,18,48,28,52,28,52,18);
        wall(58,8,58,82,62,82,62,8);
        wall(0,18,0,22,12,22,12,18);
        wall(8,8,12,8,12,18,8,18);
        wall(62,18,62,22,82,22,82,18);
        wall(48,8,48,12,82,12,82,8);
          wall(142,8,142,12,162,12,162,8);
        wall(128,8,132,8,132,32,128,32);
        wall(132,18,132,22,172,22,172,18);
        wall(168,18,168,8,172,8,172,22);
        wall(158,22,158,32,162,32,162,22);
        wall(118,8,118,32,122,32,122,8);
        wall(88,12,88,28,92,28,92,12);
        wall(78,28,78,32,102,32,102,28);
        wall(18,18,18,32,22,32,22,18);
        wall(22,18,22,22,32,22,32,18);
        wall(28,22,32,22,32,42,28,42);
        wall(32,38,32,42,72,42,72,38);
        wall(68,38,68,28,72,28,72,38);
        wall(78,48,78,28,82,28,82,48);
        wall(98,62,98,32,102,32,102,62);
        wall(68,52,68,48,92,48,92,52);
        wall(88,38,88,48,92,48,92,38);
        wall(108,82,108,18,112,18,112,82);
        wall(108,18,108,22,98,22,98,18);
        wall(180,28,180,32,168,32,168,28);
        wall(168,82,168,32,172,32,172,82);
        wall(168,78,168,82,158,82,158,78);
        wall(158,78,158,38,162,38,162,78);
        wall(158,38,158,42,118,42,118,38);
        wall(118,38,118,52,122,52,122,38);
        wall(122,52,122,48,132,48,132,52);
        wall(132,52,132,72,128,72,128,52);
        wall(138,42,138,72,142,72,142,42);
        wall(158,52,158,48,148,48,148,52);
        wall(142,58,142,62,152,62,152,58);
        wall(142,72,142,68,152,68,152,72);
        wall(112,62,112,58,122,58,122,62);
        wall(122,62,122,72,118,72,118,62);
        wall(8,28,8,42,12,42,12,28);
        wall(12,42,12,38,22,38,22,42);
        wall(18,42,18,48,22,48,22,42);
        wall(8,48,8,52,52,52,52,48);
        wall(8,52,8,62,12,62,12,52);
        wall(12,58,12,62,22,62,22,58);
        wall(18,92,18,62,22,62,22,92);
        wall(18,78,18,82,0,82,0,78);
        wall(18,102,18,98,62,98,62,102);
        wall(28,98,28,58,32,58,32,98);
        wall(32,58,32,62,52,62,52,58);
        wall(52,68,52,72,28,72,28,68);
        wall(62,92,62,88,32,88,32,92);
        wall(8,68,8,82,12,82,12,68);
        wall(68,48,68,62,72,62,72,48);
        wall(38,78,38,82,58,82,58,78);
        wall(62,62,62,58,92,58,92,62);
        wall(92,62,92,72,88,72,88,62);
        wall(108,68,108,72,92,72,92,68);
        wall(122,32,122,28,152,28,152,32);
        wall(62,72,62,68,72,68,72,72);
        wall(72,102,72,72,68,72,68,102);
        wall(72,102,72,98,78,98,78,102);
        wall(78,68,78,112,82,112,82,68);
        wall(82,82,82,78,102,78,102,82);
        wall(78,108,78,112,48,112,48,108);
        wall(48,112,48,118,52,118,52,112);       //above this is for bottom half
        wall(48,122,48,118,102,118,102,122);    //detour so remove this (38,122,38,118,102,118,102,122)
        wall(98,108,112,108,112,112,98,112);
        wall(8,88,12,88,12,112,8,112);
        wall(12,112,12,108,22,108,22,112);
        wall(22,112,22,122,18,122,18,112);     //rem
        wall(22,122,22,118,0,118,0,122);       //remove
        wall(8,122,8,132,12,132,12,122);
        wall(28,108,28,132,32,132,32,108);
        wall(28,128,28,132,12,132,12,128);
        wall(32,112,32,108,42,108,42,112);
        wall(42,108,42,102,38,102,38,108);
        wall(98,112,98,118,102,118,102,112);
        wall(112,132,112,128,58,128,58,132);
        wall(112,128,112,112,108,112,108,128);
        wall(58,152,58,128,62,128,62,152);
        wall(88,118,88,98,92,98,92,118);                //edit it wall(88,118,88,88,92,88,92,118);
        wall(118,88,118,78,122,78,122,88);//
        wall(92,98,92,102,102,102,102,98);
        wall(92,92,92,88,122,88,122,92);
        wall(128,78,128,82,152,82,152,78);       //check detour  wall(118,78,118,82,152,82,152,78);
        wall(152,82,148,82,148,88,152,88);
        wall(152,92,152,88,128,88,128,92);
        wall(128,88,128,98,132,98,132,92);
        wall(108,98,108,102,142,102,142,98);
        wall(118,102,118,162,122,162,122,102);
        wall(122,108,122,112,132,112,132,108);
        wall(132,112,132,122,128,122,128,112);
        wall(142,122,142,118,132,118,132,122);
        wall(180,88,180,92,158,92,158,88);
        wall(158,92,158,112,162,112,162,92);
        wall(172,112,172,108,162,108,162,112);
        wall(172,112,172,108,158,108,158,112);
        wall(152,122,152,98,148,98,148,122);
        wall(148,112,148,108,138,108,138,112);
        wall(152,118,152,122,172,122,172,118);
        wall(168,162,168,122,172,122,172,162);
        wall(168,142,168,138,158,138,158,142);
        wall(168,152,168,148,158,148,158,152);
        wall(148,102,148,98,172,98,172,102);
        wall(-4,172,-4,168,72,168,72,172);
        wall(172,162,172,158,148,158,148,162);
        wall(152,162,152,132,148,132,148,162);
        wall(180,172,180,168,148,168,148,172);
        wall(142,172,142,168,108,168,108,172);
        wall(78,172,78,168,102,168,102,172);
        wall(102,172,102,162,98,162,98,168);
        wall(88,8,88,12,122,12,122,8);
        wall(138,0,138,12,142,12,142,0);      //remove
        wall(122,162,122,158,78,158,78,162);
        wall(72,172,72,158,68,158,68,172);
        wall(162,132,162,128,128,128,128,132);
        wall(128,132,128,172,132,172,132,132);
        wall(142,172,142,168,108,168,108,172);
        wall(142,138,142,162,138,162,138,138);
        wall(138,158,138,162,132,162,132,158);
        wall(118,142,118,138,88,138,88,142);
        wall(112,152,112,148,68,148,68,152);
        wall(72,148,72,132,68,132,68,148);
        wall(82,142,82,138,72,138,72,142);
        wall(42,122,42,142,38,142,38,122);
        wall(38,142,38,138,18,138,18,142);
        wall(22,142,22,148,18,148,18,142);
        wall(18,152,18,148,48,148,48,152);
        wall(48,128,52,128,52,158,48,158);
        wall(62,162,62,158,18,158,18,162);
        wall(22,162,22,168,18,168,18,162);
        wall(72,172,72,168,0,168,0,172);
        wall(72,158,72,168,68,168,68,158);
        wall(12,162,12,148,8,148,8,162);
        wall(8,162,8,158,0,158,0,162);
        glColor3f(1.0,0.7,0.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(-12,160);
        glVertex2f(-16,156);
        glVertex2f(-8,156);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-14,156);
        glVertex2f(-14,146);
        glVertex2f(-10,146);
        glVertex2f(-10,156);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-18,146);
        glVertex2f(-18,143);
        glVertex2f(-6,143);
        glVertex2f(-6,146);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-20,160);
        glVertex2f(-18,156);
        glVertex2f(-6,156);
        glVertex2f(-4,160);
        glVertex2f(-7,158);
        glVertex2f(-17,158);
        glEnd();


        /*glBegin(GL_POLYGON);                //REMOVE
        glVertex2f(55,90);
        glVertex2f(58,90);
        glVertex2f(58,70);
        glVertex2f(55,70);
        glEnd();*/
        //glClear(GL_COLOR_BUFFER_BIT);
	/*glColor3f(0.0,0.0,1.0);

	glEnable(GL_TEXTURE_2D);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	tex_2d = SOIL_load_OGL_texture
		 (
			 "maze1.jpg",
			 SOIL_LOAD_RGB,
			 SOIL_CREATE_NEW_ID,
			 SOIL_FLAG_NTSC_SAFE_RGB
		 );
	glBindTexture(GL_TEXTURE_2D, tex_2d);
	//printf("%d",tex_2d);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(-60,30);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(-1,30);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(-1,80);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(-60,80);
	glEnd();
        glDisable(GL_TEXTURE_2D);
        glFlush();*/

        glutPostRedisplay();

    }

 else if(df==2)
        instructions();
    else if(df==3)
     {
      exit(1);
     }
    else if(df==4)
    {
        timeover();
    }
    else if(df==5)
    {
        winningscreen();
    }

  glFlush();

}

void keyboard(unsigned char key,int x,int y)
{

                            // if(df==101 && key==13) df=0;


    if((df==101 || df==4 || df==5)&& key=='1') //should be else if((df==0 || df==4 || df==5)&& key=='1')
                             // if(df==101 && key=='1')
   {
     df=1;
     start=clock();
     glutPostRedisplay();
   }
  else if(df==101 && key=='2')
   df=2;
  else if(df==101 && key=='3')
   df=3;
  else if(key==27)
   {
    df=101;
    }
     if((key=='0' || key=='1')&& (df==4||df==1))   //  if((key=='0' || key=='1')&& (df==4||df==1)) if(key=='1'&& df==101)  if(key=='1'&& (df==101 || df==4 || df==5))
  {

   //ax=0.0;
   //ay=165.0;
   px=60.0;
   py=175.0;                //change to 175.0            gives the inital position of the point in the maze
  }

   if (key=='s')
    {
        if (specular==0)
        {
            specular = 1;
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,
whiteSpecularMaterial);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);
        }
        else if (specular==1)
        {
            specular = 0;
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, blankMaterial);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,
blankMaterial);
        }
    }

     if (key=='d')
    {
        if (diffuse==0)
        {
            diffuse = 1;
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,
redDiffuseMaterial);
        }
        else if (diffuse==1)
        {
            diffuse = 0;
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blankMaterial);
        }
    }

    if (key=='e')
    {
        if (emissive==0)
        {
            emissive = 1;
            glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,
greenEmissiveMaterial);
        }
        else if (emissive==1)
        {
            emissive = 0;
            glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, blankMaterial);
        }
    }



  glutPostRedisplay ();
}

void myinit()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glPointSize(20.0);     //change to 20.0

  /*GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);*/

  glMatrixMode(GL_MODELVIEW);
  glClearColor(0.6,0.4,0.3,1.0);


  glEnable (GL_DEPTH_TEST);
    glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);



}


void light (void) {
    glLightfv(GL_LIGHT0, GL_SPECULAR, whiteSpecularLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, blackAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuseLight);
}

void myreshape(int w, int h)
{
    glViewport(0,0,w,h);
     gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        gluOrtho2D(45.0,135.0,-2.0*(GLfloat)h/(GLfloat)w,180.0*(GLfloat)h/(GLfloat)w);
    else
        gluOrtho2D(-45.0*(GLfloat)w/(GLfloat)h,135.0*(GLfloat)w/(GLfloat)h,-2.0,180.0);
  glMatrixMode(GL_MODELVIEW);
  glutPostRedisplay();
 }


int  main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(600,600);
  glutCreateWindow("The Amazing Race");
  glutReshapeFunc(myreshape);
  glutDisplayFunc(display);
  glutIdleFunc(idle);
  glutSpecialFunc(SpecialKey);
  glutKeyboardFunc(keyboard);
  myinit();
  glutMainLoop();
  return 0;
}
