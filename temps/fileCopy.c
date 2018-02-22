#include <stdio.h>
#include <stdlib.h>

int fileCopy(char* s_in, char* s_out);

int main(int argc, char* argv[]){

    if(argc != 3){
        fprintf(stderr, "Error: use %s inputFile outputFile\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else{
        if(fileCopy(argv[1], argv[2]) == EXIT_SUCCESS){
            fprintf(stdout, "Copy Successful!\n");
        }
    }

    return 0;
}

int fileCopy(char* s_in, char* s_out){

    FILE *f_in, *f_out;
    int ch;

    if((f_in = fopen(s_in, "r")) == NULL){
        fprintf(stderr, "Error: can not open file %s\n", s_in);
        fclose(f_in);
        return EXIT_FAILURE;
    }
    if((f_out = fopen(s_out, "w")) == NULL){
        fprintf(stderr, "Error: can not open file %s\n", s_out);
        fclose(f_out);
        return EXIT_FAILURE;
    }
    while((ch = fgetc(f_in)) != EOF){
        fputc(ch, f_out);
    }

    fclose(f_in);
    fclose(f_out);
    return EXIT_SUCCESS;
}

