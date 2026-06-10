# push_swap

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)
![Grade: 100%](https://img.shields.io/badge/Grade-100%25-brightgreen?style=for-the-badge)

An implementation in C of a sorting algorithm using a limited set of operations (swap, push, rotate).

## Implementation

This algorithm uses a cost-based strategy and hardcoded operations for very small inputs: at each reinsertion step, a cost is computed for each possible move (rotations needed in a + rotations needed in b), and the cheapest move is executed.

- 2 to 3 numbers: sort with hardcoded minimal operations.
- 5 numbers: push the smallest values to stack b, sort the 3 remaining values in stack a, then push them back.
- Larger inputs: push from stack a to stack b until only 3 values remain in a, sort those 3, then reinsert values from b to a.

## Subject

> You have 2 stacks named a and b.
> The goal is to sort numbers in ascending order into stack a using the fewest possible operations.
> To do so, you have the following operations at your disposal:

- `sa`: Swap the first 2 elements at the top of stack a.
- `sb`: Swap the first 2 elements at the top of stack b.
- `ss`: `sa` and `sb` at the same time.
- `pa`: Take the first element at the top of b and put it at the top of a.
- `pb`: Take the first element at the top of a and put it at the top of b.
- `ra`: Shift up all elements of stack a by 1.
- `rb`: Shift up all elements of stack b by 1.
- `rr`: `ra` and `rb` at the same time.
- `rra`: Shift down all elements of stack a by 1.
- `rrb`: Shift down all elements of stack b by 1.
- `rrr`: `rra` and `rrb` at the same time.

## Instructions

### Prerequisites

- make
- cc

### Quick start

```bash
# compile
make

# sort
./push_swap 360 26 18 7 120
```

### Use

Generate a large list of random integers with `jot` or `shuf`.

```bash
# macOS
ARGS=$(jot -r 100 -5000 5000 | tr '\n' ' ')
./push_swap $ARGS


# linux
ARGS=$(shuf -i -5000-5000 -n 100 | tr '\n' ' ')
./push_swap $ARGS
```

### Commands

```bash
make        # compile
make clean  # remove objects
make fclean # remove objects and executable
make re     # clean and recompile
```
