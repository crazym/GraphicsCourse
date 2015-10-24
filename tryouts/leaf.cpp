#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glui.h>


void display (void)
{

	glClear (GL_COLOR_BUFFER_BIT); 
	glLoadIdentity ();
	// gluLookAt (0.0,0.0,0.5,0.0,0.0,0.0,0.0,1.0,0.0);

	glColor3f(0.1,0.9,0.1); 
	glScalef(0.1, 0.1, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.0, 0);
	glVertex3f(0.8,0.7, 0);
	glVertex3f(1.1,1.8, 0);
	glVertex3f(0.8,2.8, 0);
	glVertex3f(0.0,3.8, 0);
	glVertex3f(-0.8,2.8, 0);
	glVertex3f(-1.1,1.8, 0);
	glVertex3f(-0.8,0.7, 0);
	glEnd();

	// glBegin(GL_POLYGON);
	// glVertex2f(0.0,0.0);
	// glVertex2f(1.0,0.7);
	// glVertex2f(1.3,1.8);
	// glVertex2f(1.0,2.8);
	// glVertex2f(0.0,4.0);
	// glVertex2f(-1.0,2.8);
	// glVertex2f(-1.3,1.8);
	// glVertex2f(-1.0,0.7);
	// glEnd();
	glFlush(); 
}

void keyboard (unsigned char key, int x, int y)
{

	if(key == 27)
	{
	exit(0); 
	}
}

void reshape (int width, int height)
{

	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode (GL_PROJECTION) ;
	glLoadIdentity (); 
	glOrtho (-1.0,1.0,-1.0,1.0,-1.0,1.0); 
	glMatrixMode (GL_MODELVIEW); 
}

int main(int argc, char **argv)
{
	glutInit (&argc, argv); 
	glutInitWindowSize (800,600);
	glutInitWindowPosition (100,100); 
	glutCreateWindow ("ex4");
	glutDisplayFunc (display); 
	glutReshapeFunc (reshape); 
	glutKeyboardFunc (keyboard); 
	glutMainLoop (); 
	return 0;
}