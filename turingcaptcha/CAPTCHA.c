#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int captcha;
    int input;

    srand(time(0));

    captcha = rand() % 9000 + 1000;

    printf("CAPTCHA: %d\n", captcha);
    printf("Enter the CAPTCHA: ");

    scanf("%d",&input);

    if(input == captcha)
        printf("Human verified!\n");
    else
        printf("Verification failed!\n");

    return 0;
}
