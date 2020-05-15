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
1. `push <int>`: pushes an element to the stack.
2. `pall`: prints all the values on the stack, starting from the top of the stack.
3. `pint`: prints the value at the top of the stack.
4. `pop`: removes the top element of the stack.
5. `swap`: swaps the top two elements of the stack.
6. `add`: adds the top two elements of the stack.
7. `nop`: doesn’t do anything.
8. `sub`: subtracts the top element of the stack from the second top element of the stack.
9. `div`: divides the second top element of the stack by the top element of the stack.
10. `mul`: multiplies the second top element of the stack with the top element of the stack.
11. `mod`: computes the rest of the division of the second top element of the stack by the top element of the stack.
12. `pchar`: prints the char at the top of the stack.
13. `pstr`: prints the string starting at the top of the stack.
14. `rotl`: rotates the stack to the top.
15. `rotr`: rotates the stack to the bottom.
16. `stack`: sets the format of the data to a stack (LIFO). This is the default behavior of the program.
17. `queue`: sets the format of the data to a queue (FIFO).

When switching mode:
- The top of the stack becomes the front of the queue
- The front of the queue becomes the top of the stack

#### Error system
- No file or more than 1 argument? `USAGE: monty file`
- Not possible to open the file? `Error: Can't open file <file>`
- Invalid instruction? `L<line_number>: unknown instruction <opcode>`
- Unable to malloc? `Error: malloc failed`
- Specific errors for each opcode:
  - push: `L<line_number>: usage: push integer`
  - pint: `L<line_number>: can't pint, stack empty`
  - pop: `L<line_number>: can't pop an empty stack`
  - swap: `L<line_number>: can't swap, stack too short`
  - add: `L<line_number>: can't add, stack too short`
  - sub: `L<line_number>: can't sub, stack too short`
  - div: `L<line_number>: can't div, stack too short`
  - mul: `L<line_number>: can't mul, stack too short`
  - mod: `L<line_number>: can't mod, stack too short`
  - pchar: `L<line_number>: can't pchar, value out of range`


#### Compilation
```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
#### Usage
```
./monty file
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

##### Example of add:
```
julien@ubuntu:~/monty$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/monty$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/monty$
```

##### Example of pchar:
```
julien@ubuntu:~/monty$ cat bytecodes/28.m 
push 72
pchar
julien@ubuntu:~/monty$ ./monty bytecodes/28.m 
H
julien@ubuntu:~/monty$
```

##### Example of pstr:
```
julien@ubuntu:~/monty$ cat bytecodes/31.m 
push 110
push 0
push 110
push 111
push 116
push 114
push 101
push 98
push 108
push 111
push 72
pstr
julien@ubuntu:~/monty$ ./monty bytecodes/31.m 
Holberton
julien@ubuntu:~/monty$ 
```

##### Example of rotl:
```
julien@ubuntu:~/monty$ cat bytecodes/35.m 
push 1
push 2
push 3
push 4
push 5
pall
rotl
pall
julien@ubuntu:~/monty$ ./monty bytecodes/35.m 
5
4
3
2
1
4
3
2
1
5
julien@ubuntu:~/monty$ 
```

##### Example of stack and queue:
```
julien@ubuntu:~/monty$ cat bytecodes/47.m
push 1
push 2
push 3
pall
stack
push 111
pall
julien@ubuntu:~/monty$ ./monty bytecodes/47.m
3
2
1
111
3
2
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
