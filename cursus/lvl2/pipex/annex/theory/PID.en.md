# What are PIDs and what are they for?
This section is dedicated to know how to manage the processes in a Unix system in a VERY VERY superficial way.

When a new process is created in a Unix system, it is **linked to an ID** (**id**entifier). **To **differentiate it and **manage** the **processes** running on the system, called PID (**p**rocess **ID**).
Apart from the PID, the process also has:
  - PPID (**P**arent **PID**). This is the PID of the process that created it (called *parent process*).
  - TTY (**T**ele **TY**pewriter). This is the ID of the terminal where the process was launched.
  - UID (**U**ser **ID**). This is the ID of the user who launched the process.
> NOTE:
>
> The first process running Linux is called `systemd` (its PID is 0). All other processes are spawned as children of `systemd`.
>
> When a process is missing the TTY, it is called *daemon*. A process running in the background that does not have a terminal to control it.

## Useful commands
To **view** them I recommend:
| ps | htop |
| ------------------ | -------------------------- |
| For simple things | More user-friendly and interactive | |
| ![Example of the execution of the "ps2" command](../img/ps_example.png) | ![Example of the execution of the "htop" command](../img/htop_example.png) | |

And to force **stop** a particular process you can use `kill`, although it is obviously not the most orthodox way to do it.
```shell
# You can use the PID of the process
sudo kill 668
# or you can kill all processes with the same name
$ sudo killall ps
```
Note that when a process terminates, it leaves the PID it was using free for another process to use. And it is possible that when that process runs again, it will have a different PID.

> NOTE: In linux it is good practice to use the `service` command for process management. For example `killall <process name>` = `service <process name> stop`.

## PID files
PID files are a way of letting other processes know what your current PID is.

Because in each run a process can have different PIDs, the PID files are created by the process writing inside it its current PID. Then the rest of the processes can read that file and relate the process and the PID.

> Normally these files are located in `/var/run/`.
