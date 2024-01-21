<p align="center">
    <img src="https://pbs.twimg.com/media/CFYYWy6UEAE9Ow-.png">
</p>

# holbertonschool-monty
This project implements an interpreter for Monty ByteCodes files. Monty ByteCodes is a programming language inspired by the Monty Python comedy group, utilizing a custom bytecode format for its instructions.

## Table of Contents :world_map:

- [Overview](#overview)
- [Description](#description)
- [Dependency](#dependency)
- [Flowchart](#flowchart)
- [Features](#features)
- [Compile](#compile)
- [Usage](#usage)
- [Installation](#installation)
- [ExpectedError](#expectederrors)
- [Authors](#authors)
- [Bugs](#bugs)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Overview
The interpreter is designed to read Monty ByteCodes files, parse their instructions, and execute them accordingly. It functions by following the instructions encoded within the bytecode file, performing operations specified by the bytecode commands.



## Description

The interpreter is designed to read Monty ByteCodes files, parse their instructions, and execute them accordingly. It functions by following the instructions encoded within the bytecode file, performing operations specified by the bytecode commands.

## Dependency

```
- Ubuntu 20.04
- gcc 9.4.0
- git 2.25.1
- GNU Make 4.2.1 
```

## Flowchart

## Features

- ByteCode Parsing: The interpreter parses Monty ByteCodes files, translating the instructions into executable operations.
- Execution: It executes the instructions step-by-step, carrying out the specified operations.
- Stack Operations: Handles stack-based operations as defined by the Monty ByteCodes language.

| **Operation** | **Description**                    |
| ------------- | ----------------------------- |
| push           | Adds an element to the stack.|
| pall           | Prints all the values on the stack, starting from the top. |
| pint           | Prints the value at the top of the stack.|
| pop            | Removes the top element of the stack.|
| swap            | Swaps the top two elements of the stack.|
| add            | Adds the top two elements of the stack.|
| nop            | Does nothing.|

## Compile

Install gcc: install gcc with `apt-get install gcc` (if necessary)
Install make: install make with `apt-get install make` (if necessary)

Our repository contains a makefile, and with makefile it allows you to compile all of the our code to your own main.c with simple command `make`.

## Usage

Compile: Compile the interpreter (if necessary).
Execute: Run the interpreter, providing the Monty ByteCodes file as an argument.

```
$ ./monty bytecodes/00.m
```

## Installation

First, clone this repository to your local machine:

```bash
$ git clone https://github.com/Goaty-yagi/holbertonschool-monty.git
```
You might need to install git on your Ubuntu with `apt-get install git` (if necessary)
Then, go to the repository folder:

```bash
$ cd holbertonschool-monty
```
To use the shell compile it using the provided Makefile:

```bash
$ make
```
Then, run the command:                                                                                         
```bash                                                               
$ ./monty bytecodes/00.m
```

Then you can get the output
```bash
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1

```

You can test your own Monty ByteCodes file

```bash
julien@ubuntu:~/monty$ cat bytecodes/your_monty.m
push 1$
push 2$
push 3$
pall$
pop$
add$
pall$
     push      20I Love montybyte code$
    swap      $
$     
pall$ 
julien@ubuntu:~/monty$ ./monty bytecodes/your_monty.m
3
2
1
3
3
20
```
You might need to make your file executable with `chmod +x bytecodes/your_monty.m` (if necessary)

## ExpectedErrors
While using this software, users may encounter specific known issues or errors. Here are a few examples:

- `USAGE: monty file`: If the user does not give any file or more than one argument to your program.

- `Error: Can't open file <file>`: If, for any reason, it’s not possible to open the file.

- `L<line_number>: unknown instruction <opcode>`: If the file contains an invalid instruction.

- `Error: malloc failed`: If you can’t malloc anymore.

- `L<line_number>: usage: push integer`: if <int> is not an integer or if there is no argument given to push.

- `L<line_number>: can't pint, stack empty`: If the stack is empty with pint operation.

- `L<line_number>: can't pop an empty stack`: If the stack is empty with pop operation.

- `L<line_number>: can't swap, stack too short`: If the stack contains less than two elements with swap operation.

- `L<line_number>: can't add, stack too short`: If the stack contains less than two elements with add operation.


## Authors

- Warren Markham https://github.com/WarrenTheRabbit
- Daniel Colorado Londono https://github.com/DanielColoradoL
- Nobuhiro Funahashi https://github.com/Goaty-yagi
## Bugs

Report bugs on the GitHub Issues page.

## Contributing

Contributions are welcome! If you'd like to contribute to the interpreter's development or report issues, please follow the guidelines outlined in [CONTRIBUTING.md].

## License

This project is released under the MIT License

## Acknowledgements

This project was developed as part of the curriculum for [Holberton School](https://www.holbertonschool.com/), a campus-based full-stack software engineering program. We would like to acknowledge the guidance and support received from our peers and mentors during the development of this Monty Interpreter project.
