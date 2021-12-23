
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"


using namespace std;

const double PI = 3.1416;
double GradToRad(double Grad){ return Grad*PI/180; }

void CartesianCoordinate(int Dx, int Dy){
  glBegin(GL_LINES);
  glVertex2f(0.0f,-1.0f);
  glVertex2f(0.0f, 1.0f);
  glVertex2f(-1.0f, 0.0f);
  glVertex2f(1.0f, 0.0f);
  
  for (int i = 0; i <= Dy; i++) {
    float posy = (2.0*i+1)/Dy - 1.0;
    glBegin(GL_LINES);
    glVertex2f(0.01f,posy);
    glVertex2f(-0.01f,posy);
    glEnd();

    //Define numbers
    
    const char *Number = to_string(i-Dy/2).c_str();
    if (i-Dy/2 == 0) continue;
    else if(i-Dy/2 < 0){
      glRasterPos2f(0.02f, posy-0.007f);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[0]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[1]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[2]);
    }
    else {
      glRasterPos2f(0.02f, (2.0*(i-1.0)+1.0)/Dy - 1.0-0.007f);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[0]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[1]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[2]);
    }

  }
  
  for (int j = 0; j <= Dx; j++) {
    float posx = (2.0*j+1)/Dx - 1.0;
    glBegin(GL_LINES);
    glVertex2f(posx,0.01f);
    glVertex2f(posx,-0.01f);
    glEnd();

    //Define numbers
    
    const char *Number = to_string(j-Dx/2).c_str();
    if (j-Dx/2 == 0) continue;
    else if(j-Dx/2 < 0){
      glRasterPos2f(posx-0.03f,-0.035f);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[0]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[1]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[2]);
    }
    else {
      glRasterPos2f((2.0*(j-1.0)+1.0)/Dx - 1.0-0.01f, -0.035f);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[0]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[1]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[2]);
    }
  }  
  glEnd();

}

double Function(double pos, int pol){
  switch (pol) {
  case 1 : { return pow(pos,pol); break; }
  case 2 : { return pow(pos,2);   break; }
  case 3 : { return pow(pos,3);   break; }
  default: { return 0;            break; }
  }
}

void FieldAngle(int Dx, int Dy, double Angle = 0){

  float Size = 0.05f;
  float TSize = 0.01f;
  for (int i = 0; i < Dy; i++) {
    float posy = (2.0*i+1)/Dy - 1.0;
    for (int j = 0; j < Dx; j++) {

      glBegin(GL_LINES);
      float posx = (2.0*j+1)/Dx - 1.0;
      float AngleX = posx+Size*cos(Angle);
      float AngleY = posy+Size*sin(Angle);
      glVertex2f(posx, posy);
      glVertex2f(AngleX , AngleY);
      glEnd();
      glBegin(GL_TRIANGLES);
      glVertex2f(AngleX+TSize*cos(Angle), AngleY+TSize*sin(Angle));
      glVertex2f(AngleX-TSize*sin(Angle), AngleY+TSize*cos(Angle));
      glVertex2f(AngleX+TSize*sin(Angle), AngleY-TSize*cos(Angle));
      glEnd();

    }  
  }
}

void Field(int Dx, int Dy, double Resize = 1.0){

  CartesianCoordinate(Dx,Dy);
  float TSize = 30*Resize/100;
  for (int i = 0; i < Dy; i++) {
    float posy = (2.0*i+1)/Dy - 1.0;
    for (int j = 0; j < Dx; j++) {
      
      glBegin(GL_LINES);
      float posx = (2.0*j+1)/Dx - 1.0;
      float posxf = posx+Resize*(-posy);
      float posyf = posy+Resize*(posx);
      glVertex2f(posx, posy);
      glVertex2f(posxf , posyf);
      glEnd();

      float VectAng = abs(atan((posyf-posy)/(posxf-posx)));
      float proySin = TSize*sin(VectAng);
      float proyCos = TSize*cos(VectAng);
      
      glBegin(GL_TRIANGLES);

      // When VectAng is different to cero
      
      if(posx > posxf && posy < posyf) {
	glVertex2f(posxf-proyCos, posyf+proySin);
	glVertex2f(posxf-proySin/sqrt(3), posyf-proyCos/sqrt(3));
	glVertex2f(posxf+proySin/sqrt(3), posyf+proyCos/sqrt(3));
      }

      else if(posx > posxf && posy > posyf) {
	glVertex2f(posxf-proyCos, posyf-proySin);
	glVertex2f(posxf+proySin/sqrt(3), posyf-proyCos/sqrt(3));
	glVertex2f(posxf-proySin/sqrt(3), posyf+proyCos/sqrt(3));
      }

      else if(posx < posxf && posy > posyf) {
	glVertex2f(posxf+proyCos, posyf-proySin);
	glVertex2f(posxf+proySin/sqrt(3), posyf+proyCos/sqrt(3));
	glVertex2f(posxf-proySin/sqrt(3), posyf-proyCos/sqrt(3));
      }

      else if(posx < posxf && posy < posyf) {
	glVertex2f(posxf+proyCos, posyf+proySin);
	glVertex2f(posxf-proySin/sqrt(3), posyf+proyCos/sqrt(3));
	glVertex2f(posxf+proySin/sqrt(3), posyf-proyCos/sqrt(3));
      }

      // When VectAng is iqual to cero

      
      else if(posy < posyf && VectAng <= 1.58 && VectAng >=1.5) {
	glVertex2f(posx, posyf+TSize);
	glVertex2f(posx-TSize/sqrt(3), posyf);
	glVertex2f(posx+TSize/sqrt(3), posyf);

      }

      else if(posy > posyf && VectAng <= 1.58 && VectAng >=1.5) {
	glVertex2f(posx, posyf-TSize);
	glVertex2f(posx+TSize/sqrt(3), posyf);
	glVertex2f(posx-TSize/sqrt(3), posyf);

      }
      
      else if(posx < posxf && VectAng == 0) {
	glVertex2f(posxf+TSize, posy );
	glVertex2f(posxf, posy+TSize/sqrt(3));
	glVertex2f(posxf, posy-TSize/sqrt(3));
      }
      
      else if(posx > posxf && VectAng == 0) {
	glVertex2f(posxf-TSize, posy );
	glVertex2f(posxf, posy+TSize/sqrt(3));
	glVertex2f(posxf, posy-TSize/sqrt(3));
      }
      
      glEnd();

    }  
  }
}

void setup(){ glClearColor(1.0f, 1.0f, 1.0f, 1.0f); }

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0f, 0.0f, 0.0f);
  Field(10,10,0.1f);
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
