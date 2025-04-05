#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

//Function to create a file and set permissions
void create_file_set_permission()
{
	int fd;
	char filename[10];
	printf("Enter the filename or path\n");
	scanf("%s", filename);
	fd = creat(filename, 0664);
	if(fd == -1)
	{
		perror("Error creating file! ");
	}
	close(fd);
}


//Function to check user permissions
void check_user_permission()
{
	int fd;
	char filename[10];
	printf("Enter the filename or path\n");
	scanf("%s", filename);
	fd = access(filename, F_OK);
	if(fd == -1)
	{
		perror("File not found! ");
	}
	fd = access(filename, R_OK);
	if(fd == 0)
	{
		printf("READ ");
	}
	fd = access(filename, W_OK);
	if(fd == 0)
        {
                printf("WRITE ");
        }
	fd = access(filename, X_OK);
        if(fd == 0)
        {
                printf("EXECUTE ");
        }
	printf("permissions are active\n");
	close(fd);
}


//Function to delete a file
void delete_file()
{
	char filename[10];
	printf("Enter the filename or path\n");
	scanf("%s", filename);
	if(remove(filename) == 0)
	{
		printf("File deleted successfully\n");
	}
	else
	{
		perror("Error deleting the file! ");
	}
}


//Function to write into a file
void write_file()
{
	char filename[10];
	char str[20];
	printf("Enter the file to open\n");
	scanf("%s", filename);
	printf("Enter the string to be written into the file\n");
	scanf("%s", str);
	int fd = open(filename, O_WRONLY);
	if(fd == -1)
	{
		perror("Error opening file for writing ");
	}
	else
	{
		if(write(fd, str, strlen(str)) == -1)
		{
			perror("Write failed!");
			close(fd);
		}
		else
		{
			printf("Successfully written into the file\n");
			close(fd);
		}
	}
}


//Function to read from a file and display it
void read_file()
{
	char filename[10];
	char str[20];
	printf("Enter the file to open\n");
	scanf("%s", filename);
	int fd = open(filename, O_RDONLY);
	if(fd == -1)
	{
		perror("Error opening file for reading ");
	}
	else
	{
		int size_str = read(fd, str, sizeof(str)-1);
		if(size_str == -1)
		{
			perror("Read failed! ");
			close(fd);
		}
		else
		{
			str[size_str] = '\0';
			printf("%s\n", str);
			close(fd);
		}
	}

}

int main()
{
	int choice;
	char ch;
	while(1)
	{
		printf("\n\n\nMenu:\n1. Write a program to create a file and set different permissions\n2. Write a program to check the user permissions using system call and print the error message\n3. Delete a file\n4. Write to a file\n5. Read from a file\n\n");
		scanf("%d", &choice);
		printf("\n");
		switch(choice)
		{
			case 1: create_file_set_permission(); break;
			case 2: check_user_permission(); break;
			case 3: delete_file(); break;
			case 4: write_file(); break;
			case 5: read_file(); break;
		}
		printf("\n\nDo you want to continue?\n");
		scanf(" %c", &ch);
		if(ch == 'N' || ch == 'n')
		{
			return 0;
		}
	}
}

