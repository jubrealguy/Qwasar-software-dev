#include <stdio.h>
#include <stdlib.h>
char* my_spaceship(char* move)
{
    int x = 0;
    int y = 0;
    char directions[4][5] = {"up", "down", "right", "left"};
    char* dir = directions[0];
    char* ans = malloc(128);

    int i, j;

    for (i = 0; move[i]; i++)
    {
        if (dir == directions[0])
        {
            if (move[i] == 'A') {
                y -= 1;
            }
            else if (move[i] == 'R') {
                dir = directions[2];
            }
            else if (move[i] == 'L') {
                dir = directions[3];
            }
        }

        else if (dir == directions[2]) {
            if (move[i] == 'A') {
                x += 1;
            }
            else if (move[i] == 'R') {
                dir = directions[1];
            }
            else if (move[i] == 'L') {
                dir = directions[0];
            }
        }

        else if (dir == directions[3]) {
            if (move[i] == 'A') {
                x -= 1;
            }
            else if (move[i] == 'R') {
                dir = directions[0];
            }
            else if (move[i] == 'L') {
                dir = directions[1];
            }
        }

        else if (dir == directions[1]) {
            if (move[i] == 'A') {
                y += 1;
            }
            else if (move[i] == 'R') {
                dir = directions[3];
            }
            else if (move[i] == 'L') {
                dir = directions[2];
            }
        }
    }
    snprintf(ans, 128, "{x: %d, y: %d, direction: '%s'}", x, y, dir);
    //printf("%d, %d, %s", x, y, dir);
    return ans;
}