#include <stdio.h>
#define SIZE 1024

int main(int argc, char *argv[]){
    char des[SIZE], src[SIZE];
    FILE *fdes, *fsrc;

    if(argc < 2){
        printf("Usage: %s <des_file> [src_file1] [src_file2] ...\n", argv[0]);
        return 1;
    }

    for(int i = 2; i < argc; i++){
        fdes = fopen(argv[1], "a");
        if(fdes == NULL){
            printf("Error: failed to merge.\n");
            return 1;
        }

        fsrc = fopen(argv[i], "r");
        if(fsrc == NULL){
            printf("WARNING: can't open file %s, skipped.\n", argv[i]);
            continue;
        }

        while(1){
            char line[SIZE] = {'\0'};

            if(fgets(line, SIZE, fsrc) != NULL){
                fprintf(fdes, "%s", line);
            }else if(feof(fsrc)){
                break;
            }
        }
        
        printf("Merging \"%s\" to \"%s\". ... done.\n", argv[i], argv[1]);
        fclose(fdes);
        fclose(fsrc);
    }
    return 0;
}