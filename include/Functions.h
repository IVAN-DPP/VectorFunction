
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

Function::Function(){}
Function::Function(string x, string y){

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

void Function::SetFunctionName(string x, string y){

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

  

double Function::GetXFunction(float posx, float posy){
    double Final = 0;
  
  for (unsigned int i = 0; i < X.size(); i++) {

    if(X[i] == "x" || X[i] == "X") {
      if (Opx[i] == '+') 	Final+=posx;
      else if(Opx[i] == '-') 	Final-=posx; 
    }
    else if(X[i] == "y" || X[i] == "Y") {
      if (Opx[i] == '+') 	Final+=posy;
      else if(Opx[i] == '-') 	Final-=posy; 
    }
    else if(X[i] == "x*x" || X[i] == "X*X" || X[i] == "x^2" || X[i] == "X^2") {
      if (Opx[i] == '+') 	Final+=pow(posx,2);
      else if(Opx[i] == '-') 	Final-=pow(posx,2);
    }
    else if(X[i] == "y*y" || X[i] == "Y*Y" || X[i] == "y^2" || X[i] == "Y^2") {
      if (Opx[i] == '+') 	Final+=pow(posy,2);
      else if(Opx[i] == '-') 	Final-=pow(posy,2);
    }
    else if(X[i] == "x*x*x" || X[i] == "X*X*X" || X[i] == "x^3" || X[i] == "X^3") {
      if (Opx[i] == '+') 	Final+=pow(posx,2);
      else if(Opx[i] == '-') 	Final-=pow(posx,2);
    }
    else if(X[i] == "y*y*y" || X[i] == "Y*Y*Y" || X[i] == "y^3" || X[i] == "Y^3") {
      if (Opx[i] == '+') 	Final+=pow(posy,3);
      else if(Opx[i] == '-') 	Final-=pow(posy,3);
    }
    else if(X[i] == "x*x*x*x" || X[i] == "X*X*X*X" || X[i] == "x^4" || X[i] == "X^4") {
      if (Opx[i] == '+') 	Final+=pow(posx,4);
      else if(Opx[i] == '-') 	Final-=pow(posx,4);
    }
    else if(X[i] == "y*y*y*y" || X[i] == "Y*Y*Y*Y" || X[i] == "y^4" || X[i] == "Y^4") {
      if (Opx[i] == '+') 	Final+=pow(posy,4);
      else if(Opx[i] == '-') 	Final-=pow(posy,4);
    }
  }
   
  return Final;
}


double Function::GetYFunction(float posx, float posy){
    double Final = 0;
  
  for (unsigned int i = 0; i < Y.size(); i++) {

    if(Y[i] == "x" || Y[i] == "X") {
      if (Opy[i] == '+') 	Final+=posx;
      else if(Opy[i] == '-') 	Final-=posx; 
    }
    else if(Y[i] == "y" || Y[i] == "Y") {
      if (Opy[i] == '+') 	Final+=posy;
      else if(Opy[i] == '-') 	Final-=posy; 
    }
    else if(Y[i] == "x*x" || Y[i] == "X*X" || Y[i] == "x^2" || Y[i] == "X^2") {
      if (Opy[i] == '+') 	Final+=pow(posx,2);
      else if(Opy[i] == '-') 	Final-=pow(posx,2);
    }
    else if(Y[i] == "y*y" || Y[i] == "Y*Y" || Y[i] == "y^2" || Y[i] == "Y^2") {
      if (Opy[i] == '+') 	Final+=pow(posy,2);
      else if(Opy[i] == '-') 	Final-=pow(posy,2);
    }
    else if(Y[i] == "x*x*x" || Y[i] == "X*X*X" || Y[i] == "x^3" || Y[i] == "X^3") {
      if (Opy[i] == '+') 	Final+=pow(posx,2);
      else if(Opy[i] == '-') 	Final-=pow(posx,2);
    }
    else if(Y[i] == "y*y*y" || Y[i] == "Y*Y*Y" || Y[i] == "y^3" || Y[i] == "Y^3") {
      if (Opy[i] == '+') 	Final+=pow(posy,3);
      else if(Opy[i] == '-') 	Final-=pow(posy,3);
    }
    else if(Y[i] == "x*x*x*x" || Y[i] == "X*X*X*X" || Y[i] == "x^4" || Y[i] == "X^4") {
      if (Opy[i] == '+') 	Final+=pow(posx,4);
      else if(Opy[i] == '-') 	Final-=pow(posx,4);
    }
    else if(Y[i] == "y*y*y*y" || Y[i] == "Y*Y*Y*Y" || Y[i] == "y^4" || Y[i] == "Y^4") {
      if (Opy[i] == '+') 	Final+=pow(posy,4);
      else if(Opy[i] == '-') 	Final-=pow(posy,4);
    }
  }
   
  return Final;
}

#endif
