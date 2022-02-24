#include <stdio.h>
#include <stdlib.h>

#define max_lines_of_data 50

typedef struct Sherkat
{
    int profit;
    int loss;
    int total_profit;
    int shomare_sherkat;
} sherkat;

int main()
{
    char directory[500];
    char buffer[20];
    printf("please enter your .txt file's full path:\n");
    scanf("%s",&directory);

    FILE *fptr;

    fptr = fopen(directory, "r");

    if (fptr == NULL)
    {
        printf("Error occured whilst opening the file!");
        exit(1);
    }

    sherkat s[max_lines_of_data];

    
    for (int i =0; i < max_lines_of_data; i++)
    {
        fgets(buffer,sizeof(buffer),fptr);
        s[i].profit = atoi(buffer);
        printf("%d",s[i].profit);
        s[i].shomare_sherkat = i;
        s[i].total_profit = s[i].profit - s[i].loss;
        fseek(fptr, 5 ,SEEK_CUR);  
    }
    
    int temp, temp2;
    for (int i = 0; i < max_lines_of_data; i++)
    {
        for (int j = i + 1; j < max_lines_of_data; j++)
        {
            if (s[i].total_profit < s[j].total_profit)
            {
                temp = s[i].total_profit;
                s[i].total_profit = s[j].total_profit;
                s[j].total_profit = temp;

                temp2 = s[i].shomare_sherkat;
                s[i].shomare_sherkat = s[j].shomare_sherkat;
                s[j].shomare_sherkat = temp2;
            }
        }
    }

    printf("%d\n",s[s[0].shomare_sherkat].profit);
    printf("%d",s[s[0].shomare_sherkat].loss);
    
    return 0;

}
