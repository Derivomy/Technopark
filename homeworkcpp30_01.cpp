#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> generate_vector(int n, int lenght){
    vector<string> v1;
    for (int i = 0; i < n; i++){
        string temp;
        for (int j = 0; j < lenght; j++){
            temp += rand() % 128;
        }
        cout << temp << endl;
        v1.push_back(temp);
    }
    return v1;
}

vector<string> find_duplicates(vector<string> v1){
    vector<string> v2, v3;
    for (auto i: v1){
        bool flag = true;
        for (auto j: v2){
            if (i == j){
                flag = false;
                for (auto k: v3){
                    if (i == k){
                        v3.push_back(i);
                    }
                }
                break;
            }
        }
        if (flag){
            v2.push_back(i);
        }
    }
    cout << "DUPLICATES:" << endl;
    for (auto k: v3){
        cout << k << " ";
    }
    cout << endl;
    return v2;
}

int main(){
    vector<string> v1;
    int n, l;
    cin >> n >> l;
    v1 = generate_vector(n, l);
    v1 = find_duplicates(v1);
    cout << "VECTOR AFTER SORTING:" << endl;
    for (auto i: v1){
        cout << i << " ";
    }
    return 0;
}