#include <GL/glut.h>
#include "src/SOIL.h"
#include <iostream>
#include<string.h>
#include <stdio.h>
#define UP 1
#define DOWN 0
#define MAX 10
#define SIZE_MIS_X 55
#define SIZE_MIS_y 40
#define MAX_MISSILES 3

using namespace std;

int page=0;

float x_step=-171.0, y_step=-171.0;    //for loading bar movement

float y_pos=-00;
float theta=0;
bool state;

int update_mis;

GLfloat x = 0.0f;

GLfloat fuel=98;
GLfloat dist, missiles;
GLfloat missile_x=250,missile_y[MAX_MISSILES]= {0};
int no_of_missiles=3;

int frames = 5, full = 0;
int i_bck,i_mis1,i_mis2,i_mis3,i_plane;
int i;

GLfloat windowWidth;
GLfloat windowHeight;

GLuint tex_2d, tex_2d_mis[4], tex_2d_plane, tex_2d_0;

class plane
{
public:
	float x[MAX], y[MAX], i;
	float ymax, ymin;
	int button;
	plane()
	{
		x[1]=-30, x[2]=30, x[3]=30, x[4]=-30;
		y[1]=15, y[2]=15, y[3]=-15, y[4]=-15;
	}
	void draw_plane()
	{
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		if (i_plane == 0)
		{
			tex_2d_plane = SOIL_load_OGL_texture
				       (
					       "plane2.png",
					       SOIL_LOAD_AUTO,
					       SOIL_CREATE_NEW_ID,
					       SOIL_FLAG_MULTIPLY_ALPHA
				       );
			i_plane = 1;
		}
		glBindTexture(GL_TEXTURE_2D, tex_2d_plane);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(x[1], y[1]);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(x[2], y[2]);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(x[3], y[3]);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(x[4], y[4]);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
	}
} plane1;

void keyboard_3(unsigned char key, int x, int y)
{
	switch (key)
	{
//27 is the ASCII value of the ESC key
	case 27:        //exit game
		exit(0);
		break;

	case 'f':       //full screen
		if (full == 0)
		{
			glutFullScreen();
			full = 1;
		}
		else
		{
			glutReshapeWindow(800, 450);
			glutPositionWindow(320,150);
			full = 0;
		}
	}
}

void mouse_3(int button, int m_state, int x, int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		state=UP;
		cout<<"Going Up!"<<endl;
	}
	else if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
	{
		state=DOWN;
		cout<<"Going Down"<<endl;
	}
}

void draw_score()
{
	int length;
	char score_text[15];
	strcpy(score_text,"Distance: ");
	glLineWidth(1);
	glPushMatrix();
	glTranslatef(85,82,0);
	glScalef(0.08,0.08,0.08);
	length = (int)strlen(score_text);
	for(i=0; i<length; i++)
	{
		glColor3f(1,1,1);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,score_text[i]);
	}
	glPopMatrix();

	char dist_text_val[15];
	sprintf(dist_text_val,"%d",(int)dist);
	glPushMatrix();
	glTranslatef(130,82,0);
	glScalef(0.08,0.08,0.08);
	length = (int)strlen(dist_text_val);
	for(i=0; i<length; i++)
	{
		glColor3f(1,1,1);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,dist_text_val[i]);
	}
	glPopMatrix();

	char missiles_text[15];
	strcpy(missiles_text,"Missiles: ");
	glPushMatrix();
	glTranslatef(85,72,0);
	glScalef(0.08,0.08,0.08);
	length = (int)strlen(missiles_text);
	for(i=0; i<length; i++)
	{
		glColor3f(1,1,1);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,missiles_text[i]);
	}
	glPopMatrix();

	char mis_text_val[15];
	sprintf(mis_text_val,"%d",(int)missiles);
	glPushMatrix();
	glTranslatef(130,72,0);
	glScalef(0.08,0.08,0.08);
	length = (int)strlen(mis_text_val);
	for(i=0; i<length; i++)
	{
		glColor3f(1,1,1);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,mis_text_val[i]);
	}
	glPopMatrix();

	char fuel_text[15];
	strcpy(fuel_text,"Fuel:  %");
	glPushMatrix();
	glTranslatef(-149,82,0);
	glScalef(0.08,0.08,0.08);
	length = (int)strlen(fuel_text);
	for(i=0; i<length; i++)
	{
		glColor3f(1,1,1);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,fuel_text[i]);
	}
	glPopMatrix();

	char fuel_text_val[15];
	sprintf(fuel_text_val,"%d",(int)fuel);
	glPushMatrix();
	glTranslatef(-125,82,0);
	glScalef(0.08,0.08,0.08);
	length = (int)strlen(fuel_text_val);
	for(i=0; i<length; i++)
	{
		glColor3f(1,1,1);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,fuel_text_val[i]);
	}
	glPopMatrix();
}

