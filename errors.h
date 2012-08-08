#ifndef ERRORS_H
#define ERRORS_H

enum streamErrors {

};

enum godModeErrors {
    notExistingMatrix               =       -50,    /* Tentativo di modificare matrici non esistenti*/
    cellsNumberOverflow             =       -51,    /* Tentativo di modificare una cella esterna alla matrice*/

    changesOccurred                 =       -59,    /* Modifiche effettuate con successo*/

    godModeChangesActivitySucc      =       -60,    /* Modificata l'attivazione della godMode*/
    godModeChangesActivitySwitched  =       -61     /* Modificata l'attivazione della godMode*/
};

#endif // ERRORS_H
