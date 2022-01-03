
#include "../include/libraries.h"
#include "../include/Cartplane.h"
#include "../include/Functions.h"
#include "../include/Field.h"

using namespace std;

const double PI = 3.1416;
double GradToRad(double Grad){ return Grad*PI/180; }

void setup(){ glClearColor(1.0f, 1.0f, 1.0f, 1.0f); }

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0f, 0.0f, 0.0f);
  Field Func("-x","+cos(+y)");
  Func.SetXYMaxMin(2,2,0.1f);
  Func.SetXYVectorsQuanty(0.5,0.5);
  Func.GetField();

  glutSwapBuffers();
}

int main(int argc, char *argv[]){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Field Project");

  setup();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}


// How plot a vector field
// https://www.youtube.com/watch?v=mTSchmlxtQQ




