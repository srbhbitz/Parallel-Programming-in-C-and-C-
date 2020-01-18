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
    timespec time_s, time_e;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_s);
    //For writing text file
    //Creating ofstream & ifstream class object
    ifstream file1 ("1.txt");
    ifstream file2 ("2.txt");
    ifstream file3 ("3.txt") ;
    ifstream file4 ("4.txt") ;
    ifstream file5 ("5.txt") ;
    ifstream file6 ("6.txt") ;
    ifstream file7 ("7.txt") ;
    ifstream file8 ("8.txt") ;
    ifstream file9 ("9.txt") ;
    ifstream file10 ("10.txt") ;
    ifstream file11 ("11.txt") ;
    ifstream file12 ("12.txt") ;
    ifstream file13 ("13.txt") ;
    ifstream file14 ("14.txt") ;
    ifstream file15 ("15.txt") ;
    ifstream file16 ("16.txt") ;
    ifstream file17 ("17.txt") ;
    ifstream file18 ("18.txt") ;
    ifstream file19 ("19.txt") ;
    ifstream file20 ("20.txt") ;
    ifstream file21 ("21.txt") ;
    ifstream file22 ("22.txt") ;
    ifstream file23 ("23.txt") ;
    ifstream file24 ("24.txt") ;
    ifstream file25 ("25.txt") ;
    ifstream file26 ("26.txt") ;
    ifstream file27 ("27.txt") ;
    ifstream file28 ("28.txt") ;
    ifstream file29 ("29.txt") ;
    ifstream file30 ("30.txt") ;
    ifstream file31 ("31.txt") ;
    ifstream file32 ("32.txt") ;
    ifstream file33 ("33.txt") ;
    ifstream file34 ("34.txt") ;
    ifstream file35 ("35.txt") ;
    ifstream file36 ("36.txt") ;
    ifstream file37 ("37.txt") ;
    ifstream file38 ("38.txt") ;
    ifstream file39 ("39.txt") ;
    ifstream file40 ("40.txt") ;
    ifstream file41 ("41.txt") ;
    ifstream file42 ("42.txt") ;
    ifstream file43 ("43.txt") ;
    //ifstream file44 ("44.txt") ;
    ifstream file45 ("45.txt") ;
    ifstream file46 ("46.txt") ;
    ifstream file47 ("47.txt") ;
    ifstream file48 ("48.txt") ;
    ifstream file49 ("49.txt") ;
    ifstream file50 ("50.txt") ;
    ifstream file51 ("51.txt") ;
    ifstream file52 ("52.txt") ;
    ifstream file53 ("53.txt") ;
    ifstream file54 ("54.txt") ;
    ifstream file55 ("55.txt") ;
    ifstream file56 ("56.txt") ;
    ifstream file57 ("57.txt") ;
    ifstream file58 ("58.txt") ;
    ifstream file59 ("59.txt") ;
    ifstream file60 ("60.txt") ;
    ifstream file61 ("61.txt") ;
    ifstream file62 ("62.txt") ;
    ifstream file63 ("63.txt") ;
    ifstream file64 ("64.txt") ;
    ifstream file65 ("65.txt") ;
    ifstream file66 ("66.txt") ;
    ifstream file67 ("67.txt") ;
    ifstream file68 ("68.txt") ;
    ifstream file69 ("69.txt") ;
    ifstream file70 ("70.txt") ;
    ifstream file71 ("71.txt") ;
    ifstream file72 ("72.txt") ;
    ifstream file73 ("73.txt") ;
    ifstream file74 ("74.txt") ;
    ifstream file75 ("75.txt") ;
    ifstream file76 ("76.txt") ;
    //ifstream file77 ("77.txt") ;
    ifstream file78 ("78.txt") ;
    ifstream file79 ("79.txt") ;
    ifstream file80 ("80.txt") ;
    ifstream file81 ("81.txt") ;
    ifstream file82 ("82.txt") ;
    ifstream file83 ("83.txt") ;
    ifstream file84 ("84.txt") ;
    ifstream file85 ("85.txt") ;
    ifstream file86 ("86.txt") ;
    ifstream file87 ("87.txt") ;
    ifstream file88 ("88.txt") ;
    ifstream file89 ("89.txt") ;
    ifstream file90 ("90.txt") ;
    ifstream file91 ("91.txt") ;
    ifstream file92 ("92.txt") ;
    ifstream file93 ("93.txt") ;
    ifstream file94 ("94.txt") ;
    ifstream file95 ("95.txt") ;
    ifstream file96 ("96.txt") ;
    ifstream file97 ("97.txt") ;
    ifstream file979 ("979.txt") ;
    ifstream file98 ("98.txt") ;
    ifstream file99 ("99.txt") ;
    ifstream file100 ("100.txt") ;
    ifstream file101 ("101.txt") ;
    ifstream file102 ("102.txt") ;
    ifstream file103 ("103.txt") ;
    ifstream file104 ("104.txt") ;
    ifstream file105 ("105.txt") ;
    ifstream file106 ("106.txt") ;
    ifstream file107 ("107.txt") ;
    ifstream file108 ("108.txt") ;
    ifstream file109 ("109.txt") ;
    ifstream file110 ("110.txt") ;
    ifstream file111 ("111.txt") ;
    ifstream file112 ("112.txt") ;
    ifstream file113 ("113.txt") ;
    ifstream file114 ("114.txt") ;
    ifstream file115 ("115.txt") ;
    ifstream file116 ("116.txt") ;
    ifstream file117 ("117.txt") ;
    ifstream file118 ("118.txt") ;
    ifstream file119 ("119.txt") ;
    ifstream file120 ("120.txt") ;
    ifstream file121 ("121.txt") ;

    ofstream out_file ("copy.txt");

    if(out_file &&
         file2 &&
         file1 &&
         file3 &&
            file4 &&
            file5 &&
            file6 &&
            file7 &&
            file8 &&
            file9 &&
            file10 &&
            file11 &&
            file12 &&
            file13 &&
            file14 &&
            file15 &&
            file16 &&
            file17 &&
            file18 &&
            file19 &&
            file20 &&
            file21 &&
            file22 &&
            file23 &&
            file24 &&
            file25 &&
            file26 &&
            file27 &&
            file28 &&
            file29 &&
            file30 &&
            file31 &&
            file32 &&
            file33 &&
            file34 &&
            file35 &&
            file36 &&
            file37 &&
            file38 &&
            file39 &&
            file40 &&
            file41 &&
            file42 &&
            file43 &&
            //file44 &&
            file45 &&
            file46 &&
            file47 &&
            file48 &&
            file49 &&
            file50 &&
            file51 &&
            file52 &&
            file53 &&
            file54 &&
            file55 &&
            file56 &&
            file57 &&
            file58 &&
            file59 &&
            file60 &&
            file61 &&
            file62 &&
            file63 &&
            file64 &&
            file65 &&
            file66 &&
            file67 &&
            file68 &&
            file69 &&
            file70 &&
            file71 &&
            file72 &&
            file73 &&
            file74 &&
            file75 &&
            file76 &&
            //file77 &&
            file78 &&
            file79 &&
            file80 &&
            file81 &&
            file82 &&
            file83 &&
            file84 &&
            file85 &&
            file86 &&
            file87 &&
            file88 &&
            file89 &&
            file90 &&
            file91 &&
            file92 &&
            file93 &&
            file94 &&
            file95 &&
            file96 &&
            file97 &&
            file979 &&
            file98 &&
            file99 &&
            file100 &&
            file101 &&
            file102 &&
            file103 &&
            file104 &&
            file105 &&
            file106 &&
            file107 &&
            file108 &&
            file109 &&
            file110 &&
            file111 &&
            file112 &&
            file113 &&
            file114 &&
            file115 &&
            file116 &&
            file117 &&
            file118 &&
            file119 &&
            file120 &&
            file121)
            {

        while(getline(file1,line) )out_file << line << "\n";
        while(getline(file2,line) )out_file << line << "\n";
        while(getline(file3,line) )out_file << line << "\n";
        while(getline(file4,line) )out_file << line << "\n";
        while(getline(file5,line) )out_file << line << "\n";
        while(getline(file6,line) )out_file << line << "\n";
        while(getline(file7,line) )out_file << line << "\n";
        while(getline(file8,line) )out_file << line << "\n";
        while(getline(file9,line) )out_file << line << "\n";
        while(getline(file10,line) )out_file << line << "\n";
        while(getline(file11,line) )out_file << line << "\n";
        while(getline(file12,line) )out_file << line << "\n";
        while(getline(file13,line) )out_file << line << "\n";
        while(getline(file14,line) )out_file << line << "\n";
        while(getline(file15,line) )out_file << line << "\n";
        while(getline(file16,line) )out_file << line << "\n";
        while(getline(file17,line) )out_file << line << "\n";
        while(getline(file18,line) )out_file << line << "\n";
        while(getline(file19,line) )out_file << line << "\n";
        while(getline(file20,line) )out_file << line << "\n";
        while(getline(file21,line) )out_file << line << "\n";
        while(getline(file22,line) )out_file << line << "\n";
        while(getline(file23,line) )out_file << line << "\n";
        while(getline(file24,line) )out_file << line << "\n";
        while(getline(file25,line) )out_file << line << "\n";
        while(getline(file26,line) )out_file << line << "\n";
        while(getline(file27,line) )out_file << line << "\n";
        while(getline(file28,line) )out_file << line << "\n";
        while(getline(file29,line) )out_file << line << "\n";
        while(getline(file30,line) )out_file << line << "\n";
        while(getline(file31,line) )out_file << line << "\n";
        while(getline(file32,line) )out_file << line << "\n";
        while(getline(file33,line) )out_file << line << "\n";
        while(getline(file34,line) )out_file << line << "\n";
        while(getline(file35,line) )out_file << line << "\n";
        while(getline(file36,line) )out_file << line << "\n";
        while(getline(file37,line) )out_file << line << "\n";
        while(getline(file38,line) )out_file << line << "\n";
        while(getline(file39,line) )out_file << line << "\n";
        while(getline(file40,line) )out_file << line << "\n";
        while(getline(file41,line) )out_file << line << "\n";
        while(getline(file42,line) )out_file << line << "\n";
        while(getline(file43,line) )out_file << line << "\n";
        //while(getline(file44,line) )out_file << line << "\n";
        while(getline(file45,line) )out_file << line << "\n";
        while(getline(file46,line) )out_file << line << "\n";
        while(getline(file47,line) )out_file << line << "\n";
        while(getline(file48,line) )out_file << line << "\n";
        while(getline(file49,line) )out_file << line << "\n";
        while(getline(file50,line) )out_file << line << "\n";
        while(getline(file51,line) )out_file << line << "\n";
        while(getline(file52,line) )out_file << line << "\n";
        while(getline(file53,line) )out_file << line << "\n";
        while(getline(file54,line) )out_file << line << "\n";
        while(getline(file55,line) )out_file << line << "\n";
        while(getline(file56,line) )out_file << line << "\n";
        while(getline(file57,line) )out_file << line << "\n";
        while(getline(file58,line) )out_file << line << "\n";
        while(getline(file59,line) )out_file << line << "\n";
        while(getline(file60,line) )out_file << line << "\n";
        while(getline(file61,line) )out_file << line << "\n";
        while(getline(file62,line) )out_file << line << "\n";
        while(getline(file63,line) )out_file << line << "\n";
        while(getline(file64,line) )out_file << line << "\n";
        while(getline(file65,line) )out_file << line << "\n";
        while(getline(file66,line) )out_file << line << "\n";
        while(getline(file67,line) )out_file << line << "\n";
        while(getline(file68,line) )out_file << line << "\n";
        while(getline(file69,line) )out_file << line << "\n";
        while(getline(file70,line) )out_file << line << "\n";
        while(getline(file71,line) )out_file << line << "\n";
        while(getline(file72,line) )out_file << line << "\n";
        while(getline(file73,line) )out_file << line << "\n";
        while(getline(file74,line) )out_file << line << "\n";
        while(getline(file75,line) )out_file << line << "\n";
        while(getline(file76,line) )out_file << line << "\n";
        //while(getline(file77,line) )out_file << line << "\n";
        while(getline(file78,line) )out_file << line << "\n";
        while(getline(file79,line) )out_file << line << "\n";
        while(getline(file80,line) )out_file << line << "\n";
        while(getline(file81,line) )out_file << line << "\n";
        while(getline(file82,line) )out_file << line << "\n";
        while(getline(file83,line) )out_file << line << "\n";
        while(getline(file84,line) )out_file << line << "\n";
        while(getline(file85,line) )out_file << line << "\n";
        while(getline(file86,line) )out_file << line << "\n";
        while(getline(file87,line) )out_file << line << "\n";
        while(getline(file88,line) )out_file << line << "\n";
        while(getline(file89,line) )out_file << line << "\n";
        while(getline(file90,line) )out_file << line << "\n";
        while(getline(file91,line) )out_file << line << "\n";
        while(getline(file92,line) )out_file << line << "\n";
        while(getline(file93,line) )out_file << line << "\n";
        while(getline(file94,line) )out_file << line << "\n";
        while(getline(file95,line) )out_file << line << "\n";
        while(getline(file96,line) )out_file << line << "\n";
        while(getline(file97,line) )out_file << line << "\n";
        while(getline(file979,line) )out_file << line << "\n";
        while(getline(file98,line) )out_file << line << "\n";
        while(getline(file99,line) )out_file << line << "\n";
        while(getline(file100,line) )out_file << line << "\n";
        while(getline(file101,line) )out_file << line << "\n";
        while(getline(file102,line) )out_file << line << "\n";
        while(getline(file103,line) )out_file << line << "\n";
        while(getline(file104,line) )out_file << line << "\n";
        while(getline(file105,line) )out_file << line << "\n";
        while(getline(file106,line) )out_file << line << "\n";
        while(getline(file107,line) )out_file << line << "\n";
        while(getline(file108,line) )out_file << line << "\n";
        while(getline(file109,line) )out_file << line << "\n";
        while(getline(file110,line) )out_file << line << "\n";
        while(getline(file111,line) )out_file << line << "\n";
        while(getline(file112,line) )out_file << line << "\n";
        while(getline(file113,line) )out_file << line << "\n";
        while(getline(file114,line) )out_file << line << "\n";
        while(getline(file115,line) )out_file << line << "\n";
        while(getline(file116,line) )out_file << line << "\n";
        while(getline(file117,line) )out_file << line << "\n";
        while(getline(file118,line) )out_file << line << "\n";
        while(getline(file119,line) )out_file << line << "\n";
        while(getline(file120,line) )out_file << line << "\n";
        while(getline(file121,line) )out_file << line << "\n";
        cout << "Copy Finished from several small files\n";

    } else {
        //Something went wrong
        printf("Cannot read File");
    }

    //Closing file
    file1.close();
    file2.close();
    file3.close();
    file4.close();
    file5.close();
    file6.close();
    file7.close();
    file8.close();
    file9.close();
    file10.close();
    file11.close();
    file12.close();
    file13.close();
    file14.close();
    file15.close();
    file16.close();
    file17.close();
    file18.close();
    file19.close();
    file20.close();
    file21.close();
    file22.close();
    file23.close();
    file24.close();
    file25.close();
    file26.close();
    file27.close();
    file28.close();
    file29.close();
    file30.close();
    file31.close();
    file32.close();
    file33.close();
    file34.close();
    file35.close();
    file36.close();
    file37.close();
    file38.close();
    file39.close();
    file40.close();
    file41.close();
    file42.close();
    file43.close();
    //file44.close();
    file45.close();
    file46.close();
    file47.close();
    file48.close();
    file49.close();
    file50.close();
    file51.close();
    file52.close();
    file53.close();
    file54.close();
    file55.close();
    file56.close();
    file57.close();
    file58.close();
    file59.close();
    file60.close();
    file61.close();
    file62.close();
    file63.close();
    file64.close();
    file65.close();
    file66.close();
    file67.close();
    file68.close();
    file69.close();
    file70.close();
    file71.close();
    file72.close();
    file73.close();
    file74.close();
    file75.close();
    file76.close();
