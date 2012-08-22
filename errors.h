#ifndef ERRORS_H
#define ERRORS_H

enum streamsReturnValues {

};

enum viaggioNelTempoReturnValues {
    tooLowTime                      =       -40,    /* Tentativo di tornare prima della prima matrice*/
    sameMatrixRequest               =       -41,    /* Ritorno alla stessa matrice di partenza*/
    notEnoughMatrix                 =       -41,    /* Tentativo di andare oltre all'ultima matrice calcolata*/
    lastPossibleMatrix              =       -42,    /* Ho finito la pila di matrici*/

    matrixFound                     =       -48,    /* Matrice Trovata correttamente*/
    timeTripSucceded                =       -49     /* Viaggio nel tempo completato*/
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

enum debugActivityReturnValues {
    maskValueChangedSuccesfully     =       -60,    /* Maschera di DBG modificata con successo*/
    logMaskValueChangedSuccesfully  =       -61,    /* Maschera di LOG modificata con successo*/
    releaseVersionApplied           =       -62     /* Disattivato tutto il debug*/
};

#endif // ERRORS_H
