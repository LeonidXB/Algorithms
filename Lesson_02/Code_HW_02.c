#include <stdio.h>

int number;
int CheckNumber(int *num);

int main()
{
    printf("This software checks the enter numerical value\n");
    printf("Enter a number: ");
    scanf("%d", &number);

    printf("The entered number is%s a prime number", CheckNumber(&number)? "": " not");
    return 0;
}

int CheckNumber(int *num){
    for(int i=2; i < *num; i++){
        if(*num%i == 0) return 0;
    }
    return 1;
}
