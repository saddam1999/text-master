#include <stdio.h>
#include <stdlib.h>
#include "include/textm.h"

int main()
{
    system("cls");
    showBanner();

    int userChoice, loopStop = 0;
    while (loopStop == 0)
    {
        userChoice = getchar();

        switch (userChoice)
        {
        case '1':
            loopStop++;
            system("cls");
            showSource();
            break;

        case '2':
            loopStop++;
            system("cls");
            startEncryptDecrypt(1);
            break;

        case '3':
            loopStop++;
            system("cls");
            startEncryptDecrypt(0);
            break;

        case '4':
            loopStop++;
            system("cls");
            showLogs(0);
            break;

        case '5':
            loopStop++;
            system("cls");
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
    return 0;
}