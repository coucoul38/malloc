/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>

void display(int ** adress, int size)
{
    int row, col;
    for (row = -1; row < size; row++) {
       //printf("ROW: %d\n", row);
       for (col = -1; col < size; col++) {
           if (row == -1) {
               printf("%d ", col + 1);
           }
           else if (col == -1) {
               printf("%d ", row + 1);
           }
           else if (adress[row][col] == 1) {
               printf("\033[22;31m%i\033[0m ", adress[row][col]);
           }
           else {
               printf("%i ", adress[row][col]);
           }
           if (col == size - 1) {
               printf("\n");
           }
       }
    }
}

int main()
{
    int size;
    printf("Choose a size for the grid\n");
    scanf("%d", &size);
    printf("Size: %i\n", size);
    
    int ** grid = malloc(size * sizeof(int*)); // initialise les rows qui vont contennir les colonnes
    
    for (int num=0; num < size; num++){
        int *col = malloc(size * sizeof(int)); //initialise les array des colonnes
        grid[num] = col; //mettre la colone dans la row
    }
    
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            grid[row][col] = 0;
        }
    }
    
    display(grid, size);
    
    free(grid);
    return 0;
}
