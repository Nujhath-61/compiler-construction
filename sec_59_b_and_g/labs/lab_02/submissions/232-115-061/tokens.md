# Lab 02 token inventory

Replace STUDENT_ID and SECTION below.

Student ID: 232-115-061
Section: B

I have followed the token labels specified in Lab_02.pdf. For example - keywords such as int, while, if, else, and return, I have used the common token label KEYWORD instead of using separate labels such as INT, WHILE, IF, ELSE, and RETURN, as shown in the lecture slides. 
## Token sequence for public.c

Replace the contents of the following single text block. List every emitted
lexeme and token in source order, including repeated occurrences. Omit comments
and whitespace. Do not add a header row inside the block.

```text
int , KEYWORD
main , IDENTIFIER
( , DELIMITER
) , DELIMITER
{ , DELIMITER
int , KEYWORD
count , IDENTIFIER
= , ASSIGNMENT_OPERATOR
3 , NUMBER
; , SEMICOLON
int , KEYWORD
total , IDENTIFIER
= , ASSIGNMENT_OPERATOR
0 , NUMBER
; , SEMICOLON
while , KEYWORD
( , DELIMITER
count , IDENTIFIER
> , RELATIONAL_OPERATOR
0 , NUMBER
) , DELIMITER
{ , DELIMITER
total , IDENTIFIER
= , ASSIGNMENT_OPERATOR
total , IDENTIFIER
+ , ARITHMETIC_OPERATOR
count , IDENTIFIER
; , SEMICOLON
count , IDENTIFIER
= , ASSIGNMENT_OPERATOR
count , IDENTIFIER
- , ARITHMETIC_OPERATOR
1 , NUMBER
; , SEMICOLON
} , DELIMITER
if , KEYWORD
( , DELIMITER
total , IDENTIFIER
>= , RELATIONAL_OPERATOR
6 , NUMBER
&& , LOGICAL_OPERATOR
count , IDENTIFIER
== , RELATIONAL_OPERATOR
0 , NUMBER
) , DELIMITER
{ , DELIMITER
return , KEYWORD
total , IDENTIFIER
; , SEMICOLON
} , DELIMITER
else , KEYWORD
{ , DELIMITER
return , KEYWORD
0 , NUMBER
; , SEMICOLON
} , DELIMITER
} , DELIMITER

```
