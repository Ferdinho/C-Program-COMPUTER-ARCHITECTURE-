//This program lists all contacts whose age is in between 18 and 25 from a file contact.txt.
//Ferdinand Tembo

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


//struct Contact *contactList[];

// a scruture for date
struct Date {
    int *day ;
    int *month;
    int *year;
};
// a stucture for name
struct Name{
    char *firstName[15];
    char *lastName[15];
};
//a structure for Contact
struct Contact {
    int age;
    struct Name name1;
    struct Date date1;

};


// This function is loding contact from my file contact.txt and print the contact in the appropriate format
void loadContact () {
    struct Name name;
    struct Date date1;
    struct Contact c1;

    FILE *fPointer;
    fPointer = fopen("/Users/ferdinandtembo/CLionProjects/ComputerArchitecturePart1/contacts.txt", "r");
    if (fPointer == NULL) {
        int errnum = errno;
        fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
    }


    char singleLine[41];
    char test[41];
    char test1[10];
    while (!feof(fPointer)) {
        fgets(singleLine, 41, fPointer);
        // spliting the line into 3 part, here I got the firstmane
        strcpy(test, singleLine);
        char *token = strtok(test, " ");
        name.firstName[15] = token;
        int count = 1;
        // here I got the lastmane
        while (token != NULL) {
            if (count == 2) {
                name.lastName[15] = token;
            }
        // Here I got the date
            if (count == 3) {
                // the date also have 3 part, but in this one I'm taking the day
                char *myDay = token;
                char *day;
                day = strndup(myDay + 3, 2);

                // In this one I'm taking the month
                char *myMonth = token;
                char *month;
                month = strndup(myMonth + 0, 2);

                // In this one I'm taking my year
                char *myYear = token;
                char *year;
                year = strndup(myYear + 6, 10);

                date1.day = atoi(day);
                date1.month = atoi(month);
                date1.year = atoi(year);

                c1.name1 = name;
                c1.date1 = date1;
                c1.age = date1.year;
            }
            count += 1;
            token = strtok(NULL, " ");

        }
        // doing some initialisation
        int currentAge = 2018 - c1.age;
        char *initial = name.firstName[15];
        char *initialLetter;
        initialLetter = strndup(initial, 1);

        //printing the correct format
        if (currentAge >= 18 && currentAge <= 25) {

            printf("%s.%s,%d\n", initialLetter, name.lastName[15], currentAge);
        }

        }

}

int main() {
    loadContact();
    return 0;

}