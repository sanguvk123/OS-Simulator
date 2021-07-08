#include<bits/stdc++.h> 
#include "bestfit_mft.h" 
#include "firstfit_mft.h" 
#include "worstfit_mft.h" 
using namespace std; 

void MFT() {
  			int choice1;
  			cout<<"Select type \n0. Exit\n1. Best fit Memory Management in Fixed size partitioning.\n2. First fit Memory Management in Fixed size partitioning.\n3. Worst fit Memory Management in Fixed size partitioning.\n";

  			while(1){
  				cout<<"\nEnter type : ";
  				cin>>choice1;
   	 			if(choice1 == 1){
      					bestfit_mft();
    				}
    				if(choice1 == 2){
      					firstfit_mft();
    				}
    				if(choice1 == 3){
      					worstfit_mft();
    				}
    				if(choice1 == 0)
    					break;
  			}
		}
