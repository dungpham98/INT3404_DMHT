/* Module      : MainFile.cpp
 * Author      :
 * Email       :
 * Course      : Computer Graphics
 *
 * Description :
 *
 *
 * Date        :
 *
 * History:
 * Revision      Date          Changed By
 * --------      ----------    ----------
 * 01.00         ?????          ???
 * First release.
 *
 */

/* -- INCLUDE FILES ------------------------------------------------------ */
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

/* -- DATA STRUCTURES ---------------------------------------------------- */
class GLintPoint  {
    public:
    int x,y;
    GLintPoint(int _x, int _y){
        this->x = _x;
        this->y = _y;
    }
};

/* -- GLOBAL VARIABLES --------------------------------------------------- */

/* -- LOCAL VARIABLES ---------------------------------------------------- */


/* ----------------------------------------------------------------------- */
/* Function    : void drawDot( GLint x, GLint y )
 *
 * Description : Draw a point at location (x, y) in the window.
 *
 * Parameters  : GLint x : X coordinate of point to draw.
 *               GLint y : X coordinate of point to draw.
 *
 * Returns     : void
 */


void drawDot()  {
    glClear( GL_COLOR_BUFFER_BIT );
	glColor3ub(255,0,0);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2i(300, 150);
    glColor3f(0.3, 0.5, 0.7);
    glVertex2i(200, 250);
    glColor3f(0.5, 0.3, 0.7);
    glVertex2i(100, 350);
    glEnd();
    glFinish();
}

void draw_rect(GLintPoint p1, GLintPoint p2, float color[]){
    //int x1 = 100, y1 = 100, x2 = 300, y2 = 300;
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(color[0], color[1], color[2]); // Red
    glVertex2i(p1.x, p2.y);     // Define vertices in counter-clockwise (CCW) order
    glVertex2i(p2.x, p2.y);     //  so that the normal (front-face) is facing you
    glVertex2i(p2.x, p1.y);
    glVertex2i(p1.x, p1.y);
    glEnd();
}

//TODO:
// - Convert int to GLintPoint
// - Finish draw triangle
void draw_triange(GLintPoint p1, GLintPoint p2, GLintPoint p3, float color[]){
    //int x1 = 100, y1 = 100, x2 = 300, y2 = 300;
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3f(color[0], color[1], color[2]); // Red
    glVertex2i(p1.x, p1.y);     // Define vertices in counter-clockwise (CCW) order
    glVertex2i(p2.x, p2.y);     //  so that the normal (front-face) is facing you
    glVertex2i(p3.x, p3.y);
    glEnd();
}

void house_draw(){
    float c1[3] = {1.0f, 0.0f, 0.0f};
    float c2[3] = {0.0f, 1.0f, 0.0f};
    float c3[3] = {0.0f, 0.0f, 1.0f};
    glClear( GL_COLOR_BUFFER_BIT );
    GLintPoint p1(300,300), p2(100,100), p3(250,250),p4(200,200), p5(50,300), p6(200, 350), p7(350, 300);
    draw_rect(p1, p2, c1);
    draw_rect(p3, p4, c2);
    draw_triange(p5,p6,p7, c3);
    glFinish();
}

/* ----------------------------------------------------------------------- */
/* Function    : void myInit( void )
 *
 * Description : Initialize OpenGL and the window where things will be
 *               drawn.
 *
 * Parameters  : void
 *
 * Returns     : void
 */

void myInit( void )  {
  glClearColor( 1.0, 1.0, 1.0, 0.0 );
  glColor3f( 0.0, 0.0, 0.0 );
  glPointSize( 1.0 );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  gluOrtho2D( 0.0, 640.0, 0.0, 480.0 );
}


/* ----------------------------------------------------------------------- */
/* Function    : void myDisplay( void )
 *
 * Description : This function gets called everytime the window needs to
 *               be redrawn.
 *
 * Parameters  : void
 *
 * Returns     : void
 */

void myDisplay( void )  {
  glClear( GL_COLOR_BUFFER_BIT );
}


/* ----------------------------------------------------------------------- */
/* Function    : int main( int argc, char** argv )
 *
 * Description : This is the main function. It sets up the rendering
 *               context, and then reacts to user events.
 *
 * Parameters  : int argc     : Number of command-line arguments.
 *               char *argv[] : Array of command-line arguments.
 *
 * Returns     : int : Return code to pass to the shell.
 */

int main( int argc, char *argv[] )  {
  // Initialize GLUT.
  glutInit( &argc, argv );
  // Set the mode to draw in.
  glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
  // Set the window size in screen pixels.
  glutInitWindowSize( 640, 480 );
  // Set the window position in screen pixels.
  glutInitWindowPosition( 100, 150 );
  // Create the window.
  glutCreateWindow( "Lab" );
  // Set the callback funcion to call when we need to draw something.
  glutDisplayFunc( drawDot); // Choose between drawDot, draw_rect or draw_house
  // Initialize some things.
  myInit( );
  // Now that we have set everything up, loop responding to events.
  glutMainLoop( );
}

/* ----------------------------------------------------------------------- */

