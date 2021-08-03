#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int generaterandom() //generating random numbers
{
    srand(time(NULL));
    char option = rand() % 3;
    return option + 1;
}

//comparing rock,paper and scissor
int greater(char c1, char c2)
{
    if (c1 == 'p' && c2 == 'r')
        return 1;
    else
        return 0;
    if (c1 == 's' && c2 == 'p')
        return 1;
    else
        return 0;
    if (c1 == 'r' && c2 == 's')
        return 1;
    else
        return -1;
    if (c1 == c2)
        return 0;
}

int main()
{
    char comp, player;
    char name[30];
    char optchar[] = {'p', 's', 'r'};
    int comp_point = 0, player_point = 0, choice;

    printf("Welcome to ROCK ,PAPER AND SCISSOR game\n");
    printf("choose\n 1 for rock \n 2 for paper\n 3 for scissor \n");
    printf("Enter the name of player \n");
    gets(name);
    printf("player1 is : ");
    puts(name);

    for (int i = 0; i < 3; i++)
    {
        //player turn
        printf("\n %s turn, enter the number(1,2 or 3): ", name);
        scanf("%d", &choice);
        player = optchar[choice - 1];
        printf(" computer chooses %c\n", player);

        //computer turns
        choice = generaterandom();
        comp = optchar[choice - 1];
        printf(" computer chooses %c\n", comp);

        //comparing for points
        if (greater(player, comp) == 1)
        {
            player_point++;
        }
        else if (greater(player, comp) == -1)
        {
            player_point += 0;
            comp_point += 0;
        }
        else
        {
            comp_point += 1;
        }
    }
    //winner results
    if (comp_point > player_point)
    {
        printf("computer is winner and its point is: %d", comp_point);
    }
    else
    {
        printf("%s is winner and point is: %d", name, player_point);
    }
    return 0;
}
