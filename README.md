This project has been created as part of the 42 curriculum by <arochd>

# PUSH_SWAP

## Description

    The "Push_swap" project is all about sorting a stack of numbers with the fewest possible moves, using only a limited set of operations. It's an algorithm puzzle designed to test both creativity and efficiency .

    The idea is simple : you start with a list of unsorted integers, and your goal is to print out a sequence of operations that will sort that list. But there's a catch: you can only use two stacks, and you're limited to a specific set of commands (push, swap, rotate, and their variations). that means every counts, and finding the optimal solution is both challenging and rewarding.

    Throughout this project, I learned a great deal about algorithm optimization, stack operations, and the trade-offs between brute-force versus efficient sorting methods.

## Instructions

### How To Compile
    To build the project, just run 'make'

    ```bash
    make
    ```

    This will generate an executable called 'push_swap'.

### How To Use

    Run the program with a list of integers as arguments:

    ```bash
    ./push_swap 2 1 3 6 5 8
    ```

    The output will be a list of operations to sort tthe numbers. If you pass a sorted list, the program prints nothing.