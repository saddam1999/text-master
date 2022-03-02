#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int charReading;
FILE *filePointer;

void showBanner()
{
    filePointer = fopen("src/1_banner.txt", "r");

    charReading = fgetc(filePointer);
    while (charReading != EOF)
    {
        fputc(charReading, stdout);
        charReading = fgetc(filePointer);
    }
    fclose(filePointer);
}

void showExitBanner()
{
    printf("\n");
    filePointer = fopen("src/2_e_banner.txt", "r");

    charReading = fgetc(filePointer);
    while (charReading != EOF)
    {
        fputc(charReading, stdout);
        charReading = fgetc(filePointer);
    }
    fclose(filePointer);
    fflush(stdin);
    getchar();
}

void showSource()
{
    filePointer = fopen("src/3_source.txt", "r");

    charReading = fgetc(filePointer);
    while (charReading != EOF)
    {
        fputc(charReading, stdout);
        charReading = fgetc(filePointer);
    }
    fclose(filePointer);
    printf("\n");
}

void showLogs(int userOption)
{
    if (userOption == 1)
    {
        filePointer = fopen("var/logs/logs.txt", "r");

        charReading = fgetc(filePointer);
        while (charReading != EOF)
        {
            fputc(charReading, stdout);
            charReading = fgetc(filePointer);
        }
        fclose(filePointer);
    }
    else
    {
        filePointer = fopen("var/logs/logs.txt", "w");
        fclose(filePointer);
    }
}

void showInstruction()
{
    filePointer = fopen("src/4_instruction.txt", "r");

    charReading = fgetc(filePointer);
    while (charReading != EOF)
    {
        fputc(charReading, stdout);
        charReading = fgetc(filePointer);
    }
    fclose(filePointer);
}

void showOutput(char userString[], int userOption)
{
    time_t currentTime;
    time(&currentTime);

    char timeUpper[30], *PTR2 = &timeUpper[0];
    strcpy(timeUpper, ctime(&currentTime));
    while (*PTR2 != '\0')
    {
        *PTR2 = toupper((int)*PTR2);
        PTR2++;
    }
    timeUpper[strcspn(timeUpper, "\n")] = 0;

    filePointer = fopen("var/logs/logs.txt", "a");
    if (userOption == 1)
    {
        fprintf(filePointer, "\n [ENCRYPTION LOG --> %s]\n [ENCRYPTED TEXT --> %s]\n", &timeUpper[0], &userString[0]);
        fprintf(stdout, "\n [ENCRYPTION DONE --> %s]\n [ENCRYPTED TEXT --> %s]\n", &timeUpper[0], &userString[0]);
    }
    else
    {
        fprintf(filePointer, "\n [DECRYPTION LOG --> %s]\n [DECRYPTED TEXT --> %s]\n", &timeUpper[0], &userString[0]);
        fprintf(stdout, "\n [DECRYPTION DONE --> %s]\n [DECRYPTED TEXT --> %s]\n", &timeUpper[0], &userString[0]);
    }
}

void startEncryptDecrypt(int userOption)
{
    getchar();
    showInstruction();

    char userString[1000], *PTR = &userString[0];
    fgets(userString, 1000, stdin);
    userString[strcspn(userString, "\n")] = 0;

    if (userOption == 1)
    {
        while (*PTR != '\0')
        {
            *PTR = *PTR + 1;
            PTR++;
        }
        showOutput(userString, 1);
    }
    else
    {
        while (*PTR != '\0')
        {
            *PTR = *PTR - 1;
            PTR++;
        }
        showOutput(userString, 0);
    }
}