/* Lab 02: implement the section manual's lexical contract.
   Read argv[1] with fopen/fgetc. Do not hard-code public.c or its token list.
   You may add helper functions. This starter is deliberately unfinished. */
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
if (argc != 2) {
fprintf(stderr, "Usage: lexical_analyzer input.c\n");
return 1;
}

FILE *input = fopen(argv[1], "r");

if (input == NULL) {
    perror(argv[1]);
    return 1;
}

int c;

while ((c = fgetc(input)) != EOF) {

    // Ignore whitespace
    if ( c == ' ' || c == '\t' || c == '\r' || c == '\n') {
        continue;
    }

    // Identifies identifier or keyword (only keywords in Lab_02.pdf)
    if ((c >= 'A' &&  c <= 'Z')|| (c>= 'a' && c <= 'z') || c == '_') {
        char word[1000];
        int i = 0;

        word[i++] = (char)c;

        while ((c = fgetc(input)) != EOF &&
                (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9')) || c == '_')) {
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

    // Handle comments and division operator
    else if (c == '/') {
        int next = fgetc(input);

        // Ignore single-line comments
        if (next == '/') {
            while ((c = fgetc(input)) != EOF && c != '\n') {
              continue;
            }
        }

        // Ignore block comments
        else if (next == '*') {
            int previous = 0;

            while ((c = fgetc(input)) != EOF) {
                if (previous == '*' && c == '/') {
                    break;
                }

                previous = c;
            }
        }

        // Division operator
        else {
            printf("/ , ARITHMETIC_OPERATOR\n");

            if (next != EOF) {
                ungetc(next, input);
            }
        }
    }

    // Recognize complete integer numbers
    else if (c >= '0' && c <= '9') {
        char number[1000];
        int i = 0;

        number[i++] = (char)c;

        while ((c = fgetc(input)) != EOF &&
              (c>= '0' && c<= '9')) {
            if (i < 999) {
                number[i++] = (char)c;
            }
        }

        number[i] = '\0';

        if (c != EOF) {
            ungetc(c, input);
        }

        printf("%s , INTEGER\n", number);
    }

    // Assignment (=) or equality (==)
    else if (c == '=') {
        int next = fgetc(input);

        if (next == '=') {
            printf("== , RELATIONAL_OPERATOR\n");
        } else {
            printf("= , ASSIGNMENT_OPERATOR\n");

            if (next != EOF) {
                ungetc(next, input);
            }
        }
    }

    // Relational operators: <, <=, >, >=
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

    // Not-equal operator (!=)
    else if (c == '!') {
        int next = fgetc(input);

        if (next == '=') {
            printf("!= , RELATIONAL_OPERATOR\n");
        } else {
            printf("! , LOGICAL_OPERATOR\n");

            if (next != EOF) {
                ungetc(next, input);
            }
        }
    }

    // Arithmetic operators
    else if (c == '+' || c == '-' || c == '*' || c=='%') {
        printf("%c , ARITHMETIC_OPERATOR\n", c);
    }

    // Logical operators: && and ||
    else if (c == '&' || c == '|' ) {
        int next = fgetc(input);

        if (next == c) {
            printf("%c%c , LOGICAL_OPERATOR\n", c, next);
        } 
        else {
            printf("%c , UNKNOWN\n", c);

            if (next != EOF) {
                ungetc(next, input);
            }
        }
    }

    // Delimiters
    else if (c == '(' || c == ')' ||
             c == '{' || c == '}' ||
             c == '[' || c == ']' ||
             c == ',' || c == ';') {
        printf("%c , DELIMITER\n", c);
    }

    // Unrecognized characters
    else {
        printf("%c , UNKNOWN\n", c);
    }
}

fclose(input);

return 0;


}
