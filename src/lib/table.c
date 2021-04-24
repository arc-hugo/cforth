#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "pile.h"
#include "table.h"
#include "etat.h"

Table creerTable() {
   Table table;
   table.taille = 0;
   table.debut = NULL;
   return table;
}

int op_add (Etat * etat) {
   Valeur val1, val2, valEmp;
   int type1, type2, typeEmp = 1, ret;

   if (etat->donnees->taille <= 1) {
      return 1;
   }

   ret = depiler(etat->donnees, &val2, &type2);
   ret += depiler(etat->donnees, &val1, &type1);
   switch (type1+type2) {
      case 0:
         valEmp.valInt = val1.valInt + val2.valInt;
         typeEmp = 0;
         break;
      case 1:
         if (type1 == 1)
            valEmp.valFloat = val1.valFloat+val2.valInt;
         else
            valEmp.valFloat = val1.valInt+val2.valFloat;
         break;
      case 2:
         valEmp.valFloat = val1.valFloat+val2.valFloat;
         break;
   }

   empiler(etat->donnees, valEmp, typeEmp);
   return ret;
}

int op_sub (Etat * etat) {
   Valeur val1, val2, valEmp;
   int type1, type2, typeEmp = 1, ret;

   if (etat->donnees->taille <= 1) {
      return 1;
   }

   ret = depiler(etat->donnees, &val2, &type2);
   ret += depiler(etat->donnees, &val1, &type1);
   switch (type1+type2) {
      case 0:
         valEmp.valInt = val1.valInt-val2.valInt;
         typeEmp = 0;
         break;
      case 1:
         if (type1 == 1)
            valEmp.valFloat = val1.valFloat-val2.valInt;
         else
            valEmp.valFloat = val1.valInt-val2.valFloat;
         break;
      case 2:
         valEmp.valFloat = val1.valFloat-val2.valFloat;
         break;
   }

   empiler(etat->donnees, valEmp, typeEmp);
   return ret; 
}

int op_mul (Etat * etat) {
   Valeur val1, val2, valEmp;
   int type1, type2, typeEmp = 1, ret;

   if (etat->donnees->taille <= 1) {
      return 1;
   }

   ret = depiler(etat->donnees, &val2, &type2);
   ret += depiler(etat->donnees, &val1, &type1);
   switch (type1+type2) {
      case 0:
         valEmp.valInt = val1.valInt*val2.valInt;
         typeEmp = 0;
         break;
      case 1:
         if (type1 == 1)
            valEmp.valFloat = val1.valFloat*val2.valInt;
         else
            valEmp.valFloat = val1.valInt*val2.valFloat;
         break;
      case 2:
         valEmp.valFloat = val1.valFloat*val2.valFloat;
         break;
   }

   empiler(etat->donnees, valEmp, typeEmp);
   return ret; 
}

int op_div (Etat * etat) {
   Valeur val1, val2, valEmp;
   int type1, type2, typeEmp = 1, ret, entier;
   float flottant;

   if (etat->donnees->taille <= 1) {
      return 1;
   }
   ret = depiler(etat->donnees, &val2, &type2);
   ret += depiler(etat->donnees, &val1, &type1);
   switch (type1+type2) {
      case 0:
         entier = (val1.valInt/val2.valInt);
         flottant = ((float) val1.valInt)/val2.valInt;
         if (entier == flottant) {
            valEmp.valInt = entier;
            typeEmp = 0;
         } else
            valEmp.valFloat = flottant;
         break;
      case 1:
         if (type1 == 1)
            valEmp.valFloat = val1.valFloat/val2.valInt;
         else
            valEmp.valFloat = ((float)val1.valInt)/val2.valFloat;
         break;
      case 2:
         valEmp.valFloat = val1.valFloat/val2.valFloat;
         break;
   }

   empiler(etat->donnees, valEmp, typeEmp);
   return ret;
}

int op_dup (Etat * etat) {
   Valeur val;
   int type, ret;

   if (etat->donnees->taille == 0) {
      return 1;
   }

   ret = depiler(etat->donnees, &val, &type);
   empiler(etat->donnees, val, type);
   empiler(etat->donnees, val, type);

   return ret;
}

int op_drop (Etat * etat) {
   Valeur val;
   int type, ret;

   if (etat->donnees->taille == 0) {
      return 1;
   }

   ret = depiler(etat->donnees, &val, &type);

   return ret;
}

int op_swap (Etat * etat) {
   if (etat->donnees->taille <= 1) {
      return 1;
   }
   Valeur val1, val2;
   int type1, type2, ret;

   ret = depiler(etat->donnees, &val1, &type1);
   ret += depiler(etat->donnees, &val2, &type2);
   empiler(etat->donnees, val1, type1);
   empiler(etat->donnees, val2, type2);

   return ret;
}

