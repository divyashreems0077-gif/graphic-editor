#include <stdio.h>

char canvas[10][20];

void initializeCanvas()
{
    int i, j;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 20; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void drawHorizontalLine(int row)
{
    int col;

    if(row >= 0 && row < 10)
    {
        for(col = 0; col < 20; col++)
        {
            canvas[row][col] = '*';
        }
    }
}

void displayCanvas()
{
    int i, j;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 20; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int row;

    initializeCanvas();

    printf("Enter row (0-9): ");
    scanf("%d", &row);

    drawHorizontalLine(row);

    displayCanvas();

    return 0;
}