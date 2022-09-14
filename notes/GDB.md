Linux: gdb

MacOS: lldb

# Quick start
```c
// use -g on compilation
gcc -g example.c

// run gdb
gdb ./a.out
```
>On compilation time **-g** flas is neaded, it means you can see the proper names of variables and functions in your stack frames, get line numbers and see the source as you step around in the executable.


# Cheatsheet
| Comand      | Description                                               |
|-------------|-----------------------------------------------------------|
| b file.c:68 | add a breakpoint on line 68 of file.c                     |
| info b      | list all the breakpoints                                  |
| disable     | disable a breakpoint                                      |
| enable      | enable a disabled breakpoint                              |
| clear       | to clear all breakpoints                                  |
| run or r    | executes the program from start to end                    |
| next or n   | executes next line of code, but don’t dive into functions |
| continue    | continue normal execution                                 |
| step        | go to next instruction, diving into the function          |
| list or l   | displays the code                                         |
| print or p  | used to display the stored value                          |
| watch <var_name> | monitor one variable all the time                    |
| set <var_name> | change the value of variable in gdb and continue execution with changed value   |
| quit or q   | exits out of gdb                                          |
| layout src  | ---                                                       |

To log watches:
```c
(gdb) set logging file <filename>
(gdb) set logging on
```

