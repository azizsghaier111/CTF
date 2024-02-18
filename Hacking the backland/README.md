first we need to retrieve the information from the pict.jpg using outguess stegonagraphy function 
outguess -er kuraq_case/pict.jpg output1

I found this website 

I need to download the client and client_slave source code from it 
wget -O output2 localhost:port (le port dans output1)
here we need to find more information about the src code the output2 will contains a html page that cocontains information about the src code path 

cat output2 | grep backups-

you will find a port example backups-18184 in my case 

wget localhost:port/backups-18184 -> ca crée backups-18184

wget localhost:port/backups-18184/server.c -> ca crée server.c

wget localhost:port/backups-18184/server_slave.c -> ca crée server_slave.c


in case you didn't succeeded to follow the steps above you will find in this directory the downloaded source codes so do not worry 



after obtaining the source codes you need to copy and paste them in you local machine to compile them manually and see what you can do with them to hack the backland 

you need first to create a folder in the same directory of server.c and server_slave.c to fullfiill one requirement 

363


