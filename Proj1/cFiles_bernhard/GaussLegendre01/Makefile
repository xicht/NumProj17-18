all : SquareMatrixMain asdf person

FLAGS=-I./
FLAGS_EXEC=-I./ -lm


matrixU.o : matrixU.cpp matrixU.hpp
	g++ -c -o matrixU.o $(FLAGS) matrixU.cpp
myvector.o : myvector.cpp myvector.hpp
	g++ -c -o myvector.o $(FLAGS) myvector.cpp
polynomial.o : polynomial.cpp polynomial.hpp
	g++ -c -o polynomial.o $(FLAGS) polynomial.cpp
matrix.o : matrix.cpp matrix.hpp
	g++ -c -o matrix.o $(FLAGS) matrix.cpp
SquareMatrix.o : SquareMatrix.cpp SquareMatrix.hpp matrix.hpp matrix.cpp
	g++ -c -o SquareMatrix.o $(FLAGS) SquareMatrix.cpp
mycppLib.a : myvector.o matrixU.o polynomial.o SquareMatrix.o matrix.o
	ar rcs mycppLib.a myvector.o matrixU.o polynomial.o SquareMatrix.o matrix.o

person : person.cpp person.hpp personmain.cpp 
	g++ -o person $(FLAGS_EXEC) person.cpp personmain.cpp

asdf : asdf.cpp 
	g++ -o asdf $(FLAGS_EXEC) asdf.cpp

SquareMatrixMain : SquareMatrixMain.cpp mycppLib.a 
	g++ -o SquareMatrixMain $(FLAGS_EXEC) SquareMatrixMain.cpp mycppLib.a
