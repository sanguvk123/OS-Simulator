#include<bits/stdc++.h> 
#include "CPU_Scheduling_FCFS.h"
#include "CPU_Scheduling_LJF.h"
#include "CPU_Scheduling_HRRN.h" 
#include "CPU_Scheduling_SJF.h" 
#include "CPU_Scheduling_SRTF.h"
#include "CPU_Scheduling_LRTF.h"
#include "CPU_Scheduling_RR.h"
#include "CPU_Scheduling_preemptive_priority.h"
#include "CPU_Scheduling_priority_np.h"

using namespace std; 

void CPU_Schedule() { 
    int choice; 

    cout<<"Enter 1 for FCFS\n2 for LJF\n3 for LRTF\n4 for RR\n5 for SJF\n6 for SRTF\n7 for HRRN\n8 for Preemptive priority\n9 for Non-preemptive priority\n---->";
    cin>>choice; 

    switch(choice) {
        case 1: 
            FCFS(); 
            break; 
        case 2: 
            LJF(); 
            break;
        case 3: 
            LRTF(); 
            break; 
        case 4: 
            RR(); 
            break; 
        case 5: 
            SJF(); 
            break; 
        case 6: 
            SRTF(); 
            break;
        case 7: 
            HRRN(); 
            break; 
        case 8: 
            ppriority(); 
            break; 
        case 9: 
            nppriority(); 
            break; 
        default: cout<<"Invalid choice\n";       
    }
}