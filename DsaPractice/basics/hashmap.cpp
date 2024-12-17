#include<bits/stdc++.h>
using namespace std;
/*
   working of finding keys in the hashmap . cannot find index if end() is not defined
   why ? it returns to the end of the hashmap if it doesn't find the key associated . causes memory overflow  
*/
void findHash(){
    map<string, int> mp;
    mp.insert({"apple",30});
    mp.insert({"banana",10});

    //  iterating through the maps
    for(auto it:mp){
        cout<<"key:"<<it.first<<" value : "<<it.second<<endl;
    }

    // finding in the hashmap .
    string key="apple";
    if(mp.find(key)!=mp.end()){
        cout<<"return if key is found "<<key<<" : "<< mp[key];
    }
    
}

/*
    POINTS TO REMEMBER 
    1. WHEN find(key)!=end() -> returns true if the key is inside the array
    2. WHEN find(key)==end() -> returns true if the key is not present inside the array .
*/

void hashDoubts(){
    map<long long ,int> preSumMap;
    long long rem=0; int maxLen=0;
    // returns true when the rem is present in the map. -> goes inside when key is present .......
    if (preSumMap.find(rem) != preSumMap.end()) {
        int len = 1 - preSumMap[rem];
        maxLen = max(maxLen, len);
        cout<<"found";
    }
    else{
        cout<<endl<<"when find(key)!=end() ->not found"<<endl;
    }
    // retrun true when rem is not present inside the map.
    if (preSumMap.find(rem) == preSumMap.end()) {
        int len = 1 - preSumMap[rem];
        maxLen = max(maxLen, len);
        cout<<"when find(key)==end() ->found";
    }
}

int main(){
    findHash();
    hashDoubts();
}






