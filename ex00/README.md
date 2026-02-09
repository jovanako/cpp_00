```std::string arg(argv[1]);```
	-> object construction
		- 'arg' becomes a std::string object
		- the parentheses call a constructor
	So this line means:
		"Create a std::string named 'arg' and initialize it 
		using the C-string argv[i]."

```std::string```	
	-> What happens internally:
		(1) std::string	- finds the '\0' at the end of argv[i]
						- calculates the length
		(2) allocates its own memory
		(3) copies each character into its internal buffer

## After this line: ```std::string arg(argv[i])```
	-> arg is now independent
	-> modifying arg does NOT affect argv[i]

## Plain English: 
	"Take the C string from the command line and turn it into a C++ string object
	so I can work with it safely and easily."

## What is ```std::string::size_type```?
```size_type``` is a type defined inside ```std::string```
	-> the correct integer type for indexing and measuring a std::string

## Internally, it is:	
	- an unsigned integer type
	- large enough to represent any possible string size

## Why not use int?
	-> using 'int j' can cause warnings: 
```for (int j = 0; j < arg.length(); j++)```
	-> Problem:
```arg.length()``` returns ```std::string::size_type``` (unsigned)
	- j is int (signed)

## Why not use size_t directly?
	-> size_t is defined in <cstddef>
```std::string::size_type``` is guaranteed to match what ```std::string``` expects

## What does the '::' mean?
	-> This is the scope resolution operator
	-> the type named 'size_type' that belongs to 'std::string'

## Why is this necessary in our loop?
```for (std::string::size_type j = 0; j < arg.length(); j++)```
	-> j and arg.length() now have the same type
	-> no signed/unsigned mismatch
	-> no warnings
	-> fully standard-compliant
	-> fully portable (the code bahaves correctly and compiles without changes on any system,
		compiler, or architecture that follows the C++ standard)

## Mental model to remember:
	-> whenever you see:
```something.length()```
	-> think: I should probably use:
```something::size_type```

```int toupper(int c)```
	- converts 'c' to its uppercase equivalent if 'c' is a lowercase letter
	 and has an uppercase equivalent. If no such conversion is possible, the 
	 value returned is 'c' unchanged.

```std::endl```
	- inserts a new-line character and flushes the stream
	- this is the act of forcing any data currently sitting in temporary memory (the buffer)
		to its final destination, such as the console screen or a file on your hard drive.

-> if you want to flush without adding a newline:
```std::flush```
	- this way, the text appears immediately on the same line
```std::cin``` also flushes the buffer because this is a call for user input
	- so C++ automatically flushes the output buffer so that the user can
	see the prompt they are responding to

EFFICIENCY TIP: '\n' vs 'std::endl'
	- if you are writing a high-performance loop that prints thousands of
	lines, avoid 'std::endl'. Constant flushing is a massive performance
	killer. Use '\n' instead, which only adds the newline and lets the
	system manage the buffer naturally.

FUN FACT: std::cerr (the standard error stream) is unbuffered by default.
	It flushes immediately because when an error occurs, you usually need
	to know about it right away.

TESTS:
```
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```