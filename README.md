# Tibby Terminal
## A Project where I describe how to make your own Simple Shell with C. 

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
# Blueprint of how our program should work: 
```
int main(int argc, char **argv)
{
  // Main Loop
  void loop()

  // Read User Commands 
  char * read_line()

  // Tokenize Input
  char * * split_line()

  // Execute Commands
  int dash_execute()

  //Crash Handeling
  return EXIT_SUCCESS/EXIT_FAILURE message;
} 

```
## Shell Initialization and Testing:  

```
void loop() {
   char * line;
   char * * args;
   int status = 1;

   do {
      printf("\033[31mtibby > \033[0m");
      line = read_line();
      flag = 0;
      args = split_lines(line);
      status = dash_launch(args);
      free(line);
      free(args);
   } while (status);
}
```
In this section of the code, we declare a pointer to a char named line and another to args with in the first two lines of the loop. The line char
pointer will hold the command given from the user within the read_line() function. Status stores the return of functions made by command execution (exit or execute).
If the exit command has been placed, force the break of the loop by returning 0. The free(line) and free(args) free up the memory as manaul garbage collection.

## Reading User Commands
```
char * read_line() {
  int buffsize = 1024;
  int position = 0;
  char * buffer = malloc(sizeof(char) * buffsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "%sdash: Allocation error%s\n", RED, RESET);
    exit(EXIT_FAILURE);
  }

  while (1) {
    c = getchar();
    if (c == EOF || c == '\n') {
      //printf("\n");
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    if (position >= buffsize) {
      buffsize += 1024;
      buffer = realloc(buffer, buffsize);

      if (!buffer) {
        fprintf(stderr, "dash: Allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}
```


Resources used to make this tutorial: 
- https://danishpraka.sh/posts/write-a-shell/
-  https://igupta.in/blog/writing-a-unix-shell-part-1/
-  https://brennan.io/2015/01/16/write-a-shell-in-c/

## TODO
- Run real shell commands
- Add operating system info commands (cd, ls, etc...)
- Add command history


