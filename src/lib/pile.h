#ifndef PILE_H
#define PILE_H

typedef union Valeur {
   int valInt;
   float valFloat;
} Valeur;

typedef struct Cellule {
   Valeur valeur;
   int type;
   struct Cellule * suivant;
} Cellule;

typedef struct Pile {
   int taille;
   Cellule * debut;
} Pile;

Pile creerPile();
int vide (Pile pile);
void empiler (Pile * pile, Valeur val, int type);
int depiler (Pile * pile, Valeur * ret, int * type);
void afficher (Pile pile);

#endif
