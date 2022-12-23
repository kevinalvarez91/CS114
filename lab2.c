/*
Write a program that echoes the input one word per line after removing all spaces, 
punctuations, and all blank lines. Use getchar() and putchar() functions only. You may not use 
any string or character handling functions in this program. 

Score: 100/100

*/

#include <stdio.h>

int main() {
    char cher = getchar();
    int start = 0;

    while((cher = getchar()) != EOF) 
    {
        if (cher == ' ' || cher == '\n' || cher == '\t') 
        {
            if (start > 0) {
                putchar('\n');
            }
            start = 0;
        } 
        else if (cher != ',' && cher != '.' && cher != '?' && cher != '!' && cher != ';' && cher != ':' && cher != '\'' && cher != '"') 
        {
            putchar(cher);
            start++;
        }
    }

    putchar('\n');
    return 0;
}

/*
OUTPUT

The
Parsnip
The
parsnip
children
I
repeat
is
simply
an
anemic
beet
some
people
call
the
parsnip
edible
myself
I
found
this
claim
incredible

*/