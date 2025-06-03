# Tibby Terminal
A Project where describe my process of making my own shell.
```
 ______   __     ______     ______     __  __        ______   ______     ______     __    __     __     __   __     ______     __        
/\__  _\ /\ \   /\  == \   /\  == \   /\ \_\ \      /\__  _\ /\  ___\   /\  == \   /\ "-./  \   /\ \   /\ "-.\ \   /\  __ \   /\ \       
\/_/\ \/ \ \ \  \ \  __<   \ \  __<   \ \____ \     \/_/\ \/ \ \  __\   \ \  __<   \ \ \-./\ \  \ \ \  \ \ \-.  \  \ \  __ \  \ \ \____  
   \ \_\  \ \_\  \ \_____\  \ \_____\  \/\_____\       \ \_\  \ \_____\  \ \_\ \_\  \ \_\ \ \_\  \ \_\  \ \_\\"\_\  \ \_\ \_\  \ \_____\ 
    \/_/   \/_/   \/_____/   \/_____/   \/_____/        \/_/   \/_____/   \/_/ /_/   \/_/  \/_/   \/_/   \/_/ \/_/   \/_/\/_/   \/_____/ 
```                                                                                                                                    

# Starting with a C compiler
First for this project, you have to make an environment that can create and run C programs.
Initially, I made a simple Ubuntu Server VM in VirtualBox and made a snapshot of the newly created box.
Next, I had to update the OS and install the packages necessary to run GCC.

With this, I could now run C applications by typing in :

```
$ sudo apt update
$ sudo apt install build-essential
$ gcc --version
```
(Make a Hello World Script to check if your GCC compiler is working)

```
# sudo nano shell

#include <stdio.h>

int main() {
    printf("hello world\n");
    return 0;
}
```

```
$ gcc -o shell shell.c
```
![hello](https://github.com/user-attachments/assets/15256d8c-3ea8-453e-99d1-d35212170ceb)

# How Does a Shell Usually Work??
1. Startup
4. Waiting for UserInput
5. Parse the User Input
6. Execute the command
7. Return a result
8. Go back to step 2

Shells act as a parent process to the act of accessing and executing processes. 

### This shell is simple enough where there won't be any configuration files. 

# Main Shell Loop
To start out, we need a driving function of the loop to test our commands. Our logic should go as follows: 

- A prompt tells us that the terminal is ready to accept input commands from the user by outputting 
something

- A prompt tells us that our request went through 

In this case I am making it output "tibby >" in red to symbolize the tibby terminal is ready for command input and "Simulated command:" to show for the testing purposes what the user input was.
So far, we need to allocated 1024 bytes for a line of input, use fget() to read from the standard input and return a point to the input string to show our request went through. We also have 
split_lines() to break the input command into arguments. To add on, of coarse we have our main loop function that reads the input from the user and passes it to the command runner + frees the allocated memory
after each command until one input has been completed (status == 0). This version of the code is just to test everything before we can start reading the user commands.

## Shell Initialization and Testing: 
```
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
```

## Output should be : 
![main](https://github.com/user-attachments/assets/6d49db60-cfce-4fd1-ab49-ae9f6515e9b0)

# Tokenizing Input


