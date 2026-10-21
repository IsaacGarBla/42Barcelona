#!/bin/bash

# Architecture
arch=$(uname -a)

# CPU physica
cpuf=$(grep "physical id" /proc/cpuinfo | wc -l)

# CPU  virtual
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# RAM
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# Disk
disk_total=$(df  -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf("%.2f"), disk_t/1024}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {printf("%.2f"), disk_u/1024}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} {disk_u += $3} END {printf("%.1f"), disk_u/disk_t*100}')

# CPU load
cpu_use=$(top -bn1 | grep "Cpu(s)" | awk -F '[ ,]+' '{print 100 - $8}')

# Last reboot
last_rebot=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# Is LVM
is_lvm=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo Yes; else echo No; fi)

# Active TCP connections
act_TCP_con=$(ss -ta | grep "ESTAB" | wc -l)

# Number of users
num_users=$(users | wc -w)

# IP Address
ip_add=$(hostname -I)

# Mac Address
mac_add=$(ip link | grep "link/ether" | awk '{print $2}')

# Number sudo commands
sudo_com=$(journalctl _COMM=sudo | grep "COMMAND" | wc -l)

wall "System status
===============
    #Architecture:   $arch
    #Physical CPUs:  $cpuf
    #Virtual CPUs:   $cpuv
    #Memory use:     $ram_use/${ram_total}Mb (${ram_percent}%) 
    #Disk use:       $disk_use/${disk_total}Gb ($disk_percent%)
    #CPU use:        $cpu_use%
    #Last boot:      $last_rebot
    #LVM active:     $is_lvm
    #TCP Connec.:    $act_TCP_con Established
    #USERS logged:   $num_users
    #IP Address:     $ip_add
    #MAC Address:    $mac_add
    #SUDO Commands:  $sudo_com commands"	

