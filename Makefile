OBJ = main.o mainwindow.o pilamatrici.o pilamatrici_IO.o starter.o coltura.o coltura_IO.o debug.o closingalert.o 
MOC = coltura_moc.cpp starter_moc.cpp mainwindow_moc.cpp debug_moc.cpp closingalert_moc.cpp
DMOC = coltura_dmoc.cpp starter_dmoc.cpp mainwindow_dmoc.cpp debug_dmoc.cpp closingalert_dmoc.cpp
MOCOBJ = coltura_moc.o starter_moc.o mainwindow_moc.o debug_moc.o closingalert_moc.o


QTLIBS = `pkg-config --libs QtGui`
QTFLAG = `pkg-config --cflags QtGui`
        
CXXFLAGS = $(QTFLAG) -Wall
LDFLAGS = $(QTLIBS)
DFLAG = -D DEBUG_MODE
        
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
	
#dmoc
mainwindow_dmoc.cpp : mainwindow.cpp mainwindow.h
	moc $(DFLAG) mainwindow.h -o mainwindow_dmoc.cpp
	
starter_dmoc.cpp : starter.cpp starter.h
	moc $(DFLAG) starter.h -o starter_dmoc.cpp
	
coltura_dmoc.cpp : coltura.cpp coltura.h
	moc $(DFLAG) coltura.h -o coltura_dmoc.cpp

debug_dmoc.cpp : debug.cpp debug.h
	moc $(DFLAG) debug.h -o debug_dmoc.cpp
	
closingalert_dmoc.cpp : closingalert.cpp closingalert.h
	moc $(DFLAG) closingalert.h -o closingalert_dmoc.cpp

.PHONY : clean cleanall doc depends debug

clean : 
	rm -f *.o *moc.cpp

cleanall:
	rm -f -r colturabatterica dependencies *.o *moc.cpp html
	
doc :
	$(shell doxygen Doxyfile > /dev/null)

depends:
	#creo la parte relativa ai "normali" file oggetto
	g++ -MM $(shell ls *.cpp | grep -v '.*moc.cpp') > dependencies

debug: $(shell ls *.cpp | grep -v '.*_moc.cpp')
	rm -f *_moc.cpp
	g++ -g $(DFLAG)  -export-dynamic -o colturabatterica $(LDFLAGS) $(CXXFLAGS) *.cpp 



