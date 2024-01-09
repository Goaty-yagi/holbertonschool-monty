![image of simple shell](https://pbs.twimg.com/media/CFYYWy6UEAE9Ow-.png)
# holbertonschool-monty
This project implements an interpreter for Monty ByteCodes files. Monty ByteCodes is a programming language inspired by the Monty Python comedy group, utilizing a custom bytecode format for its instructions.

## Table of Contents :world_map:

- [Description](#description)
- [Flowchart](#flowchart)
- [Installation & Example](#installation)
- [Authors](#authors)
- [Bugs](#bugs)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Description :bellhop_bell:

The interpreter is designed to read Monty ByteCodes files, parse their instructions, and execute them accordingly. It functions by following the instructions encoded within the bytecode file, performing operations specified by the bytecode commands.

## Dependency

```
- Ubuntu 20.04
- gcc version 9.4.0
- git version 2.25.1
- GNU Make 4.2.1 
```

## Flowchart :chart:

Below is a flowchart showing the basic implementation of how our hsh shell works.

![flowchart](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/flowchart.png)



## Features

| **Function** | **Action**                    |
| ------------- | ----------------------------- |
| push           | Adds an element to the stack.|
| pall           | Prints all the values on the stack, starting from the top. |
| pint           | Prints the value at the top of the stack.|
| pop            | Removes the top element of the stack.|
| swap            | Swaps the top two elements of the stack.|
| add            | Adds the top two elements of the stack.|
| nop            | Does nothing.|

## Compile with Makefile

Install gcc: install gcc with `apt-get install gcc` (if necessary)
Install make: install make with `apt-get install make` (if necessary)

Our repository contains a makefile, and with makefile it allows you to compile all of the our code to your own main.c with simple command `make`.

## Usage

Compile: Compile the interpreter (if necessary).
Execute: Run the interpreter, providing the Monty ByteCodes file as an argument.

```
$ ./monty bytecodes/00.m
```

## Installation & Example :electric_plug:

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
You might need to make you file executable with `chmod +x bytecodes/your_monty.m` (if necessary)
## Authors :selfie:

- Warren Markham https://github.com/WarrenTheRabbit
- Daniel Colorado Londono https://github.com/DanielColoradoL
- Nobuhiro Funahashi https://github.com/Goaty-yagi
## Bugs :clown_face:

Report bugs on the GitHub Issues page.

## Contributing :man_juggling:

Contributions are welcome! If you'd like to contribute to the interpreter's development or report issues, please follow the guidelines outlined in [CONTRIBUTING.md].

## License :label:

This project is released under the MIT License

## Acknowledgements :triangular_ruler:

This project was developed as part of the curriculum for [Holberton School](https://www.holbertonschool.com/), a campus-based full-stack software engineering program. We would like to acknowledge the guidance and support received from our peers and mentors during the development of this Simple Shell project.
