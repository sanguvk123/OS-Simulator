
#include <bits/stdc++.h>
#include <semaphore.h>
#include <pthread.h>
using namespace std;

struct prod_cons_process{
  char type;
  int no;
  int a_t;
  int b_t;
};

bool cmp(const prod_cons_process &a, const prod_cons_process &b)
{
    if(a.a_t==b.a_t){
        return (a.no<b.no);
    }
    return (a.a_t < b.a_t);
}

sem_t s; // Semaphore Variable
int prod_cons_buffer_full = 0;
int prod_cons_buffer_empty;
int prod_cons_current_time;
int prod_cons_buffer_size;

bool check_over_under_flow(prod_cons_process &cur){
  if(cur.type=='P'){
    if(prod_cons_buffer_full==prod_cons_buffer_size) return true;
  }
  else {
    if(prod_cons_buffer_full==0) return true;
  }
  return false;
}

void waiters(prod_cons_process *all,int ind,int tot){
  for(int i=ind+1;i<=tot;i++){
    if(all[i].a_t<=prod_cons_current_time){
      std::cout<<"At t= "<<(all[i]).a_t<<" "<<(all[i]).type<<(all[i]).no<<" Had Arrived But ";
      std::cout<<all[i].type<<all[i].no<<" Should Wait"<<'\n';
    }
    else break;
  }
}

void cur_process(prod_cons_process &cur,int ind,int tot,prod_cons_process *all){

    if(cur.type=='P'){

      sem_wait(&s);

      std::cout<<"Producer P"<<cur.no<<" Starts Produstd::cing at t = "<<prod_cons_current_time<<'\n';
      prod_cons_current_time+=cur.b_t;

      prod_cons_buffer_empty--;
      prod_cons_buffer_full++;

      waiters(all,ind,tot);

      sem_post(&s);

    }
    else{

      sem_wait(&s);

      std::cout<<"Consumer C"<<cur.no<<" Starts Consuming at t = "<<prod_cons_current_time<<'\n';
      prod_cons_current_time+=cur.b_t;

      prod_cons_buffer_empty++;
      prod_cons_buffer_full--;

      waiters(all,ind,tot);

      sem_post(&s);
    }
}

bool reposition(int cur_id,prod_cons_process *all,int tot){
  char need;
  int need_ind=-1;
  all[cur_id].type == 'C'? need = 'P' : need = 'C';
  for(int i = cur_id+1;i<=tot;i++){
    if(all[i].type==need){
      need_ind = i;
      break;
    }
  }
  if(need_ind==-1){
    return false;
  }
  else{
    prod_cons_process tmp = all[cur_id];
    for(int i=cur_id;i<need_ind;i++){
      all[i] = all[i+1];
    }
    all[need_ind] = tmp;
    return true;
  }
}

//int i=1;
void one_by_one(prod_cons_process* all,int tot){
    int i = 1;

    while(i<=tot){
      bool cannot = false;
      if(all[i].type=='P' && check_over_under_flow(all[i])){
        std::cout<<"Overflow Has Occurred! \n Repositioning Producer..."<<'\n';
        cannot = true;
      }
      else if(all[i].type=='C' && check_over_under_flow(all[i])){
        std::cout<<"Underflow Has Occurred! \n Repositioning Consumer..."<<'\n';
        cannot = true;
      }

      if(cannot){
        bool status = reposition(i,all,tot);
        if(!status){
          std::cout<<(all[i].type=='P'?"Producer ":"Consumer ")<<all[i].type<<all[i].no<<" Can't Execute";
          if(all[i].type=='P')
            std::cout<<" as there is no Consumer to free the Buffer"<<'\n';
          else
            std::cout<<" as there is no producer to fill the Buffer"<<'\n';
          i++;
          return;
        }
        else std::cout<<"Reposition Successful!\n"<<'\n';
      }

      cur_process(all[i],i,tot,all);
      std::cout<<all[i].type<<all[i].no<<" Completes At "<<prod_cons_current_time<<'\n';
      //std::cout<<full<<'-'<<emptyy;//debug
      std::cout<<'\n';
      i++;
    }
}

void prod_cons(){
    int p=0,c=0;
    sem_init(&s, 0, 1);
    std::cout<<"Enter Buffer Size: ";
    std::cin>>prod_cons_buffer_size;
    prod_cons_buffer_empty = prod_cons_buffer_size;
    std::cout<<"Enter The Number Of Producers: ";
    std::cin>>p;
    std::cout<<"Enter The Number of Consumers: ";
    std::cin>>c;
    int tot = p + c;
    std::cout<<"Enter Producer's Arrival Time And Burst Time: "<<'\n';
    prod_cons_process all[tot+1];
    for(int i=1;i<=p;i++){
      all[i].type = 'P';
      all[i].no = i;
      std::cout<<all[i].type<<all[i].no<<"- ";
      std::cin>>all[i].a_t>>all[i].b_t;
    }
    std::cout<<"Enter Consumer's Arrival Time And Burst Time"<<'\n';
    for(int i=1;i<=c;i++){
      all[p+i].type = 'C';
      all[p+i].no = i;
      std::cout<<all[p+i].type<<all[p+i].no<<"- ";
      std::cin>>all[p+i].a_t>>all[p+i].b_t;
    }
    std::sort(all+1,all+tot+1,cmp);
    one_by_one(all,tot);
    return;
}
