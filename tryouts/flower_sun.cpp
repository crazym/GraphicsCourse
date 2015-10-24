#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glui.h>
#include <math.h>

void drawPetal(void);
void drawBud(float cx, float cy, float r, int num_segments);
void display (void)
{

	glClear (GL_COLOR_BUFFER_BIT); 
	glLoadIdentity ();
	// gluLookAt (0.0,0.0,0.5,0.0,0.0,0.0,0.0,1.0,0.0);
    // drawPetal();

  for (int i=0; i <=16; i++){
    glRotatef(22.5*i, 0, 0, 1);
    drawPetal();
  }
  glBegin(GL_POLYGON);
    glColor3f(1,1,.1);
    drawBud(0, 0, 0.6, 16);
  glEnd();

	glFlush(); 
}

void drawPetal(void)
{ 
  glBegin (GL_POLYGON); 
    glColor3f(0.8,0.3,0.4);
    // glScalef(0.4, 0.4, 0.4); 

    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.2,0.6,0.0);
    glVertex3f(0.0,1.2,0.0);
    glVertex3f(-0.2,0.6,0.0);

  glEnd();
}

// try to draw bud with a polygon approximating a circle
// code src: http://stackoverflow.com/questions/22444450/drawing-circle-with-opengl
void drawBud(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
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
	glutInitWindowSize (800,800);
	glutInitWindowPosition (100,100); 
	glutCreateWindow ("ex4");
	glutDisplayFunc (display); 
	glutReshapeFunc (reshape); 
	glutKeyboardFunc (keyboard); 
	glutMainLoop (); 
	return 0;
}