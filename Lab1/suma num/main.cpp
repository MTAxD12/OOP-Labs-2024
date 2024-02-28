#include <stdio.h>

int charToNum(char s[])
{
    int num = 0;
    for(int i = 0; s[i]; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            num = num*10 + s[i] - '0';
        }
        else
            return 0;
    }
    return num;
}

int main()
{
    FILE *numFile;

    numFile = fopen("ini.txt", "r");
    char numar[256];
    int s = 0;
    if(numFile != NULL)
    {
        while(fscanf(numFile, "%s", numar) != EOF)
        {
            s += charToNum(numar);
        }
    }
    else
        printf("Eroare");

    printf("Suma este: %i", s);
}
