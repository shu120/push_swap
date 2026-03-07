*This project has been created as part of the 42 curriculum by shukondo.*

# push_swap

## Description

`push_swap` is a 42 sorting project.

The program receives a list of integers as arguments. These integers are placed in stack `a`, while stack `b` starts empty. The objective is to sort stack `a` in ascending order, so that the smallest value is at the top of the stack, by printing a valid sequence of allowed operations.

Only the operations defined by the subject may be used:

- `sa`
- `sb`
- `ss`
- `pa`
- `pb`
- `ra`
- `rb`
- `rr`
- `rra`
- `rrb`
- `rrr`

The challenge is not only to produce a correct result, but also to reduce the number of operations as much as possible.

This implementation is based on:

- strict input validation
- a circular-array stack structure
- dedicated sorting for very small cases
- index compression
- radix sort for larger inputs

The project is divided into the following parts:

- parsing
- stack operations
- small-case sorting
- large-case sorting

## Instructions

### Compile
Compile the project with:
```
make
```

Other useful Make targets:
```
make re
make clean
make fclean
```
---
### Usage
Example with separate arguments:
```
./push_swap 2 1 3 6 5 8
```

Example with quoted arguments:
```
./push_swap "2 1 3 6 5 8"
```
The program prints one instruction per line to standard output.

Example:
```
./push_swap 2 1 3
```

Possible output:
```
sa
```
---
### Input rules
This program accepts signed decimal integers within the int range.

Valid examples:
```
./push_swap 42 -3 0
./push_swap +42 -3 0
./push_swap "1 2 3"
```

Invalid examples:
```
./push_swap ""
./push_swap "   "
./push_swap a b c
./push_swap 1 1 2
./push_swap 2147483648
./push_swap -2147483649
```

Expected behavior for invalid input:
```
Error
```
---
### General program flow
The overall execution flow is:

- parse the arguments
- validate every token
- build `stack a`
- initialize `stack b`
- stop immediately if `stack a` is already sorted
- use small_sort when the number of elements is small
- otherwise compress values into indices
- sort the indices with radix sort
- print the generated operation sequence
---
### Stack representation
The stacks are represented with a circular array.
```
typedef struct s_stack
{
	int	*arr;
	int	size;
	int	capacity;
	int	top;
}	t_stack;
```
Meaning of each field:

- `arr` is the allocated array storing the stack data
- `size` is the current number of valid elements
- `capacity` is the total allocated size
- `top` is the logical position of the first element of the stack

This design allows efficient stack manipulation.

---
### Parsing
The implementation follows these steps:
- split each argument into tokens
- validate each token as a number
- convert the token to a numeric value
- check whether it fits in the int range
- store the validated values
- reject duplicates
- initialize `stack a`

Notes on numeric conversion

A custom `ft_atol` is used instead of relying on a simple `atoi`, because the project must detect values outside the valid integer range.

---
### Stack operations

The project implements all subject operations in a separate operations/ directory.

These include:
- swap operations
- push operations
- rotate operations
- reverse rotate operations

A command is printed only when the operation is actually performed.

For example:

- trying to swap a stack with fewer than two elements does nothing
- trying to push from an empty stack does nothing
- trying to rotate a stack of size 0 or 1 does nothing
- This prevents invalid or useless instructions from being printed.

---
### Sorting strategy
The implementation uses two different strategies depending on input size.

#### 1. Small-case sorting

When the size of `stack a` is small, a dedicated approach is used.

##### For 2 elements

If they are out of order, a single swap is enough.

##### For 3 elements

A small case-based sorting function is used.
Since only a limited number of permutations exist, it is simpler and more efficient to directly handle each arrangement than to use a large general-purpose algorithm.

##### For 4 or 5 elements

The smallest values are pushed to `stack b`, the remaining three values are sorted, and then the saved values are pushed back to `stack a`.

This reduces the number of operations compared with using radix sort on very small inputs.

#### 2. Large-case sorting

When the input is larger, the program uses:

- index compression
- radix sort

---
### Index compression

Before radix sort, the original values are replaced by their relative ranks.

Example:
```
42 -5 100 3
```
becomes:
```
2 0 3 1
```
This transformation keeps the ordering information while removing the need to process large or negative integers directly.

---

### Radix sort

After index compression, the program sorts the values with radix sort.

The algorithm processes the indices bit by bit, starting from the least significant bit.

For each bit position:

- if the current bit is `0`, the value is pushed to `stack b`
- if the current bit is `1`, the value remains in `stack a` and `stack a` is rotated

After one full pass over `stack a`, all elements in `stack b` are pushed back to `stack a`.

This process is repeated until all relevant bit positions have been processed.

---
### Complexity
#### Parsing

- token processing depends on the input length
- duplicate checking is `O(n^2)`

#### Index compression

- copying values is `O(n)`
- sorting the copied array with `qsort` is `O(n log n)`
- locating compressed indices is `O(n^2)` in the current implementation

#### Radix sort

Radix sort runs in:
```
O(n * k)
```
where:

`n` is the number of elements

`k` is the number of bits required to represent`n-1`

Since compressed values range from 0 to `n-1`, `k`is approximately:
```
log2(n)
```
---
### Test
Basic manual tests:
```
./push_swap
./push_swap 1 2 3
./push_swap 3 2 1
./push_swap 1 1 2
./push_swap 2147483648
./push_swap ""
./push_swap "   "
```

Example of checker usage:
```
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_OS $ARG
```
Expected result:

- `OK` if the instruction list sorts the stack correctly
- `KO` otherwise

Example of local tests:
```
make test100
make test500
```
These helper targets generate random inputs and measure the number of instructions produced.

---
## Resources

### Documentation
- The official 42 subject PDF

---
### Articles & Tutorials
- [C言語例文集 atol()](https://cgengo.sakura.ne.jp/atol.html)

---
### Use of AI
- Reviewing and structuring the README to ensure compliance with project requirements