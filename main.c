#include <stdio.h>
#include <stdlib.h>
char P1,P2;

void drawBoard(char A[10]);
int checkForWin(char A[10]);
void mark(int x,char board[10]);

int main()
{
    system("clear");
    char board[10]={'0','1','2','3','4','5','6','7','8','9'};
    printf("\n\t Tic - Tac - Toe\n\n");
    printf("Enter the Characters of Player 1 and Player 2 : ");
    scanf("%c %c",&P1,&P2);

    for(int i=1;i<=9;++i)
    {
        drawBoard(board);
        if(i%2==1)
            mark(1,board);
        else
            mark(2,board);

        if(checkForWin(board))
            return 0;

    }
    drawBoard(board);
    printf(">>The game was a tie.");

    return 0;
}

void drawBoard(char A[10])
{
    system("clear");
    printf("\n\t Tic - Tac - Toe\n\n");
    printf("Player 1 (%c)  -  Player 2 (%c)\n\n",P1,P2);

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",A[1],A[2],A[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",A[4],A[5],A[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",A[7],A[8],A[9]);
    printf("     |     |     \n");

    printf("\n");

}

int checkForWin(char A[10])
{
    if((A[1]==P1&&A[2]==P1&&A[3]==P1)||(A[4]==P1&&A[5]==P1&&A[6]==P1)||(A[7]==P1&&A[8]==P1&&A[9]==P1)||(A[1]==P1&&A[4]==P1&&A[7]==P1)||(A[2]==P1&&A[5]==P1&&A[8]==P1)||(A[3]==P1&&A[6]==P1&&A[9]==P1)||(A[1]==P1&&A[5]==P1&&A[9]==P1)||(A[3]==P1&&A[5]==P1&&A[7]==P1))
    {
        drawBoard(A);
        printf(">>>Player 1 has won.");
        return 1;
    }
    if((A[1]==P2&&A[2]==P2&&A[3]==P2)||(A[4]==P2&&A[5]==P2&&A[6]==P2)||(A[7]==P2&&A[8]==P2&&A[9]==P2)||(A[1]==P2&&A[4]==P2&&A[7]==P2)||(A[2]==P2&&A[5]==P2&&A[8]==P2)||(A[3]==P2&&A[6]==P2&&A[9]==P2)||(A[1]==P2&&A[5]==P2&&A[9]==P2)||(A[3]==P2&&A[5]==P2&&A[7]==P2))
    {
        drawBoard(A);
        printf(">>>Player 2 has won.");
        return 2;
    }
    return 0;
}

void mark(int x,char board[10])
{
    int index;
    printf("Player %d, Enter a number : ",x);
    scanf("%d",&index);
    for(;index<1||index>9||board[index]!=(48+index);)
    {
        printf("Invalid input, Enter again :");
        scanf("%d",&index);
    }
    board[index]= (x==1)?P1:P2;
}

