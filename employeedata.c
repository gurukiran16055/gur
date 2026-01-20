#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Employee {
    char ssn[25];
    char name[25];
    char dept[25];
    char designation[30];
    float salary;
    char phone[15];
} Employee;
typedef struct Node {
    Employee data;
    struct Node *prev, *next;
} Node;

Node *head = NULL;

Node* createNode(Employee emp) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = emp;
    newNode->prev = newNode->next = NULL;
    return newNode;
}
Employee inputEmployee() {
    Employee emp;
    printf("Enter SSN: ");
    scanf("%s", emp.ssn);
    printf("Enter Name: ");
    scanf(" %[^\n]", emp.name);
    printf("Enter Department: ");
    scanf(" %[^\n]", emp.dept);
    printf("Enter Designation: ");
    scanf(" %[^\n]", emp.designation);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    printf("Enter Phone Number: ");
    scanf("%s", emp.phone);
    return emp;
}

void insertFront() {
    Employee emp = inputEmployee();
    Node *newNode = createNode(emp);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Employee inserted at front.\n");
}


void insertEnd() {
    Employee emp = inputEmployee();
    Node *newNode = createNode(emp);
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Employee inserted at end.\n");
}


void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    printf("Deleted Employee SSN: %s\n", temp->data.ssn);
    free(temp);
}
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    if (temp->next == NULL) {
        printf("Deleted Employee SSN: %s\n", temp->data.ssn);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    printf("Deleted Employee SSN: %s\n", temp->data.ssn);
    free(temp);
}

void displayForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    printf("\nEmployee List (Forward):\n");
    while (temp != NULL) {
        printf("SSN: %s | Name: %s | Dept: %s | Designation: %s | Salary: %.2f | Phone: %s\n",
               temp->data.ssn, temp->data.name, temp->data.dept,
               temp->data.designation, temp->data.salary, temp->data.phone);
        temp = temp->next;
    }
}

void displayBackward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("\nEmployee List (Backward):\n");
    while (temp != NULL) {
        printf("SSN: %s | Name: %s | Dept: %s | Designation: %s | Salary: %.2f | Phone: %s\n",
               temp->data.ssn, temp->data.name, temp->data.dept,
               temp->data.designation, temp->data.salary, temp->data.phone);
        temp = temp->prev;
    }
}


void countNodes() {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total Employees: %d\n", count);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Employee DLL Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from End\n");
        printf("5. Display Forward\n");
        printf("6. Display Backward\n");
        printf("7. Count Employees\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }
        switch (choice) {
            case 1: insertFront(); break;
            case 2: insertEnd(); break;
            case 3: deleteFront(); break;
            case 4: deleteEnd(); break;
            case 5: displayForward(); break;
            case 6: displayBackward(); break;
            case 7: countNodes(); break;
            case 8: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}



