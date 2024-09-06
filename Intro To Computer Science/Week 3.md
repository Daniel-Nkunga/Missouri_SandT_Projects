## Class #7: 04/09/24

### Operators
- =: assignment
- +:
- -:
- \ * :
- /: integer division
- // : true division
- !:
- == :
- % : mod
- ++ : adds one to the variable; can be prefixed or postfixed but has quirks
	- Prefixed: when not in isolation, will do everythin in that operatio then increase the value of a variable
	- v = a + b++; 
		- v = a + b;
		- b++;
	- v = a + ++b;
		- v = a + (b + 1)
- && : and
- || : or

- To change variable types, use a static cast
	- static_cast\<type>(var) //This only changes the variable in this line of code
	- (type)var //Bad; doesn't change the pointer

## Class #8: 06/09/2024

### Homework Issues
- cin, getline, buffer, and whitespaces
	- Whitespaces in CPP: return, new line, tab, and space
	- cin: reads character by character
	- getline: gets an entire string
		- can be further specified to break at a certain character/string

### Loops
- Sentinel loops: runs until a flag is met
	- while(condition)
	- do{incrementor}while(condition)
- For loops: will do something for a set amount of time
	- for(initialization; condition; incrementor)