#include<bits/stdc++.h> 

using namespace std; 

struct mvt_process{
    int id=-1;
    int tot_size;
    int starting;
    int end;
}p[100];
vector <pair<int,int>> empty_slots;

void first_fit_insertion()
{
    int i=0;
    while(p[i].id!=-1)
    i++;
    cout<<"Enter process id ";
    cin>>p[i].id;
    cout<<"Enter process size ";
    cin>>p[i].tot_size;
    int min_starting=1000;
    int total_empty=0;
    for(auto a=empty_slots.begin();a!=empty_slots.end();a++)
    {
        if(p[i].tot_size<=(a->second)-(a->first))
        {
            if(min_starting>a->first)
            {
                min_starting=a->first;
            }
        }
        total_empty+=(a->second)-(a->first);
    }
    if(min_starting==1000)
    {
        if(total_empty>=p[i].tot_size)
        {
            cout<<"Process cannot be accommodated due to external fragmentation"<<endl;
        }
        else cout<<"Process too large. Not enough space in memory"<< " required: " << p[i].tot_size << " remaining space: "<<  total_empty<<"\n";
        p[i].id=-1;
        p[i].tot_size=0;
        p[i].starting=0;
        p[i].end=0;
    }
    else{
        for(auto a=empty_slots.begin();a!=empty_slots.end();a++)
        {
            if(a->first==min_starting)
            {
                p[i].starting=min_starting;
                p[i].end=min_starting+p[i].tot_size;
                int to_be_inserted=a->second;
                empty_slots.erase(a);
                if(p[i].end!=to_be_inserted)
                {
                    empty_slots.push_back(make_pair(p[i].end,to_be_inserted));
                }
                cout<<"Process inserted successfully. From "<<p[i].starting<<" To "<<p[i].end<<endl;
                break;
            }
        }
    }
}

void best_fit_insertion()
{
    int i=0;
    while(p[i].id!=-1)
    i++;
    cout<<"Enter process id ";
    cin>>p[i].id;
    cout<<"Enter process size ";
    cin>>p[i].tot_size;
    int min_starting=1000;
    int best_size=1000;
    int total_empty=0;
    for(auto a=empty_slots.begin();a!=empty_slots.end();a++)
    {
        if(p[i].tot_size<=(a->second)-(a->first))
        {
            if(best_size>(a->second)-(a->first))
            {
                best_size=(a->second)-(a->first);
                min_starting=a->first;
            }
            else if(best_size==(a->second)-(a->first))
            {
                if(min_starting>a->first)
                min_starting=a->first;
            }
        }
        total_empty+=(a->second)-(a->first);
    }
    if(min_starting==1000)
    {
        if(total_empty>=p[i].tot_size)
        {
            cout<<"Process cannot be accomodated due to external fragementation"<<endl;
        }
        else cout<<"Process too large. Not enough space in memory"<< " required: " << p[i].tot_size << " remaining space: "<<  total_empty<<"\n";
        p[i].id=-1;
        p[i].tot_size=0;
        p[i].starting=0;
        p[i].end=0;
    }
    else{
        for(auto a=empty_slots.begin();a!=empty_slots.end();a++)
        {
            if(a->first==min_starting)
            {
                p[i].starting=min_starting;
                p[i].end=min_starting+p[i].tot_size;
                int to_be_inserted=a->second;
                empty_slots.erase(a);
                if(p[i].end!=to_be_inserted)
                {
                    empty_slots.push_back(make_pair(p[i].end,to_be_inserted));
                }
                cout<<"Process inserted successfully. From "<<p[i].starting<<" To "<<p[i].end<<endl;
                break;
            }
        }
    }
}

