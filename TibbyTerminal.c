#include <stdio.h>
#include <stdlib.h>

//allocated 1024 bytes for a line of input
//fget to read from the standard input and return a point to the input string

char *read_line() {
    char *line = malloc(1024); 
    if (!line) return NULL;
    fgets(line, 1024, stdin); 
    return line;
}

//split_lines to break the input command into arguments

char **split_lines(char *line) {
    char **args = malloc(sizeof(char *) * 2); 
    args[0] = line;
    args[1] = NULL;
    return args;
}

//simulated command execution for testing purposes

int dash_launch(char **args) {
    printf("Simulated command: %s\n", args[0]);
    return 0; 
}

//loop function that reads the input from the user and passes it to the command runner

void loop() {
    char *line;
    char **args;
    int status = 1;
    int flag = 0;


    do {
        printf("\033[31mtibby > \033[0m");
        line = read_line();
        flag = 0;
        args = split_lines(line);
        status = dash_launch(args);
        free(line);
        free(args);
    } while (status);
}#

int main() {
    loop();
    return 0;
}
