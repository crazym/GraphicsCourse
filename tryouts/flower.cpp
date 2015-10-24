#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glui.h>
#include <math.h>

void drawPetal(void);


void display (void)
{

	glClear (GL_COLOR_BUFFER_BIT); 
	glLoadIdentity ();
	// gluLookAt (0.0,0.0,0.5,0.0,0.0,0.0,0.0,1.0,0.0);

    for (int i=0; i <=8; i++){
      glRotatef(45*i, 0, 0, 1);
      drawPetal();
    }
    /* draw center of flower */
    glBegin(GL_POLYGON);
    glColor3f(1,1,.1);
    // From http://slabode.exofire.net/circle_draw.shtml
    float cx=0;
    float cy=0;
    float r=.2;
    int num_segments=10;

    glBegin(GL_LINE_LOOP); 
    for(int ii = 0; ii < num_segments; ii++) 
    { 
      float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
      float x = r * cosf(theta);//calculate the x component 
      float y = r * sinf(theta);//calculate the y component 
      glVertex2f(x + cx, y + cy);//output vertex 
    } 
    glEnd();

	glFlush(); 
}

void drawPetal(void)
{ 
  glBegin(GL_POLYGON);
  glColor3f(.4,.2,.8);
  glNormal3f(0,0,1);
  
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(-0.12,0.3,0.0);
  glVertex3f(-0.18,0.6,0.0);
  glVertex3f(-0.1,0.7,0.0);
  glVertex3f(0.12,0.7,0.0);
  glVertex3f(0.18,0.6,0.0);
  glVertex3f(0.1,0.3,0.0);
  
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
	glutInitWindowSize (800,600);
	glutInitWindowPosition (100,100); 
	glutCreateWindow ("ex4");
	glutDisplayFunc (display); 
	glutReshapeFunc (reshape); 
	glutKeyboardFunc (keyboard); 
	glutMainLoop (); 
	return 0;
}