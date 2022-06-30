# Born2beroot
***Officially finished at 2022-xx-xx / Grade: xxx of 100 / Versión en [español](LEEME.md)***

This practice is an introduction to systems administration. In this internship you have learned the principles of:

- The creation of **virtual machines**
- **OS installation** with strict encryption and partitioning rules
- **Security**. Implementation of sudo, a firewall and a strong password policy
- **Remote access**. Implementing an SSH server
- **User Management**. Working with users, groups and their privileges
- **Monitoring**. Knowing how to extract information from the machine (available RAM, number of active connections, commands executed through sudo...)

## Software used[^1]
- VM: [VirtualBox](https://www.virtualbox.org/) 6.1
- OS: [Debian](https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/) bullseye 11.3.0 ([Debian vs CentOS](annex/1_Debian_VS_CentOS.en.md))

## 1. CREATE THE [VIRTUAL MACHINE](annex/2_What_is_a_VM.md)
At the top of the VirtualBox main window, click on **New** to start.
![VirtualBox image](img/1_StartWindow.png)

Put a name to the machine, decide where to install it and specifies which linux is going to be on the VM (in my case Debian). If you are using 42 computers because space reasons, you should create the virtual machine in the **/sgoinfre/goinfre/Perso/your_42_login**. Otherwise, you can put it on a large enough USB or an external hard drive.

![VirtualBox image](img/2_CfgPage1.png)

As programs that are going to consume a lot of RAM are not going to be installed, such as the graphical environment or other types of utilities that are running in the background, the default **1024MB is enough**, but to make sure **I have doubled it to 2GB**.

![VirtualBox image](img/3_CfgPage2.png)

Now you must choose the option to **create a new virtual hard disk**.

![VirtualBox image](img/4_CfgPage3.png)

Here the default partition of VirtualBox, **VirtualBox Disk Image**, will be left.

![VirtualBox image](img/5_CfgPage4.png)

The default option of letting the hard drive be **dynamically allocated** is fine.

![VirtualBox image](img/6_CfgPage5.png)

For the size of the hard drive, **12 GB is enough** for both the mandatory and additional parts. Note that the larger the disk size, the longer it will take to create the signature, which is not convenient for Born2beroot evaluation.

![VirtualBox image](img/7_CfgPage6.png)

End, Born2beroot virtual machine has been created.

![VirtualBox image](img/8_VMcreationEnd.png)

## INSTALLING DEBIAN ON VM
Before running the virtual machine, as it does not have any operating system, you have to assign the OS .iso that you have downloaded to be able to boot from it.

|![VirtualBox image](img/9_BootISO1.png)|![VirtualBox image](img/10_BootISO2.png)|![VirtualBox image](img/11_BootISO3.png)|
|-|-|-|

Once this is done, when you start the VM, the Debian installation menu appears with different options. You are interested in one of the first 2: Graphical install or Install. Both are used to install the OS, the difference between them is that the first one has a simpler graphical interface. In this case, the “**Install**” option will always be used, although the way to proceed is very similar in either of the 2 options.

![VirtualBox image](img/12_InstalationMenu.png)

The first step is to choose the installation language that you want, in my case I will leave it in **English**.

![VirtualBox image](img/13_InstalationCfg1.png)

Then it's time to choose your geographical region (for issues related to the time zone, number formats, text...). **For the purpose of this exercise it is indifferent**.

![VirtualBox image](img/14_InstalationCfg2.png)

Now you must choose the keyboard layout you want to use [more info](https://en.wikipedia.org/wiki/Keyboard_layout), in my case, I use a keyboard based on the Spanish layout.

![VirtualBox image](img/15_InstalationCfg3.png)

Regarding the hostname of the machine, the exercise specifies that the name must be composed of **your intra login followed by 42**.

![VirtualBox image](img/16_InstalationCfg4.png)

The domain name does not need to be configured in this practice, so **leave it blank**.

![VirtualBox image](img/17_InstalationCfg5.png)

For the password of the root user, you have to define a strong password following the rules that the statement of this exercise establishes.

![VirtualBox image](img/18_InstalationCfg6.png)

Once the administrator is configured, it is time to create a user. The name, it is recommended that it be your intra login, since it is the user that is going to be evaluated, and the password that has to follow the same rules as the root password.

|![VirtualBox image](img/19_InstalationCfg7.png)|![VirtualBox image](img/20_InstalationCfg8.png)|![VirtualBox image](img/21_InstalationCfg9.png)|
|-|-|-|

### MANUAL PARTITIONING
Now it's time to partition the disk. Although the installer has different options, the partitions that are requested in the mandatory part and in the bonus force you to use the **manual mode**, [more information about partitions, LVM and encryption](annex/3_Partitions_LVM_Encryption.md).

![VirtualBox image](img/22_InstalationCfg10.png)

Now you have to choose the disk where the partitions are going to be created (there should only be one called “**SCSIX (0,0,0) (sda) - […] HARDDISK**”). You will have to create 2 partitions, one for the boot loader and another encrypted partition where the LVM volumes will be.

|![VirtualBox image](img/23_InstalationCfg11.png)|![VirtualBox image](img/24_InstalationCfg12.png)|
|-|-|

In the next step you will be shown the new partition table created where you have to do the segmentation you want. The first partition to be created will be the boot partition, which should NOT be encrypted, otherwise the OS would not even boot. Select the **free space** of the disk.

![VirtualBox image](img/25_InstalationCfg13.png)

**Create a new partition**.

![VirtualBox image](img/26_InstalationCfg14.png)

A space of **500 MB** should be enough.

![VirtualBox image](img/27_InstalationCfg15.png)

The partition must be of type **primary**.

![VirtualBox image](img/28_InstalationCfg16.png)

And, the boot, it is recommended to create it at the **beginning**.

![VirtualBox image](img/29_InstalationCfg17.png)

Now you have to say what the partition is going to be used for, in this case it will be **mounted** as **/boot**.

|![VirtualBox image](img/30_InstalationCfg18.png)|![VirtualBox image](img/31_InstalationCfg19.png)|
|-|-|

Finally, click on **done**. And you have now created the boot partition.

![VirtualBox image](img/32_InstalationCfg20.png)

Now it's time to create the LVM partition where all the other volumes will be. So, select the remaining **free space and create a new partition**.

|![VirtualBox image](img/33_InstalationCfg21.png)|![VirtualBox image](img/34_InstalationCfg22.png)|
|-|-|

For the size, select the remaining space.

![VirtualBox image](img/35_InstalationCfg23.png)

This time it will be **logical**.

![VirtualBox image](img/36_InstalationCfg24.png)

And for the mount point you **don't** have to **define anything** and hit **done**. Later you will return to this partition, and you will modify it to comply with the volumes required by the statement.

|![VirtualBox image](img/37_InstalationCfg25.png)|![VirtualBox image](img/38_InstalationCfg26.png)|![VirtualBox image](img/39_InstalationCfg27.png)|
|-|-|-|

### ENCRYPTING THE PARTITION
After creating the partition for the LVM, it is time to encrypt it, for this go to configure encrypted volumes.

![VirtualBox image](img/40_InstalationCfg28.png)

If you have two partitions as it appears in the image, click **yes**.

![VirtualBox image](img/41_InstalationCfg29.png)

And start **encrypting the partitions**, don't forget that the partition containing the boot doesn't have to be encrypted.

![VirtualBox image](img/42_InstalationCfg30.png)

**Select** (select that disk and press space) the partition for **LVM** and **continue**.

![VirtualBox image](img/43_InstalationCfg31.png)

Then click **done, finish** and **yes**. And wait for the encryption process to finish.

|![VirtualBox image](img/44_InstalationCfg32.png)|![VirtualBox image](img/45_InstalationCfg33.png)|![VirtualBox image](img/46_InstalationCfg34.png)|
|-|-|-|

Once the installer finishes encrypting the data on the partition, you **must choose a decryption password**. This password must be strong, and you cannot forget it, otherwise you will not be able to access the Born2beroot machine.

![VirtualBox image](img/47_InstalationCfg35.png)

### CONFIGURING LVM
#### Logical volume group creation
It is time to create the logical volumes that the exercise asks inside the encrypted partition.

|![VirtualBox image](img/48_InstalationCfg36.png)|![VirtualBox image](img/49_InstalationCfg37.png)|
|-|-|

In order for LVM to be able to manage logical volumes, first a volume group must be created.

![VirtualBox image](img/50_InstalationCfg38.png)

Now you must **assign a name to the group**, in my case I will use the same one that is used in the statement of the exercise “LVMGroup”.

![VirtualBox image](img/51_InstalationCfg39.png)

Lastly, **select ONLY** the **partition** you have **encrypted** to the group, DO NOT assign the boot partition.

![VirtualBox image](img/52_InstalationCfg40.png)

#### Create Logical Volumes
Now that you have the volume group created and the encrypted logical partition assigned to it, you need to create the logical volumes one by one. As an example, I will make the root, which must be present for both the mandatory and bonus parts. To do this go to **create Logical Volume**.

![VirtualBox image](img/53_InstalationCfg41.png)

Select the group **where** you are going to **host the partition**.

![VirtualBox image](img/54_InstalationCfg42.png)

And give it a **name** and **disk space**. In my case I will call it "root" and a size of 3GB should be enough to complete the objectives of the practice.

|![VirtualBox image](img/55_InstalationCfg43.png)|![VirtualBox image](img/56_InstalationCfg44.png)|
|-|-|

Your first partition has already been created. Now you just must repeat the process…

1. Create a logical volume
2. Choose the group
3. Give it a name
4. Assign a disk space (below you have a screenshot of how I have organized the sizes of the different partitions[^2])

…until you have all the partitions that the exercise asks for (I recommend you also do the ones in the bonus part), when you have finished partitioning click finish.

![VirtualBox image](img/57_InstalationCfg45.png)

#### Configuring Logical Volumes
Once the volumes have been created, it is time to assign them a “task” within the OS. So that, in this case Debian, can use them accordingly. To do this you have to specify the file system and mount point for each volume.

As an example, I will again use the root partition.

![VirtualBox image](img/58_InstalationCfg46.png)

As I want to tell the OS how to use the partition, I will click on **use as:..**

![VirtualBox image](img/59_InstalationCfg47.png)

I select **Ext4 journaling file system**.

![VirtualBox image](img/60_InstalationCfg48.png)

And as for the **mount point**, I choose the one that corresponds to the root partition.

|![VirtualBox image](img/61_InstalationCfg49.png)|![VirtualBox image](img/62_InstalationCfg50.png)|![VirtualBox image](img/63_InstalationCfg51.png)|
|-|-|-|

Now all you have to do is repeat the process again...

1. Choose a logical volume
2. Go to “use as”
3. Choose the Ext4 file system (except in swap, which you have to choose the “swap” file system and you don't have to select a mount point)
4. Select the mount point depending on the function that this partition is going to have (except for var-log that you have to put it manually in “/var/log”)

…until you have all the partitions that the exercise asks for, when you have finished partitioning, click **finish partitioning and write changes to disk**. Then click **yes**.

#### Debian base system installation
In this last step, the base system will be installed and for this, some parameters must be defined:
- When **scanning** click **no**
- For the Debian packages download server you have to choose a **country** (usually the closer the country to your location the better) and a **mirror**
- The **proxy** connection can be left **empty**
- And it is **not necessary** to participate in the **statistical study**

|![VirtualBox image](img/64_InstalationCfg52.png)|![VirtualBox image](img/65_InstalationCfg53.png)|![VirtualBox image](img/66_InstalationCfg54.png)|
|-|-|-|
|![VirtualBox image](img/67_InstalationCfg55.png)|![VirtualBox image](img/68_InstalationCfg56.png)|

For the selection of software, it is not necessary to put **any**, what is needed will be installed later. So, **uncheck all the boxes** by selecting them and pressing the space bar. Then hit continue.

![VirtualBox image](img/69_InstalationCfg57.png)

Click **yes** you want to install [GRUB](https://www.gnu.org/software/grub/)

![VirtualBox image](img/70_InstalationCfg58.png)

And it will be installed in “**/dev/sda**”

![VirtualBox image](img/71_InstalationCfg59.png)

END! You already have Debian installed on your VM.

![VirtualBox image](img/72_InstalationCfg60.png)

### LOGGING INTO Born2beroot
Ahora se reiniciará la VM. Al arrancar te pedirá la contraseña para descifrar la partición encriptada, y luego las credenciales del usuario que creaste al inicio del proceso de instalación.
Para verificar que la instalación es correcta, puedes probar algunos comandos:
- **cat /etc/os-release**. Para comprobar la información del sistema operativo
- **lsblk**. Para revisar nuestras particiones
- **apt –v**. Comprueba si el administrador de paquetes está instalado de forma predeterminada
- **date**. Para comprobar la zona horaria (Tiene que coincidir con el país que pusiste en la instalación). Aunque si es incorrecta, no es muy importante para Born2beroot.

![VirtualBox image](img/73_DebianInstalled.png)

## CONFIGURING A DEBIAN AS A SERVER
### sudo implementation
#### Installation
To install a program on the server you need to login as a root.



[^1]: These are the latest stable versions of the respective programs on the date this exercise is being carried out.

[^2]: If you give a very low value to “var” when installing the base system, it can give you problems.
