#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2 || strlen(argv[1]) != 26)
        return printf("Usage: ./substitution key\n"), 1;

    string key = argv[1];
    for (int i = 0; i < 26; i++)
        if (!isalpha(key[i]))
            return printf("Key must contain only letters.\n"), 1;
    for (int i = 0; i < 26; i++)
        for (int j = i + 1; j < 26; j++)
            if (toupper(key[i]) == toupper(key[j]))
                return printf("Key must not have duplicates.\n"), 1;

    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; text[i]; i++)
        printf("%c", isupper(text[i])   ? toupper(key[text[i] - 'A'])
                     : islower(text[i]) ? tolower(key[text[i] - 'a'])
                                        : text[i]);
    printf("\n");
}
