# lista dei sorgenti separati da spazi
SOURCES = main.cpp mainwindow.cpp pilamatrici.cpp pilamatrici_IO.cpp starter.cpp coltura.cpp coltura_IO.cpp debug.cpp closingalert.cpp about.cpp
OBJ = $(SOURCES:.cpp=.o)
MOC = coltura_moc.cpp starter_moc.cpp mainwindow_moc.cpp debug_moc.cpp closingalert_moc.cpp about_moc.cpp
DMOC = coltura_dmoc.cpp starter_dmoc.cpp mainwindow_dmoc.cpp debug_dmoc.cpp closingalert_dmoc.cpp about_dmoc.cpp
MOCOBJ = $(MOC:.cpp=.o)


QTLIBS = `pkg-config --libs QtGui`
QTFLAG = `pkg-config --cflags QtGui`
        
CXXFLAGS = $(QTFLAG) -Wall
LDFLAGS = $(QTLIBS)
DFLAG = -D DEBUG_MODE
        
liferunner : $(OBJ) $(MOCOBJ)
	g++ -export-dynamic -o liferunner $+ $(LDFLAGS)

-include dependencies

#moc.cpp
mainwindow_moc.cpp : mainwindow.cpp mainwindow.h
	moc mainwindow.h -o mainwindow_moc.cpp
        
starter_moc.cpp : starter.cpp starter.h
	moc starter.h -o starter_moc.cpp
        
coltura_moc.cpp : coltura.cpp coltura.h
	moc coltura.h -o coltura_moc.cpp

debug_moc.cpp : debug.cpp debug.h
	moc debug.h -o debug_moc.cpp

about_moc.cpp : about.cpp about.o
	moc about.h -o about_moc.cpp
        
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

about_dmoc.cpp : about.cpp about.o
	moc $(DFLAG) about.h -o about_dmoc.cpp
        
closingalert_dmoc.cpp : closingalert.cpp closingalert.h
	moc $(DFLAG) closingalert.h -o closingalert_dmoc.cpp

.PHONY : clean cleanall depend debug doc exec

clean : 
	rm -f *.o *moc.cpp

cleanall:
	rm -f liferunner dependencies *.o *moc.cpp

doc: clean
	 doxygen

depend: *.cpp
	#creo la parte relativa ai "normali" file oggetto
	g++ -D DEBUG_MODE -MM $(shell ls *.cpp | grep -v '.*moc.cpp') > dependencies

debug: clean $(SOURCES) $(DMOC)
	g++ -g $(DFLAG) -export-dynamic -o liferunner $(LDFLAGS) $(CXXFLAGS) $(SOURCES) $(DMOC)

exec: liferunner
	./liferunner
