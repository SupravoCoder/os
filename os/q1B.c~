#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;  // Waiting time for first process is 0

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Calculate turn around time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to calculate average time
void findAvgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt);

    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes along with all details
    printf("Processes\tBurst time\tWaiting time\tTurn around time\n");

    // Calculate total waiting time and turn around time
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turn around time = %.2f\n", (float)total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {21, 3, 6, 2};
    findAvgTime(processes, n, burst_time);

    return 0;
}
