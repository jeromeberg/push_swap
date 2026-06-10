# libft

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)
![Grade: 125%](https://img.shields.io/badge/Grade-125%25-brightgreen?style=for-the-badge)

Reimplementation of standard C library (libc) functions from scratch and additional useful functions for string manipulation, memory and linked lists into our own library.

## Functions

### Char

| Function | Description |
|---|---|
| `ft_isalpha` | Check if character is alphabetic |
| `ft_isdigit` | Check if character is a digit |
| `ft_isalnum` | Check if character is alphanumeric |
| `ft_isascii` | Check if character is ASCII |
| `ft_isprint` | Check if character is printable |
| `ft_toupper` | Convert character to uppercase |
| `ft_tolower` | Convert character to lowercase |

### String

| Function | Description |
|---|---|
| `ft_strlen` | Get string length |
| `ft_strlcpy` | Size-bounded string copy |
| `ft_strlcat` | Size-bounded string concatenation |
| `ft_strchr` | Locate character in string |
| `ft_strrchr` | Locate character in string (reverse) |
| `ft_strncmp` | Compare two strings (n bytes) |
| `ft_strnstr` | Locate substring in string |
| `ft_strdup` | Duplicate a string |
| `ft_substr` | Extract substring |
| `ft_strjoin` | Concatenate two strings |
| `ft_strtrim` | Trim characters from string |
| `ft_split` | Split string by delimiter |
| `ft_strmapi` | Apply function to each character |
| `ft_striteri` | Apply function to each character (index) |

### Memory

| Function | Description |
|---|---|
| `ft_memset` | Fill memory with a constant byte |
| `ft_bzero` | Zero out memory |
| `ft_memcpy` | Copy memory area |
| `ft_memmove` | Move memory area |
| `ft_memchr` | Locate byte in memory |
| `ft_memcmp` | Compare memory areas |
| `ft_calloc` | Allocate and zero memory |

### Numbers

| Function | Description |
|---|---|
| `ft_atoi` | Convert string to integer |
| `ft_itoa` | Convert integer to string |

### File descriptor

| Function | Description |
|---|---|
| `ft_putchar_fd` | Write character to file descriptor |
| `ft_putstr_fd` | Write string to file descriptor |
| `ft_putendl_fd` | Write string with newline to fd |
| `ft_putnbr_fd` | Write integer to file descriptor |

### Linked lists (bonus)

| Function | Description |
|---|---|
| `ft_lstnew` | Create new list node |
| `ft_lstadd_front` | Add node at front of list |
| `ft_lstsize` | Count nodes in list |
| `ft_lstlast` | Get last node |
| `ft_lstadd_back` | Add node at back of list |
| `ft_lstdelone` | Delete a node |
| `ft_lstclear` | Delete and free list |
| `ft_lstiter` | Iterate over list |
| `ft_lstmap` | Map function over list |

## Build

```bash
make          # build libft.a
make bonus    # build with bonus
make clean    # remove object files
make fclean   # remove object files and libft.a
make re       # fclean + make
```

## Usage

Example:
```c
// main.c
#include "libft.h"

int main(void)
{
    char *s = ft_strjoin("Hello, ", "world!");
    ft_putendl_fd(s, 1);
    free(s);
}
```

`cc main.c -Wall -Wextra -Werror -L. -lft -o main`