//    file77.close();
    file78.close();
    file79.close();
    file80.close();
    file81.close();
    file82.close();
    file83.close();
    file84.close();
    file85.close();
    file86.close();
    file87.close();
    file88.close();
    file89.close();
    file90.close();
    file91.close();
    file92.close();
    file93.close();
    file94.close();
    file95.close();
    file96.close();
    file97.close();
    file979.close();
    file98.close();
    file99.close();
    file100.close();
    file101.close();
    file102.close();
    file103.close();
    file104.close();
    file105.close();
    file106.close();
    file107.close();
    file108.close();
    file109.close();
    file110.close();
    file111.close();
    file112.close();
    file113.close();
    file114.close();
    file115.close();
    file116.close();
    file117.close();
    file118.close();
    file119.close();
    file120.close();
    file121.close();
    out_file.close();

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_e);

    std::cout << "time taken to copy 120 small files is"<<Substraction(time_s,time_e).tv_sec<<":"<<Substraction(time_s,time_e).tv_nsec<< '\n';



    //string line;
    timespec t1, t2;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t1);
    //For writing text file
    //Creating ofstream & ifstream class object
    ifstream inputFile ("large107MB.txt");
    ofstream outFile2 ("CopyFromlargefile.txt");

    if(inputFile && outFile2){

        while(getline(inputFile,line)){
            outFile2 << line << "\n";
        }

        cout << "Copy Finished of Large file \n";

    } else {
        //Something went wrong
        printf("Cannot read File");
    }

    //Closing file
    inputFile.close();
    outFile2.close();

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t2);

    std::cout << "time taken to Copy large file is"<<Substraction(t1,t2).tv_sec<<":"<<Substraction(t1,t2).tv_nsec<< '\n';
    return 0;
}
