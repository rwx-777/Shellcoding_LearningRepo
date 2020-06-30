# Shellcoding_LearningRepo
You should look through my Assembly LearningRepo first before learning Shellcoding.

# Bad character
We need to remove all bad chars from our shellcode in order for it to work
- 00: This is the zero value or null terminator(\0)
- 0A: This is the line feed(\n)
- FF: This is the form feed(\f)
- 0D: This is the carriage return(\r)

# Relative address technique
we shall use "lea <destination>, [rel <source>]"
where the rel instruction will compute the address of the source relative to the RIP register.
  

# Jmp-call technique
We first jmp to the string we want to move to a register, after that we call the actual code using "call" this will push the strings address to the stack.
Then we pop the address (not the String itself) into that register. voila!


# Stack technique
