#include <stdlib.h>
#include <stdio.h>

#include "lib/etat.h"

#define EXECUTER 0

int main (int argc, char * argv[]) {

   if (argc != 2) {
      printf("SORTIE : ERROR\n");
      return 1;
   }
   
   Etat etat;

   // Initialisation des structures de Forth
   Pile pile = creerPile();
   Pile adresses = creerPile();

   Table table = creerTable();
   initTable(&table);

   Programme * programme = lexer(argv[1]);

   etat.programme = *programme;
   etat.adresses = &adresses;
   etat.donnees = &pile;
   etat.table = &table;

   // Mode initial
   etat.mode = EXECUTER;
   etat.ignorer_if = 0;

   // Exécution
   executer(&etat);

   return 0;
}
