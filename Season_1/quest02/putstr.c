#include <stdio.h>
#include <unistd.h>
/*
**
** QWASAR.IO -- my_putstr
**
** @param {char*} param_1
**
** @return {void}
**
*/

void my_putchar(char c) {
  write(1, &c, 1);
}

void my_putstr(char* s)
{
    int i;
    for ( i = 0; s[i]; i++) {
        my_putchar(s[i]);
    }
}