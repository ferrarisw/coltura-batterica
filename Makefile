OBJ = main.o mainwindow.o pilamatrici.o pilamatrici_IO.o starter.o coltura.o coltura_IO.o debug.o closingalert.o
MOC = coltura_moc.cpp starter_moc.cpp popup_moc.cpp mainwindow_moc.cpp debug_moc.cpp closingalert_moc.cpp
MOCOBJ = coltura_moc.o starter_moc.o popup_moc.o mainwindow_moc.o debug_moc.o closingalert_moc.o
QTLIBS = `pkg-config --libs QtGui`
QTFLAG = `pkg-config --cflags QtGui`
        
CXXFLAGS = $(QTFLAG)
LDFLAGS = $(QTLIBS)
        
colturabatterica : $(OBJ) $(MOCOBJ)
	g++ -Wall -export-dynamic -o colturabatterica $(OBJ) $(MOCOBJ) $(LDFLAGS)

main.o : main.cpp mainwindow.h pilamatrici.h coltura.h mainwindow.h starter.h main.h popup.h

mainwindow.o : mainwindow.cpp main.h mainwindow.h coltura.h

pilamatrici.o : pilamatrici.cpp pilamatrici.h main.h

pilamatrici_IO.o : pilamatrici_IO.cpp pilamatrici.h

starter.o : starter.cpp starter.h main.h mainwindow.h

coltura.o : coltura.cpp coltura.h main.h pilamatrici.h

coltura_IO.o : coltura_IO.cpp coltura.h

popup.o : popup.cpp popup.h

debug.o : debug.cpp debug.h main.h errors.h

closingalert.o : closingalert.cpp closingalert.h

#moc.o
mainwindow_moc.o : mainwindow_moc.cpp main.h mainwindow.h coltura.h

starter_moc.o : starter_moc.cpp starter.h main.h

coltura_moc.o : coltura_moc.cpp main.h coltura.h pilamatrici.h

popup_moc.o : popup_moc.cpp popup.h

debug_moc.o : debug_moc.cpp debug.h

closingalert_moc.o : closingalert_moc.cpp closingalert.h

#moc.cpp
mainwindow_moc.cpp : mainwindow.cpp mainwindow.h
	moc mainwindow.h -o mainwindow_moc.cpp
	
starter_moc.cpp : starter.cpp starter.h
	moc starter.h -o starter_moc.cpp
	
coltura_moc.cpp : coltura.cpp coltura.h
	moc coltura.h -o coltura_moc.cpp

popup_moc.cpp : popup.cpp popup.h
	moc popup.h -o popup_moc.cpp

debug_moc.cpp : debug.cpp debug.h
	moc debug.h -o debug_moc.cpp
	
closingalert_moc.cpp : closingalert.cpp closingalert.h
	moc closingalert.h -o closingalert_moc.cpp
	
.PHONY : clean doc
clean : 
	rm -f colturabatterica $(OBJ) $(MOC) $(MOCOBJ)
	
doc :
	doxygen Doxyfile
	
	