void rocket1(int x_cor, int y_cor)
{
	cout<<y_cor<<endl;
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	if (i_mis1 == 0)
	{
		tex_2d_mis[1] = SOIL_load_OGL_texture
				(
					"rocket2.png",
					SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_MULTIPLY_ALPHA
				);
		i_mis1 = 1;
	}
	glBindTexture(GL_TEXTURE_2D, tex_2d_mis[1]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(x_cor, y_cor);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(x_cor+SIZE_MIS_X, y_cor);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(x_cor+SIZE_MIS_X, y_cor+SIZE_MIS_y-20);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(x_cor, y_cor+SIZE_MIS_y-20);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void rocket2(int x_cor, int y_cor)
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	if (i_mis2 == 0)
	{
		tex_2d_mis[2] = SOIL_load_OGL_texture
				(
					"rocket4.png",
					SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_MULTIPLY_ALPHA
				);
		i_mis2 = 1;
	}
	glBindTexture(GL_TEXTURE_2D, tex_2d_mis[2]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(x_cor, y_cor);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(x_cor+SIZE_MIS_X, y_cor);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(x_cor+SIZE_MIS_X, y_cor+SIZE_MIS_y-10);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(x_cor, y_cor+SIZE_MIS_y-10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void rocket3(int x_cor, int y_cor)
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	if (i_mis3 == 0)
	{
		tex_2d_mis[3] = SOIL_load_OGL_texture
				(
					"rocket4.png",
					SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_MULTIPLY_ALPHA
				);
		i_mis3 = 1;
	}
	glBindTexture(GL_TEXTURE_2D, tex_2d_mis[3]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(x_cor, y_cor);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(x_cor+SIZE_MIS_X, y_cor);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(x_cor+SIZE_MIS_X, y_cor+SIZE_MIS_y-10);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(x_cor, y_cor+SIZE_MIS_y-10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void draw_rockets()
{
	if(missile_x>200)
	{
		no_of_missiles=rand()%MAX_MISSILES+1;
	}
	if(missile_x>=195 && missile_x<=200)
	{
		for(int k=1; k<=no_of_missiles; k++)
			missile_y[k]=-101+rand()%165;
	}
	switch(no_of_missiles)
	{
	case 1:
		rocket1(missile_x,missile_y[1]);
		break;
	case 2:
		rocket1(missile_x,missile_y[1]);
		rocket2(missile_x,missile_y[2]);
		break;
	case 3:
		rocket1(missile_x,missile_y[1]);
		rocket2(missile_x,missile_y[2]);
		rocket3(missile_x,missile_y[3]);
		break;
	case 4:
		rocket1(missile_x,missile_y[1]);
		rocket3(missile_x,missile_y[2]);
		rocket2(missile_x,missile_y[3]);
		rocket3(missile_x,missile_y[4]);
		break;
	default:
	case 5:
		rocket1(missile_x,missile_y[1]);
		rocket3(missile_x,missile_y[2]);
		rocket2(missile_x,missile_y[3]);
		rocket3(missile_x,missile_y[4]);
		rocket1(missile_x,missile_y[5]);
		break;

	}
}

void RenderScene_0()
{
//Clears the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);

	//load .png image
	glEnable(GL_TEXTURE_2D);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	tex_2d_0 = SOIL_load_OGL_texture
		   (
			   "res/loading.png",
			   SOIL_LOAD_RGBA,
			   SOIL_CREATE_NEW_ID,
			   SOIL_FLAG_NTSC_SAFE_RGB
		   );
	glBindTexture(GL_TEXTURE_2D, tex_2d_0);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(-190.0f, -190.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(190.0f, -190.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(190.0f, 190.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(-190.0f, 190.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//draw loading bar
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(-171.0f, -4.4f);
	glVertex2f(0.0f+x_step, -4.4f);
	glVertex2f(0.0f+x_step, 1.3f);
	glVertex2f(-171.0f, 1.3f);
	glEnd();

	glutSwapBuffers();
	glFlush();

}

void RenderScene_3()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	if (i_bck == 0)
	{
		tex_2d = SOIL_load_OGL_texture
			 (
				 "bck1.jpg",
				 SOIL_LOAD_RGBA,
				 SOIL_CREATE_NEW_ID,
				 SOIL_FLAG_NTSC_SAFE_RGB
			 );
		i_bck = 1;
	}
	glBindTexture(GL_TEXTURE_2D, tex_2d);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(-190.0f+x, -100.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(790.0f+x, -100.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(790.0f+x, 100.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(-190.0f+x, 100.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//fuel indicator outline
	glColor3f(0,0,0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-50-100,80);
	glVertex2f(50-100,80);
	glVertex2f(50-100,70);
	glVertex2f(-50-100,70);
	glEnd();

	//fuel indicator
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(-49-100,79);
	glVertex2f(-49+fuel-100,79);
	glVertex2f(-49+fuel-100,71);
	glVertex2f(-49-100,71);
	glEnd();

	//seprator--to seprate score and game screen
	glLineWidth(1);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(-200,64);
	glVertex2f(200,64);
	glEnd();

	draw_score();

	draw_rockets();

	glPushMatrix();
	glTranslatef(-130,y_pos,0);
	glRotatef(theta,0,0,1);
	plane1.draw_plane();
	glPopMatrix();
	glutSwapBuffers();

}

void TimerFunction_0(int value)
{
	if(x_step<171.0)
		x_step+=6.0;
	page=3;
	//Redraws the scene with all changes above
	glutPostRedisplay();
	glutTimerFunc(frames,TimerFunction_0, 1);
}

void TimerFunction_3(int value)
{
	x-=0.1;
	if(missile_x<-210)
		missile_x=250;
	missile_x-=1;
	if(state==UP)
	{
		if(fuel>0)
			fuel-=.1;
	}

	dist+=0.1;

	//update number of missiles douged
	{
		if(missile_x<-90)
		{
			if(update_mis==0)
			{
				missiles+=no_of_missiles;
				update_mis=1;
			}
		}
		else
			update_mis=0;
	}

	//plane position
	if(state==UP)
	{
		if(y_pos<=90)
			y_pos++;
		if(theta<0)
			theta+=.3;
		else
			theta+=.1;
	}
	else
	{
		if(y_pos>=-100)
			y_pos--;
		if(y_pos>-90)
		{
			if(theta>0)
				theta-=.3;
			else
				theta-=.1;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(frames,TimerFunction_3, 1);
}

void SetupRC(void)
{

	glClearColor(0.0f, 0.8f, 0.0f, 1.0f);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
}

void ChangeSize(int w, int h)
{
	GLfloat aspectRatio;

//Prevents a divid by zero. We wouldn't want that, now, would we.
	if(h == 0)
		h = 1;

//Makes sure that the OpenGL viewport fills the whole screen
	glViewport(0, 0, w, h);

//Resets the coordinate system so that the center of the window is (0,0,0) Cartesian x,y,z style
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

//Sets the clipping volume to the dimensions of the window, including depth ^_^
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)
	{
		windowWidth = 100;
		windowHeight = 100 / aspectRatio;
		glOrtho (-100.0, 100.0, -windowHeight, windowHeight, 1.0, -1.0);
	}
	else
	{
		windowWidth = 100 * aspectRatio;
		windowHeight = 100;
		glOrtho (-windowWidth, windowWidth, -100.0, 100.0, 1.0, -1.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void keyboard(unsigned char key, int x, int y)
{
        switch(page)
        {
        case 3:
                keyboard_3(key,x,y);
                break;
        }
}
void TimerFunction
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800,450);
	glutCreateWindow("Fuel");
	glutPositionWindow(320,150);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(33, TimerFunction, 1);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();

	return 0;
}