int op_rot (Etat * etat) {
   if (etat->donnees->taille <= 2) {
      return 1;
   }
   Valeur * val = malloc(sizeof(Valeur)*3);
   int * type = malloc(sizeof(int)*3);
   int ret = 0;

   ret += depiler(etat->donnees, &val[0], &type[0]);
   ret += depiler(etat->donnees, &val[1], &type[1]);
   ret += depiler(etat->donnees, &val[2], &type[2]);

   empiler(etat->donnees, val[1], type[1]);
   empiler(etat->donnees, val[0], type[0]);
   empiler(etat->donnees, val[2], type[2]);
   
   return ret;
}

int op_point (Etat * etat) {
   Valeur val;
   int type;
   int ret = depiler(etat->donnees, &val, &type);
   if (ret == 0) {
      if (type == 0) {
         printf("%d ", val.valInt);
      } else {
         printf("%f ", val.valFloat);
      }
   }
   return ret;
}

int op_point_s (Etat * etat) {
   afficher(*(etat->donnees));
   return 0;
}

int op_string (Etat * etat) {
   etat->mode = AFFICHER;
   return 0;
}

int op_string_end (Etat * etat) {
   etat->mode = EXECUTER;
   return 0;
}

int op_carriage_return (Etat * etat) {
   printf("\n");
   return 0;
}

int op_inf (Etat * etat) {
   Valeur val1, val2, valEmp;
   int type1, type2;

   int ret = depiler(etat->donnees, &val2, &type2);
   ret += depiler(etat->donnees, &val1, &type1);
   switch (type1+type2) {
      case 0:
         if (val1.valInt < val2.valInt)
            valEmp.valInt = TRUE;
         else
            valEmp.valInt = FALSE;
         break;
      case 1:
         if (type1 == 1)
            if (val1.valFloat < val2.valInt)
               valEmp.valInt = TRUE;
            else
               valEmp.valInt = FALSE;
         else 
            if (val1.valInt < val2.valFloat)
               valEmp.valInt = TRUE;
            else
               valEmp.valInt = FALSE;
         break;
      case 2:
         if (val1.valFloat < val2.valFloat)
            valEmp.valInt = TRUE;
         else
            valEmp.valInt = FALSE;
         break;
   }

   empiler(etat->donnees, valEmp, 0);
   return ret;
}

int op_sup (Etat * etat) {
   Valeur val1, val2, valEmp;
   int type1, type2;
   
   int ret = depiler(etat->donnees, &val2, &type2);
   ret += depiler(etat->donnees, &val1, &type1);
   switch (type1+type2) {
      case 0:
         if (val1.valInt > val2.valInt)
            valEmp.valInt = TRUE;
         else
            valEmp.valInt = FALSE;
         break;
      case 1:
         if (type1 == 1)
            if (val1.valFloat > val2.valInt)
               valEmp.valInt = TRUE;
            else
               valEmp.valInt = FALSE;
         else 
            if (val1.valInt > val2.valFloat)
               valEmp.valInt = TRUE;
            else
               valEmp.valInt = FALSE;
         break;
      case 2:
         if (val1.valFloat > val2.valFloat)
            valEmp.valInt = TRUE;
         else
            valEmp.valInt = FALSE;
         break;
   }

   empiler(etat->donnees, valEmp, 0);
   return ret;
}

int op_eq (Etat * etat) {
   Valeur val1, val2, valEmp;
   int type1, type2;
   
   int ret = depiler(etat->donnees, &val2, &type2);
   ret += depiler(etat->donnees, &val1, &type1);
   switch (type1+type2) {
      case 0:
         if (val1.valInt == val2.valInt)
            valEmp.valInt = TRUE;
         else
            valEmp.valInt = FALSE;
         break;
      case 1:
         valEmp.valInt = FALSE;
         break;
      case 2:
         if (val1.valFloat == val2.valFloat)
            valEmp.valInt = TRUE;
         else
            valEmp.valInt = FALSE;
         break;
   }

   empiler(etat->donnees, valEmp, 0);
   return ret;
}

int op_if (Etat * etat) {
   int ret = 0;
   if (etat->mode != IGNORER) {
      Valeur val;
      int type;
      ret = depiler(etat->donnees, &val, &type);
      if (val.valInt == FALSE) {
         etat->mode = IGNORER;
         etat->ignorer_if = 0;
      } else {
         etat->ignorer_if = 1;
      }
   }
   return ret;
}

int op_else (Etat * etat) {
   if (etat->ignorer_if == 0 && etat->mode == IGNORER)
      etat->mode = EXECUTER;
   else
      etat->mode = IGNORER;
   return 0;
}

int op_then (Etat * etat) {
   etat->ignorer_if = 0;
   etat->mode = EXECUTER;
   return 0;
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
