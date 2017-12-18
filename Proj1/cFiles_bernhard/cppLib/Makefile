all : polyAddMain polyDiffMain polyIntegralMain polyMultMain polynomialMain polyTaylorMain polyZeroMain

FLAGS=-I./
FLAGS_EXEC=-I./ -lm


matrixU.o : matrixU.cpp matrixU.hpp
	g++ -c -o matrixU.o $(FLAGS) matrixU.cpp
myvector.o : myvector.cpp myvector.hpp
	g++ -c -o myvector.o $(FLAGS) myvector.cpp
polynomial.o : polynomial.cpp polynomial.hpp
	g++ -c -o polynomial.o $(FLAGS) polynomial.cpp
mycppLib.a : myvector.o matrixU.o polynomial.o
	ar rcs mycppLib.a myvector.o matrixU.o polynomial.o

polyAddMain : polyAddMain.cpp mycppLib.a 
	g++ -o polyAddMain $(FLAGS_EXEC) polyAddMain.cpp mycppLib.a
	
polyDiffMain : polyDiffMain.cpp mycppLib.a 
	g++ -o polyDiffMain $(FLAGS_EXEC) polyDiffMain.cpp mycppLib.a
	
polyIntegralMain : polyIntegralMain.cpp mycppLib.a 
	g++ -o polyIntegralMain $(FLAGS_EXEC) polyIntegralMain.cpp mycppLib.a
	
polyMultMain : polyMultMain.cpp mycppLib.a 
	g++ -o polyMultMain $(FLAGS_EXEC) polyMultMain.cpp mycppLib.a
	
polynomialMain : polynomialMain.cpp mycppLib.a 
	g++ -o polynomialMain $(FLAGS_EXEC) polynomialMain.cpp mycppLib.a
	
polyTaylorMain : polyTaylorMain.cpp mycppLib.a 
	g++ -o polyTaylorMain $(FLAGS_EXEC) polyTaylorMain.cpp mycppLib.a
	
polyZeroMain : polyZeroMain.cpp mycppLib.a 
	g++ -o polyZeroMain $(FLAGS_EXEC) polyZeroMain.cpp mycppLib.a
	