
#include "../include/Cartplane.h"

CartesianPlane::CartesianPlane(int Dx, int Dy){

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
    
    const char *Number = std::to_string(j-Dx/2).c_str();
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

