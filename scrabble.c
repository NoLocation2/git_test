#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    // prompt the user for two words
    string words[2];
    for (int i = 0; i < 2; i++)
    {
        words[i] = get_string("Player %i: ", i + 1);
    }
    // compute score for each word
    int scores[27] = {1, 3, 3,  2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1,
                      1, 3, 10, 1, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int n = 0;
    int i = 0;
    int playerScore[2] = {0, 0};
    while (n < 2)
    {
        while (words[n][i] != '\0')
        {
            words[n][i] = toupper(words[n][i]);
            if (!ispunct(words[n][i]))
            {
                playerScore[n] += scores[words[n][i] - 65];
            }
            i++;
        }
        n++;
        i = 0;
    }
    // print the winner
    if (playerScore[0] > playerScore[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (playerScore[0] < playerScore[1])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
