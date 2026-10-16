/* Lab 02: implement the section manual's lexical contract.
   Read argv[1] with fopen/fgetc. Do not hard-code public.c or its token list.
   You may add helper functions. This starter is deliberately unfinished. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: lexical_analyzer input.c\n");
        return 1;
    }
    
    FILE *input = fopen(argv[1], "r");

    if (input == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int c;

    while ((c = fgetc(input)) != EOF) {

         //identifies identifier or keyword (only those keywords mentioned in the language subset of Lab_02.pdf)
        if (isspace((unsigned char)c)) {
            continue;
        }

        if (isalpha((unsigned char)c) || c == '_') {

            char word[1000];
            int i = 0;

            word[i++] = (char)c;

            while ((c = fgetc(input)) != EOF &&
                   (isalnum((unsigned char)c) || c == '_')) {

                if (i < 999) {
                    word[i++] = (char)c;
                }
            }

            word[i] = '\0';

            if (c != EOF) {
                ungetc(c, input);
            }

            if (strcmp(word, "int") == 0 ||
                strcmp(word, "if") == 0 ||
                strcmp(word, "else") == 0 ||
                strcmp(word, "while") == 0 ||
                strcmp(word, "return") == 0) {
                    printf("%s , KEYWORD\n", word);

            } else {
                printf("%s , IDENTIFIER\n", word);
            }
        }
        // ignores single line comment
        else if (c == '/') {
       int next = fgetc(input);

        if (next == '/' ) {
        while ((c = fgetc(input)) != EOF && (c != '\n')) {
           continue;
        }

    } 
    // handles division operator
        else {
        printf("/ , ARITHMETIC_OPERATOR\n");

        if (next != EOF) {
            ungetc(next, input);
        }
    }
}
          //Number
        else if (isdigit((unsigned char)c)) {
            printf("%c , NUMBER\n", c);
        }
      
        else if (c == '=') {
            int next = fgetc(input);
               //number or relational operator ?
            if (next == '=') {
                printf("== , RELATIONAL_OPERATOR\n");
            } 
        
            else {
             printf("= , ASSIGNMENT_OPERATOR\n");

                if (next != EOF) {
                    ungetc(next, input);
                }
            }
        }
      
     
        else if (c == '<' || c == '>') {
            printf("%c , RELATIONAL_OPERATOR\n", c);
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            printf("%c , ARITHMETIC_OPERATOR\n", c);
        }

        else if (c == '&' || c == '|') {
            int next = fgetc(input);

            if (next == c) {
                printf("%c%c , LOGICAL_OPERATOR\n", c, next);
            } else {
                printf("%c , UNKNOWN\n", c);

                if (next != EOF) {
                    ungetc(next, input);
                }
            }
        }
        else if (c == '<' || c == '>') {
        int next = fgetc(input);

         if (next == '=') {
        printf("%c= , RELATIONAL_OPERATOR\n", c);
        } else {
            printf("%c , RELATIONAL_OPERATOR\n", c);

        if (next != EOF) {
            ungetc(next, input);
        }
     }
}
       //delimiter
        else if (c == '(' || c == ')' ||
                 c == '{' || c == '}' ||
                 c == '[' || c == ']' ||
                 c == ',' || c == ';') {
            printf("%c , DELIMITER\n", c);
        }

        else {
            printf("%c , UNKNOWN\n", c);
        }
    }

    fclose(input);

    return 0;
}