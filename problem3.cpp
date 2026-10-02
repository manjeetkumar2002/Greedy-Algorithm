// You are given two arrays mices[] and holes[] of the same size. The array mices[] represents the positions of the mice on a straight line, while the array holes[] represents the positions of the holes on the same line. Each hole can accommodate exactly one mouse. A mouse can either stay in its current position, move one step to the right, or move one step to the left, and each move takes one minute. The task is to assign each mouse to a distinct hole in such a way that the time taken by the last mouse to reach its hole is minimized.
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        
        int time = INT64_MAX;
        
        for(int i=0;i<mices.size();i++){
            time=max(time,abs(mices[i]-holes[i]));
        }
        return time;
    }