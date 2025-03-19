#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100


typedef struct {
    char description[MAX_LENGTH];
    int isComplete; 
} Task;


Task todoList[MAX_TASKS];
int taskCount = 0;


void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Error: Task list is full!\n");
        return;
    }

    printf("Enter the task description: ");
    getchar();  
    fgets(todoList[taskCount].description, MAX_LENGTH, stdin);
    todoList[taskCount].description[strcspn(todoList[taskCount].description, "\n")] = '\0'; // Remove newline character
    todoList[taskCount].isComplete = 0;
    taskCount++;
    printf("Task added successfully!\n");
}


void editTask() {
    int taskIndex;
    printf("Enter the task number to edit (1 to %d): ", taskCount);
    scanf("%d", &taskIndex);
    
    if (taskIndex < 1 || taskIndex > taskCount) {
        printf("Invalid task number!\n");
        return;
    }
    
    printf("Enter the new description for the task: ");
    getchar();  
    fgets(todoList[taskIndex - 1].description, MAX_LENGTH, stdin);
    todoList[taskIndex - 1].description[strcspn(todoList[taskIndex - 1].description, "\n")] = '\0'; // Remove newline character
    printf("Task updated successfully!\n");
}


void markTaskComplete() {
    int taskIndex;
    printf("Enter the task number to mark as complete (1 to %d): ", taskCount);
    scanf("%d", &taskIndex);
    
    if (taskIndex < 1 || taskIndex > taskCount) {
        printf("Invalid task number!\n");
        return;
    }
    
    todoList[taskIndex - 1].isComplete = 1;
    printf("Task marked as complete!\n");
}


void displayTasks() {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("\nTo-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s [%s]\n", i + 1, todoList[i].description, todoList[i].isComplete ? "Complete" : "Incomplete");
    }
}

int main() {
    int choice;
    do {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. Edit Task\n");
        printf("3. Mark Task as Complete\n");
        printf("4. Display Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                editTask();
                break;
            case 3:
                markTaskComplete();
                break;
            case 4:
                displayTasks();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
