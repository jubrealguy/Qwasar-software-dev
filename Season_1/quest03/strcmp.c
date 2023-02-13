int my_strcmp(char* str1, char* str2)
{
    int i;
    for (i = 0; str1[i] && str2[i]; i++ )
    {
        if (str1[i] == str2[i])
        {
            ;
        }
        else
        {
            return str1[i] - str2[i];
        }
    }
    return 0;
}