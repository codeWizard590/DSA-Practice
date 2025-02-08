#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    set<vector<int>> st;
    
    // st.insert(1);
    // st.insert(2);
    // st.insert(6);
    st.insert({4, 5, 6});
    st.insert({7, 8, 9});
    st.insert({8, 2, 9});

    // Convert set of vectors to vector of vectors
    // this is used to copy values from set to vector
    
    vector<vector<int>> ans(st.begin(), st.end());

    // Print the result
    for (const auto& v : ans) { 
        for (int num : v) {
            cout << num << " ";
       }
        cout << endl;
    }
   

    return 0;
}
