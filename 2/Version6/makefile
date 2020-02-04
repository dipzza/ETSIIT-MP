
BIN=./bin
OBJ=./obj
SRC=./src
INC=./include
LIB=./lib
ZIP=.
DOC=./doc
DAT=./dat

OPT=-Wall -g

PRJ=practica2


all : $(BIN)/intervalo.bin
$(BIN)/intervalo.bin : $(OBJ)/main.o $(OBJ)/intervalo.o $(INC)/intervalo.h
	g++ -o $(BIN)/intervalo.bin $(OBJ)/main.o $(OBJ)/intervalo.o

$(OBJ)/intervalo.o : $(SRC)/intervalo.cpp $(INC)/intervalo.h
	g++ $(OPT) -c $(SRC)/intervalo.cpp -o $(OBJ)/intervalo.o -I$(INC) 
	
$(OBJ)/main.o : $(SRC)/main.cpp $(SRC)/intervalo.cpp $(INC)/intervalo.h
	g++ $(OPT) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC) 

clean: 
	@echo "Limpiando ... "
	rm -rf $(OBJ)/*.o $(BIN)/* $(LIB)/*
	
zip: clean
	@echo "Generando ZIP del proyecto " $(PRJ)
	zip -r $(ZIP)/$(PRJ).zip *
	
doxy:
	doxygen $(DOC)/intervalo.doxy
