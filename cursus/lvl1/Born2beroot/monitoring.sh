#!/bin/bash

arch=$(uname -srvmo)
corePhisycal=$(grep 'physical id' /proc/cpuinfo | uniq | wc -l)
coreVirtual=$(grep processor /proc/cpuinfo | uniq | wc -l)
ramTot=$(free -h | grep Mem | awk '{print $2}')
ramUsed=$(free -h | grep Mem | awk '{print $3}')
ramPercent=$(free -k | grep Mem | awk '{printf("%.2f%%"), $3 / $2 * 100}')
diskTot=$(df -h --total | grep total | awk '{print $2}')
diskUsed=$(df -h --total | grep total | awk '{print $3}')
diskPercent=$(df -k --total | grep total | awk '{print $5}')
CpuLoad=$(top -bn1 | grep '^%Cpu' | xargs | awk '{printf("%.1f%%"), $2 + $4}')
lastBoot=$(who -b | awk '{print($3 " " $4)}')
isLVM=$(if [ $(lsblk | grep lvm | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
actualTcp=$(grep TCP /proc/net/sockstat | awk '{print $3}')
actualUsers=$(who | wc -l)
IpAddr=$(hostname -I | awk '{print $1}')
MacAddr=$(ip link show | grep link/ether | awk '{print $2}')
sudoLog=$(grep COMMAND /var/log/sudo/sudo.log | wc -l)

wall "
       Architecture    : $arch
       Physical Cores  : $corePhisycal
       Virtual Cores   : $coreVirtual
       Memory Usage    : $ramUsed/$ramTot ($ramPercent)
       Disk Usage      : $diskUsed/$diskTot ($diskPercent)
       CPU Load        : $CpuLoad
       Last Boot       : $lastBoot
       LVM use         : $isLVM
       TCP Connections : $actualTcp established
       Users logged    : $actualUsers
       Network         : IP $IpAddr ($MacAddr)
       Sudo            : $sudoLog commands logged
	   "
