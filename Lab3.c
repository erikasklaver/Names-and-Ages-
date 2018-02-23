/*
 * Lab3.c

 *
 *  Created on: Sep 21, 2015
 *      Author: Erika Sklaver
 */

//This program will create a list of twenty random first and last names with
//a height and age associated with each name. The user will be asked for a
//last name and the program will search for that last name within the list.
//if the name is in the list, the program will print out all the information
//about that person. This program will also ask the user to select an age range
//and enter two numbers. The program will then show the user all the people
//in the list that are within their selected age range.

#include <stdio.h>
#include <stdlib.h>

#include "Lab3.h"

#include <string.h>

int main(void){

	//This allows for random names and numbers to be selected.
	srand(time(NULL));

    //This creates the list of twenty names.
	personType * allData = createDataBase();

	//These hold the original allData.
	personType * curr = allData;
	personType * curr2 = allData;

	//This prompts the user to enter a last name to search for.
	char surname[MAX_NAME_LENGTH];
	printf("What last name would you like to search for?");
	scanf("%s", surname);

    //As long as we are not checking the last item in the list, this will
    //compare the inputed last name to each last name in the list. If the
    //inputed name is in the list, that entry will be printed out.
	while (curr !=NULL){
		if (strcmp(curr->lastName, surname) == 0){
			printEntry(curr);
		}
		curr = curr->next;

		return EXIT_SUCCESS;
    }

    //This prompts the user to enter an age range.
	printf("Select an age range by entering two numbers");
	int firstNum = 0;
	int secondNum = 0;
	scanf("%d %d", &firstNum, &secondNum);

	//As long as we are not checking the last item in the list, this will go
	//through each item in the list and check to see if the age of each
	//person is in the age range, then it will print all of the entries
	//of people that fall within the age range.
     while (curr2 !=NULL){
		if(curr2->age<=secondNum && curr2->age>=firstNum){
			printEntry(curr2);
		}
		curr2 = curr2->next;
	}

    //Once the program is done, this will delete all of the entries to free
    //up memory to be used for other things.
	freeList(allData);

}

//The createDataBase function calls on createEntry to actually create each entry
//in the list. Then it calls on insertEntry to insert the entry into the list
//and thus creates the list of all the entries. It returns the final list.
personType * createDataBase (){


		personType *dataBase = NULL;

		for (int i=0; i<MAX_NAMES; i++){
			personType *entry = createEntry();
			dataBase = insertEntry(dataBase, entry);
			}

		return dataBase;
		}

//The createEntry function creates space for each entry and then puts the
//information about each person into the entry.
personType * createEntry(){

	//This creates a struct and returns values that might indicate a problem
	//If there is a problem, the program will exit.
	personType *entry = (personType *) malloc(sizeof (personType));
			if (entry == NULL){
				printf("Error: malloc returned NULL");
				return EXIT_FAILURE;
			}

	//This entry is not pointing to anything
	entry->next = NULL;

    //These randomly select names from the first and last name banks in the
	//header file. It assigns these names, then height, then age to each person
	int randFirstIndex1 = rand()% MAX_NAMES;
	strcpy(entry->firstName, bankOfFirstNames[randFirstIndex1]);

	int randFirstIndex2 = rand()% MAX_NAMES;
	strcpy(entry->lastName, bankOfLastNames[randFirstIndex2]);

	int randFirstHeight = rand()%(MAX_RAND_HEIGHT-MIN_RAND_HEIGHT+1)-MIN_RAND_HEIGHT;
	double randInches = (rand()%DIVIDER)/DIVIDER;
	strcpy(entry->height, randFirstHeight + randInches);

	int randFirstAge = rand()%(MAX_RAND_AGE-MIN_RAND_AGE+1)-MIN_RAND_AGE;
	strcpy(entry->age, randFirstAge);

   //This function then returns the entire struct which has all the information.
	return entry;
}

//The insertEntry funtion actually puts the entry into a linked list alphabetically
//by last name.
personType * insertEntry(personType * dataBase, personType *entry){

	//If we are placing the first entry, we place it into the first spot on the list.
	if (dataBase == NULL){
		dataBase = entry;
	//If we are placing an entry that belongs in the front, we place it there
	//and make dataBase point to the new head of the list.
	}else if (strcmp(dataBase->lastName, entry->lastName)>=0){
		entry->next = dataBase;
		dataBase = entry;
	//If we are placing the second entry, we place it right after the first.
	}else if (dataBase->next == NULL){
		dataBase->next = entry;
	//For all other entries, we compare each last name in the list to the entry we
	//are trying to place until we find the right spot for the entry.
    }else{
    	personType * prev = dataBase;
    	personType * curr = dataBase->next;

    	while (curr != NULL && strcmp(curr->lastName, entry->lastName)<=0){
    		prev = curr;
    		curr = curr->next;
    	}
    	prev->next = entry;
    	entry->next = curr;
    }
	//The function then returns the updated list with the new entry placed
	//in it.
	return dataBase;
}

//The printEntry function prints all the information about the entry that
//was sent to the function.
void printEntry (personType *dataBase){

		 printf("%s ", dataBase->firstName);
		 printf("%s, ", dataBase->lastName);
		 printf("Height: %d ", dataBase->height);
		 printf("Age: %d", dataBase->age);

	     printf("\n");
}

//The freeList function deletes each entry in the list one at a time from
//the last entry to the first entry.
void freeList (personType *dataBase){

	personType *curr = dataBase;

	while (dataBase != NULL){
		curr = dataBase->next;
		free(curr);
	}

}

