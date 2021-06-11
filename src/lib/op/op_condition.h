#ifndef OP_CONDITION_H
#define OP_CONDITION_H

#include "../etat.h"

int op_inf(Etat * etat, int *index);
int op_sup(Etat * etat, int *index);
int op_eq(Etat * etat, int *index);
int op_if(Etat * etat, int *index);
int op_else(Etat * etat, int *index);
int op_then(Etat * etat, int *index);

#endif
