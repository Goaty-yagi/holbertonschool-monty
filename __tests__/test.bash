#!/bin/bash

# This is an exmaple test file that test executable with args.

# Check if an argument is provided
if [ "$#" -lt 2 ]; then
    echo "Usage: $0 <executable> <arg1> <arg2> ..."
    exit 1
fi

executable="./$1"  # Assuming the executable is in the current directory
shift  # Remove the executable from the arguments

# Check if the executable file exists and is executable
if [ ! -x "$executable" ]; then
    echo "Error: Executable '$executable' not found or not executable"
    exit 1
fi

# Run the executable with the provided arguments
"$executable" "$@"

# Check the exit code of the executable
if [ $? -eq 0 ]; then
    echo "The program executed successfully"
    exit 0
else
    echo "The program did not return successfully (exit code: $?)"
    exit 1
fi
