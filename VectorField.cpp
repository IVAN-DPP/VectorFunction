
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"


using namespace std;

const double PI = 3.1416;
double GradToRad(double Grad){ return Grad*PI/180; }
// These variables must be in the public class
vector<string> X;
vector<char> Opx;
vector<string> Y;
vector<char> Opy;


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

void FunctionName(string x, string y){

  string Variable;

  for (unsigned int i = 0; i <= x.size(); i++) {

    // By the moment, is important put + or - in the begining of the equation
    if(i == 0 && (x[0] == '+' || x[0] == '-')){
      Opx.push_back(x[0]);
      continue;
    }
    if(x[i] == '+' || x[i] == '-' || i == x.size()) {
      X.push_back(Variable);
      Opx.push_back(x[i]);
      Variable.clear();
      continue;
    }
    Variable.push_back(x[i]);    
  }

  Opx.pop_back();
  Variable.clear();

  for (unsigned int i = 0; i <= y.size(); i++) {

    // By the moment, is important put + or - in the begining of the equation
    
    if(i == 0 && (y[0] == '+' || y[0] == '-')){
      Opy.push_back(y[0]);
      continue;
    }
    if(y[i] == '+' || y[i] == '-' || i == y.size()) {
      Y.push_back(Variable);
      Opy.push_back(y[i]);
      Variable.clear();
      continue;
    }
    Variable.push_back(y[i]);    
  }

  Opy.pop_back();
    
}


double Function(float posx, float posy, vector<string> Vxy, vector<char> OPxy){

  double Final = 0;
  
  for (unsigned int i = 0; i < Vxy.size(); i++) {

    if(Vxy[i] == "x" || Vxy[i] == "X") {
      if (OPxy[i] == '+') 	Final+=posx;
      else if(OPxy[i] == '-') 	Final-=posx; 
    }
    else if(Vxy[i] == "y" || Vxy[i] == "Y") {
      if (OPxy[i] == '+') 	Final+=posy;
      else if(OPxy[i] == '-') 	Final-=posy; 
    }
    else if(Vxy[i] == "x*x" || Vxy[i] == "X*X" || Vxy[i] == "x^2" || Vxy[i] == "X^2") {
      if (OPxy[i] == '+') 	Final+=pow(posx,2);
      else if(OPxy[i] == '-') 	Final-=pow(posx,2);
    }
    else if(Vxy[i] == "y*y" || Vxy[i] == "Y*Y" || Vxy[i] == "y^2" || Vxy[i] == "Y^2") {
      if (OPxy[i] == '+') 	Final+=pow(posy,2);
      else if(OPxy[i] == '-') 	Final-=pow(posy,2);
    }
    else if(Vxy[i] == "x*x*x" || Vxy[i] == "X*X*X" || Vxy[i] == "x^3" || Vxy[i] == "X^3") {
      if (OPxy[i] == '+') 	Final+=pow(posx,2);
      else if(OPxy[i] == '-') 	Final-=pow(posx,2);
    }
    else if(Vxy[i] == "y*y*y" || Vxy[i] == "Y*Y*Y" || Vxy[i] == "y^3" || Vxy[i] == "Y^3") {
      if (OPxy[i] == '+') 	Final+=pow(posy,3);
      else if(OPxy[i] == '-') 	Final-=pow(posy,3);
    }
    else if(Vxy[i] == "x*x*x*x" || Vxy[i] == "X*X*X*X" || Vxy[i] == "x^4" || Vxy[i] == "X^4") {
      if (OPxy[i] == '+') 	Final+=pow(posx,4);
      else if(OPxy[i] == '-') 	Final-=pow(posx,4);
    }
    else if(Vxy[i] == "y*y*y*y" || Vxy[i] == "Y*Y*Y*Y" || Vxy[i] == "y^4" || Vxy[i] == "Y^4") {
      if (OPxy[i] == '+') 	Final+=pow(posy,4);
      else if(OPxy[i] == '-') 	Final-=pow(posy,4);
    }
  }
   
  return Final;
}


void Field(int Dx, int Dy, double Resize = 1.0){

  CartesianCoordinate(Dx,Dy);
  float TSize = 30*Resize/100;
  for (int i = 0; i < Dy; i++) {
    float posy = (2.0*i+1)/Dy - 1.0;
    for (int j = 0; j < Dx; j++) {
      
      glBegin(GL_LINES);
      float posx = (2.0*j+1)/Dx - 1.0;
      float posxf = posx+Resize*(Function(posx,posy,X,Opx));
      float posyf = posy+Resize*(Function(posx,posy,Y,Opy));
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
  FunctionName("+y", "-x");			//Call the functions
  Field(10,10,0.1f);				//Call the field
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
