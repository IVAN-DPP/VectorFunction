INC = ./include/
SRC = ./src/
EXA = ./Examples/
BLD = ./build/
BLDI = ./build/include/
BLDE = ./build/Examples/
OBJ = cartplane.o field.o functions.o vectorfield.o

compile: $(OBJ) 
	g++ $(BLDI)* $(BLDE)/VectorField.o -lglut -lGL -o $(BLDE)VectorField

vectorfield.o: $(EXA)VectorField.cpp 
	g++ -c $(EXA)VectorField.cpp -o $(BLDE)VectorField.o

cartplane.o: $(SRC)Cartplane.C $(INC)Cartplane.h
	g++ -c $(SRC)Cartplane.C -o $(BLDI)Cartplane.o

functions.o: $(SRC)Functions.C $(INC)Functions.h
	g++ -c $(SRC)Functions.C -o $(BLDI)Functions.o

field.o: $(SRC)Field.C $(INC)Field.h
	g++ -c $(SRC)Field.C -o $(BLDI)Field.o

build:
	mkdir build build/include build/Examples

clean:
	rm -rvf ./build
