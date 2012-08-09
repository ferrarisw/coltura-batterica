#include <fstream>
#include "main.h"
#include "pilamatrici.h"

using namespace std;
/*
bool PilaMatrici::salva (QString file)
{
    ofstream salva (file.toStdString().data());

    if (!salva)
        return false;

    //salva<<versionefile<<endl;

    salva<<posizioneAttuale->tempo<<endl;

    salva<<this->dimx<<" "<<this->dimy<<endl;

    salva<<testa->tempo<<endl;

    for (int j = 1; j < dimy + 1; j++) {
        for (int i = 1; i < dimx + 1; i++)
        {
            salva<<posizioneAttuale->tabella[i + j * (dimx + 2)]<<" ";
        } salva<<endl;
    }

    salva.close();

    return true;
}

PilaMatrici* PilaMatrici::carica (QString file)
{
    ifstream carica (file.toStdString().data());

    if (!carica)
        return false;

    //carica>>versionefile;

    carica>>posizioneAttuale->tempo;

    carica>>this->dimx>>this->dimy;

    carica>>testa->tempo>>endl;

    for (int j = 1; j < dimy + 1; j++) {
        for (int i = 1; i < dimx + 1; i++)
        {
            carica>>posizioneAttuale->tabella[i + j * (dimx + 2)];
        }
    }

    int dimx, dimy;

    PilaMatrici* nuovaPila = new PilaMatrici(dimx, dimy);

    return nuovaPila;
}
*/
