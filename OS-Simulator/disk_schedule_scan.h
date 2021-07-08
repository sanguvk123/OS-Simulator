#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void disk_schedule_scan(){
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
    sort(arr,arr + size);
    for(i=0;i<size-1;i++)
        if(arr[i+1]>head)
            break;
    start=i+1;
    if(head>arr[size-1])
        seek_time = head;
    else
        seek_time = head+arr[size-1];
    cout<<"\nSeek Time: "<<seek_time;
    cout<<"\nSeek Sequence is: ";
    for(;i>=0;i--){
        cout<<arr[i]<<", ";
    }
    if(start==size)
        cout<<"0";
    else
        cout<<"0, ";
    for(;start<size-1;start++){
        cout<<arr[start]<<", ";
    }
    cout<<arr[size-1];
    return;
}
