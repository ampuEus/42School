# Partitions, LVM and Encryption
## Why Have Several Partitions?
From the point of view of operation, it is indifferent to have all the data in a single partition or in several. What is achieved by segmenting the information is to protect yourself from corruption of the partition since, if you have one partition for each thing, although one stops working, you can still recover the data from the rest of the partitions and the damage is lower.
Partitions to do the mandatory part:
- **boot**. Static files of boot loader are located here
- **root**. Is the home directory for the root user
- **home**. Here are the directories of the rest of the users
- [**swap**](https://wiki.debian.org/Swap). It is a special partition that is essentially a memory add-on to the computer's RAM

Partitions to do the bonus part:
- **var**. Storage variable data
- **srv**. Storage data for services provided by the system
- **tmp**. It is the directory for temporary files
- **var/log**. Inside the var directory there is this folder where the logs are saved

[Here](https://www.debian.org/releases/bullseye/amd64/apcs02.en.html) you can learn a little bit more about Debian directory tree.

## What is [LVM](https://wiki.debian.org/LVM)?
The **Logical Volume Manager** (LVM) is a flexible and dynamic management system for Linux hard disk memory. It allows us to have as many partitions as necessary, and to resize, move and even freeze them, without having to restart the machine. This “virtual partitioning” system is very useful on a server, which must preserve stability and rapid management of its memory resources.
