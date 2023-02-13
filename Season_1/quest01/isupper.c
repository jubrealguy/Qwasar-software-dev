/*
**
** QWASAR.IO -- my_isupper
**
** @param {char} param_1
**
** @return {int}
**
*/

int my_isupper(char ch)
{
    if (ch >= 'A' && ch <= 'Z') {
        return 1;
    }
    return 0;
}