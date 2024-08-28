## Class #1: 19/08/24

Pseudocode Challenge #1: Number guessing Game

Pseudocode written in a gross amalgamation of Python, Java, C++, and whatever else I felt like
```pseudocode
int number = random.randint(1, 100)
print("Guess a number: ")
guess = scan.nextInt()
counter = 0

# Looping and logic
while guess != number:
	if guess < number:
		print("Too low. Guess again: ")
		guess = scan.nextInt()
		counter++
	elif guess > number:
		print("Too high. Guess again: ")
		guess = scan.nextInt()
		counter++
	elif guess == number:
		print("You got it, the number was {number}!")
	else:
		print("Something went wrong. [How did you get here?] Guess again: ")

print(You took {counter} many guesses!)
```

Full code in pascal curtesy of ChatGPT
```pascal
program NumberGuessingGame;
uses crt;

var
	answer, guess, attempts: interger;

begin
	answer := 42;
	attempts := 0;

	writeln("Guess intergers until you get the right number!");

	repreat
		writeln("Guess a number: ")
		readln("guess");
		attempts := attempts + 1;

	if guess < answer then
		writeln("Too low. Guess again:");
	else if guess > answer then
		writeln("Too high. Guess again: ");
		
	until guess = answer;

	writeln('Congratulations! You got it! It took you 'attempts, 'attempts!');
end.
```

## Class #2: 21/08/24

### Programming Preliminaries
- What is a computer program
	- Goal: get they systems to get us do have a program to do the things we want to do
		- Task > Program > Output
	- *Scope of this class is mostly human level input and output*
	- **Algorithm**: clear set of instructions the computer evaluates for us
		- Should be able to be mapped out into a flowchart/diagram
	- Languages are an abstraction of the actual program meant to be read easier by humans
		- High level vs. low level languages
- Interpreted vs. Compiled Language
	- Interpreted language: code is converted on the fly from code to CPU code
	- Compiled language: code is compiled into source code which is then read and run by the computer
- Compiler
	- Compiler goals: ensure that some standards are met; makes the program executable
		- Optimizes program, 
		- Syntax: how the code is written to properly run
		- Semantics: what the code does 

## Class #3: 23/08/24

### Pipeline from Conception to Execution
1. Conception
	1. Algorithm
	2. Pseudocode
2. Source Code
	1. Preprocessor (adds header info)
	2. Compiler (creates assembly code)
		1. Syntax errors come here
	3. Assembler (creates object code)
	4. Linker (combines all object code into executable)
3. Execution
### Exploring Intermediate Steps

**Program created was "Day1_Hello" created in the desktop**