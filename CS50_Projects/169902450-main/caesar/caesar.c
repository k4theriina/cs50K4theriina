#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

string encrypt(int key, string plaintext);
bool onlyDigits(string s);


// User type in command line for KEY
int main(int argc, string argv[])
{
    if (argc != 2 || !onlyDigits(argv[1]))
    {
        printf("Usage: ./caesar.c key\n");
        return 1;
    }

    // sets key
    int key = atoi(argv[1]);

    // sets plaintext
    string plaintext;
    do
    {
        plaintext = get_string("plaintext: ");
    }
    while (onlyDigits(plaintext));

    // prints out ciphertext
    string cipher = encrypt(key, plaintext);
    printf("ciphertext: %s\n", cipher);

    //string ciphertext = encrpyt(key, plaintext);
}


// ci = (pi + key) % 26
string encrypt(int key, string plaintext)
{
    string ciphertext = plaintext;
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        //didn't quite understand the concept of why 'A' was being added and subtracted, asked ChatGPT for some asssistance. This is the resulting code
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ciphertext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
        }
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ciphertext[i] = 'a' + (plaintext[i] - 'a' + key) % 26;
        }
    }
    return ciphertext;
}


bool onlyDigits(string s)
{
    int digits = 0;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            digits++;
        }
    }
    if (digits  == strlen(s))
    {
        return true;
    }
    else
    {
        return false;
    }
}



