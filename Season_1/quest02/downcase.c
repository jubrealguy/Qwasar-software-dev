/*
**
** QWASAR.IO -- my_downcase
**
** @param {char*} param_1
**
** @return {char*}
**
*/

char* my_downcase(char* s)
{
    int i;
    for (i = 0; s[i]; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
    return s;
}