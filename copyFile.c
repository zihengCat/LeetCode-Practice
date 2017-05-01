#include <stdio.h>
#include <stdlib.h>

#define BUFFER 512

int cpFile(char *s1, char *s2);

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr, "Error: use %s [File1] [File2]...[Object File] to copy \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    for(i = 0; i < argc - 2; i++)
    {
        cpFile(argv[i + 1], argv[argc - 1]);
    }
    
    return 0;
}

int cpFile(char *s1, char *s2)
{
    FILE *fpin, *fpout;
    if((fpin = fopen(s1, "rb")) && (fpout = fopen(s2, "ab")))
    {
       fseek(fpin, 0L, SEEK_END);
       long size = ftell(fpin);
       fseek(fpin, 0L, SEEK_SET);
       long cnt = 0;

       static char buf[BUFFER];
       while((cnt = fread(buf, sizeof(char), BUFFER, fpin)) > 0)
       {
           fwrite(buf, sizeof(char), cnt, fpout);
       }

       if(!fclose(fpin) && !fclose(fpout))
       {
           printf("File Copyed Successful\n");
           return 0;
       }
    }
    else
    {
        printf("File Copyed Fail\n");
        return 1;
    }
}