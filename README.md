# Tibby Terminal
A Project that is in progress in which I am creating my own shell program. 
```
 ______   __     ______     ______     __  __        ______   ______     ______     __    __     __     __   __     ______     __        
/\__  _\ /\ \   /\  == \   /\  == \   /\ \_\ \      /\__  _\ /\  ___\   /\  == \   /\ "-./  \   /\ \   /\ "-.\ \   /\  __ \   /\ \       
\/_/\ \/ \ \ \  \ \  __<   \ \  __<   \ \____ \     \/_/\ \/ \ \  __\   \ \  __<   \ \ \-./\ \  \ \ \  \ \ \-.  \  \ \  __ \  \ \ \____  
   \ \_\  \ \_\  \ \_____\  \ \_____\  \/\_____\       \ \_\  \ \_____\  \ \_\ \_\  \ \_\ \ \_\  \ \_\  \ \_\\"\_\  \ \_\ \_\  \ \_____\ 
    \/_/   \/_/   \/_____/   \/_____/   \/_____/        \/_/   \/_____/   \/_/ /_/   \/_/  \/_/   \/_/   \/_/ \/_/   \/_/\/_/   \/_____/ 
```                                                                                                                                    



## How Does a Shell Usually Work??
1. Startup
2. Waiting for UserInput
3. Parse the User Input
4. Execute the command
5. Return a result
6. Go back to step 2

Shells act as a parent process to the act of accessing and executing processes. 

## Forks

To prevent bad commands from breaking the shell, we must use a [fork system].

Forks create copies of the current process and creates a child process with a unique process id to represent it. 
