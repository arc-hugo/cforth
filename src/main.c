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

   Pile pile = creerPile();

   Table table = creerTable();
   initTable(&table);

   Programme * programme = lexer(argv[1]);

   etat.programme = *programme;
   etat.donnees = &pile;
   etat.table = &table;
   etat.mode = EXECUTER;
   etat.ignorer_if = 0;
   executer(&etat);

   return 0;
}
