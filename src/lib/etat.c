#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "etat.h"
#include "table.h"

void executer (Etat * etat) {
   int ret = 0;
   Commande * com = malloc(sizeof(Commande));
   for (int i = 0; i < etat->programme.taille; i++) {
      if (etat->mode != AFFICHER) {
         if (rechercher(*(etat->table), etat->programme.tokens[i], com) == 0) {
            if (etat->mode == EXECUTER ||
               strcmp(etat->programme.tokens[i], "THEN" ) == 0 ||
               strcmp(etat->programme.tokens[i], "IF" ) == 0 ||
               strcmp(etat->programme.tokens[i], "ELSE") == 0)
               ret = (*com)(etat);
         } else {
            Valeur val;
            int entier = atoi(etat->programme.tokens[i]);
            float flottant = atof(etat->programme.tokens[i]);
            if (entier == flottant){
               val.valInt = entier;
               empiler(etat->donnees, val, 0);
            } else {
               val.valFloat = flottant;
               empiler(etat->donnees, val, 1);
            }
         } 
         if (ret != 0) {
            printf("SORTIE : ERROR\n");
            exit(EXIT_FAILURE);
         }
      } else if (etat->mode == AFFICHER) {
         if (strcmp(etat->programme.tokens[i],"\"") == 0) {
            rechercher(*(etat->table), etat->programme.tokens[i], com);
            (*com)(etat);
         } else {
            printf("%s ",etat->programme.tokens[i]);
         }
      }
   }
}
