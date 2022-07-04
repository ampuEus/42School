# What is AppArmor?
AppArmor ("**App**lication **Armor**") is a Linux kernel security module that allows the system administrator to restrict the capabilities of a program. Each program has an associated profile that controls its ability to access the network, its read, write, and execute permissions, among other things. This profile can be created manually or automatically. It complements the traditional Unix Discretionary Access Control (DAC) model by providing **m**andatory **Mandatory Access Control (MAC) a**ccess **c**ontrol).

For example, one application that is restricted in Ubuntu's default settings is the Evince PDF viewer. Although Evince can run as your user account, it can only perform specific actions. Evince only has the minimum permissions necessary to run and work with PDF documents. If a vulnerability was discovered in Evince's PDF renderer and you opened a malicious PDF document that took over Evince, AppArmor would restrict the damage Evince could cause. In the traditional Linux security model, Evince would have access to everything that you have access to. With AppArmor, you only have access to the things that a PDF viewer needs to access.

[Here](https://wiki.debian.org/AppArmor/HowToUse) I leave you the official guide on how to use AppArmor from the Debian page.

## AppArmor vs SELinux
AppArmor is considered an alternative to SELinux, a similar program but more difficult to install and maintain.

Their biggest differences are:

- SELinux is aimed at protecting the entire system, all system objects (files, IPC objects, networks, ...). However AppArmor is only filesystem oriented.

- AppArmor implements a task-centric policy, which means that access control attributes are tied to tasks, and SELinux implements a system object-centric policy.

Both systems use the "deny by default" principle (all operations are denied unless specifically allowed by policy). However, each one applies it in a different way:

- AppArmor, by implementing a task-centric policy, only applies the principle for those tasks it controls.
- SELinux applies the principle in any case.

In general we can say that SELinux facilitates finer grade access control than AppArmor. On the other hand, AppArmor is easier to use than SELinux as the configuration is easier to perform (less extensive).
