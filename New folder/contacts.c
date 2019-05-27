/* -------------------------------------------
Name:yunseon Lee
Student number:048757140
Email:ylee111@myseneca.ca
Section:IPC144
Date: Dec 05 2018
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name *pName) {
	
	
	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", pName->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");

	
	if (yes() == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %14[^\n]", pName->middleInitial);
		clearKeyboard();
	}
	else 
	{
		pName->middleInitial[0] = '\0';
	}
	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", pName->lastName);
	clearKeyboard();
}
// getAddress:
void getAddress(struct Address *pAddress) {
	
	//int userInputInteger;
	do {
		printf("Please enter the contact's street number: ");
		//scanf(" %s", &userInputInteger);
	pAddress->streetNumber = getInt();
		

	} while (pAddress->streetNumber <= 0);
	//pAddress->streetNumber = userInputInteger;

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", pAddress->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	
	if (yes() == 1) {
		//scanf(" %d", &userInputInteger);
		do {
		printf("Please enter the contact's apartment number: ");
		pAddress->apartmentNumber = getInt();

		} while (pAddress->apartmentNumber <= 0);
	}
	else
	{
		pAddress->apartmentNumber = '\0';
	}
		

		//pAddress->apartmentNumber = userInputInteger;
	
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", pAddress->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	
	scanf("%40[^\n]", pAddress->city);
	clearKeyboard();  
};



// getNumbers:
void getNumbers(struct Numbers *pNumber) {
	
	
	printf("Please enter the contact's cell phone number: ");
	
	getTenDigitPhone(pNumber->cell);
	//clearKeyboard();

	//scanf(" %10[^\n]", pNumber->cell);


	printf("Do you want to enter a home phone number? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(pNumber->home);
		//scanf(" %10[^\n]", pNumber->home);
	}
	else
	{
		pNumber->home[0] = '\0';
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	//scanf(" %c", &yesNo);
	if (yes() == 1) {
		printf("Please enter the contact's business phone number: ");
		//scanf(" %10[^\n]", pNumber->business);
		getTenDigitPhone(pNumber->business);
	}
	else
	{
		pNumber->business[0] = '\0';
	}
}
// getContact:
void getContact(struct Contact *pContact) {
	getName(&pContact->name);
	getAddress(&pContact->address);
	getNumbers(&pContact->numbers);
}