#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void banker(){
    cout<<"Enter number of resources: ";
    int m,n,i,j,count = 0,flag=0,check = 0;
    cin>>m;
    cout<<'\n';
    int max_count[m],resource[m];
    for(i=0;i<m;i++){
        cout<<"Enter max available count for resource "<<i+1<<": ";
        cin>>max_count[i];
        resource[i]=max_count[i];
    }
    cout<<"Enter number of processes: ";
    cin>>n;
    cout<<'\n';
    int req_res[n][m],alloc_res[n][m],flag1[n],result[n];
    for(i=0;i<n;i++){
        flag1[i]=0;
        cout<<"Enter details of process "<<i+1<<": \n";
        for(j=0;j<m;j++){
            cout<<"Max need of resource "<<j+1<<": ";
            cin>>req_res[i][j];
            if(req_res[i][j]>max_count[j]){
                cout<<"Invalid inputs\n";
                return;
            }
        }
        for(j=0;j<m;j++){
            cout<<"Allocated number of resource "<<j+1<<": ";
            cin>>alloc_res[i][j];
            resource[j]-=alloc_res[i][j];
            if(resource[j]<0){
                cout<<"Invalid inputs\n";
                return;
            }    
        }
        cout<<'\n';
    }
    cout<<"Inputs are valid \n";
    while(count<n){
        for(i=0;i<n;i++){
            if(!flag1[i])
                for(j=0;j<m;j++)
                    if(alloc_res[i][j]+resource[j]<req_res[i][j]){
                        flag=1;
                        break;
                    }
            if(!flag&&!flag1[i]){
                flag1[i]=1;
                for(j=0;j<m;j++)
                    resource[j]+=alloc_res[i][j];
                check=1;
                result[count++]=i;
            }
            flag=0;
        }
        if(!check){
            flag=2;
            break;
        }
        check=0;
    }
    if(count<n)
        cout<<"Deadlock\n";
    else{
        cout<<"No problem with config detected\n";
        for(i=0;i<n-1;i++)
            cout<<"Process No."<<result[i]+1<<" -> ";
        cout<<"Process No."<<result[n-1]+1<<'\n';
    }
    return;
}
