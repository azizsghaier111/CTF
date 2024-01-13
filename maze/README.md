
# Maze Attack demo

## Overview

This challenge showcases a file race attack, a technique that exploits timing vulnerabilities in software to gain unauthorized access to files or execute privileged operations. Use it for educational or research purposes in controlled environments with explicit permission.

## Ethical Considerations

Do not attempt to exploit file race conditions in real-world systems without authorization.
Understand the potential risks and consequences of such actions.

## Files:

`suid_cat.c`: C code for the vulnerable program 
`maze.sh`: Script to create the directory maze 
`attack.sh`: Script to execute the attack 
`flag`: File containing the sensitive information (replace with a placeholder for ethical use) 



## Create the [maze](maze.sh) structure:

```Bash
cd ~
./maze.sh
```
Utilisez le code avec précaution.
Run the [attack](attack.sh):
firstly add the executable mode to reset and attack : 
```bash
chmod +x attack.sh
chmod +x reset.sh
```
Open two terminal windows.
In terminal 1, run:
```Bash
.~/suid_cat entry/lnk/lnk/lnk/lnk/lnk/lnk/lnk/lnk/lnk/lnk/lnk/lnk/lnk/lnk/lnk/lnk/lnk/lnk
```

Immediately in terminal 2, run:
```Bash
./attack.sh
```


in case the attack doesn't successded you can run the [reset](reset.sh) script
```bash
./reset.sh
```

## Understanding the Attack

File Race Condition: The vulnerability in suid_cat arises because it uses access() to check file permissions before opening the file, but it doesn't guarantee that the file won't change between the check and the opening.
Attack Mechanism: The attack script exploits this timing window by replacing a link in the maze with a link to the "flag" file, tricking suid_cat into reading the flag due to its elevated privileges.
