#include <stdlib.h>

#include "op_boucle.h"

int op_begin(Etat *etat, int *index) {
   Valeur val;
   val.adresse = *index;
   empiler(etat->adresses, val, ADRESSE);
   return 0;
}

int op_until(Etat *etat, int *index) {

   return 0;
}
