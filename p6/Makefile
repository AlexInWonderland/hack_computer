#test
all: main.o parser.o coder.o translater.o global.o SymbolTable.o
	g++ -g -o main main.o parser.o coder.o translater.o global.o SymbolTable.o
#	g++ -g -Q -da -v -o main main.o parser.o coder.o translater.o global.o SymbolTable.o
main.o: main.cpp
	g++ -g -c main.cpp
parser.o: parser.cpp parser.h
	g++ -g -c parser.cpp -std=c++11
coder.o: coder.cpp coder.h
	g++ -g -c coder.cpp
translater.o: translater.cpp translater.h
	g++ -g -c translater.cpp
global.o: global.cpp global.h
	g++ -g -c global.cpp
SymbolTable.o: SymbolTable.cpp SymbolTable.h
	g++ -g -c SymbolTable.cpp -std=c++11

clean:
	rm -f *.o
	rm main
	
