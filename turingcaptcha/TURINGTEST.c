#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MSG 10
#define MAX_LEN 120

typedef struct {
    char messages[MAX_MSG][MAX_LEN];
    int count;
} Chat;

int totalTests = 0;
int aiFooled = 0;

// Human chat dataset 
Chat humanChats[] = {
    {{"hey what are you doing","just watching a movie","which one","interstellar again lol"},4},
    {{"did you finish the assignment","not yet","same here","ill probably do it tonight"},4},
    {{"you seeing the game tonight","probably not i got work","that sucks","yeah tell me about it"},4},
    {{"im starving","didnt you just eat","that was like 4 hours ago","fair enough pizza?"},4},
    {{"the weather is weird today","yeah it was sunny earlier","now its raining","classic weather lol"},4}
};

int humanChatCount = 5;


// generate AI chat 
void generateAIChat(Chat *chat)
{
    char *openers[] = {
        "hey what are you up to",
        "yo whats going on",
        "hey hows your day",
        "sup",
        "what are you doing rn"
    };

    char *responses[] = {
        "not much just chilling",
        "working on some stuff",
        "watching youtube lol",
        "trying to finish homework",
        "just scrolling my phone",
        "kinda bored tbh"
    };

    char *followups[] = {
        "what about you",
        "you doing anything fun",
        "got plans later",
        "same here honestly",
        "yeah its been a long day"
    };

    char *endings[] = {
        "lol",
        "haha yeah",
        "true true",
        "idk honestly",
        "maybe later"
    };

    chat->count = 4;

    strcpy(chat->messages[0], openers[rand()%5]);
    strcpy(chat->messages[1], responses[rand()%6]);
    strcpy(chat->messages[2], followups[rand()%5]);
    strcpy(chat->messages[3], endings[rand()%5]);

    // simulate small typing variation 
    if(rand()%3 == 0)
        strcat(chat->messages[1], " haha");
}

 
void printChat(Chat chat)
{
    for(int i=0;i<chat.count;i++)
    {
        if(i%2==0)
            printf("User1: %s\n", chat.messages[i]);
        else
            printf("User2: %s\n", chat.messages[i]);
    }
}


void runTest()
{
    Chat human = humanChats[rand()%humanChatCount];
    Chat ai;

    generateAIChat(&ai);

    int humanIsA = rand()%2;

    Chat chatA = humanIsA ? human : ai;
    Chat chatB = humanIsA ? ai : human;

    printf("\n====================================\n");
    printf("              ROUND %d\n",totalTests+1);
    printf("====================================\n");

    printf("\nConversation A\n");
    printf("--------------------\n");
    printChat(chatA);

    printf("\nConversation B\n");
    printf("--------------------\n");
    printChat(chatB);

    printf("\nWhich conversation is HUMAN? (A/B): ");

    char guess;
    scanf(" %c",&guess);

    totalTests++;

    int correct = 0;

    if((guess=='A' || guess=='a') && humanIsA)
        correct = 1;
    else if((guess=='B' || guess=='b') && !humanIsA)
        correct = 1;

    if(correct)
        printf("\nCorrect! You identified the human conversation.\n");
    else
    {
        printf("\nThe AI fooled you!\n");
        aiFooled++;
    }

    float rate = (aiFooled*100.0)/totalTests;

    printf("\n----- Statistics -----\n");
    printf("Total Evaluations: %d\n", totalTests);
    printf("AI Fooling Rate: %.2f%%\n", rate);
}


int main()
{
    srand(time(NULL));

    printf("====================================\n");
    printf("           TURING TEST\n");
    printf("====================================\n");

    while(1)
    {
        runTest();

        printf("\nRun another test? (y/n): ");

        char choice;
        scanf(" %c",&choice);

        if(choice!='y' && choice!='Y')
            break;
    }

    printf("\nSession ended.\n");

    return 0;
}
