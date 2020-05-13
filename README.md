# Interpreter for Monty byte codes

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

#### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```
## The monty program:

#### Monty Instructions:
1. `push <int>`: The opcode `push` pushes an element to the stack.
2. `pall`: The opcode pall prints all the values on the stack, starting from the top of the stack.
3. `pint`: The opcode `pint` prints the value at the top of the stack.
4. `pop`: The opcode pop removes the top element of the stack.
5. `swap`: The opcode swap `swaps` the top two elements of the stack.
6. `add`: The opcode `add` adds the top two elements of the stack.
7. `nop`: The opcode nop doesn’t do anything.
8. `sub`: The opcode `sub` subtracts the top element of the stack from the second top element of the stack.
9. `div`: The opcode div divides the second top element of the stack by the top element of the stack.
10. `mul`: The opcode mul multiplies the second top element of the stack with the top element of the stack.
11. `mod`: The opcode `mod` computes the rest of the division of the second top element of the stack by the top element of the stack.

#### Error system
- If the user does not give any file or more than one argument to the program, print the error message `USAGE: monty file`
- If it’s not possible to open the file, print the error message `Error: Can't open file <file>`
- If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`
- When it can’t malloc anymore, print the error message `Error: malloc failed, followed by a new line`
#### Compilation
```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
#### Usage
```
monty file
```
Where file is the path to the file containing Monty byte code.

##### Example of push and pall:
```
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$
```

##### Example of pint:
```
julien@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/monty$ 
```

##### Example of pop:
```
julien@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/monty$ 
```

##### Example of swap:
```
julien@ubuntu:~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/monty$ 
```



## Learning Objectives
The objective of this project is to be able to explain to anyone, without the help of Google:

- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables

## Authors

- Manuel Puerta Villa
- Diana Carolina Quintero Caro
