#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "table.h"

#include "op/op_base.h"
#include "op/op_gestion.h"
#include "op/op_affichage.h"
#include "op/op_condition.h"

Table creerTable() {
   Table table;
   table.taille = 0;
   table.debut = NULL;
   return table;
}

void ajouter (Table * table, char * entree, int taille, Commande commande) {
   Symbole * aux;
   if (table->taille == 0){
      aux = malloc(sizeof(Symbole));
      table->debut = aux;
   } else if (table->taille == 1) {
      aux = malloc(sizeof(Symbole));
      table->debut->suivant = aux;
   } else {
      aux = table->debut;
      while (aux->suivant != NULL) {
         aux = aux->suivant;
      }
      aux->suivant = malloc(sizeof(Symbole));
      aux = aux->suivant;
   }
   aux->suivant = NULL;
   aux->tocken = malloc(sizeof(char)*(taille+1));
   snprintf(aux->tocken, taille+1, "%s", entree);
   aux->commande = commande;
   table->taille++;
}

int rechercher (Table table, char * entree, Commande * commande) {
   Symbole * aux = table.debut;
   while (aux != NULL && strcmp(aux->tocken, entree) != 0) {
      aux = aux->suivant;
   }
   if (aux != NULL) {
      *commande = aux->commande;
      return 0;
   } else {
      return 1;
   }
}

void initTable (Table * table) {
   ajouter(table, "+", 1, op_add);
   ajouter(table, "-", 1, op_sub);
   ajouter(table, "*", 1, op_mul);
   ajouter(table, "/", 1, op_div);
   ajouter(table, "DUP", 3, op_dup);
   ajouter(table, "DROP", 4, op_drop);
   ajouter(table, "SWAP", 4, op_swap);
   ajouter(table, "ROT", 3, op_rot);
   ajouter(table, ".", 1, op_point);
   ajouter(table, ".S", 2, op_point_s);
   ajouter(table, ".\"", 2, op_string);
   ajouter(table, "\"", 1, op_string_end);
   ajouter(table, "CR", 2, op_carriage_return);
   ajouter(table, "=", 1, op_eq);
   ajouter(table, "<", 1, op_inf);
   ajouter(table, ">", 1, op_sup);
   ajouter(table, "IF", 2, op_if);
   ajouter(table, "ELSE", 4, op_else);
   ajouter(table, "THEN", 4, op_then);
}
