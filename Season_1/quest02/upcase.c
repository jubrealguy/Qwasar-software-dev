/*
**
** QWASAR.IO -- my_upcase
**
** @param {char*} param_1
**
** @return {char*}
**
*/

char* my_upcase(char* s)
{
    int i;
    for (i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
    }
    return s;
}