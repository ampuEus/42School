# Get Next Line (gnl) : Reading a line from a fd is way too tedious
***Officially finished at 2022-08-xx / Grade: xxx of 100 / Versión en [español](LEEME.md)***

The goal of this project is to write a function that returns a line read from a file descriptor without losing track of the next line and with a random buffer size.

## Table of content
***TODO***

## Exercise Requirements
- The way to read the content of a file must be by extracting a line in each execution of the program with successive calls to it
- Must return the content of the read line followed by the newline character ('\n'), unless it is at the end of the file and does not end with a newline
- Must return NULL when there is nothing to read or on error
- (Bonus) You must read from a file or from standard input
- (Bonus) The program can only have a single static variable
-
## Basic concepts to internalize in this practice
### Static variables
A local variable at the time the subroutine/function in which it was declared ends is dereferenced from the stack and removed from memory.
On the other hand, a static variable persists until the end of the program, regardless of where it was declared (they are comparable to global variables, although with some differences).

![Memory scheme](annex/MemoryAllocationDiagram.png)

> NOTE: Arrays in C are stored in the Stack, not in the Heap. Although they are equivalent to a pointer + malloc.

Here is an example of how a local static variable does not lose its memory no matter how many times the function in which it was declared is called:

```c
#include <stdio.h>

void foo(void)
{
	static int	x; // Static variable declaration
	// NOTE: Its default value is 0

	printf("x = %d", x);
	x++;
}
int main(void)
{
	int count;

	count = 0;
	while (count <= 10)
	{
		foo();
		count++;
	}
	return (0);
}
// Here, once the program ends, is when the static variable ceases to "exist"
```

Output:
```c
x = 0
x = 1
x = 2
x = 3
x = 4
x = 5
x = 6
x = 7
x = 8
x = 9
x = 10
```

Looking at the get next line practice, once the characters read from the buffer are loaded into the static variable and it is seen that there is no line break (`\n`) and also the reading of the file has not been completed, there is to keep saving in this variable the things read from `read` until it finds a `\n`. For later, remove the characters before the line break and continue saving the rest in the static variable.

### File Descriptors (*fd*) + open and close a file
To manipulate a file in C you have to tell the operating system where the information in the file is going to come from, this is where the file descriptor comes in. On Unix-based operating systems, the file descriptor is a unique identifier for a file or other input/output resource.

There are three standard descriptors, each related to the three standard data streams:

| Integer value |       Name       |   Symbolic constant   |     File Sequence     |
|:-------------:|:----------------:|:---------------------:|:---------------------:|
| 0             | Standard input   | STDIN_FILENO          | stdin                 |
| 1             | Standard output  | STDOUT_FILENO         | stdout                |
| 2             | Standard error   | STDERR_FILENO         | stderr                |

Knowing this, in order to open the file you want to read you will need to use the `open` function form `fcntl.h` library, its operation is as follows:

```c
// Propotype:
int open(const char *direccion_archivo, int flags);

// Flags types:
flags1 = open("archivo.txt", O_RDONLY); // read only
flags2 = open("archivo.txt", O_WRONLY); // write only
flags3 = open("archivo.txt", O_RDWR);   // read and write
```

The return value is a file descriptor is a reference to the file passed to it. Furthermore, `open` can return −1 indicating a failure with `errno` detailing the error.

Finally, when you're done manipulating the file, you have to dereference the file descriptor with the `unistd.h` library's `close` function.

This is an example of how to open and close a file correctly:

```c
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

// Open the file and assign the file descriptor
// returned to the variable fd for later use:
	fd = open("fichier.txt", O_RDONLY);
// Check that it has been opened correctly:
	if (fd == -1)
		return (-1);

//	[...]

// Finally close the file with the reference of its fd:
	close(fd);
	return (0);
}
```

### Read from a file
The `read` function, from the `unistd.h` library, loads the contents of a file into memory, in whole or in part (depends on buffer size), using a file descriptor.

