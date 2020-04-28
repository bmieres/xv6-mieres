#include "types.h"
#include "stat.h"
#include "user.h"
//#include <time.h> 
  
void delay(int number_of_milliseconds){ 
    // Converting time into milli_seconds 
    int milli_seconds = number_of_milliseconds; 
  
    int start_time = uptime(); 
  
    while (uptime() < start_time + milli_seconds) ;
} 
int main(){ 
    // Creating first child 
    int n1 = fork(); 
    int count = 0;
    int times = 20; 
    int millisec_to_wait = 5;

    // Creating second child. First child 
    // also executes this line and creates 
    // grandchild. 
    int n2 = fork(); 

    if (n1 > 0 && n2 > 0) 
    { 
        printf(1,"\n0.- parent ID: %d\n",getpid());
        while(count < times){
            printf(1,"0 ");
            delay(millisec_to_wait); 
            count++;
        }
    } 
    else if (n1 == 0 && n2 > 0) 
    { 
        printf(1,"\n1.- first child ID: %d\n",getpid()); 
        while(count < times){
            printf(1,"1 ");
            delay(millisec_to_wait); 
            count++;
        }
    } 
    else if (n1 > 0 && n2 == 0) 
    { 
        printf(1,"\n2.- second child ID: %d\n",getpid()); 
        while(count < times){
            printf(1,"2 ");
            delay(millisec_to_wait); 
            count++;
        }
    } 
    else { 
        printf(1,"\n3.- third child ID: %d\n",getpid()); 
        while(count < times){
            printf(1,"3 ");
            delay(millisec_to_wait); 
            count++;
        }
    } 
  
    while(wait() >= 0);
    exit(); 
} 