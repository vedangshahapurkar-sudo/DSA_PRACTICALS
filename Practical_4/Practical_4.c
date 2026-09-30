#include <stdio.h>

struct employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

int main() {
    struct employee emp[100];
    int n = 0, choice, i, id, found;

    do {
        printf("\n\n===== EMPLOYEE DATABASE =====");
        printf("\n1. Create Database");
        printf("\n2. Display Employees");
        printf("\n3. Search Employee");
        printf("\n4. Update Employee");
        printf("\n5. Insert New Employee");
        printf("\n6. Delete Employee");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("\nEnter number of employees: ");
            scanf("%d", &n);

            for(i = 0; i < n; i++) {
                printf("\nEnter Employee ID: ");
                scanf("%d", &emp[i].id);

                getchar();
                printf("\nEnter Employee Name: ");
                fgets(emp[i].name, 50, stdin);

                printf("\nEnter Department: ");
                fgets(emp[i].department, 30, stdin);

                printf("\nEnter Salary: ");
                scanf("%f", &emp[i].salary);
            }

            printf("\nDatabase created successfully.");
            break;

        case 2:
            if(n == 0)
                printf("\nDatabase is empty.");
            else {
                for(i = 0; i < n; i++) {
                    printf("\n\nEmployee %d", i + 1);
                    printf("\nID: %d", emp[i].id);
                    printf("Name: %s", emp[i].name);
                    printf("Department: %s", emp[i].department);
                    printf("Salary: %.2f", emp[i].salary);
                }
            }
            break;

        case 3:
            printf("\nEnter Employee ID to search: ");
            scanf("%d", &id);
            found = 0;

            for(i = 0; i < n; i++) {
                if(emp[i].id == id) {
                    printf("\nEmployee Found!");
                    printf("\nID: %d", emp[i].id);
                    printf("\nName: %s", emp[i].name);
                    printf("\nDepartment: %s", emp[i].department);
                    printf("\nSalary: %.2f", emp[i].salary);
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("\nEmployee not found.");
            break;

        case 4:
            printf("\nEnter Employee ID to update: ");
            scanf("%d", &id);
            found = 0;

            for(i = 0; i < n; i++) {
                if(emp[i].id == id) {
                    getchar();

                    printf("\nEnter new Name: ");
                    fgets(emp[i].name, 50, stdin);

                    printf("Enter new Department: ");
                    fgets(emp[i].department, 30, stdin);

                    printf("Enter new Salary: ");
                    scanf("%f", &emp[i].salary);

                    printf("\nEmployee updated successfully.");
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("\nEmployee not found.");
            break;

        case 5:
            if(n >= 100)
                printf("\nDatabase is full.");
            else {
                printf("\nEnter Employee ID: ");
                scanf("%d", &emp[n].id);

                getchar();
                printf("Enter Employee Name: ");
                fgets(emp[n].name, 50, stdin);

                printf("Enter Department: ");
                fgets(emp[n].department, 30, stdin);

                printf("Enter Salary: ");
                scanf("%f", &emp[n].salary);

                n++;
                printf("\nEmployee inserted successfully.");
            }
            break;

        case 6:
            printf("\nEnter Employee ID to delete: ");
            scanf("%d", &id);
            found = 0;

            for(i = 0; i < n; i++) {
                if(emp[i].id == id) {
                    for(int j = i; j < n - 1; j++)
                        emp[j] = emp[j + 1];

                    n--;
                    printf("\nEmployee deleted successfully.");
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("\nEmployee not found.");
            break;

        case 7:
            printf("\nExiting Program...");
            break;

        default:
            printf("\nEnter a valid choice.");
        }

    } while(choice != 7);

    return 0;
}
