#include <GL/glut.h>
#include "src/SOIL.h"
#include <iostream>
#include<string.h>
#define MAX 10
int page;
using namespace std;
int i_plane;
GLuint tex_2d_plane;
void* currentfont;
void setFont(void* font)
{
	currentfont=font;
}
void drawstring(float x,float y,float z,char* string)
{
	char* c;
	glRasterPos3f(x,y,z);

	for(c=string; *c!='\0'; c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}
int plane_choice=2;
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
		if(plane_choice==1)
		{
			if (i_plane == 0)
			{
				tex_2d_plane = SOIL_load_OGL_texture
					       (
						       "plane1.png",
						       SOIL_LOAD_AUTO,
						       SOIL_CREATE_NEW_ID,
						       SOIL_FLAG_MULTIPLY_ALPHA
					       );
				i_plane = 1;
			}
		}
		if(plane_choice==2)
		{
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
//Sets jimmy's initial position and size.
//rsize equals half of jimmy's height and width
GLfloat x = 0.0f;
GLfloat y = 0.0f;
GLfloat rsize = 8;
int frames = 5, full = 0;
int i = 0;
//Sets the direction and velocity of jimmy at the program initialization
/*The value of these variables defines the amount of pixels along the standard Cartesian coordinate system
Jimmy moves. For example, setting xstep to -2.0f would mean that jimmy would move two pixels
in a certain amount of time defined by the frames variable. The frames variable dictates the amount of milliseconds inbetween each movement of the square.
That means that if frames = 2, I get 50 fps, and therefore 50 movements of jimmy in a second.*/
GLfloat xstep = 0.0f;   //defines mivement. Stopped if 0
GLfloat ystep = 0.0f;

GLfloat windowWidth;
GLfloat windowHeight;

GLuint tex_2d;


void keycrap(unsigned char key, int x, int y)
{
	switch (key)
	{
//32 is the ASCII value of the space key
	case 32:        //to stop jimmy
		xstep = 0.0f, ystep = 0.0f;
		break;

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
			glutReshapeWindow(800, 600);
			glutPositionWindow(320,150);
			full = 0;
		}
	}
}

void SpecialKeys(int key, int x, int y) //to specify direction of jimmy
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:    //move jimy in right direction
		xstep = 1.0f, ystep = 0.0f;
		break;

	case GLUT_KEY_LEFT:
		xstep = -1.0f, ystep = 0.0f;
		break;

	case GLUT_KEY_DOWN:
		xstep = 0.0f, ystep = -1.0f;
		break;

	case GLUT_KEY_UP:
		xstep = 0.0f, ystep = 1.0f;
		break;
	}

	glutPostRedisplay();
}

void draw_chPlane_text()
{
	char string[15][120];
	int i,lengthOfString;


	strcpy(string[0],"Choose Plane");
	strcpy(string[1],"Paper Plane!");
	strcpy(string[2],"Military X991+");
	strcpy(string[3],"Next");

	glLineWidth(2);
	glPushMatrix();
	glTranslatef(-120,55,0);
	glScalef(0.3,0.3,0.3);
	lengthOfString = (int)strlen(string[0]);
	for(i=0; i<lengthOfString; i++)
	{
		glColor3f(1,1,1);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,string[0][i]);
	}
	glPopMatrix();

	glLineWidth(1);
	int y_pos_21=40;
	for(int k_t=1; k_t<=2; k_t++)
	{
		glPushMatrix();
		glTranslatef(50,y_pos_21-=30,0);
		glScalef(0.1,0.1,0.1);
		lengthOfString = (int)strlen(string[k_t]);
		for(i=0; i<lengthOfString; i++)
		{
			glColor3f(1,1,1);
			glutStrokeCharacter(GLUT_STROKE_ROMAN,string[k_t][i]);
		}
		glPopMatrix();
	}

	glLineWidth(2);
	glPushMatrix();
	glTranslatef(-30,-75,0);
	glScalef(0.15,0.15,0.15);
	lengthOfString = (int)strlen(string[3]);
	for(i=0; i<lengthOfString; i++)
	{
		glColor3f(1,1,1);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,string[3][i]);
	}
	glPopMatrix();

}

void mouse(int button, int m_state, int x, int y)
{
	if(button==GLUT_LEFT_BUTTON && m_state==GLUT_UP)
	{
		if(full==0)
		{
			cout<<x<<" "<<y<<endl;
			if(y>168 && y<205)
			{
				plane_choice=1;
				i_plane=0;
				glutPostRedisplay();
			}
			if(y>242 && y<287)
			{
				plane_choice=2;
				i_plane=0;
				glutPostRedisplay();
			}
			if(y>300)
			{
			        cout<<"next"<<endl;
			        i_plane=0;
			        page=3;
			}
		}
		else
		{
			if(y>307 && y<347)
			{
				plane_choice=1;
				i_plane=0;
				glutPostRedisplay();
			}
			if(y>416 && y<463)
			{
				plane_choice=2;
				i_plane=0;
				glutPostRedisplay();
			}
			if(y>470)
			{
			        cout<<"next"<<endl;
			        i_plane=0;
			        page=3;
			}
		}
	}
}

void draw_chosen_plane()
{
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-150,-40);
	glVertex2f(-30,-40);
	glVertex2f(-30,40);
	glVertex2f(-150,40);
	glEnd();

	glPushMatrix();
	glTranslatef(-90,0,0);
	glScalef(1.6,1.6,0);
	plane1.draw_plane();
	glPopMatrix();
}

void RenderScene()
{
//Clears the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);


	glEnable(GL_TEXTURE_2D);

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	if (i == 0)
	{
		tex_2d = SOIL_load_OGL_texture
			 (
				 "res/bck_plane.jpg",
				 SOIL_LOAD_RGBA,
				 SOIL_CREATE_NEW_ID,
				 SOIL_FLAG_NTSC_SAFE_RGB
			 );
		i = 1;
	}

	glBindTexture(GL_TEXTURE_2D, tex_2d);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(-178.0f, -100.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(178.0f, -100.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(178.0f, 100.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(-178.0f, 100.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	draw_chPlane_text();
	draw_chosen_plane();

	glutSwapBuffers();
}



void SetupRC(void)
{
//Sets the clear color. Again, the values are in RGBA float format
	glClearColor(0.0f, 0.8f, 0.0f, 1.0f);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
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


//Actually opens the window, initializes all the functions I made, and throws it all into a loop. Hooray!
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800,450);
	glutCreateWindow("Get the Burger 3 - OpenGL");
	glutPositionWindow(320,150);
	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(SpecialKeys);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keycrap);
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();

	return 0;
}
