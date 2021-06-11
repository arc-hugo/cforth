#include <stdlib.h>

#include "op_gestion.h"

int op_dup (Etat * etat, int *index) {
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

int op_drop (Etat * etat, int *index) {
   Valeur val;
   int type, ret;

   if (etat->donnees->taille == 0) {
      return 1;
   }

   ret = depiler(etat->donnees, &val, &type);

   return ret;
}

int op_swap (Etat * etat, int *index) {
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

int op_rot (Etat * etat, int *index) {
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
