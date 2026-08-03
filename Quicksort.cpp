#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &v, int s, int e){
    if(s >= e) return;

    int pivot = e;
    int i = s;

    for(int j = s; j < e; j++){
        if(v[j] < v[pivot]){
            swap(v[j], v[i]);
            i++;
        }
    }

    swap(v[pivot], v[i]);

    quickSort(v, s, i - 1);
    quickSort(v, i + 1, e);
}

int main(){
    vector<int> v = {4, 3, -1, 2, 7, 0};

    quickSort(v, 0, v.size() - 1);

    for(int x : v){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

