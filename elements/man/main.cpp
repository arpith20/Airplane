#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
GLint x0=400,y0=150,x[10],y[10],dx=100,dy=100;
GLint a0=550,b0=400,a[5],b[5],da=50,db=50;
GLint c0=550,d0=200,c[5],d[5],dc=50,dd=50;
void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	gluOrtho2D(0.0,1249.0,0.0,699.0);
}


void colour()
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x[0],y[3]);
		glVertex2f(x[0],y[4]);
		glVertex2f(x[1],y[4]);
		glVertex2f(x[1],y[3]);
	glEnd();
	glFlush();
}

void bigbox()
{
	GLint i,j;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	for(i=0;i<5;i++)
		x[i]=x0+i*dx;
	for(j=0;j<5;j++)
		y[j]=y0+j*dy;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			glColor3f(0.0,0.0,1.0);
			glBegin(GL_LINE_LOOP);
				glVertex2f(x[i],y[j]);
				glVertex2f(x[i],y[j+1]);
				glVertex2f(x[i+1],y[j+1]);
				glVertex2f(x[i+1],y[j]);
			glEnd();
		}

	glFlush();
	}
}
void smallbox1()
{
	GLint i,j;
	glColor3f(0.0,0.0,1.0);
	for(i=0;i<3;i++)
		a[i]=a0+i*da;
	for(j=0;j<3;j++)
		b[j]=b0+j*db;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			glColor3f(0.0,0.0,1.0);
			glBegin(GL_LINE_LOOP);
				glVertex2f(a[i],b[j]);
				glVertex2f(a[i],b[j+1]);
				glVertex2f(a[i+1],b[j+1]);
				glVertex2f(a[i+1],b[j]);
			glEnd();
		}

	glFlush();
	}
}

void smallbox2()
{
	GLint i,j;
	glColor3f(0.0,0.0,1.0);
	for(i=0;i<3;i++)
		c[i]=c0+i*dc;
	for(j=0;j<3;j++)
		d[j]=d0+j*dd;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			glColor3f(0.0,0.0,1.0);
			glBegin(GL_LINE_LOOP);
				glVertex2f(c[i],d[j]);
				glVertex2f(c[i],d[j+1]);
				glVertex2f(c[i+1],d[j+1]);
				glVertex2f(c[i+1],d[j]);
			glEnd();
		}

	glFlush();
	}
}
void display()
{
	bigbox();
	smallbox1();
	smallbox2();
	colour();

}
int main(int argc, char **argv)
{
	 glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1250,700);
glutInitWindowPosition(0,0);
glutCreateWindow("Square Counting");
myinit();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
