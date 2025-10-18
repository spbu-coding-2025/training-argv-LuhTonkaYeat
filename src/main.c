#include <stdio.h>
#include <string.h>

#define LOWER_BOUND "--lower_bound"
#define UPPER_BOUND "--upper_bound"

int num_parsing(char* str){
    if (*str == '\0' || *str == '0') return 0;

    int sign = 1;
    if (*str == '-'){
        sign = -1;
        str++;
    }

    int res = 0;
    for ( ; *str != '\0'; str++){
        res = res * 10 + (*str - '0');
    }

    return res * sign;
}

int main(int argc, char* argv[]){
    int lower = 0, upper = 0;
    int is_lower = 0, is_upper = 0;

    for (int i = 1; i < argc; i++){
        if (strncmp(argv[i], "--lower_bound=", 14) == 0){
            is_lower = 1;
            lower = num_parsing(argv[i] + 14);
        }
        if (strncmp(argv[i], "--upper_bound=", 14) == 0){
            is_upper = 1;
            upper = num_parsing(argv[i] + 14);
        }
    }

    if (is_lower == 0 && is_upper == 0){
        fprintf(stderr, "No flags found.\n");
        return 1;
    }
    else if (is_lower == 0){
        fprintf(stderr, "Flag %s is missing.", LOWER_BOUND);
        return 1;
    }
    else if (is_upper == 0){
        fprintf(stderr, "Flag %s is missing.", UPPER_BOUND);
        return 1;
    }

    if (lower > upper) {
        fprintf(stderr, "The lower bound is greater than the upper bound.");
        return 1;
    }

    for (int i = lower; i < upper + 1; i++){
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}