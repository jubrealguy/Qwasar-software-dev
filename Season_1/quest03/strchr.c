char* my_strchr(char* str, char ch)
{
    int i;
    for (i = 0; str[i]; i++)
    {
        if (str[i] == ch)
        {
            return &(str[i]);
        }
    }
}