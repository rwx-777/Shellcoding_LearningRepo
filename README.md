# Shellcoding_LearningRepo
You should look through my Assembly LearningRepo first before learning Shellcoding.


## How to compile & create shellcode
```
$ ./CompileNasm.sh execve-sh.nasm

$ ./makeShellcode.sh compiled
```
Voila now you should get the returned shellcode printed to stdout of your assembler programm.


## Bad character
We need to remove all bad chars from our shellcode in order for it to work
- 00: This is the zero value or null terminator(\0)
- 0A: This is the line feed(\n)
- FF: This is the form feed(\f)
- 0D: This is the carriage return(\r)

## Relative address technique
we shall use "lea <destination>, [rel <source>]"
where the rel instruction will compute the address of the source relative to the RIP register.
  

## Jmp-call technique
We first jmp to the string we want to move to a register, after that we call the actual code using "call" this will push the strings address to the stack.
Then we pop the address (not the String itself) into that register. voila!


## Stack technique
We Reverse String & encode it into hex then copy the hex bytes into our code so we do not have to store the string in any register.
```
$python
>> string = 'hello World'

>> string[::-1].encode('hex')

We need to convert port to htons using Python:
>> import socket

>> hex(socket.htons(1234))

And we need to pack the IP in a 32 bit format:
>> import socket

>> socket.inet_aton("192.168.178.1")[::-1]
```




