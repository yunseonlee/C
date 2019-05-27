/* -------------------------------------------
Name:yunseon Lee
Student number:048757140
Email:ylee111@myseneca.ca
Section:IPC144
Date: Dec 05 2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:

#include "contactHelpers.h"

// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose

}


// pause:
void pause(void) {
	printf("\n(Press Enter to Continue)");
	clearKeyboard();
	
}

// getInt:0
int getInt(void) {
	int value = 0;
	char NL = 'x';
	scanf(" %d%c", &value, &NL);
while (NL != '\n') {

		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf(" %d%c", &value, &NL);
	}
	return value;
}

// getIntInRange:
int getIntInRange(int lower, int upper) {
	int value = 0;

	//printf("value: %d", value);
	do {
		value = getInt();
		if (value <lower || value>upper) {
			//printf("value: %d", value);
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", lower, upper);
		}


	} while (value <lower || value>upper);

	return value;

}

// yes:
int yes(void) {
	char yesNo = '\0';
	char NL = '\0';
	int value = 2;
	do
	{
		scanf(" %c%c", &yesNo, &NL);



		if (NL == '\n')
		{
			if (yesNo == 'y' || yesNo == 'Y')
			{
				value = 1;
			}
			else if
			 (yesNo == 'n' || yesNo == 'N'){
			
				value = 0;
			}
		}
		else
		{

			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}
	} while (value == 2);


	return value;

}

// menu:
int menu(void) {
	
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	
	printf("Select an option:> ");
	
	
	return getIntInRange(0, 6);

}

// contactManagerSystem:
void contactManagerSystem(void) {
	int done = 0;
	int option = 0;

	
	

	struct Contact contacts[MAXCONTACTS] = { {{ "Rick", {'\0'}, "Grimes" },
									 { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
									 { "4161112222", "4162223333", "4163334444" } },
								  {
									 { "Maggie", "R.", "Greene" },
									 { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
									 { "9051112222", "9052223333", "9053334444" } },
								  {
									 { "Morgan", "A.", "Jones" },
									 { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
									 { "7051112222", "7052223333", "7053334444" } },
								  {
									 { "Sasha", {'\0'}, "Williams" },
									 { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
									 { "9052223333", "9052223333", "9054445555" } },
	};

	do {
		option = menu();

		switch (option) {
		case 0:
			printf("\n");
			printf("Exit the program? (Y)es/(N)o: ");
			done = yes();
			printf("\n");
			

		

			break;

		case 1:
			printf("\n");
			displayContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");

			break;
		case 2:
			printf("\n");
			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
			//printf("\n<<< Feature 2 is unavailable >>>\n\n");

		case 3:
			printf("\n");
			updateContact(contacts, MAXCONTACTS);
			//printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 4:
			printf("\n");
			deleteContact(contacts, MAXCONTACTS);
			//printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 5:
			printf("\n");
			searchContacts(contacts, MAXCONTACTS);
			//printf("<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");

			break;
		case 6:
			printf("\n");
			sortContacts(contacts, MAXCONTACTS);
			//printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		default:



			;
		}

	} while (done == 0);
	printf("Contact Management System: terminated\n");
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+
//void getTenDigitPhone(char telNum[])

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int Input = 1;
	int i, iNumber = 0;

	while (Input == 1)
	{
		scanf("%10s", telNum);
		clearKeyboard();
		iNumber = 0;
		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
		{
			for (i = 0; i < 10; i++)
			{
				if (telNum[i] >= '0' && telNum[i] <= '9')
				{
					iNumber = iNumber + 1;
				}
			}
			if (iNumber == 10)
			{
				Input = 0;
			}
			else
			{
				printf("Enter a 10-digit phone number: ");
				//clearKeyboard();   //added
			}
		}
		
		if(strlen(telNum) != 10)
		{
			printf("Enter a 10-digit phone number: ");
			//clearKeyboard();
		}
	}
}






//{
//	//int telNum = 0;
//	int needInput = 1;
//	int i;
//	
//	while (needInput == 1) {
//		scanf("%10s", telNum);
//		clearKeyboard();
//		if (strlen(telNum) == 10)
//		{
//			for (i = 0; i < 10; i++)
//			{
//				if (strlen(telNum) != 10 || (telNum[i] < '0' || telNum[i]>'9'))
//				{
//					printf("Enter a 10-digit phone number: ");
//					scanf("%10s", telNum);
//					clearKeyboard();
//
//					//needInput = 1;
//					break;
//				}
//				else
//					needInput = 0;
//			}
//			
//		}
//	}
//
//}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i = 0;
	int check = -1;

	for (i = 0; i < size; i++) {
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			check = i;
		}

	}

	return check;
}

// displayContactHeader
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

}

// displayContactFooter
void displayContactFooter(int count) {

	printf("+-----------------------------------------------------------------------------+\n");
	   			
	printf("Total contacts: %d\n", count);
}



// displayContact:
void displayContact(const struct Contact *contacts) {

			
			printf(" %s ", contacts->name.firstName);
			if (contacts->name.middleInitial[0] != '\0') {
				printf("%s ", contacts->name.middleInitial);

			}
			printf("%s\n", contacts->name.lastName);


			printf("    C: %-10s   H: %-10s   B: %-10s\n", contacts->numbers.cell, contacts->numbers.home, contacts->numbers.business);     //cellphone, homephone, business phone
			printf("       %d %s, ", contacts->address.streetNumber, contacts->address.street);   // contacta[i]?



			if (contacts->address.apartmentNumber > 0) {
				printf("Apt# %d, ", contacts->address.apartmentNumber);
			}
			printf("%s, %s\n", contacts->address.city, contacts->address.postalCode);
		
		
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size) {
	int i=0;
	int count = 0;
	displayContactHeader();
	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) > 0) {
			displayContact(&contacts[i]);
			count++;

		}

	}
	displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size) {
	int index;
	char cellNum[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	index = findContactIndex(contacts, size, cellNum); 

	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n");
		
		


	}else
	{
		printf("\n");
		displayContact(&contacts[index]);

	}
	

}

// addContact:
void addContact(struct Contact contacts[], int size) {
	int i = 0;
	int index = -1;

	for (i = 0; i < size; i++) {
		if (strlen(contacts[i].numbers.cell) == '\0') {
			index = i;
			break;
		}
	}
	if (index != -1) {
		getContact(&contacts[index]);
		printf("--- New contact added! ---\n");
	}
	else {
		printf("*** ERROR: The contact list is full! ***\n");

	}

}

// updateContact:
void updateContact(struct  Contact contacts[], int size) {
	
	int index;
	
	char cellNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	index = findContactIndex(contacts, size, cellNum);  

	if (index != -1) {
	
		printf("\nContact found:\n");
		
		displayContact(&contacts[index]);
	
		printf("\nDo you want to update the name? (y or n): ");
		
	
		
				if (yes() == 1) {
					getName(&contacts[index].name);

				}
				printf("Do you want to update the address? (y or n): ");
	

				if (yes() == 1) {
					getAddress(&contacts[index].address);    
				}
				printf("Do you want to update the numbers? (y or n): ");
	
				if (yes() == 1) {
					getNumbers(&contacts[index].numbers);
				}
				printf("--- Contact Updated! ---\n");
	}	
	else 
	{
	printf("*** Contact NOT FOUND ***\n");
	}

	}



void deleteContact(struct  Contact contact[], int size) {
	int index;
	
	
	char cellNum[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	index = findContactIndex(contact, size, cellNum);
	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		
		printf("\nContact found:\n");

		displayContact(&contact[index]);
		
	}

	printf("\nCONFIRM: Delete this contact? (y or n): ");
	
	if (yes() == 1) {
		contact[index].numbers.cell[0] = '\0';
		//contact[index]->numbers.cell[0] = '\0';
	printf("--- Contact deleted! ---\n");
	}
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
	int i;
	int n;
	int total = 0;
	struct Contact value;

	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) > 0)
		{
			total++;
		}
	}

	for (i = 0; i < total - 1; i++)
	{
		for (n = i; n < total; n++)
		{
			if (strcmp(contacts[i].numbers.cell, contacts[n].numbers.cell) > 0)
			{
				value = contacts[i];
				contacts[i] = contacts[n];
				contacts[n] = value;
			}
		}
	}
	printf("--- Contacts sorted! ---\n");
}