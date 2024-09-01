#include<bits/stdc++.h>
using namespace std;

class Hashing{
    vector<list<int>> hashTable;
    int buckets;
public:

    Hashing(int size){
        buckets = size;
        hashTable.resize(size);
    }

    int hashvalue(int key){
        return key%buckets;
    }

    void addKey(int key){
        int idx = hashvalue(key);
        hashTable[idx].push_back(key);
    }

    list<int>::iterator searchKey(int key){
        int idx = hashvalue(key);
        return find(hashTable[idx].begin(), hashTable[idx].end(), key);
    }

    void deleteKey(int key){
        
        int idx = hashvalue(key);
        if(searchKey(key) != hashTable[hashvalue(key)].end()){
            hashTable[idx].erase(searchKey(key));
            cout<<key<<" deleted successfully"<<endl;
        }else{
            cout<<key<<" not found"<<endl;
        }   
    }
};

int main(){
    Hashing h(7);
    h.addKey(10);
    h.addKey(20);   
    h.addKey(30);   
    h.addKey(40);
    h.deleteKey(20);
    h.deleteKey(20);

}