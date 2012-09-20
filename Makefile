OBJ = main.o mainwindow.o pilamatrici.o pilamatrici_IO.o newgame.o coltura.o coltura_IO.o popup.o debug.o closingalert.o 
MOC = coltura_moc.cpp newgame_moc.cpp popup_moc.cpp mainwindow_moc.cpp debug_moc.cpp closingalert_moc.cpp
MOCOBJ = coltura_moc.o newgame_moc.o popup_moc.o mainwindow_moc.o debug_moc.o closingalert_moc.o
QTLIBS = `pkg-config --libs QtGui`
QTFLAG = `pkg-config --cflags QtGui`
        
CXXFLAGS = $(QTFLAG)
LDFLAGS = $(QTLIBS)
        
colturabatterica : $(OBJ) $(MOCOBJ)
	g++ -Wall -export-dynamic -o colturabatterica $+ $(LDFLAGS)


-include dependencies

#moc.o
mainwindow_moc.o : mainwindow_moc.cpp main.h mainwindow.h coltura.h

newgame_moc.o : newgame_moc.cpp newgame.h main.h

coltura_moc.o : coltura_moc.cpp main.h coltura.h pilamatrici.h

popup_moc.o : popup_moc.cpp popup.h

debug_moc.o : debug_moc.cpp debug.h

closingalert_moc.o : closingalert_moc.cpp closingalert.h

#moc.cpp
mainwindow_moc.cpp : mainwindow.cpp mainwindow.h
	moc mainwindow.h -o mainwindow_moc.cpp
	
newgame_moc.cpp : newgame.cpp newgame.h
	moc newgame.h -o newgame_moc.cpp
	
coltura_moc.cpp : coltura.cpp coltura.h
	moc coltura.h -o coltura_moc.cpp

popup_moc.cpp : popup.cpp popup.h
	moc popup.h -o popup_moc.cpp

debug_moc.cpp : debug.cpp debug.h
	moc debug.h -o debug_moc.cpp
	
closingalert_moc.cpp : closingalert.cpp closingalert.h
	moc closingalert.h -o closingalert_moc.cpp
	
.PHONY : clean cleanall doc depends

clean : 

	rm -f *.o *_moc.cpp

cleanall:
	rm -f colturabatterica dependencies *.o *_moc.cpp
	
doc :
	doxygen Doxyfile

depends:
	#creo la parte relativa ai "normali" file oggetto
	g++ -MM $(shell ls *.cpp | grep -v '.*_moc.cpp') > dependencies
	

	
	
