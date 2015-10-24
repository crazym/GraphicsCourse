#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glui.h>


void display (void)
{

	glClear (GL_COLOR_BUFFER_BIT); 
	glLoadIdentity ();
	// gluLookAt (0.0,0.0,0.5,0.0,0.0,0.0,0.0,1.0,0.0);

	glBegin (GL_LINE_LOOP); 
	glVertex3f(0.0,0.2,0.0);
	glVertex3f(0.1,0.1,0.0);
	glVertex3f(0.2,0.05,0.0);
	glVertex3f(0.1,0.0,0.0);
	glVertex3f(0.2,-0.1,0.0);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(-0.2,-0.1,0.0);
	glVertex3f(-0.1,0.0,0.0);
	glVertex3f(-0.2,0.05,0.0);
	glVertex3f(-0.1,0.1,0.0);
	glEnd();
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