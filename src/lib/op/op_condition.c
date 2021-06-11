#include <stdlib.h>
#include <string.h>

#include "../etat.h"

int op_inf (Etat * etat, int *index) {
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
         if (type1 == FLOTTANT)
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

int op_sup (Etat * etat, int *index) {
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
         if (type1 == FLOTTANT)
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

int op_eq (Etat * etat, int *index) {
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

int op_if (Etat * etat, int *index) {
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

int op_else (Etat * etat, int *index) {
   if (etat->ignorer_if == 0 && etat->mode == IGNORER)
      etat->mode = EXECUTER;
   else
      etat->mode = IGNORER;
   return 0;
}

int op_then (Etat * etat, int *index) {
   etat->ignorer_if = 0;
   etat->mode = EXECUTER;
   return 0;
}
