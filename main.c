#include <stdio.h>
#include <stdlib.h>
#include "include/textm.h"

void main()
{
    system("clear");
    showBanner();

    short int userChoice, loopStop = 0;
    while (loopStop == 0)
    {
        userChoice = getchar();

        switch (userChoice)
        {
        case '1':
            loopStop++;
            system("clear");
            showSource();
            break;

        case '2':
            loopStop++;
            system("clear");
            startEncryptDecrypt(1);
            break;

        case '3':
            loopStop++;
            system("clear");
            startEncryptDecrypt(0);
            break;

        case '4':
            loopStop++;
            system("clear");
            showLogs(0);
            break;

        case '5':
            loopStop++;
            system("clear");
            showLogs(1);
            break;

        case '6':
            exit(0);

        default:
            printf("\n [INVALID INPUT, PLEASE TRY AGAIN]\n YOUR INPUT IS --> ");
            getchar();
        }
    }
    showExitBanner();
}