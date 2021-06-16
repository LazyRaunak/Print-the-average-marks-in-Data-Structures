#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>


using namespace std;

#define NUM_FIELDS 3
struct SplitLine {
    std::string fields[NUM_FIELDS];
};

int processData(std::vector<struct SplitLine> data) 
{
    string id;
    int num;
    map<string, double> studentMarks;
    map<string, double> studentMarksAvg;
    map<string, double> studentCount;
    // auto x = data[0].fields[2];
    int numOfID=0;
    double sum, avgMarks=0;
    
    for(int i=0; i<data.size(); i++)
    {
        for(int j=0; j<data.size(); j++)
        {
            if((data[i].fields[0]) == (data[j].fields[0]))
                {
                    sum += stoi(data[j].fields[2]);
                    numOfID++;
                }
        }
        avgMarks = sum/numOfID;
        studentMarksAvg.insert(make_pair(data[i].fields[0], avgMarks));
        studentMarks.insert(make_pair(data[i].fields[0], sum));
        sum = 0;
        numOfID = 0;
    }

    for(int i=0; i<data.size(); i++)
    {
        studentCount[data[i].fields[0]]++;
    }
    
    cout<<" "<<endl;
    cout<<"ID & Total Marks of student"<<endl;
    for(auto pair1:studentMarks)
        cout<<pair1.first<<"->"<<pair1.second<<endl;
    
    cout<<endl<<"ID & Number of student"<<endl;
    for(auto pair2:studentCount)
        cout<<pair2.first<<"->"<<pair2.second<<endl;
    
        
    cout<<endl<<"ID & Average Marks of student"<<endl;
    for(auto pair3:studentMarksAvg)
        cout<<pair3.first<<"->"<<pair3.second<<endl;
    
    return studentMarksAvg.begin()->second; //To return the first value of the key
}

int main(void) {
  std::ifstream in("input.txt");
  std::vector<struct SplitLine> input_data;
  while (in) {
    struct SplitLine line;
    for (int i=0; i<NUM_FIELDS; i++) {
      if (i==NUM_FIELDS-1)
        std::getline(in, line.fields[i]);
      else
        std::getline(in, line.fields[i], ',');
    }
    if (line.fields[0] != "")
      input_data.push_back(line);
  }
  std::ofstream out("output.txt");
  out << processData(input_data) << std::endl;
  return 0;
}
