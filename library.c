#include "library.h"

void createNewFile(const char* filename)
{
	char* file = (char*) malloc((sizeof(filename)+13) * sizeof(char));
	
	if(file==NULL)
	{
		printf("Unexpected Error!\n");
		return;
	}
	
	strcpy(file,PATH);
	strcat(file,filename);
	strcat(file,".txt");
	
	FILE *fp = fopen(file,"r");
	if(fp!=NULL)
	{
		printf("File Already Exists!\n");
		return;
	}
	fclose(fp);
	
	printf("Creating file %s ....\n",file);
	
	fp = fopen(file,"w+");
	
	if(fp==NULL)
	{
		printf("Failed to create %s. This inconvience is deeply regretted.\n",file);
		return;
	}
	
	char text[128];
	fflush(stdin); printf("Enter Text : "); scanf("%[^\n]",text); fflush(stdin);
	fprintf(fp,"%s",text);
	printf("Created file %s successfully....\n",file);
	
	fclose(fp);
}
void deleteFile(const char* filename)
{
	char* file = (char*) malloc((sizeof(filename)+13) * sizeof(char));
	
	if(file==NULL)
	{
		printf("Unexpected Error!\n");
		return;
	}
	
	strcpy(file,PATH);
	strcat(file,filename);
	
	if(!(remove(file)))
		printf("File deleted successfully...\n");
	else
		printf("Unable to delete the file.\n");
}
void modifyFile(const char* filename)
{
	char* file = (char*) malloc((sizeof(filename)+13) * sizeof(char));
	
	if(file==NULL)
	{
		printf("Unexpected Error!\n");
		return;
	}
	
	strcpy(file,PATH);
	strcat(file,filename);
	
	FILE *fp = fopen(file,"r");
	
	if(fp==NULL)
	{
		printf("File Not Found.\n");
		return;
	}
	
	char existing_text[128];
	fscanf(fp, "%[^\n]", existing_text);
	printf("Existing Text in %s : %s\n",file,existing_text);
	fclose(fp);
	
	unsigned short int choice;
	printf("Do you wish to modify the text in %s (Yes = 1 , No = 0) ? ",file); scanf("%hu",&choice);
	
	if(choice)
	{
		fp = fopen(file,"w+");
		printf("Modifying file %s ....\n",file);
		char text[128];
		fflush(stdin); printf("Enter New Text : "); scanf("%[^\n]",text); fflush(stdin);
		fprintf(fp,"%s",text);
		printf("Modified file %s successfully....\n",file);
		fclose(fp);
	}
}
void viewFile(const char* filename)
{
	char* file = (char*) malloc((sizeof(filename)+13) * sizeof(char));
	
	if(file==NULL)
	{
		printf("Unexpected Error!\n");
		return;
	}
	
	strcpy(file,PATH);
	strcat(file,filename);
	
	FILE *fp = fopen(file,"r");
	
	if(fp==NULL)
	{
		printf("File Not Found.\n");
		return;
	}
	
	char existing_text[128];
	fscanf(fp, "%[^\n]", existing_text);
	printf("Contents of %s : %s\n",file,existing_text);
	fclose(fp);
	
}
void listDir()
{
	struct dirent *entry;
	DIR *dp;
	dp = opendir(PATH);
	if(dp==NULL)
	{
		printf("Couldn't open the Directory.\n");
		return;
	}
	printf("Directory Listing of ./Files\n");
	printf("----------------------------\n");
	while((entry = readdir(dp)))
		puts(entry->d_name);
	printf("\n");
	closedir(dp);
		
}
