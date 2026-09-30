#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char command[100];

    while(1)
    {
        printf("2520030360_SHELLFORGE$ ");
        fgets(command, sizeof(command), stdin);

        command[strlen(command) - 1] = '\0';

        if(strcmp(command, "exit") == 0)
            return 0;

        printf("you entered %s\n", command);
    }

    return 0;
}
