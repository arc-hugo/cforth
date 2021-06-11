#ifndef TABLE_H
#define TABLE_H

#include "pile.h"
#include "programme.h"

typedef struct Etat Etat;

typedef int (*Commande)(Etat*, int*);

typedef struct Symbole {
   char * tocken;
   Commande commande;
   struct Symbole * suivant;
} Symbole;

typedef struct Table {
   int taille;
   Symbole * debut;
} Table;

Table creerTable();
void initTable(Table * table);
void ajouter(Table * table, char * entree, int taille, Commande commande);
int rechercher(Table table, char * entree, Commande * commande);
#endif
