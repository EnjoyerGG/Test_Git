#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 150
#define HEIGHT 90
#define ALIVE '*'
#define DEAD ' '

// git test
void init_board(char board[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            board[i][j] = DEAD;
        }
    }
}

// read the Life 1.06 file format and initialize the board
void read_life_file(const char *filename, char board[HEIGHT][WIDTH])
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // define the lines buffer
    char line[100];
    int x, y;

    // skip the first line which is the comment "#Life 1.06"
    int num = sizeof(line);
    fgets(line, num, fp);

    // read live cell coordinates from the file
    // the center cell must be alive
    while (fgets(line, num, fp))
    {
        if (sscanf(line, "%d %d", &x, &y) == 2)
        {
            int center_x = WIDTH / 2 + x;
            int center_y = HEIGHT / 2 + y;
            if (center_x >= 0 && center_x < WIDTH && center_y >= 0 && center_y < HEIGHT)
            {
                board[center_y][center_x] = ALIVE;
            }
        }
    }
    fclose(fp);
}
