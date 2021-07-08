 

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void disk_scheduling_choice(int choice)
{
      int tot_disks, n;             
      cout<<"    Number of cylinders in disk : ";
      cin>>tot_disks;
      cout<<"    Number of disk access requests : ";
      cin>>n;
      int req[n];
      int current_pos;

      int i;
      cout<<"   Enter the request array :\n    ";
      int flag=0;
      for(i=0; i<n; i++)
      {
        cin>>req[i];
      }
      for(i=0; i<n; i++)
      {
        if(req[i]>=tot_disks || req[i]<0)
        {
          cout<<"    "<<req[i]<<" is invalid disk request. disk scheduling aborted.\n";
          flag=1;
        }
      }
      if(flag==1)
      {
        cout<<"\n";
        return;
      }
      while(1)
      {
        cout<<"    Enter current position of R/W head : ";
        cin>>current_pos;
        if(current_pos<0 || current_pos>=tot_disks)
        {
          cout<<"    Invalid position of R/W head.\n";
        }
        else
        {
          break;
        }
      }
       

      int seek_time=0;
      if(choice==1)
      {
        sort(req, req+n);
        int mark;
 
          for(mark=0; mark<n; mark++)
          {
            if(current_pos<req[mark])
            {
              break;
            }
          }

          cout<<"    Seek Sequence :";
          for(i=mark-1; i>=0; i--)
          {
            cout<<" "<<req[i];
          }
          if(mark!=n)
          {
            if(req[0]!=0)
            cout<<" "<<0;
            if(req[n-1]!=tot_disks-1)
            cout<<" "<<tot_disks-1;
          }
          for(i=n-1; i>=mark; i--)
          {
            cout<<" "<<req[i];
          }

          if(mark!=n)
          {
            seek_time=(current_pos)+(tot_disks-1)+(tot_disks-1-req[mark]);
          }
          else
          {
            seek_time=current_pos-req[0];
          }
        cout<<"\n";  
        cout<< "Seek time :" << seek_time;
        cout<<"\n";

      }
       else if(choice==2)
      {
        sort(req, req+n);
        int mark;
          for(mark=0; mark<n; mark++)
          {
            if(current_pos<req[mark])
            {
              break;
            }
          }

          cout<<"    Seek Sequence :";
          for(i=mark-1; i>=0; i--)
          {
            cout<<" "<<req[i];
          }
          for(i=n-1; i>=mark; i--)
          {
            cout<<" "<<req[i];
          }

          if(mark!=n)
          {
            seek_time=abs(current_pos-req[0])+(req[n-1]-req[0])+(req[n-1]-req[mark]);
          }
          else
          {
            seek_time=current_pos-req[0];
          }
        cout<<"\n";
        cout<< "Seek time :" << seek_time;
        cout<<"\n";
      }
      else if(choice==3)
      {
        sort(req, req+n);

        cout<<"    Seek Sequence :";
        if(current_pos<=req[0])
        {
          for(i=0; i<n; i++)
          {
            cout<<" "<<req[i];
            seek_time+=abs(req[i]-current_pos);
            current_pos=req[i];
          }
        }
        else if(req[n-1]<=current_pos)
        {
          for(i=n-1; i>=0; i--)
          {
            cout<<" "<<req[i];
            seek_time+=abs(req[i]-current_pos);
            current_pos=req[i];
          }
        }
        else
        {
          int mark;
          for(mark=0; mark<n-1; mark++)
          {
            if(req[mark]==current_pos)
            {
              cout<<" "<<req[mark];
              if(req[mark+1]-current_pos>=current_pos-req[mark-1])
              {
                for(i=mark+1; i<n; i++)
                {
                  cout<<" "<<req[i];
                  seek_time+=abs(req[i]-current_pos);
                  current_pos=req[i];
                }
                for(i=mark-1; i>=0; i--)
                {
                  cout<<" "<<req[i];
                  seek_time+=abs(req[i]-current_pos);
                  current_pos=req[i];
                }
              }
              else
              {
                for(i=mark-1; i>=0; i--)
                {
                  cout<<" "<<req[i];
                  seek_time+=abs(req[i]-current_pos);
                  current_pos=req[i];
                }
                for(i=mark+1; i<n; i++)
                {
                  cout<<" "<<req[i];
                  seek_time+=abs(req[i]-current_pos);
                  current_pos=req[i];
                }
              }
              break;
            }
            else if(req[mark]<current_pos && current_pos<req[mark+1])
            {
              if(req[mark+1]-current_pos<=current_pos-req[mark])
              {
                for(i=mark+1; i<n; i++)
                {
                  cout<<" "<<req[i];
                  seek_time+=abs(req[i]-current_pos);
                  current_pos=req[i];
                }
                for(i=mark; i>=0; i--)
                {
                  cout<<" "<<req[i];
                  seek_time+=abs(req[i]-current_pos);
                  current_pos=req[i];
                }
              }
              else
              {
                for(i=mark; i>=0; i--)
                {
                  cout<<" "<<req[i];
                  seek_time+=abs(req[i]-current_pos);
                  current_pos=req[i];
                }
                for(i=mark+1; i<n; i++)
                {
                  cout<<" "<<req[i];
                  seek_time+=abs(req[i]-current_pos);
                  current_pos=req[i];
                }
              }
              break;
            }
          }
        }
        cout<<"\n";
        cout<< "Seek time :" << seek_time;
        cout<<"\n";

      }
   
}
