#include <stdio.h>
//Given data structure
typedef struct{ 
int p_id; 
int arr_time; 
int burst_time; 
int waiting_time; 
int turn_around_time;
int completion_time;
}threadInfo;

int main(){
    FILE *inputFile;
    threadInfo threads[10];
    int completion_time = 0;
    int nThreads = 0;
    float total_waiting_time = 0;
    float total_turn_around_time = 0;
    
    //Reading sample_in_schedule.txt
    inputFile = fopen("sample_in_schedule.txt","r");
    while(fscanf(inputFile,"%d, %d, %d", &threads[nThreads].p_id, &threads[nThreads].arr_time, &threads[nThreads].burst_time) != EOF){
        nThreads++;
    }
    fclose(inputFile);
    //Calculating turn around, completion and waiting time
    for(int i = 0; i < nThreads; i++) {
        threads[i].waiting_time = completion_time - threads[i].arr_time;
        if (threads[i].waiting_time < 0) {
            threads[i].waiting_time = 0;
        }
        
        completion_time += threads[i].burst_time;
        threads[i].completion_time = completion_time;
        
        threads[i].turn_around_time = threads[i].completion_time - threads[i].arr_time;
        total_waiting_time += threads[i].waiting_time;
        total_turn_around_time += threads[i].turn_around_time;
    }

    //Displaying output  
    printf("Thread ID\tArrival Time\tBurst Time\tCompletion Time\tTurn-Around Time\tWaiting Time\n");
    for (int i = 0; i < nThreads; i++) {
    printf("%-10d\t%-12d\t%-10d\t%-16d\t%-17d\t%-12d\n", 
           threads[i].p_id, 
           threads[i].arr_time, 
           threads[i].burst_time, 
           threads[i].completion_time, 
           threads[i].turn_around_time, 
           threads[i].waiting_time);
    }  
    //Summing all threads' waiting times/total number of threads
    printf("\nThe average waiting time: %.2f\n", total_waiting_time / nThreads);
    //Summing avg turn-around time of all threads/total number of threads
    printf("The average turn-around time: %.2f\n", total_turn_around_time / nThreads);

return 0;

}
