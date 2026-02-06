GOAL:
	- write a small terminal-based phonebook program that:
		-> runs in a loop
		-> accepts only three commands: ADD, SEARCH, EXIT
		-> stores up to 8 contacts (no more)
		-> uses two classes: PhoneBook and Contact
		-> uses no dynamic memory allocation (new, malloc, etc.)
	- this simulates an old-school phonebook program 
		with very limited memory

CONTACT CLASS:
	- this represents one person in the phonebook
	- required fields:	- first name
						- last name
						- nickname
						- phone number
						- darkest secret
	- these should be private, because the outside world should not
		directly modify contact data
	- IMPORTANT: no field can be empty

PHONEBOOK CLASS:
	- this class manages contacts
	- required properties:	- an array of 8 contact objects
							- no dynamic allocation -> use a fixed array
	- maximum 8 contacts 
		- when adding the 9th contact, overwrite the oldest one
		- if i == 8 -> i == 0

At startup:	- phonebook is empty
			- program waits for user input

Accepted commands:
	- ADD		- add a new contact
	- SEARCH	- display and inspect contacts
	- EXIT		- quit program
	anything else - ignored

PHONEBOOK:
	- bool empty() const;	- tests if string is empty
							- returns whether the string is empty
							- does not modify the value of the string in any way
	
	- istream& getline(istream& is, string& str);
				- get line from stream into string
				- extracts characters from 'is' and stores them into 'str'
					until the newline character is found
				- the extraction also stops if the end of file is reached in 'is' or
					if some other error occurs during the input operation