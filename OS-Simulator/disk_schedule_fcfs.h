#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void disk_schedule_fcfs(){
    int disk_size,size,i,j,head,start,seek_time;
    cout<<"\nEnter number of cylinders in disk : ";
    cin>>disk_size;
    cout<<"\nEnter number of disk access requests : ";
    cin>>size;
    int arr[size];
    cout<<"\n Enter the request array : \n";
    for(i=0;i<size;i++){
        cin>>arr[i];
        if(arr[i]>=disk_size||arr[i]<0){
            cout<<"\nInvalid disk access request.Disk Scheduling aborted";
            return;
        }
    }
    cout<<"\nInitial location of R/W head: ";
    cin>>head;
    if(head>=disk_size||head<0){
        cout<<"\nInvalid position of R/W head.Disk Scheduling aborted";
            return;
    }
    for(i=0;i<size;i++){
        if(head>arr[i])
            seek_time += head-arr[i];
        else
            seek_time += arr[i]-head;
        head=arr[i];
    }
    cout<<"\nSeek Time: "<<seek_time;
    cout<<"\nSeek Sequence is: ";
    for(i=0;i<size-1;i++)
        cout<<arr[i]<<", ";
    cout<<arr[size-1];
    return;
}
