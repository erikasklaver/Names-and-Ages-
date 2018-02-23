/*
 * Lab3.h
 *
 *  Created on: Sep 21, 2015
 *      Author: Erika
 */

#ifndef LAB3_H_
#define LAB3_H_

//These are all the named constants used in the program.
#define MAX_NAME_LENGTH 15
#define MAX_NAMES 20
#define MAX_RAND_HEIGHT 7
#define MIN_RAND_HEIGHT 4
#define MIN_RAND_AGE 1
#define MAX_RAND_AGE 120
#define DIVIDER 10

//These are the first and last names that may be in the lists in the program.
char bankOfFirstNames[MAX_NAMES][MAX_NAME_LENGTH] =
		 { "Alex", "Angela", "Sonya", "Eric", "Robert", "Svetlana", "Carl",
        "Sujit", "Niejls", "Janet", "Isac", "Emily", "Terik", "Nevin" };
char bankOfLastNames[MAX_NAMES][MAX_NAME_LENGTH] =
        { "Borisov", "Johnson", "BenHaim", "Kourakis", "Elfasi", "Newton",
          "Gorbachev", "Marinescu", "Voltaire", "Albertson", "Lee", "Chin",
          "Kraft", "Roitman" };

//This is the struct that holds information for one person and points to the
//next entry. This struct is what allows for a linked list to be formed.
typedef struct person {
	char firstName[MAX_NAME_LENGTH];
	char lastName[MAX_NAME_LENGTH];
	int height;
	int age;
	struct person *next;

} personType;

//These are all the functions that are used in the program.
personType * createDataBase();
personType * createEntry();
personType * insertEntry(personType * dataBase, personType *entry);
void printEntry (personType *dataBase);
void freeList (personType *dataBase);

#endif /* LAB3_H_ */
