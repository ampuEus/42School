# root, superusuario y sudo
***Versión en [español](5_Root_Superuser_Sudo.es.md)***

In computing, the **superuser** is a special user account used for system administration. It has all the rights in all modes and can do many things that a common user cannot (change the owner or permissions to files, install software, open ports...).

By convention, on most Linux systems, the **root** user is the default superuser name. Although, regardless of the name, what really tells if a user is superuser or not is that it has the** user ID** (uid) equal to **0**.

Using the root superuser for regular usage sessions is not recommended, as it puts the system at risk by giving privileged access to running programs. It is best to use a normal user account and switch to root with the `su` command to access your privileges if necessary. Although this can also be dangerous, since to change to the root user by executing `su root` you need to know the root password,furthermore, it is also possible to remain as the root user indefinitely and not only to execute the specific command that was needed.

To fix this, there are programs like **sudo** (**s**uper-**u**ser **do**). This program allows executing certain commands as root in normal users' own sessions (who have permission to execute `sudo`). In this way it is not necessary that each user must have the password of the root user since the sudo utility only asks for the user's own password. Also, sudo logs all executed `sudo` commands as a security measure.
