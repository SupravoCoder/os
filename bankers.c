#include <stdio.h>

#define MAX 5

// Structure to represent a process
struct Process {
    int processID;
    int allocated[MAX];
    int max[MAX];
    int need[MAX];
};

// Structure to represent the system state
struct System {
    int available[MAX];
    int work[MAX];
    int n, m;
    struct Process processes[MAX];
};

void initialize(struct System *system, int n, int m) {
    system->n = n;
    system->m = m;
    for (int i = 0; i < m; i++) {
        system->available[i] = 0;
        system->work[i] = 0;
    }
}

void addProcess(struct System *system, int processID, int allocated[], int max[]) {
    system->processes[system->n].processID = processID;
    for (int i = 0; i < system->m; i++) {
        system->processes[system->n].allocated[i] = allocated[i];
        system->processes[system->n].max[i] = max[i];
        system->processes[system->n].need[i] = max[i];
    }
    system->n++;
}

int isSafe(struct System *system, int processID) {
    int work[MAX];
    int available[MAX];
    int need[MAX];
    int allocated[MAX];

    for (int i = 0; i < system->m; i++) {
        work[i] = system->work[i];
        available[i] = system->available[i];
        need[i] = system->processes[processID].need[i];
        allocated[i] = system->processes[processID].allocated[i];
    }

    for (int i = 0; i < system->m; i++) {
        work[i] += allocated[i];
    }

    for (int i = 0; i < system->m; i++) {
        if (work[i] > available[i]) {
            return 0; // Not safe
        }
    }

    return 1; // Safe
}

void request(struct System *system, int processID, int request[]) {
    int work[MAX];
    int available[MAX];
    int need[MAX];
    int allocated[MAX];

    for (int i = 0; i < system->m; i++) {
        work[i] = system->work[i];
        available[i] = system->available[i];
        need[i] = system->processes[processID].need[i];
        allocated[i] = system->processes[processID].allocated[i];
    }

    for (int i = 0; i < system->m; i++) {
        work[i] -= allocated[i];
        work[i] += request[i];
    }

    for (int i = 0; i < system->m; i++) {
        if (work[i] > available[i]) {
            return; // Request denied
        }
    }

    for (int i = 0; i < system->m; i++) {
        available[i] -= request[i];
        need[i] -= request[i];
    }

    for (int i = 0; i < system->m; i++) {
        system->work[i] = work[i];
        system->available[i] = available[i];
    }
}

int main() {
    struct System system;
    int n = 3; // Number of processes
    int m = 3; // Number of resources

    initialize(&system, n, m);

    // Add processes
    int allocated1[] = {0, 1, 0};
    int max1[] = {7, 5, 3};
    addProcess(&system, 0, allocated1, max1);

    int allocated2[] = {2, 0, 0};
    int max2[] = {3, 2, 2};
    addProcess(&system, 1, allocated2, max2);

    int allocated3[] = {3, 0, 2};
    int max3[] = {9, 0, 2};
    addProcess(&system, 2, allocated3, max3);

    // Request resources
    int request1[] = {1, 0, 1};
    request(&system, 0, request1);

    int request2[] = {0, 1, 0};
    request(&system, 1, request2);

    int request3[] = {1, 0, 0};
    request(&system, 2, request3);

    // Check safety
    if (isSafe(&system, 0) && isSafe(&system, 1) && isSafe(&system, 2)) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is not in a safe state.\n");
    }

    return 0;
}
