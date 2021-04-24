#ifndef OP_CONDITION_H
#define OP_CONDITION_H

#include "../etat.h"

int op_inf(Etat * etat);
int op_sup(Etat * etat);
int op_eq(Etat * etat);
int op_if(Etat * etat);
int op_else(Etat * etat);
int op_then(Etat * etat);

#endif
