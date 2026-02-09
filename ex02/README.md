## In Account.hpp
	- the private variables:
		- static variables belong to the bank
		- non-static variables belong to one account

## STATIC	
		- there is exactly one copy of this variable, no matter how many Account objects exist
		- every account	- sees the same values
						- updates the same counters
		- if you create 10 accounts, all accounts see '_nbAccounts == 10'
		- no account "owns" this number - the CLASS does
		- these are global states
		- if they were not static, every account would have their own '_totalAmount' for example
		- with 3 accounts, we would have 3 "total amounts" which doesn't make sense
		- so: anything representing a GLOBAL STATE must be STATIC

## NON-STATIC	
		- these describe one specific account instance
```_accountIndex```:
	- each account	- has a unique index
					- that index never changes
					- two accounts must NEVER share the same index
```_amount```:
	- two accounts can have different balances at the same time

```_nbDeposits```:
	- one account might have 5 deposits, another 0 deposits
	- clearly not global
			
### Why ```displayTimestamp()``` is static:
		This function:
			- doesn't depend on any account
			- prints the current time
			- doesn't read or modify object state
		So: It belongs to the CLASS, not to any instance.

		Static functions:
			- can only access static data
			- are utility functions for the class

### Why the default constructor is private:
		- this is a design restriction
		- it means you are not allowed to create an account without an initial amount
		This guarantees:
				- every account starts with a defined balance
				- no "uninitialized" accounts exist

## A MENTAL MODEL:

	THE BANK (CLASS)						EACH ACCOUNT(OBJECT)
	- knows totals							- knows its own balance
	- knows how many accounts exist			- knows its own history
	- prints global info					- has its own identity

### STATIC:		
	bank-wide memory
### NON-STATIC:
	account-specific memory

## MEMBER INITIALIZER LIST:
	- only non-static data members can (and should) appear in the member initializer list

	- the initializer list initializes the data that belongs to the object being constructed
	So only data that:
		- lives INSIDE each object
		- needs to be initialized at construction time
	can go there.

## Static members	
	- do not belong to any specific object
	- exist once for the entire program
	- are initialized OUTSIDE the constructor (in the .cpp)

So when an Account object is constructed, static members already exist - they are not part of the object.

## TIMESTAMP
	- time_t time(time_t* timer);
			- get the current calendar time as a value of type 'time_t'
			- returns this value, and if the argument is not a null pointer,
				it also sets this value to the object pointed by 'timer'
				and returns the current caendar time as a 'time_t' object
			- 'timer' is a pointer to an object of type 'time_t',
				where the time value is stored

	- struct tm* localtime(const time_t* timer);
			- uses the value pointed by 'timer' to fill a 'tm' structure
				with values that represent the corresponding time,
				expressed for the local timezone
	
	- size_t strftime(char* ptr, size_t maxsize, const char* format,
					const struct tm* timeptr);
			- copies into 'ptr' the content of 'format', expanding its format specifiers
				into the corresponding values that represent the time described in
				'timeptr', with a limit of 'maxsize' characters

	- std::string(buffer)
		- constructs a new std::string object from the C-style string
		- this copies the contents of 'buffer' into a safer,
			more flexible C++ string object

### TEST to add to Makefile:
	test: $(NAME)
	./$(NAME) | cut -d ' ' -f 2- > my_log.log
	cat 19920104_091532.log | cut -d ' ' -f 2- > ref_log.log
	diff my_log.log ref_log.log