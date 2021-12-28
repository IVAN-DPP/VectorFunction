
#include "libraries.h"
#include "Functions.h"

#ifndef FIELD_H
#define FIELD_H

class Field{
private:

  int Dx;
  int Dy;
  double Resize;
  Function Func;

public:
  Field(){}
  Field(string, string);
  void SetXYVectorsQuanty(int = 5, int = 5, double = 1.0);
  void GetField();
};

Field::Field(string x, string y){
  Func.SetFunctionName(x,y);
}

void Field::SetXYVectorsQuanty(int DX, int DY, double RESIZE){
  Dx=DX;
  Dy=DY;
  Resize=RESIZE;
}

void Field::GetField(){

  float TSize = 30*Resize/100;
  for (int i = 0; i < Dy; i++) {
    float posy = (2.0*i+1)/Dy - 1.0;
    for (int j = 0; j < Dx; j++) {
      
      glBegin(GL_LINES);
      float posx = (2.0*j+1)/Dx - 1.0;
      float posxf = posx+Resize*(Func.GetXFunction(posx,posy));
      float posyf = posy+Resize*(Func.GetYFunction(posx,posy));
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

#endif
