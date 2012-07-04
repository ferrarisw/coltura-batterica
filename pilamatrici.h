#ifndef PILAMATRICI_H
#define PILAMATRICI_H

class PilaMatrici
{
public:
    PilaMatrici(int x, int y);
    int * next();

    void stampa ();

private:

    int dimx;   //Dimensioni della matrice
    int dimy;

    enum stato {morto = 0, vivo = 1};

    /*
      * La Matrice ha un puntatore a puntatore di interi per la tabella,
      * un puntatore alla tabella successiva e uno alla tabella precedente.
      */
    struct Matrix {
        int* tabella;
        Matrix* succ;
        Matrix* prec;
        int tempo;
    };

    /*
      * Due puntatori, uno alla testa e uno alla coda della lista di matrici
      */
    Matrix* testa;
    Matrix* coda;
    Matrix* posizioneAttuale;

    Matrix* creaMatrice(Matrix* succ, Matrix* prec);
    void riempiCasuale(Matrix* pos);
    int getValore(int * cella, int , int);
};

#endif // PILAMATRICI_H
