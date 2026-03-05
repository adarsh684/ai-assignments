#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CAPTCHA_LEN 6
#define MAX_ATTEMPTS 3

void generateCaptcha(char captcha[]) {

    char chars[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for(int i=0;i<CAPTCHA_LEN;i++)
    {
        captcha[i] = chars[rand() % strlen(chars)];
    }

    captcha[CAPTCHA_LEN] = '\0';
}

void displayCaptcha(char captcha[]) {

    char command[200];

    printf("\nSolve the CAPTCHA below:\n\n");

    // Using toilet for distortion
    sprintf(command,"toilet -f mono12 --gay \"%s\"",captcha);

    system(command);
}

int verifyCaptcha(char captcha[]) {

    char input[20];

    printf("\nEnter CAPTCHA: ");
    scanf("%s",input);

    if(strcmp(input,captcha)==0)
        return 1;

    return 0;
}

int main() {

    char captcha[CAPTCHA_LEN+1];
    int attempts=0;

    srand(time(NULL));

    printf("----- CAPTCHA Verification System -----\n");

    generateCaptcha(captcha);

    while(attempts < MAX_ATTEMPTS)
    {
        displayCaptcha(captcha);

        if(verifyCaptcha(captcha))
        {
            printf("\nAccess Granted: Human verified.\n");
            return 0;
        }

        else
        {
            printf("Incorrect CAPTCHA. Try again.\n");
            attempts++;
        }
    }

    printf("\nAccess Denied: Too many failed attempts.\n");

    return 0;
}
