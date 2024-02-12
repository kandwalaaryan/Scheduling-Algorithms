/**
 * This scheduler integrates priority scheduling with round-robin scheduling.
 * It prioritizes tasks based on their priority level, and applies a round-robin method for tasks of equal priority.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "list.h"
#include "cpu.h"

// Pointer to the start of the linked list holding the tasks
struct node *head = NULL;

// Counter to keep track of the total number of tasks added
int numberOfTasks = 0;

// Forward declarations of functions
Task **pickNextTasks();

// Function to add a new task to the scheduler
void add(char *name, int priority, int burst) {
    Task *newTask = (Task *)malloc(sizeof(Task));
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;
    insert(&head, newTask);  // Add the new task to the end of the list
    numberOfTasks++;         // Increment the total number of tasks
}

// Function to start the task scheduling process
void schedule() {
    Task **currentTasks;     // Array to hold tasks of the highest current priority
    
    // Output the task list for confirmation
    traverse(head);

    // Continue scheduling until there are no tasks left
    while (head != NULL) {
        currentTasks = pickNextTasks();  // Get the tasks with the highest priority
        
        for (int i = 0; currentTasks[i] != NULL; i++) {
            Task *task = currentTasks[i];

            // Compute the time slice for the task, considering the quantum limit
            int slice = task->burst > QUANTUM ? QUANTUM : task->burst;
            run(task, slice);  // Execute the task for its time slice

            task->burst -= slice;  // Reduce the remaining burst time of the task

            // Eliminate tasks that have completed their execution
            if (task->burst == 0) {
                delete(&head, task);
            }
        }
        free(currentTasks);  // Release memory allocated for the array of tasks
    }
}

// Function to identify and return the next set of highest priority tasks
Task **pickNextTasks() {
    Task *highestPriorityTask = NULL;
    struct node *temp;
    
    // Loop to find the task with the highest priority in the list
    for (temp = head; temp != NULL; temp = temp->next) {
        if (!highestPriorityTask || temp->task->priority > highestPriorityTask->priority) {
            highestPriorityTask = temp->task;
        }
    }

    // Allocate memory for an array to hold tasks with the highest priority
    Task **tasksWithHighestPriority = (Task **)calloc(numberOfTasks + 1, sizeof(Task *));

    // Fill the array with tasks that have the highest priority
    int index = 0;
    for (temp = head; temp != NULL; temp = temp->next) {
        if (temp->task->priority == highestPriorityTask->priority) {
            tasksWithHighestPriority[index++] = temp->task;
        }
    }

    return tasksWithHighestPriority;  // Return the array of highest priority tasks
}

