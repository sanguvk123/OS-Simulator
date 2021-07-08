// SHORTEST JOB FIRST (SJF)

#include <bits/stdc++.h>

using namespace std;

class SJF_process
{
    // making a class of name process
public:
    // each process has attributes: process id, arrival time (AT), burst time (BT),
    // completion time (CT), turn around time (TAT), Waiting Time (WT)
    int id, AT, BT;
    int CT, TAT, WT;

    SJF_process(int id, int AT, int BT)
    {
        this->id = id;
        this->AT = AT;
        this->BT = BT;
    }
};

// this is a custom sort function to sort the processes on basis of arrival time and process ids
bool sort_by_arrival_time_SJF(SJF_process p1, SJF_process p2)
{
    // if arrival times are different, sort on the basis of arrival times
    if (p1.AT != p2.AT)
        return p1.AT < p2.AT;

    // else sort on the basis of the process id number, always unique
    else
        return p1.id < p2.id;
}

void SJF()
{
    // Take input from user about the processes
    int n;
    cout << "Enter number of processes for SJF: ";
    cin >> n;

    vector<SJF_process> P;
    cout << "Enter the process id, arrival time, burst time of each process for each of the " << n << " processes: " << endl;
    for (int i = 0; i < n; i++)
    {
        int process_id, arrival_time, burst_time;
        cout << "Enter the process id, arrival time, burst time: ";

        cin >> process_id >> arrival_time >> burst_time;
        P.emplace_back(SJF_process(process_id, arrival_time, burst_time));
    }

    // sort the processes on the basis on burst times for FCFS (First Come First Serve)
    sort(P.begin(), P.end(),sort_by_arrival_time_SJF);

    map<int, int> index_of_process_with_id;

    for (int i = 0; i < P.size(); i++)
    {
        index_of_process_with_id[P[i].id] = i;
    }

    // this set holds the next process to run
    set<pair<int, int>> next_process_to_execute;
    int i = 0;

    for (int current_time = 0; current_time < 1000;)
    {

        while (i < P.size() && P[i].AT <= current_time)
        {
            next_process_to_execute.insert({P[i].BT, P[i].id});
            i++;
        }

        if (!next_process_to_execute.empty())
        {
            // Calculate and update values for each of CT, TAT, WT for each process
            int next_process = next_process_to_execute.begin()->second;

            next_process_to_execute.erase(next_process_to_execute.begin());
            int ind = index_of_process_with_id[next_process];

            P[ind].CT = current_time + P[ind].BT;
            P[ind].TAT = P[ind].CT - P[ind].AT;
            P[ind].WT = P[ind].TAT - P[ind].BT;

            current_time += P[ind].BT;
        }
        else
        {
            current_time += 1;
        }
        if (current_time > 100000)
            break;
    }

    // printing the values chart having all times of all processes
    cout << "\nProcess Id\t AT\t BT\t CT\t TAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << P[i].id << "\t\t " << P[i].AT << "\t " << P[i].BT << "\t " << P[i].CT << "\t " << P[i].TAT << "\t " << P[i].WT << endl;
    }

    // calculating average TAT and WT
    double avg_TAT = 0, avg_WT = 0;
    for (int i = 0; i < n; i++)
    {
        avg_TAT += P[i].TAT;
        avg_WT += P[i].WT;
    }
    avg_TAT /= n;
    avg_WT /= n;

    cout << endl;
    cout << "\n------------------------------------------------------------------------------\n";
    // Printing out final average values of TAT and WT
    cout << "The average TAT is:  " << avg_TAT << endl;
    cout << "The average WT is :  " << avg_WT << endl;
    cout << "------------------------------------------------------------------------------\n\n";
}