#include "disk_schedule_choice.h" 
#include "disk_schedule_fcfs.h" 
#include "disk_schedule_look.h" 
#include "disk_schedule_scan.h"

void disk_schedule() {
  int choice; 

  cout<<"Enter the choice as follows:\n1 for C-Scan\n2 for C-Look\n3 for SSTF\n4 for FCFS\n 5 for look\n6 for scan\n---->"; 
  cin>>choice; 
  if(choice >= 1 && choice <= 3) disk_scheduling_choice(choice); 
  else if(choice == 4) disk_schedule_fcfs(); 
  else if(choice == 5) disk_schedule_look(); 
  else if(choice == 6) disk_schedule_scan(); 
  else cout<<"Invalid Choice\n";
  return; 
}