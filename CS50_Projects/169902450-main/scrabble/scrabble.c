#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void capitalize(string word);
int check_score(char letter, char matched_letter[], int arrayLength, int score_amt);

int main(void)
{
    //Prompts word from Player 1
    string word1 = get_string("Player 1: ");
    //Prompts word from Player 2
    string word2 = get_string("Player 2: ");

    //makes the words all capitalized
    capitalize(word1);
    capitalize(word2);

    //establishes the scores and corresponding letter points
    int score1 = 0;
    int score2 = 0;
    char point1[] = {'A', 'E', 'I', 'L', 'N', 'O', 'R', 'S', 'T', 'U'};
    char point2[] = {'D', 'G'};
    char point3[] = {'B', 'C', 'M', 'P'};
    char point4[] = {'F', 'H', 'V', 'W', 'Y'};
    char point5[] = {'K'};
    char point8[] = {'J', 'X'};
    char point10[] = {'Q', 'Z'};

    //checks what letters are in the words for score1
    for (int i = 0, length = strlen(word1); i < length; i++)
    {
        score1 += check_score(word1[i], point1, sizeof(point1) / sizeof(point1[0]), 1);
        score1 += check_score(word1[i], point2, sizeof(point2) / sizeof(point2[0]), 2);
        score1 += check_score(word1[i], point3, sizeof(point3) / sizeof(point3[0]), 3);
        score1 += check_score(word1[i], point4, sizeof(point4) / sizeof(point4[0]), 4);
        score1 += check_score(word1[i], point5, sizeof(point5) / sizeof(point5[0]), 5);
        score1 += check_score(word1[i], point8, sizeof(point8) / sizeof(point8[0]), 8);
        score1 += check_score(word1[i], point10, sizeof(point10) / sizeof(point10[0]), 10);
    }

    //checks what letters are in the words for score2
    for (int i = 0, length = strlen(word2); i < length; i++)
    {
        score2 += check_score(word2[i], point1, sizeof(point1) / sizeof(point1[0]), 1);
        score2 += check_score(word2[i], point2, sizeof(point2) / sizeof(point2[0]), 2);
        score2 += check_score(word2[i], point3, sizeof(point3) / sizeof(point3[0]), 3);
        score2 += check_score(word2[i], point4, sizeof(point4) / sizeof(point4[0]), 4);
        score2 += check_score(word2[i], point5, sizeof(point5) / sizeof(point5[0]), 5);
        score2 += check_score(word2[i], point8, sizeof(point8) / sizeof(point8[0]), 8);
        score2 += check_score(word2[i], point10, sizeof(point10) / sizeof(point10[0]), 10);
    }

    //Checks who wins or ties
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

//return score function
int check_score(char letter, char matched_letter[],int arrayLength, int score_amt)
{
    for (int i = 0; i < arrayLength; i++)
    {
        if (letter == matched_letter[i])
        {
            return score_amt;
        }
    }
    return 0;
}

//function to change original word to capital word
void capitalize(string word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = toupper(word[i]);
    }

}
