#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glui.h>
#include <math.h>

void DrawFlowerHelper(int i);

void display (void)
{

	glClear (GL_COLOR_BUFFER_BIT); 
	glLoadIdentity ();

	for (int i=0; i<4; i++){
	 glPushMatrix();
	 glRotatef(i*90, 0, 0, 1);
	 DrawFlowerHelper(1);
	 glPopMatrix();
	 
	}

	for (int i=0; i<10; i++){

	 glPushMatrix();
	 glRotatef(i*36, 0, 0, 1);
	 DrawFlowerHelper(2);
	 glPopMatrix();
	 
	}

	glFlush(); 
}

void DrawFlowerHelper(int i){
  if (i == 1){
    glBegin(GL_POLYGON);
    for (int j=0; j<360; j++){
      float x = (float)0.05*cos(j)+0.1;
      float y = (float)0.05*sin(j)+0.1;
      float z = 0.0;
      glNormal3f(0, 0, 1);
      glVertex3f(x, y, z);
    }
    glEnd();
  }
  else {
    
    glBegin(GL_POLYGON);
    for (int j=0; j<360; j++){
      float x = (float)0.1*cos(j);
      float y = (float)0.25*sin(j)+0.5;
      float z = 0.0;
      glNormal3f(0, 0, 1);
      glVertex3f(x, y, z);
    }
    glEnd();
  }
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