
#include "../include/Functions.h"

Function::Function(){}
Function::Function(string x, string y){

  string Variable;

  for (unsigned int i = 0; i <= x.size(); i++) {

    // By the moment, is important put + or - in the begining of the equation
    if(i == 0 && (x[0] == '+' || x[0] == '-')){
      Opx.push_back(x[0]);
      continue;
    }

    if (x.substr(i,3) == "sin" || x.substr(i,3) == "cos" || x.substr(i,3) == "tan" ||
	x.substr(i,3) == "csc" || x.substr(i,3) == "sec" || x.substr(i,3) == "ctg" ||
	x.substr(i,3) == "asi" || x.substr(i,3) == "aco" || x.substr(i,3) == "ata" ||
	x.substr(i,3) == "sih" || x.substr(i,3) == "coh" || x.substr(i,3) == "tah" ||
	x.substr(i,3) == "exp" || x.substr(i,3) == "log" || x.substr(i,3) == "abs") {

      X.push_back(x.substr(i,3));
      
      for (unsigned int j  = i+4; true ; j++) {
	
	if(x[j] == '+' || x[j] == '-' || x[j] == ')') { 
	  XF.push_back(Variable);
	  OpxF.push_back(x[j]);
	  Variable.clear();
	  i=j;
	  if(x[j] == ')') break;
	  continue;
	}
	Variable.push_back(x[j]);    
      }
      continue;
    }

    else if(x[i] == '+' || x[i] == '-' || i == x.size()) {
      X.push_back(Variable);
      if(X[X.size()-1].empty()) Opx.push_back(' ');
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

    if (y.substr(i,3) == "sin" || y.substr(i,3) == "cos" || y.substr(i,3) == "tan" ||
	y.substr(i,3) == "csc" || y.substr(i,3) == "sec" || y.substr(i,3) == "ctg" ||
	y.substr(i,3) == "asi" || y.substr(i,3) == "aco" || y.substr(i,3) == "ata" ||
	y.substr(i,3) == "sih" || y.substr(i,3) == "coh" || y.substr(i,3) == "tah" ||
	y.substr(i,3) == "exp" || y.substr(i,3) == "log" || y.substr(i,3) == "abs") {

      Y.push_back(y.substr(i,3));
      
      for (unsigned int j  = i+4; true ; j++) {
	
	if(y[j] == '+' || y[j] == '-' || y[j] == ')') { 
	  YF.push_back(Variable);
	  OpyF.push_back(y[j]);
	  Variable.clear();
	  i=j;
	  if(y[j] == ')') break;
	  continue;
	}
	Variable.push_back(y[j]);    
      }
      continue;
    }

    else if(y[i] == '+' || y[i] == '-' || i == y.size()) {
      Y.push_back(Variable);
      if(Y[Y.size()-1].empty()) Opy.push_back(' ');
      Opy.push_back(y[i]);
      Variable.clear();
      continue;
    }
    Variable.push_back(y[i]);    
  }

  Opy.pop_back();
  Variable.clear();
}

void Function::SetFunctionName(string x, string y){

  string Variable;

  for (unsigned int i = 0; i <= x.size(); i++) {

    // By the moment, is important put + or - in the begining of the equation
    if(i == 0 && (x[0] == '+' || x[0] == '-')){
      Opx.push_back(x[0]);
      continue;
    }

    if (x.substr(i,3) == "sin" || x.substr(i,3) == "cos" || x.substr(i,3) == "tan" ||
	x.substr(i,3) == "csc" || x.substr(i,3) == "sec" || x.substr(i,3) == "ctg" ||
	x.substr(i,3) == "asi" || x.substr(i,3) == "aco" || x.substr(i,3) == "ata" ||
	x.substr(i,3) == "sih" || x.substr(i,3) == "coh" || x.substr(i,3) == "tah" ||
	x.substr(i,3) == "exp" || x.substr(i,3) == "log" || x.substr(i,3) == "abs") {

      X.push_back(x.substr(i,3));
      
      for (unsigned int j  = i+4; true ; j++) {
	
	if(x[j] == '+' || x[j] == '-' || x[j] == ')') { 
	  XF.push_back(Variable);
	  OpxF.push_back(x[j]);
	  Variable.clear();
	  i=j;
	  if(x[j] == ')') break;
	  continue;
	}
	Variable.push_back(x[j]);    
      }
      continue;
    }

    else if(x[i] == '+' || x[i] == '-' || i == x.size()) {
      X.push_back(Variable);
      if(X[X.size()-1].empty()) Opx.push_back(' ');
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

    if (y.substr(i,3) == "sin" || y.substr(i,3) == "cos" || y.substr(i,3) == "tan" ||
	y.substr(i,3) == "csc" || y.substr(i,3) == "sec" || y.substr(i,3) == "ctg" ||
	y.substr(i,3) == "asi" || y.substr(i,3) == "aco" || y.substr(i,3) == "ata" ||
	y.substr(i,3) == "sih" || y.substr(i,3) == "coh" || y.substr(i,3) == "tah" ||
	y.substr(i,3) == "exp" || y.substr(i,3) == "log" || y.substr(i,3) == "abs") {

      Y.push_back(y.substr(i,3));
      
      for (unsigned int j  = i+4; true ; j++) {
	
	if(y[j] == '+' || y[j] == '-' || y[j] == ')') { 
	  YF.push_back(Variable);
	  OpyF.push_back(y[j]);
	  Variable.clear();
	  i=j;
	  if(y[j] == ')') break;
	  continue;
	}
	Variable.push_back(y[j]);    
      }
      continue;
    }

    else if(y[i] == '+' || y[i] == '-' || i == y.size()) {
      Y.push_back(Variable);
      if(Y[Y.size()-1].empty()) Opy.push_back(' ');
      Opy.push_back(y[i]);
      Variable.clear();
      continue;
    }
    Variable.push_back(y[i]);    
  }

  Opy.pop_back();
  Variable.clear();
}

  

double Function::GetXFunction(float posx, float posy){

  double Final = 0;
  double FinalT = 0;
  int Temp = 0;
  for (unsigned int i = 0; i < X.size(); i++) {
    if(X[i].empty()) continue;
    if(X[i] == "sin" || X[i] == "cos" || X[i] == "tan" ||
       X[i] == "csc" || X[i] == "sec" || X[i] == "ctg" ||
       X[i] == "asi" || X[i] == "aco" || X[i] == "ata" ||
       X[i] == "sih" || X[i] == "coh" || X[i] == "tah" ||
       X[i] == "exp" || X[i] == "log" || X[i] == "abs") {

      for (unsigned int  j = Temp; j < XF.size(); j++) {

	if(XF[j].empty()) continue;

	if(XF[j] == "x" || XF[j] == "X") {
	  if (OpxF[j-1] == '+')	 	FinalT+=posx;
	  else if(OpxF[j-1] == '-') 	FinalT-=posx; 
	}
	else if(XF[j] == "y" || XF[j] == "Y") {
	  if (OpxF[j-1] == '+') 	FinalT+=posy;
	  else if(OpxF[j-1] == '-') 	FinalT-=posy; 
	}
	else if(XF[j] == "x*x" || XF[j] == "X*X" || XF[j] == "x^2" || XF[j] == "X^2") {
	  if (OpxF[j-1] == '+') 	FinalT+=pow(posx,2);
	  else if(OpxF[j-1] == '-') 	FinalT-=pow(posx,2);
	}
	else if(XF[j] == "y*y" || XF[j] == "Y*Y" || XF[j] == "y^2" || XF[j] == "Y^2") {
	  if (OpxF[j-1] == '+') 	FinalT+=pow(posy,2);
	  else if(OpxF[j-1] == '-') 	FinalT-=pow(posy,2);
	}
	else if(XF[j] == "x*x*x" || XF[j] == "X*X*X" || XF[j] == "x^3" || XF[j] == "X^3") {
	  if (OpxF[j-1] == '+') 	FinalT+=pow(posx,2);
	  else if(OpxF[j-1] == '-') 	FinalT-=pow(posx,2);
	}
	else if(XF[j] == "y*y*y" || XF[j] == "Y*Y*Y" || XF[j] == "y^3" || XF[j] == "Y^3") {
	  if (OpxF[j-1] == '+') 	FinalT+=pow(posy,3);
	  else if(OpxF[j-1] == '-') 	FinalT-=pow(posy,3);
	}
	else if(XF[j] == "x*x*x*x" || XF[j] == "X*X*X*X" || XF[j] == "x^4" || XF[j] == "X^4") {
	  if (OpxF[j-1] == '+') 	FinalT+=pow(posx,4);
	  else if(OpxF[j-1] == '-') 	FinalT-=pow(posx,4);
	}
	else if(XF[j] == "y*y*y*y" || XF[j] == "Y*Y*Y*Y" || XF[j] == "y^4" || XF[j] == "Y^4") {
	  if (OpxF[j-1] == '+') 	FinalT+=pow(posy,4);
	  else if(OpxF[j-1] == '-') 	FinalT-=pow(posy,4);
	}

	if(XF[j+1].empty()) {Temp = j+1; break;}
      }

      if(X[i] == "sin"){
	if(Opx[i] == '+')	Final+=sin(FinalT);
	else if(Opx[i] == '-')	Final-=sin(FinalT);
      }
      else if(X[i] == "cos"){
	if(Opx[i] == '+')	Final+=cos(FinalT);
	else if(Opx[i] == '-')	Final-=cos(FinalT);
      }
      else if(X[i] == "tan"){
	if(Opx[i] == '+')	Final+=tan(FinalT);
	else if(Opx[i] == '-')	Final-=tan(FinalT);
      }
      else if(X[i] == "csc"){
	if(Opx[i] == '+')	Final+=1/sin(FinalT);
	else if(Opx[i] == '-')	Final-=1/sin(FinalT);
      }
      else if(X[i] == "sec"){
	if(Opx[i] == '+')	Final+=1/cos(FinalT);
	else if(Opx[i] == '-')	Final-=1/cos(FinalT);
      }
      else if(X[i] == "ctg"){
	if(Opx[i] == '+')	Final+=1/tan(FinalT);
	else if(Opx[i] == '-')	Final-=1/tan(FinalT);
      }
      else if(X[i] == "asi"){
	if(Opx[i] == '+')	Final+=asin(FinalT);
	else if(Opx[i] == '-')	Final-=asin(FinalT);
      }
      else if(X[i] == "aco"){
	if(Opx[i] == '+')	Final+=acos(FinalT);
	else if(Opx[i] == '-')	Final-=acos(FinalT);
      }
      else if(X[i] == "ata"){
	if(Opx[i] == '+')	Final+=atan(FinalT);
	else if(Opx[i] == '-')	Final-=atan(FinalT);
      }
      else if(X[i] == "sih"){
	if(Opx[i] == '+')	Final+=sinh(FinalT);
	else if(Opx[i] == '-')	Final-=sinh(FinalT);
      }
      else if(X[i] == "coh"){
	if(Opx[i] == '+')	Final+=cosh(FinalT);
	else if(Opx[i] == '-')	Final-=cosh(FinalT);
      }
      else if(X[i] == "tah"){
	if(Opx[i] == '+')	Final+=tanh(FinalT);
	else if(Opx[i] == '-')	Final-=tanh(FinalT);
      }
      else if(X[i] == "exp"){
	if(Opx[i] == '+')	Final+=exp(FinalT);
	else if(Opx[i] == '-')	Final-=exp(FinalT);
      }
      else if(X[i] == "log"){
	if(Opx[i] == '+')	Final+=log(FinalT);
	else if(Opx[i] == '-')	Final-=log(FinalT);
      }
      else if(X[i] == "abs"){
	if(Opx[i] == '+')	Final+=abs(FinalT);
	else if(Opx[i] == '-')	Final-=abs(FinalT);
      }
      FinalT = 0;
    }
    
    else {
	
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
  }
  

  return Final;
}


double Function::GetYFunction(float posx, float posy){


  double Final = 0;
  double FinalT = 0;
  int Temp = 0;

  for (unsigned int i = 0; i < Y.size(); i++) {
    if(Y[i].empty()) continue;
    if(Y[i] == "sin" || Y[i] == "cos" || Y[i] == "tan" ||
       Y[i] == "csc" || Y[i] == "sec" || Y[i] == "ctg" ||
       Y[i] == "asi" || Y[i] == "aco" || Y[i] == "ata" ||
       Y[i] == "sih" || Y[i] == "coh" || Y[i] == "tah" ||
       Y[i] == "exp" || Y[i] == "log" || Y[i] == "abs") {

      for (unsigned int  j = Temp; j < YF.size(); j++) {

	if(YF[j].empty()) continue;

	if(YF[j] == "x" || YF[j] == "X") {
	  if (OpyF[j-1] == '+')	 	FinalT+=posx;
	  else if(OpyF[j-1] == '-') 	FinalT-=posx; 
	}
	else if(YF[j] == "y" || YF[j] == "Y") {
	  if (OpyF[j-1] == '+') 	FinalT+=posy;
	  else if(OpyF[j-1] == '-') 	FinalT-=posy; 
	}
	else if(YF[j] == "x*x" || YF[j] == "X*X" || YF[j] == "x^2" || YF[j] == "X^2") {
	  if (OpyF[j-1] == '+') 	FinalT+=pow(posx,2);
	  else if(OpyF[j-1] == '-') 	FinalT-=pow(posx,2);
	}
	else if(YF[j] == "y*y" || YF[j] == "Y*Y" || YF[j] == "y^2" || YF[j] == "Y^2") {
	  if (OpyF[j-1] == '+') 	FinalT+=pow(posy,2);
	  else if(OpyF[j-1] == '-') 	FinalT-=pow(posy,2);
	}
	else if(YF[j] == "x*x*x" || YF[j] == "X*X*X" || YF[j] == "x^3" || YF[j] == "X^3") {
	  if (OpyF[j-1] == '+') 	FinalT+=pow(posx,2);
	  else if(OpyF[j-1] == '-') 	FinalT-=pow(posx,2);
	}
	else if(YF[j] == "y*y*y" || YF[j] == "Y*Y*Y" || YF[j] == "y^3" || YF[j] == "Y^3") {
	  if (OpyF[j-1] == '+') 	FinalT+=pow(posy,3);
	  else if(OpyF[j-1] == '-') 	FinalT-=pow(posy,3);
	}
	else if(YF[j] == "x*x*x*x" || YF[j] == "X*X*X*X" || YF[j] == "x^4" || YF[j] == "X^4") {
	  if (OpyF[j-1] == '+') 	FinalT+=pow(posx,4);
	  else if(OpyF[j-1] == '-') 	FinalT-=pow(posx,4);
	}
	else if(YF[j] == "y*y*y*y" || YF[j] == "Y*Y*Y*Y" || YF[j] == "y^4" || YF[j] == "Y^4") {
	  if (OpyF[j-1] == '+') 	FinalT+=pow(posy,4);
	  else if(OpyF[j-1] == '-') 	FinalT-=pow(posy,4);
	}

	if(YF[j+1].empty()) {Temp = j+1; break;}
      }

      if(Y[i] == "sin"){
	if(Opy[i] == '+')	Final+=sin(FinalT);
	else if(Opy[i] == '-')	Final-=sin(FinalT);
      }
      else if(Y[i] == "cos"){
	if(Opy[i] == '+')	Final+=cos(FinalT);
	else if(Opy[i] == '-')	Final-=cos(FinalT);
      }
      else if(Y[i] == "tan"){
	if(Opy[i] == '+')	Final+=tan(FinalT);
	else if(Opy[i] == '-')	Final-=tan(FinalT);
      }
      else if(Y[i] == "csc"){
	if(Opy[i] == '+')	Final+=1/sin(FinalT);
	else if(Opy[i] == '-')	Final-=1/sin(FinalT);
      }
      else if(Y[i] == "sec"){
	if(Opy[i] == '+')	Final+=1/cos(FinalT);
	else if(Opy[i] == '-')	Final-=1/cos(FinalT);
      }
      else if(Y[i] == "ctg"){
	if(Opy[i] == '+')	Final+=1/tan(FinalT);
	else if(Opy[i] == '-')	Final-=1/tan(FinalT);
      }
      else if(Y[i] == "asi"){
	if(Opy[i] == '+')	Final+=asin(FinalT);
	else if(Opy[i] == '-')	Final-=asin(FinalT);
      }
      else if(Y[i] == "aco"){
	if(Opy[i] == '+')	Final+=acos(FinalT);
	else if(Opy[i] == '-')	Final-=acos(FinalT);
      }
      else if(Y[i] == "ata"){
	if(Opy[i] == '+')	Final+=atan(FinalT);
	else if(Opy[i] == '-')	Final-=atan(FinalT);
      }
      else if(Y[i] == "sih"){
	if(Opy[i] == '+')	Final+=sinh(FinalT);
	else if(Opy[i] == '-')	Final-=sinh(FinalT);
      }
      else if(Y[i] == "coh"){
	if(Opy[i] == '+')	Final+=cosh(FinalT);
	else if(Opy[i] == '-')	Final-=cosh(FinalT);
      }
      else if(Y[i] == "tah"){
	if(Opy[i] == '+')	Final+=tanh(FinalT);
	else if(Opy[i] == '-')	Final-=tanh(FinalT);
      }
      else if(Y[i] == "exp"){
	if(Opy[i] == '+')	Final+=exp(FinalT);
	else if(Opy[i] == '-')	Final-=exp(FinalT);
      }
      else if(Y[i] == "log"){
	if(Opy[i] == '+')	Final+=log(FinalT);
	else if(Opy[i] == '-')	Final-=log(FinalT);
      }
      else if(Y[i] == "abs"){
	if(Opy[i] == '+')	Final+=abs(FinalT);
	else if(Opy[i] == '-')	Final-=abs(FinalT);
      }
      FinalT = 0;
    }

    else {
	
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
  }
  

  return Final;
}
