
#include "libraries.h"
#include "Functions.h"
#include "Cartplane.h"

#ifndef FIELD_H
#define FIELD_H

class Field{
private:

  int Dx;
  int Dy;
  float NX = 1.0;			// Number of vectors in x and y
  float NY = 1.0;
  double Resize;
  Function Func;

public:
  Field(){}
  Field(string, string);
  void SetXYVectorsQuanty(float, float);
  void SetXYMaxMin(int = 5, int = 5, double = 1.0);
  void GetField();
};


#endif
