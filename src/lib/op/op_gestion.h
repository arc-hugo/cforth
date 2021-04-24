#ifndef OP_GESTION_H
#define OP_GESTION_H

#include "../etat.h"

int op_dup(Etat * etat);
int op_drop(Etat * etat);
int op_swap(Etat * etat);
int op_rot(Etat * etat);

#endif
