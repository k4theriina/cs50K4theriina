#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

float amtLetters(string text);
float amtWords(string text);
float amtSentences(string text);

int main(void)
{
    // Prompts user for a text
    string text = get_string("Text: ");

    //L = average letters per words
    float L = (amtLetters(text) / amtWords(text)) * 100;

    //S = average number of sentences per words
    float S = (amtSentences(text) / amtWords(text)) * 100;

    //Coleman-Liau Index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Prints the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

float amtLetters(string text)
{
    int letters = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] != ' ' && !ispunct(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

float amtWords(string text)
{
    int words = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == ' ' || i == length - 1)
        {
            words++;
        }
    }
    return words;
}

float amtSentences(string text)
{
    int sentences = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}
