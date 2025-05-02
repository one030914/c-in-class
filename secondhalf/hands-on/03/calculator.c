#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
    double x, y, result;

    if (argc != 4){
        printf("Usage: %s <operator> <operand_1> operand_2>\n", argv[0]);
        return 1;
    }

    x = atof(argv[2]);
    y = atof(argv[3]);

    if(strcmp(argv[1], "add") == 0){
        result = x + y;
    }else if(strcmp(argv[1], "subtract") == 0){
        result = x - y;
    }else if(strcmp(argv[1], "multiply") == 0){
        result = x * y;
    }else if(strcmp(argv[1], "divide") == 0){
        result = x / y;
    }else if(strcmp(argv[1], "mod") == 0){
        result = fmod(x, y);
    }else if(strcmp(argv[1], "exp") == 0){
        result = pow(x, y);
    }else{
        printf("Operation \"%s\" not supported.\n", argv[1]);
    }

    printf("Result = %.5lf\n", result);
    return 0;
}