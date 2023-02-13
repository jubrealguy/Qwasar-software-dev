/*
**
** QWASAR.IO -- my_string_index
**
** @param {char*} param_1
** @param {char} param_2
**
** @return {int}
**
*/

int my_string_index(char* haystack, char needle)
{
    int i;
    for (i = 0; haystack[i]; i++) {
        if (haystack[i] == needle) {
            return i;
        }
    }
    return (-1);
}