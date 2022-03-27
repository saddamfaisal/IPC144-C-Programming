
//==============================================
// Name:           saddamfaisal
// Student Number:11846198 
// Email:          Sfaisal6@myseneca.ca
// Section:        NII
// Date:           
//==============================================
// Assignment:     1
// Milestone:      1
//==============================================

// Structure type Name declaration
struct Name
{
	char firstName[32];
	char middleInitial[8];
	char lastName[37];
};

// Structure type Address declaration
// Place your code here...
struct Address
{
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code here...

struct Numbers
{
	char cell[11];
	char home[11];
	char business[11];
};

// Structure type Contact declaration
// Place your code here...
struct Contact
{
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name*);


// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address*);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers*);
   