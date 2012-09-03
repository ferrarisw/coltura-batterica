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

PilaMatrici* PilaMatrici::carica (QString file)
{
    ifstream carica (file.toStdString().data());

    if (!carica)
        return static_cast<PilaMatrici*>(false);

    //carica>>versionefile;

    int dimx, dimy;
    carica>>dimx>>dimy;

    PilaMatrici* nuovaPila = new PilaMatrici(dimx, dimy, 99);

    carica>>posizioneAttuale->tempo;

    for (int j = 1; j < dimy + 1; j++) {
        for (int i = 1; i < dimx + 1; i++)
        {
            carica>>posizioneAttuale->tabella[i + j * (dimx + 2)];
        }
    }

    return nuovaPila;
}

