#ifndef PROGRAMME_H
#define PROGRAMME_H

typedef struct Programme {
   char **tokens;
   int taille;
} Programme;

Programme * lexer (char * chaine);
#endif
