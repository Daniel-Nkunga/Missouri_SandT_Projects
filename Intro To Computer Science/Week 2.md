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
	- Command that can format a specific file to fit a specific formatting guide
	- 