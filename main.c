#include "library.h"

void displayMenu()	//Used to display the menu.
{
	printf("------------------------------\n");
	printf("             MENU             \n");
	printf("------------------------------\n");
	printf("1. Create a new file\n");
	printf("2. Modifying an existing file\n");
	printf("3. Deleting a file\n");
	printf("4. View contents of a file\n");
	printf("5. See directory listing\n");
	printf("------------------------------\n");
	printf("\nYour Choice : ");
}
void main()
{
	unsigned short int choice;
	char filename[30];
	do
	{
		printf("\n");
		displayMenu();
		scanf("%hu",&choice);
		printf("\n");
		switch(choice)
		{
			case 1 : printf("File Name : "); scanf("%s",filename);
					 createNewFile(filename);
					 break;
			case 2 : printf("File Name (with extension) : "); scanf("%s",filename);
					 modifyFile(filename);
					 break;
			case 3 : printf("File Name (with extension) : "); scanf("%s",filename);
					 deleteFile(filename);
					 break;
			case 4 : printf("File Name (with extension) : "); scanf("%s",filename);
					 viewFile(filename);
					 break;
			case 5 : listDir();
					 break;
			default : printf("Invalid Choice!\n");
		}
		printf("\n");
		printf("Do you wish to continue(Yes = 1, No = 0)? "); scanf("%hu",&choice);
	}while(choice);
}
