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
    godModeChangesActivitySucceded  =       -52,    /* Modificata l'attivazione della godMode*/
    godModeChangesActivitySwitched  =       -53,    /* Modificata l'attivazione della godMode*/

    godModeInitialized              =       -57,    /* Inizializzata la godMode con nuova linea di matrici*/
    changesOccurred                 =       -58,    /* Modifiche effettuate con successo*/
    returnedToMainLine              =       -59     /* Ritornato alla linea principale*/
};

#endif // ERRORS_H
