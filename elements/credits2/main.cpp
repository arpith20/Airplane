//credits
///Arpith

#include <GL/glut.h>
#include "src/SOIL.h"
#include <iostream>
#include<string.h>

using namespace std;


int frames = 2;
int direction=0;
int y_cre=0;

GLfloat windowWidth;
GLfloat windowHeight;

GLuint tex_2d;

void draw_text()
{
        char string[5][20];
	int i,lengthOfString;

        strcpy(string[3],"PES Institute of Technology, BSC");
	strcpy(string[2],"Thank you!");
	strcpy(string[1],"Arpith (1PE10CS018)");
	strcpy(string[0],"Anil S (1PE10CS015)");

        glLineWidth(1);

        glPushMatrix();
	glTranslatef(-105,130-y_cre,0);
	glScalef(0.1,0.1,0.1);
	lengthOfString = (int)strlen(string[3]);
	for(i=0; i<lengthOfString; i++)
	{
		glColor3f(1,1,1);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,string[3][i]);
	}
	glPopMatrix();

        glPushMatrix();
	glTranslatef(-35,100-y_cre,0);
	glScalef(0.1,0.1,0.1);
	lengthOfString = (int)strlen(string[2]);
	for(i=0; i<lengthOfString; i++)
	{
		glColor3f(1,1,1);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,string[2][i]);
	}
	glPopMatrix();

        glPushMatrix();
	glTranslatef(-160,-110+y_cre,0);
	glScalef(0.1,0.1,0.1);
	lengthOfString = (int)strlen(string[1]);
	for(i=0; i<lengthOfString; i++)
	{
		glColor3f(1,1,1);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,string[1][i]);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35,-110+y_cre,0);
	glScalef(0.1,0.1,0.1);
	lengthOfString = (int)strlen(string[0]);
	for(i=0; i<lengthOfString; i++)
	{
		glColor3f(1,1,1);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,string[0][i]);
	}
	glPopMatrix();

}

void RenderScene()
{

	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	tex_2d = SOIL_load_OGL_texture
		 (
			 "res/cre.jpg",
			 SOIL_LOAD_RGBA,
			 SOIL_CREATE_NEW_ID,
			 SOIL_FLAG_NTSC_SAFE_RGB
		 );
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

	draw_text();
	glutSwapBuffers();

}

void SetupRC(void)
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

void reshape(int w, int h)
{
	GLfloat aspectRatio;

	if(h == 0)
		h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

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

void mouse(int button, int state, int x, int y)
{
	if(state==GLUT_UP)
	{

		cout<<"From Credit page: "<<x<<" "<<y<<endl;
	}
}

void TimerFunction(int value)
{
        if(y_cre<80)
                y_cre++;

	glutPostRedisplay();
	glutTimerFunc(frames,TimerFunction, 1);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800,450);
	glutCreateWindow("Cre");
	glutPositionWindow(320,150);

	glutMouseFunc(mouse);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(33, TimerFunction, 1);
	glutReshapeFunc(reshape);
	SetupRC();
	glutMainLoop();
	return 0;
}
