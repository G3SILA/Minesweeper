#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define row 9
#define col 9
#define row_frame row+2
#define col_frame col+2

// board for player
char board[row_frame][col_frame] = {0};

// solution board
int solution[row_frame][col_frame] = {0};

// initial board
void init_bd(char bd[row_frame][col_frame])
{
    int i = 0; 
    int j = 0; 

    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
        {
            bd[i][j] = '*'; 
        }
    }
}

// print board
void print_bd(char bd[row_frame][col_frame])
{
    int i = 0; 
    int j = 0; 

    for (i = 0; i <=  col; i++)
    {
        printf("%d ", i); 
    }
    printf("\n");
    
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i); 
        for (j = 1; j <= col; j++)
        {
            printf("%c ", bd[i][j]); 
        }
        printf("\n");
    }
}




// set solution / mines
void set_solu (int bd[row_frame][col_frame], int mines)
{
    
    int i = 0; 
    int j = 0; 

    for (i = 0; i < row_frame; i++)
    {
        for (j = 0; j < col_frame; j++)
        {
            bd[i][j] = 0; 
        }
    }
    
    int count_m = 0; 

    while (count_m < mines)
    {
        int r = rand() % row +1; 
        int c = rand() % col +1; 

        if (bd[r][c] == 0)
        {
            bd[r][c] = 1; 
            count_m ++;
        }
         
    }
     
}


void game (int mines)
{
    int win = 0; 

    while (col*row - mines > win)
    {
        int x = 0; 
        int y = 0; 

       
        printf("enter a pair of integer a b to indicate a "
           "square that you think is safe: ");
        scanf("%d %d", &x, &y);

        if (x > row || y > row || x < 1 || y < 1)
        {
            printf("coordinate does not exist. Try again!\n");
        }
        else if (solution [x][y] == 1) 
        {
            printf("\nPOWWWW!\nThe mine exploded. You failed.\n");
            break;
        }
        else 
        {
        int mines_around = 
        solution[x-1][y-1] +  solution[x-1][y] + solution[x-1][y+1] +
        solution[x][y-1] +                       solution[x][y+1] +
        solution[x+1][y-1] +  solution[x+1][y] + solution[x+1][y+1]; 

        board[x][y] = mines_around + '0';
        win++; 
       // system("cls"); //clear the board before, cleaner 
        print_bd(board); 

        }
        
    }
    if (col*row - mines == win)
    { 
        printf("\n\nCONGRATS! You Have Found All Mines!"); 
        printf("\n\n");
        
        void menu();
        menu();
    }
}


int main (void)
{
    void menu();
    void print_solu(int bd[row_frame][col_frame]);

    srand((unsigned int)time(NULL));

    init_bd(board); 
    set_solu(solution,10);
 //   print_solu(solution);         
 //   for debug purposes
    menu();
    


    return 0; 
}


void menu()
{
    printf("********************************\n"
           "********************************\n"
           "*********** 1. Play ************\n"
           "*********** 0. Exit ************\n"
           "********************************\n"
           "********************************\n");

    int a = 0;
    printf("enter 1 or 0: ");
    scanf("%d", &a); 

    switch (a)
    {
        case 0: 
            break;
        case 1: 
            print_bd(board);
            game(10);
            break;
        default: 
            printf("error input, try again.\n");
            menu(); 
            break; 

    } 
}










void print_solu(int bd[row_frame][col_frame])
{
    int i = 0; 
    int j = 0; 

    for (i = 0; i <=  col; i++)
    {
        printf("%d ", i); 
    }
    printf("\n");
    
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i); 
        for (j = 1; j <= col; j++)
        {
            printf("%d ", bd[i][j]); 
        }
        printf("\n");
    }
}
