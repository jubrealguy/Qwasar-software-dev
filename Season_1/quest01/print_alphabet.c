#include <stdio.h>
#include <unistd.h>

void my_putchar(char c) {
  write(1, &c, 1);
}
/*
**
** QWASAR.IO -- my_print_alphabet
**
**
** @return {void}
**
*/

void my_print_alphabet()
{
    char ch;

    for (ch = 'a'; ch <= 'z'; ch++) {
        my_putchar(ch);
    }
    my_putchar('\n');
}
