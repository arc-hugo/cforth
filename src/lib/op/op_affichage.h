#ifndef OP_AFFICHAGE_H
#define OP_AFFICHAGE_H

#include "../etat.h"

int op_point(Etat * etat, int *index);
int op_point_s(Etat * etat, int *index);
int op_string(Etat * etat, int *index);
int op_string_end(Etat * etat, int *index);
int op_carriage_return(Etat * etat, int *index);

#endif
