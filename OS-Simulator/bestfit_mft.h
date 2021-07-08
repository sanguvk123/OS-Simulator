//Best fit memory management in fixed partitioning

#include<bits/stdc++.h>
using namespace std;
struct process{
  int p_id;
	int p_size;
	int p_flag={0};
}process;

struct block{
  int p_id;
  int p_size;
	int b_size;
	int b_flag={0};
}block;


int i,j,min_frag,id;
void insert_bestfit(struct process p,struct block b[],int m){
	min_frag=INT_MAX,id=INT_MAX;
	for(j=0;j<m;j++){
		if(p.p_size <= b[j].b_size && b[j].b_flag == 0 && min_frag > (b[j].b_size - p.p_size)){
			min_frag = b[j].b_size - p.p_size;
			id = j;
		}
	}
	if(min_frag != INT_MAX){
		b[id].b_flag = p.p_flag = 1;
    b[id].p_id=p.p_id;
    b[id].p_size=p.p_size;
		// cout<<"Process "<<p.p_id<<" is at part "<<id+1<<"\n";
	}
	if(p.p_flag == 0){
    int max_free=0,ext_frag=0;
    for(int i=0;i<m;i++){
      if(b[i].b_flag==0 && b[i].b_size>max_free)
      max_free=b[i].b_size;
      if(b[i].b_flag==1)
      ext_frag+=b[i].b_size-b[i].p_size;
      // if(b[i].b_flag==0)
      // ext_frag+=b[i].b_size;
    }
    if(ext_frag>=p.p_size)
    cout<<"Process "<<p.p_id<<" can't be given partition due to external fragmentation.\n";
    else if(max_free)
		cout<<"Process "<<p.p_id<<" can't be given partition as max available size partition is "<<max_free<<".\n";
    else
    cout<<"No partion available";
  }
}

void delete_process(struct block b[],int m,int p_id){
  int flag=0;
  for(int i=0;i<m;i++){
    if(b[i].p_id==p_id){
      b[i].b_flag=0;
      cout<<"Process "<<p_id<<" deleted from part "<<i+1<<"\n";
      flag=1;
      break;
    }
  }
  if(flag==0)
  cout<<"Process not found\n";
}

void bestfit_mft(){
	int m,i,mem_size;
  
  cout<<"\nBest fit memory management\n";
  cout<<"Enter the memory size: ";
  cin>>mem_size;
  if(mem_size<=0){
    cout<<"Invalid memory size\n";
    return;
  }
	cout<<"\nEnter no of partitions ";
  cin>>m;
  if(m<=0){
    cout<<"Invalid no of partitions\n";
    return;
  }
	struct block b[m];
  
	for(i=0;i<m;i++){
    cout<<"Enter size of partition "<<i+1<<" : ";
    int size;
    cin>>size;
    if(mem_size>=size){
		  b[i].b_size=size;
      mem_size-=size;
    }
    else{
      cout<<"Partition cannot be assigned as only "<<mem_size<<" units of size is left\n";
    }
	}

  cout<<"Select Operation\n 1.Insertion\n 2.Deletion\n 3.Stop\n";
  while(1){
    cout<<"Enter choice ";
    int choice;
    cin>>choice;
    if(choice==1){
	    struct process p;
      int p_id;
      cout<<"Enter process id and size of process ";
		  cin>>p_id>>p.p_size;
      p.p_id=p_id;
      insert_bestfit(p,b,m);
    }
    else if(choice==2){
      int p_id;
      cout<<"Enter process id to be deleted ";
      cin>>p_id;
      delete_process(b,m,p_id);
    }
    else if(choice==3){
      for(int i=0;i<m;i++){
        if(b[i].b_flag==1){
          cout<<"Partion "<<i+1<< " has Process "<<b[i].p_id<<" with size "<<b[i].p_size<<"\n";
        }
        else{
          cout<<"Partition "<<i+1<<" is empty with size "<<b[i].b_size<<"\n";
        }
      }
      break;
    }
    else break;
  }
  cout<<"\n";
}