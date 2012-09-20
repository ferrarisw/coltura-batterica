OBJ = main.o mainwindow.o pilamatrici.o pilamatrici_IO.o starter.o coltura.o coltura_IO.o popup.o debug.o closingalert.o 
MOC = coltura_moc.cpp starter_moc.cpp popup_moc.cpp mainwindow_moc.cpp debug_moc.cpp closingalert_moc.cpp
MOCOBJ = coltura_moc.o starter_moc.o popup_moc.o mainwindow_moc.o debug_moc.o closingalert_moc.o

QTLIBS = `pkg-config --libs QtGui`
QTFLAG = `pkg-config --cflags QtGui`
        
CXXFLAGS = $(QTFLAG) -Wall
LDFLAGS = $(QTLIBS)
        
colturabatterica : $(OBJ) $(MOCOBJ)
	g++ -export-dynamic -o colturabatterica $+ $(LDFLAGS)


-include dependencies

#moc.o
mainwindow_moc.o : mainwindow_moc.cpp main.h mainwindow.h coltura.h

starter_moc.o : starter_moc.cpp starter.h main.h

coltura_moc.o : coltura_moc.cpp main.h coltura.h pilamatrici.h

debug_moc.o : debug_moc.cpp debug.h

closingalert_moc.o : closingalert_moc.cpp closingalert.h

#moc.cpp
mainwindow_moc.cpp : mainwindow.cpp mainwindow.h
	moc mainwindow.h -o mainwindow_moc.cpp
	
starter_moc.cpp : starter.cpp starter.h
	moc starter.h -o starter_moc.cpp
	
coltura_moc.cpp : coltura.cpp coltura.h
	moc coltura.h -o coltura_moc.cpp

debug_moc.cpp : debug.cpp debug.h
	moc debug.h -o debug_moc.cpp
	
closingalert_moc.cpp : closingalert.cpp closingalert.h
	moc closingalert.h -o closingalert_moc.cpp
	
.PHONY : clean cleanall doc depends debug

clean : 
	rm -f *.o *_moc.cpp

cleanall:
	rm -f -r colturabatterica dependencies *.o *_moc.cpp html
	
doc :
	doxygen Doxyfile

depends:
	#creo la parte relativa ai "normali" file oggetto
	g++ -MM $(shell ls *.cpp | grep -v '.*_moc.cpp') > dependencies

debug:
	g++ -export-dynamic -g -D DEBUG_MODE -o colturabatterica $(LDFLAGS) $(OBJ) $(MOCOBJ) 

	

