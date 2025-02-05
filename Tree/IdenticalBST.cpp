#include <bits/stdc++.h>
using namespace std;

bool checkIdenticalBST(vector<int>& v1, vector<int>& v2, int a1, int a2, int minValue, int maxValue) {

	// find the first element in v1 within range
	int i;
	for(i = a1 ; i < v1.size() ; i++) {
		if(v1[i] > minValue && v1[i]<maxValue) break;
	}

	//  find the first element in v2 within range
    int j;
    for(j = a1 ; j < v2.size() ; j++){
       if(v2[j] > minValue && v2[j]<maxValue) break; 
    }
    
    // if no element is found within range (leaf nodes)
    if(i == v1.size() && j == v2.size()) return true;
    
    // if only one vector does not have element within range
    if((i == v1.size() && j != v2.size()) && (i != v1.size() && j == v2.size())){
        return false;
    }
    
    // checking if both elemenets are equal
    if(v1[i] != v2[j]) return false;
    
    // recursively check for left and right
    return checkIdenticalBST(v1,v2,a1+1,a2+1,minValue,v1[i]) && checkIdenticalBST(v1,v2,a1+1,a2+1,v1[i],maxValue);
}
int main()
{
    return checkIdenticalBST(v1,v2,0,0,INT_MIN,INT_MAX);


	// return 0;
}