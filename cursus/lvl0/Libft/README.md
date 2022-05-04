# Libft: My first C library 
***Officially finished at 2022-xx-xx / Grade: xxx of 100 / Versión en [español](LEEME.md)***

This project is about programming a library in C. Many general purpose functions have been made on which future 42 school programs will be built.

## What is Libft?
Libft is a project for the recreation of some [C standards library](https://www.tutorialspoint.com/c_standard_library/index.html) ("libc.a") and some other that can be useful later to built programs easier and make your own library, learning along the way how that functions work by coding them from scratch.

## Quick start
```bash
# Clone the project and access the folder
git clone https://github.com/ampuEus/42School/tree/main/cursus/lvl0/Libft && cd Libft/

# Run Make so you can build the library
make

# Run Make with bonus if you want chained lists manipulation functions
make bonus

# Compile your main with the library, example:
clang main.c libft.a

# Execute your program
./a.out

# Clean output objects with
make fclean

# Well done!
```

## Pass testers
To pass tests first you have to download testers submodules with `git clone --recursive` command and then execute `make <tester name>`. For example:
```bash
git clone --recursive https://github.com/ampuEus/42School/tree/main/cursus/lvl0/Libft && cd Libft/
make libftTester
make fclean

# Tester passed
```
- Used testers
  - Tripouille/libftTester: https://github.com/Tripouille/libftTester

## Included functions
[Makefile](src/Makefile), [main.c](src/main.c), [libft.h](src/libft.h)

<table>
    <thead>
        <tr>
            <th colspan=2><h3>C Standard Library</h3></a></th>
        </tr>
        <tr>
            <th colspan=2><h4><a href="https://www.tutorialspoint.com/c_standard_library/ctype_h.htm">&lt;ctype.h&gt;</a>: Functions to check and manipulate characters</h4></th>
        </tr>
        <tr>
            <th>Name</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=src/ft_isalnum.c>ft_isalnum</a></td>
            <td>Checks whether the passed character is alphanumeric.</td>
        </tr>
        <tr>
            <td><a href=src/ft_isalpha.c>ft_isalpha</a></td>
            <td>Checks whether the passed character is alphabetic.</td>
        </tr>
        <tr>
            <td><a href=src/ft_isascii.c>ft_isascii</a></td>
            <td>Checks whether the passed character is ASCII.</td>
        </tr>
        <tr>
            <td><a href=src/ft_isdigit.c>ft_isdigit</a></td>
            <td>Checks whether the passed character is decimal digit.</td>
        </tr>
        <tr>
            <td><a href=src/ft_isprint.c>ft_isprint</a></td>
            <td>Checks whether the passed character is printable.</td>
        </tr>
        <tr>
            <td><a href=src/ft_tolower.c>ft_tolower</a></td>
            <td>Converts uppercase letters to lowercase.</td>
        </tr>
        <tr>
            <td><a href=src/ft_toupper.c>ft_toupper</a></td>
            <td>Converts lowercase letters to uppercase.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=2><h4><a href="https://www.tutorialspoint.com/c_standard_library/string_h.htm">&lt;string.h&gt;</a>: Functions to manipulate strings</h4></th>
        </tr>
        <tr>
            <th>Name</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=src/ft_bzero.c>ft_bzero</a></td>
            <td>Erases the data in the <i>n</i> bytes of the memory block. (Write zeroes)</td>
        </tr>
        <tr>
            <td><a href=src/ft_memchr.c>ft_memchr</a></td>
            <td>Searches for the first occurrence of the character <i>c</i> (an unsigned char) in the first <i>n</i> bytes of the string.</td>
        </tr>
        <tr>
            <td><a href=src/ft_memcmp.c>ft_memcmp</a></td>
            <td>Compares the first <i>n</i> bytes of <i>str1</i> and <i>str2</i>.</td>
        </tr>
        <tr>
            <td><a href=src/ft_memcpy.c>ft_memcpy</a></td>
            <td>Copies <i>n</i> characters from <i>src</i> to <i>dest</i>.</td>
        </tr>
        <tr>
            <td><a href=src/ft_memmove.c>ft_memmove</a></td>
            <td>Copies <i>n</i> characters from <i>src</i> to <i>dest</i>. (Non destructive manner)</td>
        </tr>
        <tr>
            <td><a href=src/ft_memset.c>ft_memset</a></td>
            <td>Copies the character <i>c</i> (an unsigned char) to the first <i>n</i> characters of the string.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strchr.c>ft_strchr</a></td>
            <td>Searches for the first occurrence of the character <i>c</i> (an unsigned char) in the string.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strlcat.c>ft_strlcat</a></td>
            <td>Appends string <i>src</i> to the end of <i>dst</i>. It will append at most <i>dstsize - strlen(dst) - 1</i> characters.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strlcpy.c>ft_strlcpy</a></td>
            <td>Copies up to <i>dstsize - 1</i> characters from the string <i>src</i> to <i>dst</i>.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strlen.c>ft_strlen</a></td>
            <td>Computes the length of the string but not including the terminating null character.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strncmp.c>ft_strncmp</a></td>
            <td>Compares at most the first <i>n</i> bytes of <i>str1</i> and <i>str2</i>.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strnstr.c>ft_strnstr</a></td>
            <td>Locates the first occurrence of the null-terminated string <i>little</i> in the string <i>big</i>, where not more than <i>len</i> characters are searched.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strrchr.c>ft_strrchr</a></td>
            <td>Searches for the last occurrence of the character <i>c</i> (an unsigned char) in the string.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=2><h4><a href="https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm">&lt;stdlib.h&gt;</a>: General propose functions</h4></th>
        </tr>
        <tr>
            <th>Name</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=src/ft_atoi.c>ft_atoi</a></td>
            <td>Converts the string to an integer (type int).</td>
        </tr>
        <tr>
            <td><a href=src/ft_calloc.c>ft_calloc</a></td>
            <td>Allocates the requested memory initialized to zero bytes.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=3><h4>Non-stantard C Library</h4></a></th>
        </tr>
        <tr>
            <th>Name</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=src/ft_itoa.c>ft_itoa</a></td>
            <td>Converts the int to a string (type char *).</td>
        </tr>
        <tr>
            <td><a href=src/ft_putchar_fd.c>ft_putchar_fd</a></td>
            <td>Outputs the character <i>c</i> to the given file descriptor.</td>
        </tr>
        <tr>
            <td><a href=src/ft_putendl_fd.c>ft_putendl_fd</a></td>
            <td>Outputs the string <i>s</i> to the given file descriptor, followed by a newline.</td>
        </tr>
        <tr>
            <td><a href=src/ft_putnbr_fd.c>ft_putnbr_fd</a></td>
            <td>Outputs the integer <i>n</i> to the given file descriptor.</td>
        </tr>
        <tr>
            <td><a href=src/ft_putstr_fd.c>ft_putstr_fd</a></td>
            <td>Outputs the string <i>s</i> to the given file descriptor.</td>
        </tr>
        <tr>
            <td><a href=src/ft_split.c>ft_split</a></td>
            <td>Allocates and returns an array of strings obtained by splitting <i>s</i> using the character <i>c</i> as a delimiter. The array must end with a NULL pointer.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strdup.c>ft_strdup</a></td>
            <td>Returns a pointer to a null-terminated byte string, which is a duplicate of the string.</td>
        </tr>
        <tr>
            <td><a href=src/ft_striteri.c>ft_striteri</a></td>
            <td>Applies a function to each character of the string.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strjoin.c>ft_strjoin</a></td>
            <td>Returns a new string, which is the result of the concatenation of <i>s1</i> and <i>s2</i>.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strmapi.c>ft_strmapi</a></td>
            <td>Applies a function to each character of the string <i>s</i> to create a new string.</td>
        </tr>
        <tr>
            <td><a href=src/ft_strtrim.c>ft_strtrim</a></td>
            <td>Returns a copy of <i>s1</i> with the characters specified in <i>set</i> removed from the beginning and the end of the string.</td>
        </tr>
        <tr>
            <td><a href=src/ft_substr.c>ft_substr</a></td>
            <td>Returns a substring from the string <i>s</i>. The substring begins at index <i>start</i> and is of maximum size <i>len</i>.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=2><h4>Chained lists manipulation</h4></a></th>
        </tr>
        <tr>
            <th>Name</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=src/ft_lstadd_back.c>ft_lstadd_back</a></td>
            <td>Adds the element at the end of the list.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstadd_front.c>ft_lstadd_front</a></td>
            <td>Adds the element at the beginning of the list.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstclear.c>ft_lstclear</a></td>
            <td>Deletes and frees the given element and every successor of that element, using a given function and <i>free()</i>.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstdelone.c>ft_lstdelone</a></td>
            <td>Takes as a parameter an element and frees the memory of the element’s content using a function given as a parameter and free the element.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstiter.c>ft_lstiter</a></td>
            <td>Iterates the list and applies a function to the content of each element.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstlast.c>ft_lstlast</a></td>
            <td>Returns the last element of the list.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstmap.c>ft_lstmap</a></td>
            <td>Iterates the list and applies a function to the content of each element. Creates a new list resulting of the successive applications of the function. A <i>del</i> function is used to delete the content of an element if needed.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstnew.c>ft_lstnew</a></td>
            <td>Returns a new element.</td>
        </tr>
        <tr>
            <td><a href=src/ft_lstsize.c>ft_lstsize</a></td>
            <td>Counts the number of elements in a list.</td>
        </tr>
    </tbody>
</table>

## References
 - Open C Standard Libraries (Libc.a)
    - https://www.gnu.org/software/libc/documentation.html
    - https://rootdirectory.de/doku.php?id=pdclib:start
    - https://www.tutorialspoint.com/c_standard_library/index.html
 - How to make a Makefile
    - https://makefiletutorial.com/
    - https://www.gnu.org/software/make/manual/make.html
 - Information about static libraries
    - https://medium.com/@meghamohan/all-about-static-libraries-in-c-cea57990c495

## Useful repositories from other students
- https://github.com/wwwwelton/libft

- https://github.com/mcombeau/libft


## Updating
As this the base library for all the course in 42 School it will be updating regularly. See "[src/extra](src/extra)" file.

---
Made by daampuru | LinkedIn: [David Ampurua](www.linkedin.com/in/david-ampurua)
