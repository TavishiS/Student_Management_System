#include <stdio.h>
#include <string.h>

struct usrdata
{
    char id[50];
    char password[50];
} user1, check;

void signup()
{
    FILE *fp = fopen("userdata.txt", "a+");
    char userid[20], password[20], confirm[20];
    printf("Enter your user-id\n");
    getchar();
    gets(userid);
    printf("Enter your password\n");
    gets(password);
    printf("Confirm your password\n");
    // getchar();
    gets(confirm);

    if (strcmp(password, confirm) == 0)
    {
        fprintf(fp, "%s\t%s", userid, password);
        printf("\033[1;36m");
        printf("New user successfully created!...  Remember your credentials.");
	    printf("\033[1;32m");

    }

    else
    {
        printf("Confirm password does not match\n");
        main();
    }
}

void login()
{
    getchar();
    printf("Enter user id: ");
    scanf("%[^\n]", check.id);
    printf("Enter password: ");
    getchar();
    scanf("%[^\n]", check.password);
    FILE *fp = fopen("userdata.txt", "r+");
    char temp_id[50], temp_password[50];
    int found = 0;
    while (fscanf(fp, "%[^\t] %[^\n]\n", temp_id, temp_password) != EOF)
    {
        if (strcmp(check.id, temp_id) == 0 && strcmp(check.password, temp_password) == 0)
        { // strcmp se do strings match karwate h agar match ho gaye to 0 return karta
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found)
    {
        printf("\033[1;31m");
        printf("Invalid id or password\n");
        printf("\033[1;32m");
        main();
    }
}

int check_if_present(char id[])
{
    FILE *fptr = fopen("userdata.txt", "r");
    char temp_id[10], temp_password[30];
    while (fscanf(fptr, "%s %s", temp_id, temp_password) != EOF)
    {
        if (strcmp(temp_id, id) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void deleteid()
{
    char del_id[50];
    FILE *temp_fp = fopen("temp_userdata.txt", "w");
    FILE *fp = fopen("userdata.txt", "r");
    do
    {
        printf("Enter id to be deleted :");
        scanf("%s", del_id);
        // char del_id[10];
        char temp_id[50], temp_password[50];
        if (check_if_present(del_id) == 1)
        {
            while (fscanf(fp, "%s %s\n", temp_id, temp_password) != EOF)
            {
                if (strcmp(del_id, temp_id) != 0)
                {
                    fprintf(temp_fp, "%s\t%s\n", temp_id, temp_password);
                }
            }
            remove("userdata.txt");                      // Remove  original file
            rename("temp_userdata.txt", "userdata.txt"); // Rename the temporary file to the original name
            printf("User with ID %s deleted successfully\n", del_id);
        }
        else
        {
            printf("Invalid id...\n");
            fclose(fp);
            fclose(temp_fp);
        }
        
    }while (check_if_present(del_id) == 0) ;
}
