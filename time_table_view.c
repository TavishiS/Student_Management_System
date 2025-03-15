#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void time_table(char section) {
    if(section == 'a' ||  section == 'A'){
    const char* imagePath = "C:/Users/sagar/Desktop/eren.jpeg";
        char command[100];
        snprintf(command, sizeof(command), "start %s", imagePath);
        system(command);
    return 0;}

    else if(section == 'b' || section == 'B'){
    const char* imagePath = "C:/Users/sagar/Desktop/levi.jpeg";
        char command[100];
        snprintf(command, sizeof(command), "start %s", imagePath);
        system(command);
    return 0;}

    else{
        printf("\033[1;31m");
        printf("Invalid!\n");
	    printf("\033[1;32m");
        printf("Enter Section(A/B):");
        fflush(stdin);
        getchar();
            scanf("%c",&section);
                time_table(section);
        }
        
    
}
