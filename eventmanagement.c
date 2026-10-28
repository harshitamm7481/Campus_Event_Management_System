#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int id;
    char name[50];
    char event[50];
    char category[20];
    struct Node *next;
};

struct Node *head = NULL;


void registerParticipant() {
    struct Node *newNode, *temp;
    int id;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\nEnter Registration ID: ");
    scanf("%d", &id);

    temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Registration ID already exists!\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    newNode->id = id;

    printf("Enter Participant Name: ");
    scanf(" %49[^\n]", newNode->name);

    printf("Enter Event Name: ");
    scanf(" %49[^\n]", newNode->event);

    printf("Enter Category (Tech/Non-Tech): ");
    scanf(" %19[^\n]", newNode->category);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("\nParticipant registered successfully!\n");
}


void displayParticipants() {
    struct Node *temp;

    if (head == NULL) {
        printf("\nNo registrations found.\n");
        return;
    }

    temp = head;

    printf("\n========== REGISTERED PARTICIPANTS ==========\n");

    while (temp != NULL) {
        printf("\nRegistration ID: %d\n", temp->id);
        printf("Participant Name: %s\n", temp->name);
        printf("Event Name: %s\n", temp->event);
        printf("Category: %s\n", temp->category);

        temp = temp->next;
    }
}


void searchParticipant() {
    struct Node *temp;
    int id;

    printf("\nEnter Registration ID to search: ");
    scanf("%d", &id);

    temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nParticipant Found!\n");
            printf("Registration ID: %d\n", temp->id);
            printf("Participant Name: %s\n", temp->name);
            printf("Event Name: %s\n", temp->event);
            printf("Category: %s\n", temp->category);
            return;
        }

        temp = temp->next;
    }

    printf("\nParticipant not found.\n");
}


void updateParticipant() {
    struct Node *temp;
    int id, choice;

    printf("\nEnter Registration ID to update: ");
    scanf("%d", &id);

    temp = head;

    while (temp != NULL) {
        if (temp->id == id) {

            do {
                printf("\n===== UPDATE PARTICIPANT DETAILS =====\n");
                printf("1. Update Name\n");
                printf("2. Update Event\n");
                printf("3. Update Category\n");
                printf("4. Exit Update Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("\nOld Name: %s\n", temp->name);
                        printf("Enter New Name: ");
                        scanf(" %49[^\n]", temp->name);
                        printf("Name updated successfully!\n");
                        break;

                    case 2:
                        printf("\nOld Event: %s\n", temp->event);
                        printf("Enter New Event Name: ");
                        scanf(" %49[^\n]", temp->event);
                        printf("Event updated successfully!\n");
                        break;

                    case 3:
                        printf("\nOld Category: %s\n", temp->category);
                        printf("Enter New Category (Tech/Non-Tech): ");
                        scanf(" %19[^\n]", temp->category);
                        printf("Category updated successfully!\n");
                        break;

                    case 4:
                        printf("Exiting update menu.\n");
                        break;

                    default:
                        printf("Invalid choice! Please enter 1 to 4.\n");
                }

            } while (choice != 4);

            return;
        }

        temp = temp->next;
    }

    printf("\nParticipant not found.\n");
}


void cancelRegistration() {
    struct Node *temp, *prev;
    int id;

    printf("\nEnter Registration ID to cancel: ");
    scanf("%d", &id);

    temp = head;
    prev = NULL;

    while (temp != NULL) {
        if (temp->id == id) {

            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);

            printf("\nRegistration cancelled successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nParticipant not found.\n");
}


void countParticipants() {
    struct Node *temp;
    int count = 0;

    temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("\nTotal Registered Participants: %d\n", count);
}


void loadSampleParticipants() {
    int ids[] = {101, 102, 103, 104, 105, 106};

    char names[][50] = {
        "Aarav Patel",
        "Diya Shah",
        "Rohan Mehta",
        "Ananya Desai",
        "Karan Joshi",
        "Priya Shah"
    };

    char events[][50] = {
        "Coding Contest",
        "Tech Quiz",
        "Dance Competition",
        "Robotics Challenge",
        "Singing Competition",
        "Poster Making"
    };

    char categories[][20] = {
        "Tech",
        "Tech",
        "Non-Tech",
        "Tech",
        "Non-Tech",
        "Non-Tech"
    };

    for (int i = 0; i < 6; i++) {
        struct Node *newNode;

        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed while loading sample data.\n");
            return;
        }

        newNode->id = ids[i];

        strcpy(newNode->name, names[i]);
        strcpy(newNode->event, events[i]);
        strcpy(newNode->category, categories[i]);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            struct Node *temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

int main() {
    int choice;

    loadSampleParticipants();

    do {
        printf("\n============================================\n");
        printf("   CAMPUS EVENT REGISTRATION SYSTEM\n");
        printf("============================================\n");

        printf("1. Register Participant\n");
        printf("2. Display All Participants\n");
        printf("3. Search Participant\n");
        printf("4. Update Participant Details\n");
        printf("5. Cancel Registration\n");
        printf("6. Count Participants\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 7) {
            printf("\nInvalid choice! Please enter a number between 1 and 7.\n");
            continue;
        }

        switch (choice) {
            case 1:
                registerParticipant();
                break;

            case 2:
                displayParticipants();
                break;

            case 3:
                searchParticipant();
                break;

            case 4:
                updateParticipant();
                break;

            case 5:
                cancelRegistration();
                break;

            case 6:
                countParticipants();
                break;

            case 7:
                printf("\nThank you for using the system!\n");
                break;
        }

    } while (choice != 7);

    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


