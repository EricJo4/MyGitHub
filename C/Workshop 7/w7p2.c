/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : Eric Jo
Student ID#: 137057188
Email      : hjo9@myseneca.ca
Section    : NII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
#define MAX_LIVES 10
#define MIN_LIVES 1
#define MAX_MOVES 15
#define MIN_MOVES 3

struct PlayerInfo
{
    char symbol;
    int lives; 
    int treasuresFound;
    int history[MAX_PATH_LENGTH];
};
struct GameInfo
{
    int pathLength, moves_limit,
        bombs[MAX_PATH_LENGTH], treasures[MAX_PATH_LENGTH];
};

int main(void)
{
    struct PlayerInfo player;
    struct GameInfo game;
    int i;
    int nextMove;
    player.treasuresFound = 0;

    printf("================================\n");
    printf("        Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives < MIN_LIVES || player.lives > MAX_LIVES
            )
        {
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
        }
        else
        {
            printf("Player configuration set-up is complete\n");
        }
    } while (player.lives < MIN_LIVES || player.lives>MAX_LIVES);
    printf("\n");

    printf("GAME Configuration\n");
    printf("------------------\n");
    do
    {
        printf("Set the path length (a multiple of 5 between %d-%d): ", MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &game.pathLength);
        if (game.pathLength % 5 != 0 || game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH)
        {
            printf("     Must be a multiple of 5 and between %d-%d!!!\n", MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }
    } while (game.pathLength % 5 != 0 || game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH);
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves_limit);
        if (game.moves_limit < MIN_MOVES || game.moves_limit > MAX_MOVES)
        {
            printf("     Value must be between %d and %d\n", MIN_MOVES, MAX_MOVES);
        }
    } while (game.moves_limit < MIN_MOVES || game.moves_limit > MAX_MOVES);

    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d- %2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]);
    }

    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d- %2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.treasures[i], &game.treasures[i + 1], &game.treasures[i + 2], &game.treasures[i + 3], &game.treasures[i + 4]);
    }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasures[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    
    /*player's statistics before number input*/
    printf("   ");
    for(i= 0; i< game.pathLength; i++)
    {
        printf("-");
    }

    printf("\n   ");
    for (i = 1; i < game.pathLength + 1; i++)
    {
        if (i % 10 == 0)
        {
            printf("%d", i / 10);
            
        }
        else
        printf("|");
    }

    printf("\n   ");
    for(i = 1;i<game.pathLength+1;i++)
    {
        printf("%d", i%10);
    }
    
    printf("\n");

    /*A Loop for Player input*/
    do
    {
       

        do
        {
            printf("Next Move [1-%d]: ", game.pathLength);
            scanf("%d", &nextMove);

        
            if (nextMove < 1 || nextMove > game.pathLength)
                printf("  Out of Range!!!\n");

        } while (nextMove < 1 || nextMove > game.pathLength);

        /*Message display by a result of player's move*/
        if (player.history[nextMove - 1] == 1)
            printf("\n===============> Dope! You've been here before!\n");
        else
        {
            player.history[nextMove - 1] = 1;

            if (player.history[nextMove - 1] == game.bombs[nextMove - 1] && player.history[nextMove - 1] != game.treasures[nextMove - 1])
            {
                printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
                player.lives -= 1;
                if (player.lives == 0)
                    printf("\nNo more LIVES remaining!\n");
            }
            else if (player.history[nextMove - 1] == game.treasures[nextMove - 1] && player.history[nextMove - 1] != game.bombs[nextMove - 1])
            {
                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
                player.treasuresFound += 1;
            }
            else if (player.history[nextMove - 1] == game.treasures[nextMove - 1] && player.history[nextMove - 1] == game.bombs[nextMove - 1])
            {
                printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                player.lives -= 1;
                player.treasuresFound += 1;
                if (player.lives == 0)
                    printf("\nNo more LIVES remaining!\n");
                
            }

            else
            {
                printf("\n===============> [.] ...Nothing found here...\n");
            }
            game.moves_limit -= 1;
        }

        /*Player statistics during the loop*/
        printf("\n   ");
        for (i = 1; i < game.pathLength + 1; i++)
        {
            if (i == nextMove)
                printf("%c", player.symbol);
            else
                printf(" ");
        }


        printf("\n   ");
        for (i = 0; i < game.pathLength; i++)
        {
            if (player.history[i] == player.history[nextMove - 1] && (player.history[i] == game.bombs[i] && player.history[i] != game.treasures[i]))
                printf("!");
            else if (player.history[i] == player.history[nextMove - 1] && (player.history[i] == game.treasures[i] && player.history[i] != game.bombs[i]))
                printf("$");
            else if (player.history[i] == player.history[nextMove - 1] && (player.history[i] == game.treasures[i] && player.history[i] == game.bombs[i]))
                printf("&");
            else if (player.history[i] == player.history[nextMove - 1] && (player.history[i] != game.bombs[i] && player.history[i] != game.treasures[i]))
                printf(".");
            else
            printf("-");
        }


        printf("\n   ");
        for (i = 1; i < game.pathLength + 1; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", i / 10);

            }
            else
                printf("|");
        }


        printf("\n   ");
        for (i = 1; i < game.pathLength + 1; i++)
        {
            printf("%d", i % 10);
        }


        printf("\n");
        /*The game result*/
        printf("+-------------------------------------------------------+\n");
        printf("  Lives: %2d   | Treasures: %2d  |  Moves Remaining:  %2d\n", player.lives, player.treasuresFound, game.moves_limit);
        printf("+-------------------------------------------------------+\n");
        
    } while (game.moves_limit != 0 && player.lives !=0);
   
    if (game.moves_limit == 0)
        printf("No more MOVES remaining!\n");


    
    /*Game over message*/
    printf("\n###################\n");
    printf("#    Game over!   #\n");
    printf("###################\n\n");
    printf("You should play again and try to beat your score!\n");

 
    
    return 0;
}