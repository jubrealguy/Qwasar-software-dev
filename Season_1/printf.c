#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>

/* Function to print character */
void _putchar(char c)
{
    write(1, &c, 1);
}

/* Funtion to print strings and return length of string */
int _putstr(char* s)
{
    int i = 0;

    if (!s)
    {
        return 0;
    }
    
    while (*s != '\0')
    {
        _putchar(*s++);
        i++;
    }
    return i;
}


/* converts an unsigned integer num to a string representation in the given base */
char* unsigned_num_to_base(unsigned int num, int base)
{
    unsigned int tmp, len = 0, num_original = num;
    char* res_str = NULL;

    if (num_original > 0)
    {
        num_original = num_original;
    }
    else
    {
        num_original = -1 * num_original;
    }

    if (num != 0)
    {
        while (num)
        {
            num /= base;
            len++;
        }
        res_str = malloc(sizeof(char) * (len + 1));
    }
    else 
    {
        len = 1;
        res_str = malloc(sizeof(char) * (len + 1));
    }

    if (!(res_str))
        return NULL;

    *(res_str + len) = '\0';
    len--;

    while (num_original > 0)
    {
        tmp = num_original % base;
        if (tmp < 10)
            *(res_str + len) = tmp + '0';
        else
            *(res_str + len) = ((tmp)-10 + 97);
        num_original /= base;
        len--;
    }

    if (len == 0 && res_str[1] == '\0')
    {
        *(res_str) = '0';
    }
    return res_str;
}


/* converts a signed integer num to a string representation in the given base */
char* signed_num_to_base(int num, int base)
{
    char* res_str;
    int len, tmp, num_original = num;

    if (num_original > 0)
    {
        len = 0;
    }
    else
    {
        len = 1;
    }

    if (num_original > 0)
    {
        num_original = num_original;
    }
    else
    {
        num_original = -1 * num_original;
    }

    while (num)
    {
        num = num / base;
        len++;
    }

    if (!(res_str = (char*)malloc(sizeof(char) * len + 1)))
    {
        return NULL;
    }

    *(res_str + len) = '\0';
    len--;

    while (num_original > 0)
    {
        tmp = num_original % base;
        if (base == 16 && num_original < 0)
        {
            tmp = 15 - tmp + 1;
        }

        if (tmp < 10)
            *(res_str + len) = tmp + '0';
        else
            *(res_str + len) = ((tmp)-10 + 97);

        num_original /= base;
        len--;
    }

    if (len == 0 && res_str[1] == '\0')
    {
        *(res_str + len) = '0';
    }

    else if (len == 0 && res_str[1] != '\0')
    {
        *(res_str + len) = '-';
    }
    return res_str;
}


/* converts an unsigned long integer num to a string representation in the given base */
char* unsigned_long_num_to_base(unsigned long int num, int base)
{
    unsigned long int tmp, len = 0, num_original = num;
    char* res_str = NULL;

    num_original = num_original > 0 ? num_original : -(num_original);

    while (num)
    {
        num = num / base;
        len++;
    }

    res_str = malloc(sizeof(char) * (len + 1));
    if (res_str == NULL) {
        return NULL;
    }

    *(res_str + len) = '\0';
    len--;
    while (num_original > 0)
    {
        tmp = num_original % base;
        if (tmp < 10)
            *(res_str + len) = tmp + '0';
        else
            *(res_str + len) = ((tmp)-10 + 97);

        num_original /= base;
        len--;
    }
    return res_str;
}


/* ********* MY PRINTF FUNCTION *********** */
int my_printf(char* restrict format, ...)
{
    va_list args_p;
    char* str_val;
    char* p;
    char* res_convert = NULL;
    intptr_t val_p;
    int len, val, char_count = 0;

    va_start(args_p, format);

    for (p = format; *p; p++)
    {
        if (*p != '%')
        {
            _putchar(*p);
            char_count++;
            continue;
        }

        switch (*++p)
        {
            case 'd':
            {
                val = va_arg(args_p, int);
                res_convert = signed_num_to_base(val, 10);
                len = _putstr(res_convert);
                char_count += len;
                break;
            }
            case 'o':
            {
                val = va_arg(args_p, int);
                res_convert = unsigned_num_to_base(val, 8);
                len = _putstr(res_convert);
                char_count += len;
                break;
            }
            case 'u':
            {
                val = va_arg(args_p, int);
                res_convert = unsigned_num_to_base(val, 10);
                len = _putstr(res_convert);
                char_count += len;
                break;
            }
            case 'x':
            {
                val = va_arg(args_p, unsigned int);
                res_convert = unsigned_num_to_base(val, 16);
                for (int i = 0; i < len; i++) {
                    res_convert[i] = toupper(res_convert[i]);
                }
                len = _putstr(res_convert);
                char_count += len;
                break;
            }
            case 'c':
            {
                val = va_arg(args_p, int);
                _putchar(val);
                char_count++;
                break;
            }
            case 's':
            {
                str_val = va_arg(args_p, char*);
                if (str_val == NULL)
                {
                    _putstr("(null)");
                    char_count += 6;
                }
                else {
                    len = _putstr(str_val);
                    char_count += len;
                }
                break;
            }
            case 'p':
            {
                val_p = va_arg(args_p, intptr_t);
                res_convert = unsigned_long_num_to_base(val_p, 16);
                write(1, "0x", 2);
                len = _putstr(res_convert);
                char_count += len + 2;
                break;
            }
        }
        if (res_convert != NULL){
            free(res_convert);
            res_convert = NULL;
        }
    }
    return char_count;
    va_end(args_p);
}