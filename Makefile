# lista dei sorgenti separati da spazi
SOURCES = main.cpp mainwindow.cpp pilamatrici.cpp pilamatrici_IO.cpp starter.cpp coltura.cpp coltura_IO.cpp wdebug.cpp closingalert.cpp 
OBJ = $(SOURCES:.cpp=.o)
MOC = coltura_moc.cpp starter_moc.cpp mainwindow_moc.cpp wdebug_moc.cpp closingalert_moc.cpp
DMOC = coltura_dmoc.cpp starter_dmoc.cpp mainwindow_dmoc.cpp wdebug_dmoc.cpp closingalert_dmoc.cpp
MOCOBJ = coltura_moc.o starter_moc.o mainwindow_moc.o wdebug_moc.o closingalert_moc.o


QTLIBS = `pkg-config --libs QtGui`
QTFLAG = `pkg-config --cflags QtGui`
        
CXXFLAGS = $(QTFLAG) -Wall
LDFLAGS = $(QTLIBS)
DFLAG = -D DEBUG_MODE
        
liferunner : $(OBJ) $(MOCOBJ)
	g++ -export-dynamic -o liferunner $+ $(LDFLAGS)


#moc.cpp
mainwindow_moc.cpp : mainwindow.cpp mainwindow.h
	moc mainwindow.h -o mainwindow_moc.cpp
        
starter_moc.cpp : starter.cpp starter.h
	moc starter.h -o starter_moc.cpp
        
coltura_moc.cpp : coltura.cpp coltura.h
	moc coltura.h -o coltura_moc.cpp

wdebug_moc.cpp : wdebug.cpp wdebug.h
	moc wdebug.h -o wdebug_moc.cpp
        
closingalert_moc.cpp : closingalert.cpp closingalert.h
	moc closingalert.h -o closingalert_moc.cpp
        
#dmoc
mainwindow_dmoc.cpp : mainwindow.cpp mainwindow.h
	moc $(DFLAG) mainwindow.h -o mainwindow_dmoc.cpp
        
starter_dmoc.cpp : starter.cpp starter.h
	moc $(DFLAG) starter.h -o starter_dmoc.cpp
        
coltura_dmoc.cpp : coltura.cpp coltura.h
	moc $(DFLAG) coltura.h -o coltura_dmoc.cpp

wdebug_dmoc.cpp : wdebug.cpp wdebug.h
	moc $(DFLAG) wdebug.h -o wdebug_dmoc.cpp
        
closingalert_dmoc.cpp : closingalert.cpp closingalert.h
	moc $(DFLAG) closingalert.h -o closingalert_dmoc.cpp

.PHONY : clean cleanall doc depend debug

clean : 
	rm -f *.o *moc.cpp

cleanall:
	rm -f -r liferunner dependencies *.o *moc.cpp doc

doc: clean
	doxygen Doxyfile

depend: *.cpp
	#creo la parte relativa ai "normali" file oggetto
	g++ -MM $(shell ls *.cpp | grep -v '.*moc.cpp') > dependencies

debug: $(SOURCES) $(DMOC)
	g++ -g $(DFLAG) -export-dynamic -o liferunner $(LDFLAGS) $(CXXFLAGS) $(SOURCES) $(DMOC)
