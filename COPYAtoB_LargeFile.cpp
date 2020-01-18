//Copy from one file to another file which is greater than 100MB (This is for comparision to check which is faster i.e. one lrage file to copy from one to another or too many small fil to one another file?)

#include <iostream>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

timespec Substraction(timespec startTime, timespec endTime)
{
    timespec timeStamp;
    if ((endTime.tv_nsec-startTime.tv_nsec)<0) {
        timeStamp.tv_sec = endTime.tv_sec-startTime.tv_sec-1;
        timeStamp.tv_nsec = 1000000000+endTime.tv_nsec-startTime.tv_nsec;
    } else {
        timeStamp.tv_sec = endTime.tv_sec-startTime.tv_sec;
        timeStamp.tv_nsec = endTime.tv_nsec-startTime.tv_nsec;
    }
    return timeStamp;
}

int main()
{
    string line;
    timespec t1, t2;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t1);
    //For writing text file
    //Creating ofstream & ifstream class object
    ifstream inputFile ("large107MB.txt");
    ofstream outFile2 ("copy.txt");

    if(inputFile && outFile2){

        while(getline(inputFile,line)){
            outFile2 << line << "\n";
        }

        cout << "Copy Finished \n";

    } else {
        //Something went wrong
        printf("Cannot read File");
    }

    //Closing file
    inputFile.close();
    outFile2.close();

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t2);

    std::cout << "time taken to execute this program is"<<Substraction(t1,t2).tv_sec<<":"<<Substraction(t1,t2).tv_nsec<< '\n';


    return 0;
}
