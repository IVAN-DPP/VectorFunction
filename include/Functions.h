
#include "libraries.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class Function{
private:

  vector<string> X;
  vector<char> Opx;
  vector<string> Y;
  vector<char> Opy;
  
public:
  Function();
  Function(string, string);
  void SetFunctionName(string = " ", string = " ");
  double GetXFunction(float, float);
  double GetYFunction(float, float);
};

#endif
