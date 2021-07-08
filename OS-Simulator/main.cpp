#include<bits/stdc++.h>
#include "mft.h"
#include "mvt.h"
#include "prod_cons.h"
#include "CPU_Scheduling.h"
#include "disk_schedule.h"
#include "Page_Replacement.h"
#include "banker.h"
#include "read_write.h"

using namespace std; 

int main() { 
	int choice; 

	cout<<"---->Enter the choice as per the following menu:\n"; 
       	cout<<"---->1 for CPU Scheduling\n---->2 for Producer Consumer\n---->3 for Reader Writer\n---->4 for Banker's problem\n---->5 for MFT\n---->6 for MVT\n---->7 for Page Replacement\n---->8 for Disk Scheduling\nEnter Choice:";
	cin>>choice; 
	switch(choice) { 
		case 1: CPU_Schedule();
			break; 
		case 2: prod_cons();
			break; 
		case 3: readwrite(); 
			break; 
		case 4: banker(); 
			break; 
		case 5:	MFT(); 
			break;
		case 6: mvt();  
			break; 
		case 7: page_replacement(); 
			break; 
		case 8: disk_schedule(); 
			break; 
		default: cout<<"---->Invalid option\n";
	} 
  return 0;
} 

