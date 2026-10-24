#include <stdio.h>

#define MAX 100

struct PrintJob
{
    int jobID;
    char studentName[50];
    char documentName[100];
    int pages;
};

struct PrintJob queue[MAX];

int front = -1;
int rear = -1;

int nextJobID = 101;
int totalSubmitted = 0;
int totalCompleted = 0;


void submitJob()
{
    int pages;
    int index;

    
    if (rear == MAX - 1)
    {
        printf("\nPrint queue is full!\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    index = rear;

    queue[index].jobID = nextJobID++;

    printf("\nEnter student name: ");
    scanf("%49s", queue[index].studentName);

    printf("Enter document name: ");
    scanf("%99s", queue[index].documentName);

    printf("Enter number of pages: ");
    scanf("%d", &pages);


    if (pages <= 0)
    {
        printf("\nInvalid page count! Job not submitted.\n");

        rear--;

        if (rear == -1)
        {
            front = -1;
        }

        nextJobID--;

        return;
    }

    queue[index].pages = pages;

    totalSubmitted++;

    printf("\nPrint job submitted successfully!\n");
    printf("Your Job ID is: %d\n", queue[index].jobID);
}


void processNextJob()
{
    
    if (front == -1)
    {
        printf("\nNo pending print jobs!\n");
        return;
    }

    
    printf("\n--- Processing Print Job ---\n");

    printf("Job ID: %d\n", queue[front].jobID);
    printf("Student Name: %s\n", queue[front].studentName);
    printf("Document Name: %s\n", queue[front].documentName);
    printf("Number of Pages: %d\n", queue[front].pages);

    printf("\nPrint job completed successfully\n");

    totalCompleted++;


    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}


void displayPendingJobs()
{
    int i;

    if (front == -1)
    {
        printf("\nNo pending print jobs!\n");
        return;
    }

    printf("\n--- Pending Print Jobs ---\n");

    for (i = front; i <= rear; i++)
    {
        printf("\n--------------------------\n");

        printf("Job ID: %d\n", queue[i].jobID);
        printf("Student Name: %s\n", queue[i].studentName);
        printf("Document Name: %s\n", queue[i].documentName);
        printf("Pages: %d\n", queue[i].pages);
    }

    printf("\n--------------------------\n");
}


void viewNextJob()
{
    if (front == -1)
    {
        printf("\nNo pending print jobs!\n");
        return;
    }

    printf("\n--- Next Print Job ---\n");

    printf("Job ID: %d\n", queue[front].jobID);
    printf("Student Name: %s\n", queue[front].studentName);
    printf("Document Name: %s\n", queue[front].documentName);
    printf("Pages: %d\n", queue[front].pages);
}


void viewStatistics()
{
    int pendingJobs;
    int totalPendingPages = 0;
    int i;

    pendingJobs = totalSubmitted - totalCompleted;

    if (front != -1)
    {
        for (i = front; i <= rear; i++)
        {
            totalPendingPages =
                totalPendingPages + queue[i].pages;
        }
    }

    printf("\n--- Printing Statistics ---\n");

    printf("Total Jobs Submitted: %d\n", totalSubmitted);
    printf("Total Jobs Completed: %d\n", totalCompleted);
    printf("Total Jobs Pending: %d\n", pendingJobs);
    printf("Total Pages Pending: %d\n", totalPendingPages);
}


int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf(" SMART PRINTER QUEUE MANAGEMENT\n");
        printf("====================================\n");

        printf("1. Submit Print Job\n");
        printf("2. Process Next Print Job\n");
        printf("3. Display Pending Jobs\n");
        printf("4. View Next Print Job\n");
        printf("5. View Printing Statistics\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                submitJob();
                break;

            case 2:
                processNextJob();
                break;

            case 3:
                displayPendingJobs();
                break;

            case 4:
                viewNextJob();
                break;

            case 5:
                viewStatistics();
                break;

            case 6:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Please select 1-6.\n");
        }

    } while (choice != 6);

    return 0;
} 