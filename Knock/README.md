

# Knock Knock Challenge

## Introduction
This challenge involves simulating interaction with a secret server through TCP and UDP communication. The goal is to brute force UDP ports to gain access to the server by exploiting vulnerabilities.

## Setup
1. Open two terminals. in the second terminal: 
```bash
vi attack 

```
and put this "nc -uv -w 0 127.0.0.1 1024-10000"
2. In the first terminal, initiate TCP communication with the service on port 9999 using the following command:

``` bash 
nc 127.0.0.1 9999 
```

3. Run the bruteforce.py script and input your username and the received nonce when prompted.
4. Wait until a valid result is found. The result should be in the format: `username-nonce-randombyte`.

## Obtaining Valid Ports
1. When a valid port is found during the attack, add it to the top of the attack file as a fixed port.
For example, if the port 55555 is found to be valid, add the following line to the attack file:
nc -uv -w 0 127.0.0.1 55555

2. Adjust the range of ports in the attack script to cover all specific ports. Iterate through ports from 1024 to 65535.

## Conclusion
Repeat the brute force attack process until three specific valid ports are found. These ports will provide access to the secret server.

when finding all the target ports you will see the flag in the firt terminal 


