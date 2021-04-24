#include <stdlib.h>

#include "op_base.h"


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
