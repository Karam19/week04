#include <stdio.h>
#include <stdlib.h>

void read_command(char* command);

int main()
{
    char command[20];
    while (1){
        printf("> ");
        read_command(command);
        system(command);
    }
}
void read_command(char* command){
    gets(command, 10, stdin);
}