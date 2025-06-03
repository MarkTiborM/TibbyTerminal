#include <stdio.h>
#include <stdlib.h>

char *read_line() {
    char *line = malloc(1024); 
    if (!line) return NULL;
    fgets(line, 1024, stdin); 
    return line;
}

char **split_lines(char *line) {
    char **args = malloc(sizeof(char *) * 2); 
    args[0] = line;
    args[1] = NULL;
    return args;
}

int dash_launch(char **args) {
    printf("Simulated command: %s\n", args[0]);
    return 0; 
}

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
