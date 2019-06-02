//
//		          Programming Assignment #1 
//
//			        Victor Zordan
//		
//		
//
/***************************************************************************/

                                                   /* Include needed files */
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header

#define WIDTH 500
#define HEIGHT 500

int x_last,y_last;
struct Point{
	float x, y;
}
Point p1, p2, p3, p4;
char color;
/***************************************************************************/

void init_window()
                 /* Clear the image area, and set up the coordinate system */
{

        					       /* Clear the window */
        glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
        glOrtho(0,WIDTH,0,HEIGHT,-1.0,1.0);
}

/***************************************************************************/

void write_pixel(int x, int y, double intensity)
                                         /* Turn on the pixel found at x,y */
{

		if(color == 'r')
		{
			glColor3f(intensity, 0.0, 0.0);
		}
		else if(color == 'g')
		{
			glColor3f(0.0, intensity, 0.0);
		}
		else if(color == 'b')
		{
			glColor3f(0.0, 0.0, intensity);
		}
		else
        {
			glColor3f (intensity-k, 0.0, k);                 
        }
		glBegin(GL_POINTS);
           glVertex3i( x, y, 0);
        glEnd();	
}

//***************************************************************************/

void display ( void )   // Create The Display Function
{

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	      // Clear Screen 
+
//  write_pixel(x_last,y_last,1.0);//<-you can get rid of this call if you like
  // CALL YOUR CODE HERE

  while(opt == 1)
  {
	if(count == 2)
		construct_line(p1,p2);
	else
		continue;
  }
  while(opt == 2)
  {
	if (count == 4)
		construct_curve(p1,p2,p3,p4);
	else
		continue;
  }
	
  glutSwapBuffers();                                      // Draw Frame Buffer 
}

/***************************************************************************/
void mouse(int button, int state, int x, int y)
{
/* This function I finessed a bit, the value of the printed x,y should
   match the screen, also it remembers where the old value was to avoid multiple
   readings from the same mouse click.  This can cause problems when trying to
   start a line or curve where the last one ended */
        static int oldx = 0;
        static int oldy = 0;
	int mag;
	
	y *= -1;  //align y with mouse
	y += 500; //ignore 
	mag = (oldx - x)*(oldx - x) + (oldy - y)*(oldy - y);
	if (mag > 20) {
		printf(" x,y is (%d,%d)\n", x,y);
		count++;
	}
	
	if(count == 1)
	{
		p1.x = x;
		p1.y = y;
	}
	else if(count == 2)
	{
		p2.x = x;
		p2.y = y;
	}
	else if(count == 3 && opt == 1)
	{
		count = 0;
	}
	else if(count == 3 && opt == 2)
	{
		p3.x = x;
		p3.y = y;
	}
	else if(count == 4 && opt == 2)
	{
		p4.x = x;
		p4.y = y;
	}
	else
	{
		count = 0;
	}
	
	oldx = x;
	oldy = y;
	x_last = x;
	y_last = y;
}
 
/***************************************************************************/
void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{

	switch ( key ) {
		case 27:              // When Escape Is Pressed...
			exit ( 0 );   // Exit The Program
			break;        
	    case '1':             // stub for new screen
		    printf("New screen\n");
			break;
		case 'l':
			opt = 1;
			break;
		case 'c':
			opt = 2;
			break;
		case 'r':
			color = 'r';
			break;
		case 'g':
			color = 'g';
			break;
		case 'b':
			color = 'b';
			break;
		default:       
			break;
	}
}
/***************************************************************************/


/*Start /02-13-2019/Abhinav*/

void construct_line(Point p1, Point p2)
{
  int dx = 0, dy = 0;
  float x_increment = 0.0, y_increment = 0.0, x0 = 0.0, y0 0.0;
  
  x0 = p1.x;
  y0 = p1.y;

  dx = p2.x - x0;
  dy = p2.y - y0;

  if(dx > dy)
    steps = abs(dx);
  else
    steps = abs(dy);

  x_increment = dx / float(steps);
  y_increment = dy / float(steps);

  for(int i = 0; i < steps; i++)
    {
      if(k < 1.0)
      k = k + 1.0/float(steps);
      else
      k = 0;

      write_pixel(round(x0), round(y0), 1.0);
      x0 = x0 + x_increment;
      y0 = y0 + y_increment;
    }
}

void construct_curve(Point p1, Point p2, Point p3, Point p4)
{

int i, X[10], Y[10];
float u = 0.0;
Point p, p0;

p0.x = p1.x;
p0.y = p1.y;

for( i = 0; i < 10; i++)
	{
		b0 = pow((1-u), 3);
		b1 = 3 * u * (pow((1-u), 2));
		b2 = 3 * pow(u, 2) * (1-u);
		b3 = pow(u, 3);
	
		X[i] = (p1.x * b0)+(p2.x * b1)+(p3.x * b2)+(p4.x * b3);
		Y[i] = (p1.y * b0)+(p2.y * b1)+(p3.y * b2)+(p4.y * b3);
		
		if(i<9)
		{	
		write_pixel(p0.x,p0.y,1.0);
		p.x = X[i];
		p.y = Y[i];
		
		construct_line(p0, p);
		
		p0.x = X[i];
		p0.y = Y[i];
		}
		if(i==9)
		{
			write_pixel(p0.x,p0.y,1.0);
			p.x = X[i];
			p.y = Y[i];
			
			construct_line(p,p4);
		}
		u = u+0.10;
	}

/*for(i = 0; i < 9; i++)
	{
		x_buffer[1] = X[i];
		y_buffer[1] = Y[i];
		x_buffer[2] = X[i+1];
		y_buffer[2] = Y[i+1];
		write_pixel(round(x_buffer[2]), round(y_buffer[2]), 1.0);
		construct_line();
	}*/
}
/*End /02-13-2019/Abhinav*/




int main (int argc, char *argv[])
{
/* This main function sets up the main loop of the program and continues the
   loop until the end of the data is reached.  Then the window can be closed
   using the escape key.						  */
	
	glutInit            ( &argc, argv ); 
       	glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH ); 
	glutInitWindowSize  ( 500,500 ); 
	glutCreateWindow    ( "Computer Graphics" ); 
	glutDisplayFunc     ( display );  
	glutIdleFunc	    ( display );
	glutMouseFunc       ( mouse );
	glutKeyboardFunc    ( keyboard );
        					      
        init_window();				             //create_window
						       		
	glutMainLoop        ( );                 // Initialize The Main Loop
}


