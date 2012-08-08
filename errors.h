#ifndef ERRORS_H
#define ERRORS_H

enum streamsReturnValues {

};

enum viaggioNelTempoReturnValues {
    notExistingTime                 =       -40,    /* Tentativo di tornare prima della prima matrice*/
    sameMatrixRequest               =       -41,    /* Ritorno alla stessa matrice di partenza*/
    notEnoughMatrix                 =       -41,    /* Tentativo di andare oltre all'ultima matrice calcolata*/

    matrixFound                     =       -49     /* Matrice Trovata correttamente*/
};

enum godModeReturnValues {
    notExistingMatrix               =       -50,    /* Tentativo di modificare matrici non esistenti*/
    cellsNumberOverflow             =       -51,    /* Tentativo di modificare una cella esterna alla matrice*/

    changesOccurred                 =       -59,    /* Modifiche effettuate con successo*/

    godModeChangesActivitySucceded  =       -60,    /* Modificata l'attivazione della godMode*/
    godModeChangesActivitySwitched  =       -61     /* Modificata l'attivazione della godMode*/
};

#endif // ERRORS_H
