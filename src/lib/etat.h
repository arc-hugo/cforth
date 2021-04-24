#ifndef ETAT_H
#define ETAT_H

#include "pile.h"
#include "programme.h"
#include "table.h"

#define TRUE -1
#define FALSE 0

#define EXECUTER 0
#define AFFICHER 1
#define IGNORER 2

typedef struct Etat {
   Pile * donnees;
   Programme programme;
   Table * table;
   int mode;
   int ignorer_if;
} Etat;

void executer (Etat * etat);
#endif
