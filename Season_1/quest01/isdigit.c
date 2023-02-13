/*
**
** QWASAR.IO -- my_isdigit
**
** @param {char} param_1
**
** @return {int}
**
*/

int my_isdigit(char dig)
{
    if (dig >= '0' && dig <= '9') {
        return 1;
    }
    return 0;
}