#include <stdio.h>

int charCount(FILE *fp, 
             int *tchar, int *wchar, int *nlchar, int *nwords);

int main(int argc, char *argv[])
{
    FILE *fp;
    if(fp = fopen(argv[1], "rt"))
    {
        int tchar, wchar, nlchar, nwords;
        charCount(fp, &tchar, &wchar, &nlchar, &nwords);
        printf("Total: %d \nWhite: %d\nLine: %d\nWords: %d\n",
                tchar, wchar, nlchar, nwords);
    }
    
    return 0;
}

int charCount(FILE *fp, 
             int *tchar, int *wchar, int *nlchar, int *nwords)
{
    char ch;
    int in_word = 0;

    int totalChar   = 0;
    int whiteChar   = 0;
    int newlineChar = 0;
    int words       = 0;

    while((ch = getc(fp)) != EOF)
    {
        if(ch == ' ' || ch == '\t' || ch == '\n')
        {
            in_word = 0;

            if(ch == '\n')
            {
                newlineChar++;
            }
            whiteChar++;
        }
        else
        {
            if(!in_word)
            {
                words++;
                in_word = 1;
            }
        }
        totalChar++;
    }

    *tchar  = totalChar;
    *wchar  = whiteChar;
    *nlchar = newlineChar;
    *nwords = words;

    return 0;
}