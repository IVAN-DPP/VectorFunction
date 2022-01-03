
#include "../include/Cartplane.h"

CartesianPlane::CartesianPlane(int Dx, int Dy){

  glBegin(GL_LINES);
  glVertex2f(0.8f, 0.8f);
  glVertex2f(-0.8f, 0.8f);
  glVertex2f(-0.8f, -0.8f);
  glVertex2f(0.8f, -0.8f);
  glVertex2f(0.8f, 0.8f);
  glVertex2f(0.8f, -0.8f);
  glVertex2f(-0.8f, 0.8f);
  glVertex2f(-0.8f, -0.8f);
  glEnd();

  glRasterPos2f(-0.95f, 0.0);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'Y');

  glRasterPos2f(0.0,-0.95f);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'X');
 
  int jNumber = 0;
  
  for (float i = 0; i <= 2*0.75f; i+=0.75/Dx) {

    float posx = i-0.75f;
    
    glBegin(GL_LINES);
    glVertex2f(posx,-0.8f+0.03f);
    glVertex2f(posx,-0.8f+-0.03f);
    glVertex2f(posx,+0.8f+0.03f);
    glVertex2f(posx,+0.8f+-0.03f);
    glEnd();

    const char *Number = to_string(jNumber-Dx).c_str();
    jNumber++;

    if(posx >= 0){
      glRasterPos2f(posx-0.01f, -0.8f-0.07f);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[0]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[1]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[2]);
    }
    else {
      glRasterPos2f(posx-0.03f, -0.8f-0.07f);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[0]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[1]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[2]);
    }
  }

  jNumber = 0;
  
  for (float i = 0; i <= 2*0.75f; i+=0.75/Dy) {

    float posy = i-0.75f;

    glBegin(GL_LINES);
    glVertex2f(-0.8f+0.03f,posy);
    glVertex2f(-0.8f-0.03f,posy);
    glVertex2f(+0.8f+0.03f,posy);
    glVertex2f(+0.8f-0.03f,posy);
    glEnd();

    
    const char *Number = to_string(jNumber-Dy).c_str();
    jNumber++;

    if(posy >= 0){
      glRasterPos2f(-0.8f-0.07f,posy-0.005f);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[0]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[1]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[2]);
    }
    else {
      glRasterPos2f(-0.8f-0.09f, posy-0.005f);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[0]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[1]);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, Number[2]);
    }
  }

}

