all : mycppLib.a matrixMatrixProdukt

FLAGS=-I./
FLAGS_EXEC=-I./ -lm


matrixU.o : matrixU.cpp matrixU.hpp
	g++ -c -o matrixU.o $(FLAGS) matrixU.c
myvector.o : myvector.cpp myvector.hpp
	g++ -c -o myvector.o $(FLAGS) myvector.c
mycppLib.a : myvector.o matrixU.o
	ar rcs mycppLib.a myvector.o matrixU.o

matrixMatrixProdukt : matrixMatrixProdukt.c mycppLib.a 
	gcc -o matrixMatrixProdukt $(FLAGS_EXEC) matrixMatrixProdukt.cpp
	
palindrom : palindrom.c
	gcc -o palindrom $(FLAGS_EXEC) palindrom.c
	
frobeniusnorm : frobeniusnorm.c myLib.a
	gcc -o frobeniusnorm $(FLAGS_EXEC) frobeniusnorm.c myLib.a
	
detlaplace : detlaplace.c myLib.a
	gcc -o detlaplace $(FLAGS_EXEC) detlaplace.c myLib.a
	
det : det.c myLib.a
	gcc -o det $(FLAGS_EXEC) det.c myLib.a
	
dec2float : dec2float.c myLib.a
	gcc -o dec2float $(FLAGS_EXEC) dec2float.c myLib.a
	
computeLU : computeLU.c myLib.a
	gcc -o computeLU $(FLAGS_EXEC) computeLU.c myLib.a
	