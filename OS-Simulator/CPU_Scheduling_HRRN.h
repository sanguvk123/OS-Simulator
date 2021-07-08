#include<bits/stdc++.h>
using namespace std;

void HRRN() {
    
	cout << "Enter the number of processes:\n";
	int n,i,j;
	cin >> n;
	while(n<0){
		cout<<"Wrong input, try again\nEnter number of processes: ";
		cin>>n;
	}
	vector<tuple<int, int, int, int, int>>times(n); // {at, bt, ct, tat, wt}
	
	cout << "Enter the Arrival time and Burst time respectively of "<<n<<" programs:\n";
	for(i=0;i<n;i++){
	    int t;
		cout << "Arrival Time: ";
	    cin>>t;
		while(t<0){
			cout<<"Wrong input, try again\nArrival time: ";
			cin>>t;
		}
	    get<0>(times[i])=t;  // Arrival time
	    cout << "Burst Time: ";
	    cin>>t;
		while(t<0){
			cout<<"Wrong input, try again\nBurst time: ";
			cin>>t;
		}
	    get<1>(times[i])=t;  // Burst time
	    get<2>(times[i])=0;  // Completion time
	    get<3>(times[i])=0;  // Turn around time
	    get<4>(times[i])=0;  // Waiting time
	}
	
	sort(times.begin(),times.end()); // sorting according to Arrival time
	
	int ti=get<0>(times[0]);   // current time
	int visited[n];        // programs visited
	for(int i=0;i<n;i++)
  visited[i]=0;
	for(i=0;i<n;i++){
	    
	    int max=0,tak=-1,min1=1000000; // tak is the index of the chosen element
	    
	    for(j=0;j<n;j++){
	        
	        if(visited[j])continue;
	        
	        if(get<0>(times[j])<=ti){
	            if(((ti - get<0>(times[j])) + get<1>(times[j]))/get<1>(times[j]) > max){
	                max = ((ti - get<0>(times[j])) + get<1>(times[j]))/get<1>(times[j]);
	                tak=j;
	            }
	        }
	        
	        else{
	            if(get<0>(times[j])<min1){
	                min1=get<0>(times[j]);
	            }
	        }
	        
	    }


	    // no element chosen (Arrival time of each greater than current time)
	    if(tak==-1){
	        ti=min1;
	        i--;
	    }
	    
	    else{
	        visited[tak]=1;
	        ti += get<1>(times[tak]);
	        get<2>(times[tak]) = ti;
	        get<3>(times[tak]) = get<2>(times[tak]) - get<0>(times[tak]);
	        get<4>(times[tak]) = get<3>(times[tak]) - get<1>(times[tak]);
	    }

	    // all processes done
        int fla=1;
        for(j=0;j<n;j++)if(visited[j]==0)fla=0;

        if(fla)break;
	    
	}
	
	double TAT=0,TWT=0;
	
	for(i=0;i<n;i++){
	    TAT += get<3>(times[i]);
	    TWT += get<4>(times[i]);
	}

	cout << "\nProcess No.\tArrival Time\tBurst Time\tCompletion Time\t\tTurn-around Time\tWaiting Time\n";
	for(i=0;i<n;i++){
		cout << i+1 << "\t\t" << get<0>(times[i]) << "\t\t" << get<1>(times[i]) << "\t\t" << get<2>(times[i]) << "\t\t\t" << get<3>(times[i]) << "\t\t\t" << get<4>(times[i]) << "\n";
	}
	
	TAT = TAT/(1.0*n);    // Average TAT
	TWT = TWT/(1.0*n);    // Average WT
	
	cout << "\nAverage Turn around time is: " << TAT <<"\n";
	cout << "Average Waiting time is: " << TWT <<"\n";
	
	return;
}
