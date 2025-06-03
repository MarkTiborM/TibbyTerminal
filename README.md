# Tibby Terminal
A Project where I make my own shell program.
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

# Starting of the Shell Loop
To start out, we need a driving function of the loop. Our logic should go as follows : a prompt tells us that the terminal is ready to accept input commands from the user.
Our prompt for the time being is going to be tibby >. 

```
void loop() {
   char * line;
   char * * args;
   int status = 1;

   do {
      printf("\033[1;31m");
      printf("tibby > ");
      line = read_line();
      flag = 0;
      args = split_lines(line);
      status = dash_launch(args);
      free(line);
      free(args);
   } while (status);
}
```
