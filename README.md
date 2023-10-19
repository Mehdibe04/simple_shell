# Educational Objectives
Upon the completion of this project, you should be capable of conveying the following information to others without relying on external resources:

# Overview
- The originator and developer of the initial Unix operating system.
- The pioneer behind the original UNIX shell.
- The innovator behind the B programming language, which directly influenced the C programming language.
- The significance of Ken Thompson in the realm of computing.
- The internal mechanics of a shell.
- Comprehending the concepts of "pid" and "ppid."
- Proficiency in modifying the environment of the present process.
- Distinguishing the distinction between a function and a system call.
- Competence in crafting new processes and understanding their three core prototypes.
- Grasping how the shell leverages the PATH to locate programs.
- Proficiency in launching other programs utilizing the execve system call.
- The art of pausing process execution until one of its offspring terminates.
- Appreciating the significance of "EOF" or "end-of-file."

# Project Prerequisites
## General
- Approved text editors: vi, vim, emacs.
- Compilation on Ubuntu 20.04 LTS using gcc, with these options: -Wall -Werror -Wextra -pedantic -std=gnu89.
- Append a newline character to the end of each code file.
- Mandatory inclusion of a README.md file in the project's root directory.
- Adherence to the Betty style, which will be validated using betty-style.pl and betty-doc.pl.
- Ensure your shell remains memory leak-free.
- Limit each file to a maximum of five functions.
- Guard all header files against multiple inclusions.
- Use system calls judiciously.

# GitHub
- Maintain a single repository for each project group.
- Collaborate effectively with your partner by adding them as a collaborator to avoid issues related to duplicate repository names on both accounts.

# Output
- Unless explicitly specified otherwise, the program's output should be identical to that of the sh (/bin/sh) shell, including error messages.
- The only variance should be in error messages, where the program name must match your argv[0].

# List of Permissible Functions and System Calls
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

# Compilation
## Compile your shell as follows:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

# files
- README.md: A detailed description of the project repository.
- man_1_simple_shell: The manual page for the shell you are developing.
- AUTHORS: A file located at the root of your repository, listing all individuals who have contributed to the repository's content.
- main.h: The header file that includes standard headers and function prototypes used in the program.
- main.c: The entry point of the program, initializing an infinite loop by invoking the prompt function.
- prompt.c: Uses the getline system call to read user input and maintains an infinite loop with fork to sustain the shell prompt.
- special_character: Identifies special inputs, such as a leading slash, "exit," or "env."
- string.c: Manages strings, including string length, writing strings, finding strings in directories, and string concatenation.
- cmd.c: Identifies the user-entered command.
- execute.c: Executes the identified command.