```c
ssize_t read(int fd, void *buf, size_t count);
             └─┬──┘  └───┬───┘  └─────┬────┘
               │         │            └─────> Number of characters to read
               │         └─────> Pointer to a memory area where to temporarily store the characters that are read
               └─────> This is fd that is returned from open function
```

The result of `read` is the characters it has read, using *-1* as a warning of some error in the read.

**IMPORTANT:** `read` stops reading when it reaches the given number of characters, or at the end of file (EOF). And it will remember the position of the last character read, so if it is called again later with the same file descriptor, it will resume reading where it left off, or stay at the end of the file if it had already finished reading it.

In the case of the get next line, the *fd* is one of the variables to be passed to the function and *count* is defined by the value of *BUFFER_SIZE* which must be set at compilation time.

### What is a buffer + BUFFER_SIZE
In the case of software, a buffer is an area of data shared by program processes running at different speeds. The buffer allows each process to run without being stopped by the other. Like a cache, a buffer is a "midpoint waiting place", but it exists not so much to speed up the speed of an activity as to support the coordination of separate activities.

For a buffer to be effective, you must consider the size of the buffer and the algorithms for moving data in and out of the buffer.

Example of a 16-byte buffer working:

![Circular buffer animation](annex/Circular_Buffer_Animation.gif)

The get next line requests that the buffer size be defined in the `BUFFER_SIZE` variable at compile time (using the `-D` flags) so that it can be easily changed. And to prevent yourself in case the user does not define it when compiling, it is recommended to set a default value in the header of the get next line:

```c
# ifndef BUFFER_SIZE		// If BUFFER_SIZE is not defined
#  define BUFFER_SIZE 64	// Give it a default value
# endif
```

NOTE: Depending on the size of the buffer when using `read` it is likely that you will fall short and not find an end of line and have to save that information from the buffer, and re-execute `read` until you find a line break. Normally you go overboard from `\n` and you have to save the characters after the line break in the static variable, because when you run `read` again it will read from where it left off and the buffer will be overwritten again.


## How I have organized the goals of this exercise
### [main](src/main.c) which opens and closes a test file to pass to the get_next_line
***TODO***

### Function to read from a file descriptor
Inside [get_next_line.c](src/get_next_line.c) is the `gnl_read` function which has a read loop that stops when `read` returns 0, i.e. the end of the file has been reached and there is nothing left more to read. And inside the loop it does the following:

   1. Read from file descriptor
   2. If the read returns -1, it means there was an error, and exit the loop
   3. Add the data read from the buffer to the static variable
   5. Checks for a line break, to see if an entire line has already been read, and if so stops the loop.

### Get a line out of the static variable and save the extra characters read
Inside [get_next_line.c](src/get_next_line.c) is the function `split_new_line` which is only called if it is known that there is a newline in the static variable or that there is nothing left to read from the file. And what is done in this function is to take the characters until the line break (to get the line) that must be returned in the `get_next_line` function:

  1. Count the number of characters including the line break, if it exist
  2. Mallocs a string of the counted size (+ 1 for the final \0)
  3. Copy the characters up to \n or \0 and add the final \0

If the end of the file has been reached, the line is returned directly. If not, you have to reset the static variable saving only the characters after the line break:

  1. Copy the static variable to a helper variable
  2. Measure the size of the string in the static variable, minus the number of characters up to the line break (this one included) (+ 1 for the final \0)
  3. The static variable is rescaled with this new size
  4. And the data of the auxiliary variable is copied from the line break to the end
  5. Return the line

### Put everything together in the get_next_line function
From the [`get_next_line`](src/get_next_line.c) function:

- Declare the static variable
- It is verified that the fd and the BUFFER_SIZE are correct
- Coordinate the other functions
   - Call the read function
   - If something has been read, a line is taken from the static variable
   - If in future calls to `get_next_line` nothing has been read, but the static variable is not null or not empty, a line is taken from the static variable again
  - If the line to return is null or empty, any allocated memory is freed and pointed to NULL,
  - The value of the line is returned

### (Bonus) Read from more than one *fd*
***TODO***

