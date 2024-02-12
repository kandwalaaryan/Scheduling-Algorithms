/* SJF Scheduling Algorithm
 *
 * Chooses the task with the minimum execution time required and schedules it next.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "task.h"
#include "list.h"
#include "cpu.h"

// Root node for the task queue
struct node *head = NULL;

// Incremental counter for task IDs
int nextTid = 0;

// Declare the next task selection function
Task *pickNextTask();

// Insert a task into the queue
void add(char *name, int priority, int burst) {
    Task *newTask = (Task *)malloc(sizeof(Task));  // Allocate new task
    newTask->name = name;  // Set task name
    newTask->tid = nextTid++;  // Assign an incremental unique ID
    newTask->priority = priority;  // Set task priority (unused in SJF)
    newTask->burst = burst;  // Set task burst time
    insert(&head, newTask);  // Place the task into the linked list
}

// Executes the task schedule
void schedule() {
    Task *currentTask;
    // Cycle through tasks until the queue is empty
    while ((currentTask = pickNextTask()) != NULL) {
        run(currentTask, currentTask->burst);  // Execute the chosen task fully
        delete(&head, currentTask);  // Clean up the completed task from the queue
    }
}

// Selects the task with the least burst time remaining
Task *pickNextTask() {
    struct node *current = head;
    Task *shortestTask = NULL;  // This will point to the shortest task found
    int shortestBurst = INT_MAX;  // Placeholder for the shortest burst duration

    // Loop over all tasks, identifying the one with the smallest burst
    while (current != NULL) {
        // Update shortest task if a new one with a smaller burst is found
        if (current->task->burst < shortestBurst) {
            shortestBurst = current->task->burst;  // Update shortest burst value
            shortestTask = current->task;  // Update shortest task pointer
        }
        current = current->next;  // Move to the next task in the queue
    }

    return shortestTask;  // Deliver the task with the shortest burst for execution
}

