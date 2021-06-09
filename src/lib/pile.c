#include <stdlib.h>
#include <stdio.h>

#include "pile.h"

Pile creerPile () {
   Pile pile;
   pile.taille = 0;
   pile.debut = NULL;
   return pile;
}

int vide (Pile pile) {
   if (pile.taille != 0){
      return 0;
   }
   return 1;
}

void empiler (Pile * pile, Valeur val, int type) {
   Cellule * cell = malloc(sizeof(Cellule)); 
   if (type == ENTIER) {
      cell->valeur.valInt = val.valInt;
   } else {
      cell->valeur.valFloat = val.valFloat;
   }
   cell->type = type;
   cell->suivant = pile->debut;
   pile->taille++;
   pile->debut = cell;
}

int depiler (Pile * pile, Valeur * val, int * type) {
   if (!vide(*pile)) {
      Cellule * cell = pile->debut;
      *type = cell->type;
      *val = cell->valeur;
      pile->debut = cell->suivant;
      free(cell);
      pile->taille--;
      return 0;
   }
   return 1;
}

void afficher (Pile pile) {
   printf("[");
   Cellule * cell = pile.debut;
   while (cell != NULL) {
      if (cell->type == ENTIER) {
	 printf("%d", cell->valeur.valInt);
      } else {
	 printf("%f", cell->valeur.valFloat);
      }
      if (cell->suivant != NULL) {
         printf(" -> ");
         cell = cell->suivant;
      } else {
         cell = NULL;
      }
   }
   printf("]");
}