## Typical troubleshooting
### The definition of the buffer and its size: **Stack Overflow**
#### What is Stack Overflow?
To understand this error, it is necessary to know that *stack* memory is limited depending on the language/compiler being used, although in various languages/compilers the requested size can be set to custom value.

Usually the defaults (if not manually configures) are about 1 MB for current languages, which is plenty unless you do something that's not generally recommended (like allocating huge arrays on the stack).

Knowing this, it can already be intuited that this error occurs when the limit established in the stack is exceeded.

One of the solutions, is to use heap memory instead which has a much higher limit (depending on how much RAM the PC has).

#### Two ways to declare the buffer: Array VS malloc()
<table>
    <thead>
        <tr>
            <th>Array form (stored on stack)</th>
            <th>With Malloc (it is saved in the heap)</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><pre lang="c">
char	buffer[BUFFER_SIZE + 1];
<br>
reader = read(fd, buffer, BUFFER_SIZE);</pre></td>
            <td><pre lang="c">
char	*buffer;
<br>
buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
if (!buffer)
	return (NULL);
reader = read(fd, buffer, BUFFER_SIZE);
<br>
/* [some code] */
<br>
free(buffer);</pre></td>
        </tr>
        <tr>
        	<td>Although this way is much simpler, since the stack is limited (and the idea of this practice is not to modify that limit) the only way to solve is to limit the maximum size of the buffer to a value that the stack can handle by introducing the following code in the header.
			<pre lang="c">
# if BUFFER_SIZE > 8000000		// If the buffer size is too large
#  undef BUFFER_SIZE			// the value is deleted
#  define BUFFER_SIZE 8000000	// and resizes to something manageable
# endif</pre></td>
        	<td>This other option, which I recommend, although a little more complex, avoids having to limit the size of the buffer and thus do the practice in the most orthodox way possible.</td>
        </tr>
    </tbody>
</table>

#### What if the BUFFER_SIZE is not defined when compiling?
One way to protect the program if the BUFFER_SIZE value is not defined at compile time, can be to enter the following code in the [header](src/get_next_line.h) to define a default value:

```c
# ifndef BUFFER_SIZE		// If BUFFER_SIZE is not defined
#  define BUFFER_SIZE 64	// Give it a default value
# endif
```

### Bad liberalization / memory management
As you can already guess from the statement of the practice, it is likely that in this practice some variables will have to be released in a loop, or without knowing if the variable to be released is *mallocated* or not. This can lead to typical errors such as double releases, failed releases, or attempted releases of unassigned strings. In this sense, the best tools to combat this problem are the compilation flag `-fsanitize=address` and `Valgrind`. Although depending on the operating system you are on, these two tools have more or less features:

| OS        | -fsanitize=address                                                           | Valgrind                                                   |
|-----------|------------------------------------------------------------------------------|------------------------------------------------------------|
| GNU/Linux | Detect where `segmentation fault` occurs, as well as memory errors           | For our level it does more or less the same as -fanitize   |
| MacOS     | Detect where `segmentation fault` occurs                                     | Detect memory errors                                       |

> Some types of memory errors:
>- `detected memory leaks`: No memory release (`free()`)
>- `heap-use-after-free`: Use a variable after being freed without having memory allocated for it
>- `stack-buffer-overflow`, `heap-buffer-overflow`, or `global-buffer-overflow`: When more memory than available has been allocated

One way to avoid the **double-free** error is that when you want to reuse an already freed memory variable, before mallocing it again to allocate memory, point it to `NULL`. This can be especially useful with global or static variables.

```c
void	foo(void)
{
	static char	*mem;

	mem = malloc ((SIZE + 1) * sizeof(*mem));
	if (!mem)
		return (NULL);

	/* code */

	free(*mem);
	*mem = NULL;

	/* more code */

	mem = malloc ((SIZE + 1) * sizeof(*mem));
	if (!mem)
		return (NULL);
}
```

---
Made by daampuru | LinkedIn: [David Ampurua](www.linkedin.com/in/david-ampurua)
