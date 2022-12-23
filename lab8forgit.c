/*
Write a program to input names and addresses that are in alphabetic order and output the names and 
addresses in acsending zip code order. You could assume a maximum of 50 names.

(Ensure you split the program into 3 different files, and then compile all the files 
together)

Score: 200/200
*/


~~~~~~~~~~~code.h~~~~~~~~~~~~~~~
/*notnecessary*/
#ifndef _CODE_H
#define _CODE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* addressstructure */
typedef struct names{
	char name[100];
	char streetAddress[100] ;
	char nameState[100];
	long zip;
}names;

/*function protoypes*/
void sort(names *arr,int size);
int main(int argc, char **argv);
#endif

~~~~~~~~~~~code.c~~~~~~~~~~
#include"code.h"

void sort(names *arr,int size){	
	names temp;
	int j,i;

	/*sort record by zip code8*/
	for(i=0;i<size-1;i++){
		for(j=i+1;j<size;j++){
			if(arr[i].zip>arr[j].zip)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

~~~~~~~~~~~~~~~main.c~~~~~~~~~~~
#include"code.h"


int main(int argc, char **argv)
{

	/* Descriptive message if argc is not 3 */
	if (argc != 3){
		printf("Error: Invalid number of arguments\n");
		printf("Try again!");
		exit(1);	
	} 
	/*for command line arguments */
	names name;

	/*check the status of fopen(input)*/
	FILE *file = fopen(argv[1],"r");
	if (file == NULL) 
	{
		printf("Error opening input file");
		return(1);
	}
	/*check status of fopen(output)*/
	FILE *writer = fopen(argv[2],"w");
	if (writer == NULL)
	{
		printf("Error opening output file");
		return(1);
	}


	int i , j;
	char line[128]; /* or other suitable maximum line size */
	int count=0;

	/*Pointer of structure*/
	/*array of pointers to structures*/

	names *nameArray;
	/* note nameArray is array */


	/*count the number of structure*/
	/*totalfile*/
	while (fgets ( line, sizeof line, file ) != NULL) /* read a line */
	{

		strcpy(name.name,line);
		fgets ( line, sizeof line, file );
		strcpy(name.streetAddress,line);
		fgets ( line, sizeof line, file );
		strcpy(name.nameState,line);
		fscanf(file,"%li",&name.zip);
		/*read blank line*/

		fgets ( line, sizeof line, file );
		count++;

	}

	/* set file pointer to first */
	fseek(file, 0, SEEK_SET);

	/* dynamic array (memory allocation) */
	nameArray=(names *) malloc(count*sizeof(names));

	i=0;

	/* read file  */	
	while (fgets ( line, sizeof line, file ) != NULL) /* read a line */
	{
		names name;
		strcpy(name.name,line);
		fgets ( line, sizeof line, file );
		strcpy(name.streetAddress,line);
		fgets ( line, sizeof line, file );
		strcpy(name.nameState,line);
		fscanf(file,"%li",&name.zip);
		/*read blank line*/

		fgets ( line, sizeof line, file );
		nameArray[i] = name;
		i++;
	}

	fclose ( file );

	/*calling sort function defined in code.c*/
	sort(nameArray,count);

	for(i=0;i<count;i++)
	{
		fprintf(writer,"%s",nameArray[i].name);
		fprintf(writer,"%s",nameArray[i].streetAddress);
		fprintf(writer,"%s",nameArray[i].nameState);
		fprintf(writer,"%li\n",nameArray[i].zip);
	}

	/*Make sure that the file closes*/
	/*set fclose properly for writer pointer*/
	fclose(writer);
	return 0;

}