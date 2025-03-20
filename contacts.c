#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Contact manager with intentional errors for Cppcheck testing

typedef struct {
    char name[50];
    char phone[15];
} Contact;

void add_contact(Contact contacts[], int *count) {
    if (*count >= 5) {
        printf("Contact list is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", contacts[*count].name); // Possible buffer overflow
    printf("Enter phone: ");
    scanf("%s", contacts[*count].phone); // Possible buffer overflow
    (*count)++;
}

void list_contacts(Contact contacts[], int count) {
    for (int i = 0; i < count; i++) { 
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

int main() {
    Contact contacts[5];
    int count; // Uninitialized variable
    int choice;
    
    while (1) {
        printf("\n1. Add Contact\n2. List Contacts\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_contact(contacts, &count);
                break;
            case 2:
                list_contacts(contacts, count);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}
