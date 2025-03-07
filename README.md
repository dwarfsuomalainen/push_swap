# Push Swap

Push Swap is a sorting algorithm project developed during my studies at Hive Helsinki School in 2024. The goal of this project is to efficiently sort a stack of integers using a restricted set of operations.

## Features

This program sorts numbers using two stacks (`a` and `b`) with the following operations:

### **Operations Implemented**

- `sa`, `sb`, `ss` - Swap the first two elements of stack `a`, `b`, or both.
- `pa`, `pb` - Push the top element from one stack to the other.
- `ra`, `rb`, `rr` - Rotate stack `a`, `b`, or both upwards.
- `rra`, `rrb`, `rrr` - Reverse rotate stack `a`, `b`, or both downwards.

## Files Overview

- `main.c` - Entry point of the program.
- `push_swap.h` - Header file containing function prototypes and macros.
- `push_swap_init.c` - Initializes stacks and arguments.
- `push_swap_command.c` - Implements core push\_swap logic.
- `push_command.c` - Handles push operations.
- `swap_command.c` - Implements swap operations.
- `rotate.c` - Implements rotate operations.
- `reverse_rotate.c` - Implements reverse rotate operations.
- `stack_init.c` - Stack initialization functions.
- `stack_utils.c` - Utility functions for stack manipulation.
- `sort_sort.c` - Sorting logic implementation.
- `err_free.c` - Error handling and memory management.
- `Makefile` - Automates compilation.

## Compilation

To compile the project, run:

```sh
make
```

To clean up object files:

```sh
make clean
```

To remove all compiled files:

```sh
make fclean
```

To recompile everything:

```sh
make re
```

## Usage

Run the program with a list of integers:

```sh
./push_swap 4 67 3 87 23
```

The program will output a sequence of operations to sort the numbers.

## License

This project is released under the MIT License.

## Author

Created by Roman Bogoudinov during Hive Helsinki studies.

