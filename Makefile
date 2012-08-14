OBJ = main.o mainwindow.o pilamatrici.o starter.o coltura.o

colturabatterica : $(OBJ)
	g++ -o colturabatterica $(OBJ)

main.o : main.cpp QtGui iostream mainwindow.h pilamatrici.h coltura.h mainwindow.h starter.h main.h popup.h
	g++ -c main.cpp

mainwindow.o : mainwindow.cpp iostream QtGui main.h mainwindow.h coltura.h
	g++ -c mainwindow.cpp

pilamatrici.o : pilamatrici.cpp iostream ctime cstdlib pilamatrici.h main.h
	g++ -c pilamatrici.cpp

starter.o : starter.cpp QtGui starter.h main.h cassert
	g++ -c starter.cpp

coltura.o : coltura.cpp iostream QtGui cmath main.h coltura.h pilamatrici.h cassert
	g++ -c coltura.cpp
  
.PHONY : clean 
clean : 
	rm colturabatterica $(OBJ)
	
	