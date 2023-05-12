#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#define PATH "./Files/"

void createNewFile(const char* filename);  //Creates a new filename.txt at PATH 
void modifyFile(const char* filename); 	   //Modifies an existing file in PATH
void deleteFile(const char* filename);	   //Deletes an existing file in PATH
void viewFile(const char* filename);	   //Views and prints the contents of an existing file in PATH
void listDir();							   //Prints the directory listing of PATH
