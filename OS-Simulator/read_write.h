#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//class to store the arrival time and brust time along with process id
struct read_write{
public:
  int AT,BT,CT=0,flag=0,id,queued=0;
};


//function to compare the arrival time of the read and write opertion. used while sorting
bool at_comparsion(const read_write &a,const read_write &b){
  return a.AT<b.AT;
}

void writer_pro(vector<read_write> &writer,vector<read_write>&reader,int &time,int writer_point){
  writer[writer_point].flag=1;
  cout<<"writer "<<writer[writer_point].id<<" has started writing at time="<<time<<"\n";

  for(int i=0;i<writer[writer_point].BT;i++){
    //loop check if any writer has came to write other than the processing one
    for(int i=0;i<writer.size();i++){
      if(writer[i].flag==0 && writer[i].AT==time){
        cout<<"writer "<<writer[i].id<<" has to wait "<<"writer "<<writer[writer_point].id<<" is writing\n";
      }
    }
    //loop check if any reader has came to read while writing is processing
    for(int i=0;i<reader.size();i++){
      if(reader[i].flag==0 && reader[i].AT==time){
        cout<<"reader "<<reader[i].id<<" has to wait "<<"writer "<<writer[writer_point].id<<" is writing\n";
      }
    }
    time++;//increment the time
  }
  //allocate value to the CT parameter
  writer[writer_point].CT=time;
  // to print that the writing is complete
  cout<<"writer "<<writer[writer_point].id<<" has completed writing at time="<<time<<"\n\n";
}
void reader_pro(vector<read_write> &writer,vector<read_write> &reader,int& time,int &read_point){
  int act_reader=1;// this shows the number of reading operation currently in process
  cout<<"reader "<<reader[read_point].id<<" has started reading at time="<<time<<"\n";
  //the reader pointer is added to the queue to read the particular data
  reader[read_point].queued=1;
  while(act_reader!=0){
    //this for loop check if any writer wants to write while reading is in process
    for(int i=0;i<writer.size();i++){
      if(writer[i].flag==0 && writer[i].AT==time){
        cout<<"writer "<<writer[i].id<<" has to wait "<<"reading process is taking place\n";
      }
    }
    //for looop checks if a reader has came at time t to read the data and insert it into the queue
    for(int i=0;i<reader.size();i++){
      if(reader[i].flag==0 && reader[i].queued==0 && reader[i].AT<=time){
        act_reader++;
        reader[i].queued=1;
        cout<<"reader "<<reader[i].id<<" has started reading at time="<<time<<"\n";
      }
    }
    time++;
    //this for loop increments the CT of the particular
    for(int i=0;i<reader.size();i++){
        if(reader[i].flag==0 && reader[i].AT<time){
          reader[i].CT++;
        }
        //prints when the reader has completed its reading
        if(reader[i].CT==reader[i].BT && reader[i].flag==0){
          cout<<"reader "<<reader[i].id<<" has completed reading at time="<<time<<"\n";
          act_reader--;
          read_point++;
          reader[i].flag=1;
          reader[i].CT=time;
        }
      }
    }

    cout<<"\n";

}

void reader_writer(vector<read_write> writer,vector<read_write> reader){
  //sort the writer based on the arrival time;
  std::sort(writer.begin(),writer.end(),at_comparsion);
  //sort the reader based on the arrival time
  std::sort(reader.begin(),reader.end(),at_comparsion);

  int writer_point=0,reader_point=0; //writer_point to count the number of writer completed writing same is with reader_point
  int writer_count=writer.size();//calculate number of write processes
  int reader_count=reader.size();
  int time=0,x=0,y=0;
  for(int i=0;i<writer_count+reader_count;){
    //this if statment prints if there is any ideal condition
    if( (time<writer[writer_point].AT && time<reader[reader_point].AT) || (x==1 && time<reader[reader_point].AT) || (y==1 && time<writer[writer_point].AT)){
      if(writer[writer_point].flag==0 && writer[writer_point].AT<=reader[reader_point].AT){
        cout<<"idle time from time="<<time<<" to time="<<writer[writer_point].AT<<"\n";
        time= writer[writer_point].AT;
      }
      if(reader[reader_point].flag==0 && writer[writer_point].AT>reader[reader_point].AT){
        cout<<"idle time from time="<<time<<" to time="<<reader[reader_point].AT<<"\n";
        time= reader[reader_point].AT;
      }
      if(writer[writer_point].flag==0 && y==1){
        cout<<"idle time from time="<<time<<" to time="<<writer[writer_point].AT<<"\n";
        time= writer[writer_point].AT;
      }
      if(reader[reader_point].flag==0 && x==1){
        cout<<"idle time from time="<<time<<" to time="<<reader[reader_point].AT<<"\n";
        time= reader[reader_point].AT;
      }

    }else{
      // if statment checks if the writer has finished its writing if not then checks if the arrival time is less than the reading process
      if(writer[writer_point].flag==0 && writer[writer_point].AT<=reader[reader_point].AT && time>=writer[writer_point].AT){
        writer_pro(writer,reader,time,writer_point);
        writer_point++;
        if(writer_point==writer_count){
          writer_point--;x=1;

        }
      }

      else if(writer[writer_point].flag==0 && reader_point+1==reader_count && time>=writer[writer_point].AT){
        writer_pro(writer,reader,time,writer_point);
        writer_point++;
        if(writer_point==writer_count){
          writer_point--;x=1;

        }
      }
      // checks if the reader has finished reading or not if not then checks if the arrival time is less than the writer process
      else if(reader[reader_point].flag==0 && reader[reader_point].AT<writer[writer_point].AT && time>=reader[reader_point].AT){
        reader_pro(writer,reader,time,reader_point);
        if(reader_point==reader_count){
          reader_point--;y=1;

        }
      }
      else if(reader[reader_point].flag==0 && writer_point+1==writer_count && time>=reader[reader_point].AT){
        reader_pro(writer,reader,time,reader_point);
        if(reader_point==reader_count){
          reader_point--;y=1;
        }
      }
      i++;

    }
  }
}

void readwrite(){
  cout<<"enter the number of writers\n";
  int writer_count;
  cin>>writer_count;
  cout<<"enter the number of readers\n";
  int reader_count;
  cin>>reader_count;
  vector<read_write> writer(writer_count);
  vector<read_write> reader(reader_count);
  for(int i=0;i<writer_count;i++){
      cout<<"enter the arrival time and burst time for the writer "<<i<<"\n";
      cin>>writer[i].AT>>writer[i].BT;
      writer[i].id=i;
  }
  for(int i=0;i<reader_count;i++){
    cout<<"enter the arrival time and burst time for the reader "<<i<<"\n";
    cin>>reader[i].AT>>reader[i].BT;
    reader[i].id=i;
  }

  reader_writer(writer,reader);
  return;
}
