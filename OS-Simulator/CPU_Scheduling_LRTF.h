#include<bits/stdc++.h>

using namespace std; 

struct LRTF_Process {
    int pid; // Process ID
    int bt; // Burst Time
    int art; // Arrival Time
};
  
// Function to find the waiting time for all
// processes
void findWaitingTime(LRTF_Process proc[], int n,
                                int wt[])
{
    int rt[n];
  
    // Copy the burst time into rt[]
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;
  
    int complete = 0, t = 0, maxm = 0;
    int longest = 0, finish_time;
    bool check = false;
  
    // Process until all processes gets
    // completed
    while (complete != n) {
  
        // Find process with minimum
        // remaining time among the
        // processes that arrives till the
        // current time`
        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) &&
            (rt[j] > maxm) && rt[j] > 0) {
                maxm = rt[j];
                longest = j;
                check = true;
            }
        }
  
        if (check == false) {
            t++;
            continue;
        }
  
        // Reduce remaining time by one
        rt[longest]--;
  
        // Update minimum
        maxm = rt[longest];
  
        // If a process gets completely
        // executed
        if (rt[longest] == 0) {
  
            // Increment complete
            complete++;
            check = false;
  
            // Find finish time of current
            // process
            finish_time = t + 1;
  
            // Calculate waiting time
            wt[longest] = finish_time -
                        proc[longest].bt -
                        proc[longest].art;
  
            if (wt[longest] < 0)
                wt[longest] = 0;
        }
        // Increment time
        t++;
    }
}
  
// Function to calculate turn around time
void findTurnAroundTime(LRTF_Process proc[], int n,
                        int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}
  
// Function to calculate average time
void findavgTime(LRTF_Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0,
                    total_tat = 0;
  
    // Function to find waiting time of all
    // processes
    findWaitingTime(proc, n, wt);
  
    // Function to find turn around time for
    // all processes
    findTurnAroundTime(proc, n, wt, tat);
  
    // Display processes along with all
    // details
    cout << "Processes "
        << " Burst time "
        << " Waiting time "
        << " Turn around time\n";
  
    // Calculate total waiting time and
    // total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t"
            << proc[i].bt << "\t\t " << wt[i]
            << "\t\t " << tat[i] << endl;
    }
  
    cout << "\nAverage waiting time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n;
}
  
// Driver code
void LRTF()
{
    int n; 
    cout<<"Enter the number of processes:\n"; 
    cin>>n; 
    LRTF_Process proc[n];

    cout<<"Enter the arrival time and burst time of each process:\n"; 
    for(int i = 0; i < n; i++) 
    {
        cout<<"Process "<<i+1<<":";
        proc[i].pid = i + 1; 
        cin>>proc[i].art; 
        cin>>proc[i].bt;  
        cout<<"\n";
    }

    findavgTime(proc, n);
    return; 
}
