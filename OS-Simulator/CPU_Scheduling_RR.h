// ROUND ROBIN (RR)

#include <bits/stdc++.h>

using namespace std;

class RR_process
{
    // making a class of name process
public:
    // each process has attributes: process id, arrival time (AT), burst time (BT),
    // completion time (CT), turn around time (TAT), Waiting Time (WT)
    int id, AT, BT, remainingBT;
    int CT, TAT, WT;

    RR_process(int id, int AT, int BT)
    {
        this->id = id;
        this->AT = AT;
        this->BT = BT;
        this->remainingBT = BT;
    }
};

// this is a custom sort function to sort the processes on basis of arrival time and process ids
bool sort_by_arrival_time(RR_process p1, RR_process p2)
{
    // if arrival times are different, sort on the basis of arrival times
    if (p1.AT != p2.AT)
        return p1.AT < p2.AT;

    // else sort on the basis of the process id number, always unique
    else
        return p1.id < p2.id;
}

void RR()
{

    // Take input from user about the processes
    int n;
    cout << "Enter number of processes for RR: ";
    cin >> n;
    vector<RR_process> Q;
    cout << "Enter the process id, arrival time, burst time of each process for each of the " << n << " processes: " << endl;
    for (int i = 0; i < n; i++)
    {
        int process_id, arrival_time, burst_time;
        cout << "Enter the process id, arrival time, burst time: ";

        cin >> process_id >> arrival_time >> burst_time;
        Q.emplace_back(RR_process(process_id, arrival_time, burst_time));
    }

    // take input for Time Quanta (time slice) value from the user
    int time_quanta;
    cout << "\nEnter Time Quanta value : ";
    cin >> time_quanta;

    // First sort the processes on the basis on the arrival times and process ids
    sort(Q.begin(), Q.end(),sort_by_arrival_time);

    // make a Ready Queue of queue data structure of type of class process that we have created
    queue<RR_process> ready_queue;

    // printing the values chart having all times of all processes
    cout << "\nProcess Id\t AT\t BT\t CT\t TAT\tWT\n";

    // for calculating average TAT and WT
    double avg_TAT = 0, avg_WT = 0;

    int current_time = Q[0].AT;
    int n_executed = 0, i = 0;
    while (n_executed < Q.size())
    {
        while (i < Q.size() && Q[i].AT <= current_time)
        {
            ready_queue.push(Q[i]);
            i++;
        }

        if (ready_queue.size() == 0)
        {
            current_time++;
            continue;
        }

        RR_process current_process = ready_queue.front();

        ready_queue.pop();
        current_time = max(current_time, current_process.AT);
        if (current_process.remainingBT <= time_quanta)
        {

            current_process.CT = current_time + current_process.remainingBT;
            current_process.TAT = current_process.CT - current_process.AT;
            current_process.WT = current_process.TAT - current_process.BT;
            current_time += current_process.remainingBT;
            n_executed++;

            cout << current_process.id << "\t\t " << current_process.AT << "\t " << current_process.BT
                 << "\t " << current_process.CT << "\t " << current_process.TAT << "\t " << current_process.WT << endl;

            avg_TAT += current_process.TAT;
            avg_WT += current_process.WT;
        }
        else
        {
            current_process.remainingBT -= time_quanta;
            while (i < Q.size() && Q[i].AT <= current_time + time_quanta)
            {
                // cout << "Pushing process: " << P[i].id << endl;
                ready_queue.push(Q[i]);
                i++;
            }
            ready_queue.push(current_process);
            current_time += time_quanta;
        }
    }

    avg_TAT /= n;
    avg_WT /= n;

    cout << endl;
    // Printing out final average values of TAT and WT
    cout << "The average TAT is:  " << avg_TAT << endl;
    cout << "The average WT is :  " << avg_WT << endl;
}
