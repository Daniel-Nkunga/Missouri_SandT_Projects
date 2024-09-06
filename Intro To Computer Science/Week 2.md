## Class #4: 26/08/24

```cpp
#include <iostream>
using namespace std;

int main() //Auto-run in the program
{
	// Declarations
	float celc;
	float fahr;
	
	// Greetings and Input
	cout<<"\t\tWelcome to Temperature Conversion Program"<<endl<endl;
	cout<<"Please enter a temperature in Fahrenheit: ";
	cin>>fahr

	// Computations and Output
	celc = (5.0/9)*(fahr - 32)
	cout<<"\n\nYour temperature input of "<<fahr<<" degrees Fahrenheit is "<<celc<<"degrees celcius"<<endl;
	return 0;
}
```

- main()
	- A specialized function that must return an int value
	- *Can* be "void main()" in older program to return nothing
	- Only one "main" per program; if a program has multiple "main" functions, it will error out
- cin - "console input"
	- Comes in from the terminal
- cout "console output"
	- goes out to the terminal
- << - "insertion operator"
	- After text, follow with "endl" (endline) to flush the terminal
- >> - "extraction operator"
	- Can be strung together using multiple operators
		- cin >> fname >> lname
- *We started zoning out at 12:35*

- clang-format -i main.cpp
	- Command that can format a specific file to fit a specific formatting guide (clang)

## Class #5: 28/08/24

- Are we allowed to access the Virtual Machines at all times? Are there other machines we should be using for recreational use?
	- https://itrss.mst.edu/
	- https://itrss.mst.edu/cluster/mill/

### Variable Types
- atuo: allows for a class to automatically be assigned to a variable based on implicit context
- short: whole number; 2 bytes
- int: whole number; 4 bytes
- float: decimal number; 4 bytes
- double: decimal number; 8 bytes
	- long double: decimal number; 16 bytes
- char: single character; 1 byte
- string: collection of characters; memory dependent of size
- boolean: true or false; 1 byte
	- Or can be represented by integers; 0 is false, anything else is true

## Class #6: 30/08/24
- Arity: the number of things an operator works with
- implicit type conversion: when one variable is stored into another type 
	- Will not work with var(value) assignment
### Operators
- =: assignment
- +:
- -:
- \ * :
- /:
- //
- !:
- == :
- 