void worst_fit_insertion()
{
    int i=0;
    while(p[i].id!=-1)
    i++;
    cout<<"Enter process id ";
    cin>>p[i].id;
    cout<<"Enter process size ";
    cin>>p[i].tot_size;
    int min_starting=5000;
    int worst_size=-1;
    int total_empty=0;
    for(auto a=empty_slots.begin();a!=empty_slots.end();a++)
    {
        if(p[i].tot_size<=(a->second)-(a->first))
        {
            if(worst_size<(a->second)-(a->first))
            {
                worst_size=(a->second)-(a->first);
                min_starting=a->first;
            }
            else if(worst_size==(a->second)-(a->first))
            {
                if(a->first<min_starting)
                min_starting=a->first;
            }
        }
        total_empty+=(a->second)-(a->first);
    }
    if(min_starting==5000)
    {
        if(total_empty>=p[i].tot_size)
        {
            cout<<"Process cannot be accomodated due to external fragementation"<<endl;
        }
        else cout<<"Process too large. Not enough space in memory"<< " required: " << p[i].tot_size << " remaining space: "<<  total_empty<<"\n";
        p[i].id=-1;
        p[i].tot_size=0;
        p[i].starting=0;
        p[i].end=0;
    }
    else{
        for(auto a=empty_slots.begin();a!=empty_slots.end();a++)
        {
            if(a->first==min_starting)
            {
                p[i].starting=min_starting;
                p[i].end=min_starting+p[i].tot_size;
                int to_be_inserted=a->second;
                empty_slots.erase(a);
                if(p[i].end!=to_be_inserted)
                {
                    empty_slots.push_back(make_pair(p[i].end,to_be_inserted));
                }
                cout<<"Process inserted successfully. From "<<p[i].starting<<" To "<<p[i].end<<endl;
                break;
            }
        }
    }
}

void delete_from_memory()
{
    int pid;
    cout<<"Enter process id to be deleted ";
    cin>>pid;
    int i=0;
    while(p[i].id!=pid&&i<100)
    i++;
    if(i==100)
    {
        cout<<"Process not in memory"<<endl;
        return;
    }
    for(auto a=empty_slots.begin();a!=empty_slots.end();a++)
    {
        if(a->first==p[i].end)
        {
            p[i].end=a->second;
            empty_slots.erase(a);
            a--;
        }
        if(a->second==p[i].starting)
        {
            p[i].starting=a->first;
            empty_slots.erase(a);
            a--;
        }
        p[i].id=-1;
        p[i].tot_size=0;
    }
    empty_slots.push_back(make_pair(p[i].starting,p[i].end));
    cout<<"Process removed successfully"<<endl;
}

void printer()
{
    int count=0;
    cout<<"The processes in memory and their location are as follows :-\n";
    for(int i=0;i<100;i++)
    {
        if(p[i].id!=-1)
        {
            cout<<"Process "<<p[i].id<<" from "<<p[i].starting<<" to "<<p[i].end<<endl;
            count++;
        }
    }
    if(count==0)
    cout<<"No process in memory"<<endl;
    if(empty_slots.size()==0)
    {
        cout<<"Memory completely occupied. No process can be accommodated anymore unless an existing process is deleted"<<endl;
        return;
    }
    cout<<"The empty slots in memory are "<<endl;
    for(auto a=empty_slots.begin();a!=empty_slots.end();a++)
    {
        cout<<"From "<<a->first<<" to "<<a->second<<endl;
    }
}

void mvt(){
    int fitchoice;
    cout << "First enter the way by which you want to insert pages into the physical memory\n";
    cout << "Press 1 for first fit\nPress 2 for best fit\nPress 3 for worst fit\n";
    do{
        cout << "Enter the fit choice: ";
        cin >> fitchoice;
        if(fitchoice<=0||fitchoice>=4){
            cout << "Please enter the valid fit choice\n";
        }
    }while(fitchoice<=0|| fitchoice>=4);
    int memory_size;
    cout<<"Enter size of main memory ";
    cin>>memory_size;
    empty_slots.push_back(make_pair(0,memory_size));
    cout<<"Press 1 to enter new process \n";
    cout << "Press 2 to delete a process\n";
    cout << "Press 3 to display present state of memory\n";
    cout << "Press 4 to exit\n\n";
    int choice;
    while(1)
    {
        cout<<"Enter your choice ";
        cin>>choice;
        if(choice==1){
            if(fitchoice==1){
                first_fit_insertion();
            }
            else if(fitchoice==2){
                best_fit_insertion();
            }
            else if(fitchoice==3){
                worst_fit_insertion();
            }
            cout << "\n";
        }
        else if(choice==2){
            delete_from_memory();
            cout << "\n";
        }
        else if(choice==3){
            printer();
            cout << "\n";
        }
        else if(choice==4){
            break;
        }
        else{
            cout << "Please enter valid choice\n";
        }
    }
}
