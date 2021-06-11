#include <stdlib.h>

#include "op_base.h"


int op_add (Etat * etat, int *index) {
   Valeur val1, val2, valEmp;
   int type1, type2, typeEmp = FLOTTANT, ret;

   if (etat->donnees->taille <= 1) {
      return 1;
   }

   ret = depiler(etat->donnees, &val2, &type2);
   ret += depiler(etat->donnees, &val1, &type1);
   switch (type1+type2) {
      case 0:
         valEmp.valInt = val1.valInt + val2.valInt;
         typeEmp = ENTIER;
         break;
      case 1:
         if (type1 == FLOTTANT)
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

int op_sub (Etat * etat, int *index) {
   Valeur val1, val2, valEmp;
   int type1, type2, typeEmp = FLOTTANT, ret;

   if (etat->donnees->taille <= 1) {
      return 1;
   }

   ret = depiler(etat->donnees, &val2, &type2);
   ret += depiler(etat->donnees, &val1, &type1);
   switch (type1+type2) {
      case 0:
         valEmp.valInt = val1.valInt-val2.valInt;
         typeEmp = ENTIER;
         break;
      case 1:
         if (type1 == FLOTTANT)
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

int op_mul (Etat * etat, int *index) {
   Valeur val1, val2, valEmp;
   int type1, type2, typeEmp = FLOTTANT, ret;

   if (etat->donnees->taille <= 1) {
      return 1;
   }

   ret = depiler(etat->donnees, &val2, &type2);
   ret += depiler(etat->donnees, &val1, &type1);
   switch (type1+type2) {
      case 0:
         valEmp.valInt = val1.valInt*val2.valInt;
         typeEmp = ENTIER;
         break;
      case 1:
         if (type1 == FLOTTANT)
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

int op_div (Etat * etat, int *index) {
   Valeur val1, val2, valEmp;
   int type1, type2, typeEmp = ENTIER, ret, entier;
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
            typeEmp = ENTIER;
         } else
            valEmp.valFloat = flottant;
         break;
      case 1:
         if (type1 == FLOTTANT)
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
