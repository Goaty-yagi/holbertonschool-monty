#!/bin/bash

# Check if an argument is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <executable>"
    exit 1
fi

executable="$1"

# Check if the executable file exists
if [ ! -x "$executable" ]; then
    echo "Error: Executable '$executable' not found or not executable"
    exit 1
fi

# Define the expected output
expected_output="1
6
2
1
0"

# Run the executable with argument 00.m and capture the output
actual_output=$(./"$executable" bytecodes/00.m)

# Display the expected and actual output
echo "Expected output:"
echo "$expected_output"
echo "Actual output:"
echo "$actual_output"

# Check if the output matches the expected output
if [ "$actual_output" = "$expected_output" ]; then
    echo "Test passed: Output matches expected"
else
    echo "Test failed: Output does not match expected"
fi
