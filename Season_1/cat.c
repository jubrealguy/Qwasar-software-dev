#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
    int file_d, buf;
    for (int i = 1; i < argc; i++)
    {
        /* Open file for read only */
        file_d = open(argv[i], O_RDONLY);

        /* if file descriptor is less than 0, display error message for file */
        if (file_d < 0)
        {
            perror(argv[i]);
            continue;
        }
        /* Display file content */
        while (read(file_d, &buf, 1) == 1)
        {
            write(STDOUT_FILENO, &buf, 1);
        }
        /* closing file */
        close(file_d);
    }
}