# Minishell

## Overview

**Minishell** is a simple, Unix-like shell developed as part of my studies at 42 Porto. This project demonstrates my understanding of system programming, process management, and the implementation of shell features. Achieving a final note of 100, this project highlights my proficiency in C programming and system-level programming concepts.

## Features

- **Command Execution**: Supports the execution of executable programs, both from absolute paths and relative paths.
- **Built-in Commands**: Implements essential built-in shell commands such as `cd`, `echo`, `env`, `setenv`, `unsetenv`, and `exit` made by us.
- **Environment Variables**: Handles environment variables and allows for their manipulation using built-in commands.
- **Pipes and Redirection**: Supports piping (`|`) and I/O redirection (`<`, `>`, `>>`).
- **Signal Handling**: Manages common signals like `SIGINT` (Ctrl+C) and `SIGQUIT` (Ctrl+\).
- **Error Handling**: Provides comprehensive error messages for invalid commands and syntax errors, always updating the exit status.

## Installation

1. **Clone the repository**:
  ```bash
  git clone git@github.com:Joaofcpereira8/42Cursus_Minishell.git
  ```
2. Navigate to the project directory:
  ```bash
  cd minishell
  ```
3. Compile the project:
  ```bash
  make
  ```

## Usage
Start the shell by running:

  ```bash
  ./minishell
  ```

33 Built-in Commands:

- cd [directory]: Change the current directory.
- echo [arguments]: Display a line of text.
- env: Display the environment variables.
- export [key]=[value]: Set an environment variable.
- unset [key]: Unset an environment variable.
- exit: Exit the shell.

- Example:
  ```bash
  minishell> echo Hello, World!
  Hello, World!
  minishell> ls | grep minishell
  minishell.c
  minishell.h
  ```

## Achievements
Final Note: 95
This project was evaluated and received an almost perfect score, highlighting its quality and completeness.

## Acknowledgements
- Special thanks to my peers who provided guidance and support throughout the development of this project.
- And a special thanks to my colleague and project partner <a href="https://github.com/berestv" target="_blank">Bernardo</a>.

## Attention
The error that made us have 95 out of 100 is solved.
