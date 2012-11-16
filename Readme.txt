LifeRunner (v1.0)

Requisiti.
Il programma necessita delle librerie grafiche QT, che nella compilazione
vengono incluse con gli appositi comandi definiti nel Makefile.

Compilazione.
Per compilare il programma è sufficiente invocare il comando make all'interno
della cartella dei file di codice.
In questo modo vengono compilati tutti i file sorgente tramite il compilatore
g++ e con l'utilizzo delle librerie esterne QtGui.
Verrà così creato un eseguibile di nome "liferunner".

Tramite l'invocazione di "make clean" verranno eliminate dalla cartella
tutti i file oggetto creati durante la compilazione e tutti i file moc
(Meta Object File) necessari per utilizzare le librerie Qt.

L'opzione "cleanall" permette di eliminare anche l'eseguibile e le dipendenze
create tramite il comando depend.

Il comando "doc" invoda doxygen e realizza una cartella contenente la
documentazione completa del progetto. Per accedervi è sufficiente aprire
il file "index.html" in un browser.

La "make depend" invoca g++ per generare parte delle dipendenze necessarie
per eseguire la compilazione vera e propria.

"make debug" crea una versione di debug del programma, contenente alcune 
funzionalità escluse dalla release grazie alla compilazione condizionale.
Viene per questo definita una Macro a tempo di compilazione di modo da
rendere attive le parti del programma escluse dalla compilazione condizionale.
Le funzionalità aggiunte consistono nella possibilità di attivare o meno
i diversi livelli i debug tramite tracing.
Esistono tre livelli di debug grafico e un livello di tracing algoritmico.
Inoltre esiste anche un livello di log che permette di accedere ad alcuni
dati statistici durante l'esecuzione del programma.
