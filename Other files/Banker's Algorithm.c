// C++ Program to Print all possible safe sequences using banker's algorithm
#include <iostream>
#include <string.h>
#include <vector>
// total number of process
#define P 4
// total number of resources
#define R 3
 
// total safe-sequences
int total = 0;
 
using namespace std;
 
// function to check if process
// can be allocated or not
bool is_available(int process_id, int allocated[][R],
                  int max[][R], int need[][R], int available[])
{
 
    bool flag = true;
 
    // check if all the available resources
    // are less greater than need of process
    for (int i = 0; i < R; i++) {
 
        if (need[process_id][i] > available[i])
            flag = false;
    }
 
    return flag;
}
 
// Print all the safe-sequences
void safe_sequence(bool marked[], int allocated[][R], int max[][R],
                   int need[][R], int available[], vector<int> safe)
{
 
    for (int i = 0; i < P; i++) {
 
        // check if it is not marked
        // already and can be allocated
        if (!marked[i] && is_available(i, allocated, max, need, available)) {
 
            // mark the process
            marked[i] = true;
 
            // increase the available
            // by deallocating from process i
            for (int j = 0; j < R; j++)
                available[j] += allocated[i][j];
 
            safe.push_back(i);
            // find safe sequence by taking process i
            safe_sequence(marked, allocated, max, need, available, safe);
            safe.pop_back();
 
            // unmark the process
            marked[i] = false;
 
            // decrease the available
            for (int j = 0; j < R; j++)
                available[j] -= allocated[i][j];
        }
    }
 
    // if a safe-sequence is found, display it
    if (safe.size() == P) {
 
        total++;
        for (int i = 0; i < P; i++) {
 
            cout << "P" << safe[i] + 1;
            if (i != (P - 1))
                cout << "--> ";
        }
 
        cout << endl;
    }
}
 
// Driver Code
int main()
{
 
    // allocated matrix of size P*R
    int allocated[P][R] = { { 0, 1, 0 },
                            { 2, 0, 0 },
                            { 3, 0, 2 },
                            { 2, 1, 1 } };
 
    // max matrix of size P*R
    int max[P][R] = { { 7, 5, 3 },
                      { 3, 2, 2 },
                      { 9, 0, 2 },
                      { 2, 2, 2 } };
 
    // Initial total resources
    int resources[R] = { 10, 5, 7 };
 
    // available vector of size R
    int available[R];
 
    for (int i = 0; i < R; i++) {
 
        int sum = 0;
        for (int j = 0; j < P; j++)
            sum += allocated[j][i];
 
        available[i] = resources[i] - sum;
    }
 
    // safe vector for displaying a safe-sequence
    vector<int> safe;
 
    // marked of size P for marking allocated process
    bool marked[P];
    memset(marked, false, sizeof(marked));
 
    // need matrix of size P*R
    int need[P][R];
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allocated[i][j];
 
    cout << "Safe sequences are:" << endl;
    safe_sequence(marked, allocated, max, need, available, safe);
 
    cout << "\nThere are total " << total << " safe-sequences" << endl;
    return 0;
}
