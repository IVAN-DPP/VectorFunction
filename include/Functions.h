
#include "libraries.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class Function{
private:

  vector<string> X;
  vector<char> Opx, OpxF;
  vector<string> Y;
  vector<char> Opy, OpyF;
  vector<string> XF, YF;
  
public:
  Function();
  Function(string, string);
  void SetFunctionName(string = " ", string = " ");
  double GetXFunction(float, float);
  double GetYFunction(float, float);
};

#endif
