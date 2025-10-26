#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int cmp_scores(string word);
string compare_scores(int a, int b);

int main(void)
{
    string player1 = get_string("Player 1:");
    string player2 = get_string("Player 2:");
    int score1 = cmp_scores(player1);
    int score2 = cmp_scores(player2);
    printf("%s\n", compare_scores(score1, score2));
}

int cmp_scores(string word)
{
    int score = 0;
    int length = strlen(word);
    int score_table[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                         1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for (int i = 0; i < length; i++)
    {
        if isalpha (word[i])
        {
            score += score_table[tolower(word[i]) - 'a'];
        }
        else
        {
            continue;
        }
    }
    return score;
}

string compare_scores(int a, int b)
{
    if (a > b)
    {
        return "Player 1 wins!";
    }
    else if (a < b)
    {
        return "Player 2 wins!";
    }
    else
    {
        return "Tie!";
    }
}
