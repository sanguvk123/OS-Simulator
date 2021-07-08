#include<bits/stdc++.h>
using namespace std;
void fifo()
 {
  int n,m,page_faults=0,i,x,k,frame=-1,temp;
  unordered_set<int> s;
  queue<int> index;
  unordered_map<int, int> q;
  cout<<"Enter total number of frames in Main Memory\n";
  cin>>n;
  cout<<"Enter total number of pages in Hard Disk\n";
  cin>>m;
  int P[m];
  cout<<"Enter the reference string (Page numbers sequence)\n";
  for(i=0;i<m;i++)
  {
   cin>>P[i];
  }
  for(i=0;i<m;i++)
   {
    if(s.find(P[i])==s.end())
    {
     page_faults++;
     if(s.size()<n)
     {
      s.insert(P[i]);
      index.push(P[i]);
      frame++;
      q[P[i]]=frame;
      cout<<"Page-"<<P[i]<<" is accommodated in Frame-"<<frame<<"\n";
     }
     else
     {
      x=index.front();
      index.pop();
      s.erase(x);
      s.insert(P[i]);
      cout<<"Page-"<<x<<" is replaced with Page-"<<P[i]<<" in Frame-"<<q[x]<<"\n";
      temp=q[x];
      q.erase(x);
      q[P[i]]=temp;
     }
    }
    else
    {
      for(auto it=q.begin();it!=q.end();it++)
      {
       if(it->first==P[i])
       {
        temp=it->second;
       }
      }
      cout<<"Page-"<<P[i]<<" is already present in Frame-"<<temp<<"\n";
    }
   }
  cout<<"Total number of Page Faults in Fifo method are "<<page_faults<<endl;
 }
void lru()
 {
  int page_faults=0,x,lru,frame=-1,temp,n,m,i;
  unordered_set<int> s;
  unordered_map<int, int> index;
  unordered_map<int, int>q;
  cout<<"Enter total number of frames in Main Memory\n";
  cin>>n;
  cout<<"Enter total number of pages in Hard Disk\n";
  cin>>m;
  int P[m];
  cout<<"Enter the reference string (Page numbers sequence)\n";
  for(i=0;i<m;i++)
  {
   cin>>P[i];
  }
  for(i=0;i<m;i++)
  {
   if(s.find(P[i])==s.end())
   {
    page_faults++;
    if(s.size()<n)
    {
     s.insert(P[i]);
     index[P[i]]=i;
     frame++;
     cout<<"Page-"<<P[i]<<" is accommodated in Frame-"<<frame<<"\n";
     q[P[i]]=frame;
    }
    else
    {
     lru=INT_MAX;
     for(auto it=s.begin();it!=s.end();it++)
     {
      if(index[*it]<lru)
      {
       lru=index[*it];
       x=*it;
      }
     }
     s.erase(x);
     s.insert(P[i]);
     index[P[i]]=i;
     cout<<"Page-"<<x<<" is replaced with Page-"<<P[i]<<" in Frame-"<<q[x]<<"\n";
     temp=q[x];
     q.erase(x);
     q[P[i]]=temp;
    }
   }
   else
   {
    index[P[i]]=i;
    for(auto it=q.begin();it!=q.end();it++)
    {
     if(it->first==P[i])
     {
      temp=it->second;
      break;
     }
    }
    cout<<"Page-"<<P[i]<<" is already present in Frame-"<<temp<<"\n";
   }
  }
 cout<<"Total number of Page Faults in LRU method are "<<page_faults<<endl;
 }
void mru()
 {
  int page_faults=0,i,x,mru,frame=-1,temp,n,m;
  unordered_set<int> s;
  unordered_map<int, int> index;
  unordered_map<int, int>q;
  cout<<"Enter total number of frames in Main Memory\n";
  cin>>n;
  cout<<"Enter total number of pages in Hard Disk\n";
  cin>>m;
  int P[m];
  cout<<"Enter the reference string (Page numbers sequence)\n";
  for(i=0;i<m;i++)
  {
   cin>>P[i];
  }
  for(i=0;i<m;i++)
  {
   if(s.find(P[i])==s.end())
   {
    page_faults++;
    if(s.size()<n)
    {
     s.insert(P[i]);
     index[P[i]]=i;
     frame++;
     cout<<"Page-"<<P[i]<<" is accommodated in Frame-"<<frame<<"\n";
     q[P[i]]=frame;
    }
    else
    {
     mru=INT_MIN;
     for(auto it=s.begin();it!=s.end();it++)
     {
      if(index[*it]>mru)
      {
       mru=index[*it];
       x=*it;
      }
     }
     s.erase(x);
     s.insert(P[i]);
     index[P[i]]=i;
     cout<<"Page-"<<x<<" is replaced with Page-"<<P[i]<<" in Frame-"<<q[x]<<"\n";
     temp=q[x];
     q.erase(x);
     q[P[i]]=temp;
    }
   }
   else
   {
    index[P[i]]=i;
    for(auto it=q.begin();it!=q.end();it++)
    {
     if(it->first==P[i])
     {
      temp=it->second;
      break;
     }
    }
    cout<<"Page-"<<P[i]<<" is already present in the Frame-"<<temp<<"\n";
   }
  }
  cout<<"Total number of Page Faults in MRU method are "<<page_faults<<endl;
 }

void page_replacement() { 
  int choice; 
  cout<<"\nEnter 1 for FIFO\n 2 for LRU\n 3 for MRU\n";
  cin>>choice; 
  if(choice == 1) fifo(); 
  else if(choice == 2) lru(); 
  else if(choice == 3) mru();
  else cout<<"\nInvalid choice\n"; 
}