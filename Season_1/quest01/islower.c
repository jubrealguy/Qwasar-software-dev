/*
**
** QWASAR.IO -- my_islower
**
** @param {char} param_1
**
** @return {int}
**
*/

int my_islower(char ch)
{
    if (ch >= 'a' && ch <= 'z') {
        return 1;
    }
    return 0;
}