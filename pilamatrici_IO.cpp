#include "pilamatrici.h"

using namespace std;

bool PilaMatrici::salva (QString file)
{
    ofstream salva (file.toStdString().data());

    if (!salva)
        return false;

    //salva<<versionefile<<endl;

    salva<<this->dimx<<" "<<this->dimy<<endl;

    salva<<posizioneAttuale->tempo<<endl;

    for (int j = 1; j < dimy + 1; j++) {
        for (int i = 1; i < dimx + 1; i++) {
            salva<<posizioneAttuale->tabella[i + j * (dimx + 2)]<<" ";
        } salva<<endl;
    }

    salva.close();

    return true;
}

bool PilaMatrici::carica (QString file)
{
    ifstream carica (file.toStdString().data());

    if (!carica)
        return false;

    carica>>dimx>>dimy;
    TRACE("[PilaMatrici::carica] modificati dimx e dimy");

    testa = creaMatrice(NULL, NULL, 0);
    coda = testa;
    posizioneAttuale = testa;

    matriciRealizzate = 0;

    carica>>posizioneAttuale->tempo;

    for (int j = 1; j < dimy + 1; j++) {
        for (int i = 1; i < dimx + 1; i++) {
            carica>>posizioneAttuale->tabella[i + j * (dimx + 2)];
        }
    }

    GD3(cout<<"[PilaMatrici::carica] tabella:"<<endl;
        this->stampa();
        ); //Fine GD3

    return true;
}

