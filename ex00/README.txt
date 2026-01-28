std::string	-> What happens internally:
					(1) std::string	- finds the '\0' at the end of argv[i]
									- calculates the length
					(2) allocates its own memory
					(3) copies each character into its internal buffer

After this line: std::string arg(argv[i])
		-> arg is now independent
		-> modifying arg does NOT affect argv[i]

Plain English: "Take the C string from the command line
				and turn it into a C++ string object
				so I can work with it safely and easily."

What is std::string::size_type?
	-> sie_type is a type defined inside std::string
		-> the correct integer type for indexing and measuring a std::string

Internally, it is:	- an unsigned integer type
					- large enough to represent any possible string size

Why not use int?	-> using 'int j' can cause warnings: for (int j = 0; j < arg.length(); j++)
					-> Problem:	- arg.length() returns std::string::size_type (unsigned)
								- j is int (signed)

Why not use size_t directly?	-> size_t is defined in <cstddef>
								-> std::string::size_type is guaranteed to match what std::string expects

What does the '::' mean?	-> This is the scope resolution operator
								-> the type named 'size_type' that belongs to 'std::string'

Why is this necessary in our loop?
		for (std::string::size_type j = 0; j < arg.length(); j++)
		-> j and arg.length() now have the same type
		-> no signed/unsigned mismatch
		-> no warnings
		-> fully standard-compliant
		-> fully portable (the code bahaves correctly and compiles without changes on any system,
							compiler, or architecture that follows the C++ standard)