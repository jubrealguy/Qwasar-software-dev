/*
**
** QWASAR.IO -- my_isalpha
**
** @param {char} param_1
**
** @return {int}
**
*/

int my_isalpha(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        return 1;
    }
    return 0;
}