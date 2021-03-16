#include <stdio.h>

int decNumber;
int bufVar;

int main()
{
    //Exercise#1
    printf("Exercise#1. Conversion of the decimal number to binary\n");
    printf("Enter the decimal number: ");
    scanf("%d", &decNumber);
    Decimal_To_Binary(decNumber, &bufVar);

    //Exercise#2
    int a,b;
    printf("\nExercise#2. Exponentiation (a^b)\n");
    printf("Enter the base:");
    scanf("%d", &a);
    printf("Enter the exponent:");
    scanf("%d", &b);
    bufVar = 0;
    printf("%d",Exponentiation_1(a, &b, &bufVar));

    //Exercise#3
    printf("\nExercise#3. Exponentiation (a^b) with parity property\n");
    printf("Enter the base:");
    scanf("%d", &a);
    printf("Enter the exponent:");
    scanf("%d", &b);
    bufVar = 0;
    printf("%d",Exponentiation_2(a, &b, &bufVar));
    return 0;
}

void Decimal_To_Binary(int num, int *buf){
    *buf <<= 1;
    *buf |= num%2;
    if(num >= 2) Decimal_To_Binary(num/2,buf);
    printf("%d", *buf & 1);
    *buf >>= 1;
}

int Exponentiation_1(int base, int *exp,int *buf){
    if(*buf < base) *buf = 1;
    *buf *= base;
    if(*exp>1){
        *exp -= 1;
        Exponentiation_1(base, exp, buf);
    }
    return *buf;
}

int Exponentiation_2(int base, int *exp,int *buf){
    if(*buf < base) {
        *buf = 1;
        if (*exp%2 != 0) *exp -= 1;
    }
    if(*exp > 0){
        if (*exp%2 == 0){
            *buf *= base*base;
            *exp /= 2;
            Exponentiation_2(base, exp, buf);
        } else {
            *buf *= base;
            *exp -= 1;
            Exponentiation_2(base, exp, buf);
        }
    }
    return *buf;
}


