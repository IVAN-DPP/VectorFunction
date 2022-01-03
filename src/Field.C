
#include "../include/Field.h"

Field::Field(string x, string y){
  Func.SetFunctionName(x,y);
}

void Field::SetXYVectorsQuanty(float nx, float ny){
  NX = nx;
  NY = ny;
}

void Field::SetXYMaxMin(int DX, int DY, double RESIZE){
  Dx=DX;
  Dy=DY;
  Resize=RESIZE;    
}
void Field::GetField(){

  CartesianPlane Plane(Dx,Dy);

  for (float i = 0; i <= 2*Dy; i+=NY) {

    for (float j = 0; j <= 2*Dx; j+=NX) {

      float posy = i-Dy;

      glBegin(GL_LINES);
      float posx = j-Dx;
      float posxf = posx+Resize*(Func.GetXFunction(posx,posy));
      float posyf = posy+Resize*(Func.GetYFunction(posx,posy));
      float TSize = 10*sqrt(pow(posxf-posx,2)+pow(posyf-posy,2))/100;
      
      posx = 0.75f*posx/Dx;			posy = 0.75f*posy/Dy;
      posxf = 0.75f*posxf/Dx;	      		posyf = 0.75f*posyf/Dy;
      
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
