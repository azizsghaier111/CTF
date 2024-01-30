# Path to victory challenge
## Overview
This challenge simulates a scenario where a token recovery tool is available in Unix sessions for employees who have lost their authentication tokens. Participants will use a custom script to set up a modified grep command, leveraging a file race attack to recover the admin authentication token.

## Ethical Considerations
This challenge is designed for educational and research purposes in controlled environments. Do not attempt to exploit vulnerabilities in real-world systems without proper authorization. Understand the ethical implications and potential risks associated with such actions.

## Files:
`recover_token`: Script to set up a custom grep command and execute the recover_token script.
`recover_token.c`: the src code of the binary above 
secret_tokens: File containing sensitive information


As a company staff member, you are using a web management service with a private token for authentication. In case of token loss, the IT team has provided a tool for token recovery, accessible through SSH. Your task is to leverage the provided script to recover the admin authentication token.

## Solution
So this is the [exploit](exploit.sh) that we are going to use in this challenge

Steps of the exploit: 
1- Creates the ~/tmp directory if it doesn't exist.
2- Creates a custom grep script in ~/tmp that simply prints the content of /etc/staffserver/secret_tokens.
3- Makes the custom grep script executable.
4- Adds the ~/tmp directory to the beginning of the PATH.

then run the exploit and the `recover_token` program to obtain your flag 

```Bash
chmod +x exploit
cd staff_tools
./exploit.sh
./recover_token.sh
```
