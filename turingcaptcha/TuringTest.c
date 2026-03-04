#include <stdio.h>
#include <string.h>

int main()
{
    char question[100];

    printf("Turing Test Simulation\n");
    printf("Ask a question (type 'exit' to stop)\n");

    while(1)
    {
        printf("\nJudge: ");
        fgets(question,100,stdin);

        if(strncmp(question,"exit",4)==0)
            break;

        if(strstr(question,"name"))
            printf("Machine: My name is Alex. Nice to meet you.\n");

        else if(strstr(question,"how are you"))
            printf("Machine: I am doing well. How about you?\n");

        else if(strstr(question,"weather"))
            printf("Machine: The weather seems nice today.\n");

        else if(strstr(question,"hello"))
            printf("Machine: Hello! How can I help you today?\n");

        else
            printf("Machine: That's interesting. Tell me more.\n");
    }

    printf("\nConversation ended.\n");

    return 0;
}
