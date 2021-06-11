#ifndef OP_BASE_H
#define OP_BASE_H

#include "../etat.h"

int op_add(Etat * etat, int *index);
int op_sub(Etat * etat, int *index);
int op_mul(Etat * etat, int *index);
int op_div(Etat * etat, int *index);

#endif
