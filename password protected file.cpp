#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int new_file_create();
int existing_file_open();
int read_data(FILE *user_file);
int update_data(FILE *user_file);
int feeding_data(FILE *user_file);

int main()
{
	int i;
	
	// Taking input from the user for first time with welcome message.
	printf("Hello User\nEnter 0: Exit\nEnter 1: Open new file\nEnter 2: Open existing file\n");
	scanf("%d",&i);

	while(i!=0){
		if(i==1) new_file_create();						// Creating the new file.
		else if(i==2) existing_file_open();				// Opening the existing file.
		else printf("\nEnter valid Input!!!");
		
		// Taking input from the user for the subsequent times.
		printf("\nEnter 0: Exit\nEnter 1: Open new file\nEnter 2: Open existing file\n"); 
		fflush(stdin);
		scanf("%d",&i);
		system("cls");
	}
		
	return 0;
}

// Function for opening an existing file.
int existing_file_open()
{
	fflush(stdin);
	system("cls");
	FILE *user_file;
	int i;
	char username[40], password[20];

	printf("\nEnter your username:");
	scanf("%s",username);
	printf("\nEnter password:");
	scanf("%s",password);
	strcat(username, strcat(password,".txt"));
	
	// Opening the file.
	user_file = fopen(username,"r");
	if (user_file==NULL) {
		printf("\nWARNING: Invalid username or password.");
		return 0;
	}
	
	// Taking input from the user first time.
	printf("Enter 0: Return\nEnter 1: Read data\nEnter 2: Update data\n");
	fflush(stdin);
	scanf("%d",&i);
	system("cls");
	
	while(i!=0){
		if (i==1) read_data(user_file);
		else if(i==2) {
			fclose(user_file);
			user_file = fopen(username,"w");
			update_data(user_file);
		}
		
		// Taking input from the user for the subsequent times.
		printf("\nEnter 0: Return\nEnter 1: Read data\nEnter 2: Update data\n");
		fflush(stdin);
		scanf("%d",&i);
		user_file = fopen(username,"r");
	}
	
	// Closing the file.
	if(user_file!=NULL) fclose(user_file);
	return 0;
	
}

// Function for creating a new file.
int new_file_create()
{
	fflush(stdin);
	system("cls");
	FILE *user_file;
	char username[40], password[20];
	
	printf("Enter a username(no spaces and not greater than 20 characters):");
	scanf("%s",username);
	printf("\nMake a password(not greater than 15 characters):");
	scanf("%s",password);
	strcat(username,strcat(password, ".txt"));
	printf("\n%s", username);
	
	// Opening the new file.
	user_file = fopen(username, "w");
	
	// Calling the feeding_data function.
	feeding_data(user_file);
	
	// Closing the file.
	if(user_file!=NULL) fclose(user_file);
	return 0;
}

// Function for reading data from a file.
int read_data(FILE *user_file)
{
	char ch[50];
	fscanf(user_file,"%[^'\0']s",ch);
	printf("%s",ch);
	fclose(user_file);
	return 0;
}

// Function for updating the data inside a file.
int update_data(FILE *user_file)
{
	char ch[50];
	printf("(use . (dot) to end the file)\n");
	scanf("%[^.]s",ch);
	fprintf(user_file,"%s",ch);
	fclose(user_file);
	return 0;
}

// Function for feeding the data inside a file.
int feeding_data(FILE *user_file)
{
	system("cls");
	int i; char data[50];
	printf("Enter 0: Close file\nEnter 1: Feed data\n");
	fflush(stdin);
	scanf("%d",&i);
	
	while(i!=0){
		if(i==0) return 0;
		else if(i==1){
			printf("(use . (dot) to end the file)\n");
			scanf("%[^.]s",data);
			fprintf(user_file,"%s",data);
			fclose(user_file);
			return 0;
		}
		else printf("\nWARNING: Invalid input.");
	printf("\nEnter 0: Close file\nEnter 1: Feed data");
	fflush(stdin);
	scanf("%d",&i);
	}
}
