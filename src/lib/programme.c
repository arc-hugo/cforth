#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "programme.h"

int numberOfDelimiters(char* string) {

   int count = 0;
   for (int i=0;i<strlen(string);i++) {

      if (string[i] == ' ') count++;
   }
   return count;
}

Programme* lexer(char* chaine) {

   char *token,*str;
   str = strdup(chaine);
   int i=0;
   int arraySize = (numberOfDelimiters(str)+1);
   char** programme = (char**)malloc(sizeof(char*)*arraySize);
   while ( (token = strsep(&str," ")) ) {
      programme[i] = token;
      i++;
   }
   Programme *retour = (Programme*)malloc(sizeof(Programme));
   retour->tokens = programme;
   retour->taille = i;
   return retour;
}
