#include <stdlib.h>
#include <stdio.h>

#include "op_affichage.h"

int op_point (Etat * etat) {
   Valeur val;
   int type;
   int ret = depiler(etat->donnees, &val, &type);
   if (ret == 0) {
      if (type == ENTIER) {
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
