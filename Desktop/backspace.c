#include <stdio.h>
#include <time.h>
#include <string.h>

#define ClearscreenTotop printf("\x1b[1J");
#define nxtLine MoveTo(45, y++) //cursor movement to the next line in terminal

void delay(unsigned int mseconds)
{
    clock_t Target_Delay = mseconds + clock();
    while (Target_Delay > clock())
        ;
}

void MoveTo(int x, int y)
{
    printf("\x1b[%d;%df", y, x);
}



int main()
{
    system("cls");
    char *word[10] = {"Hell0", "Fuck OFF", "shit my Ass","dickAndBalls","shitty ass","bellai","shit my Ass","dickAndBalls","shitty ass","bell"};
    for(int y = 0; y < 10; y++)
    {
        MoveTo(0,3);
        for (int i = y; i>= 0;i--)
        {
            
            printf("%s",word[i]);
            printf("\n");
        }
        delay(1500);
        ClearscreenTotop;




        for (int y = 10; y < 20; y++)
        {
          MoveTo(45,1);
          for (int i = y; i >= 0; i--)
          {

            for(int j = 0; j <strlen(word[i]);j++)
            {
            printf("%c",word[i][j]);
            delay(500);
            }
            printf("\n");
            centeralize;
          }
          delay(1500);
          ClearscreenTotop
        }
    }
    



}