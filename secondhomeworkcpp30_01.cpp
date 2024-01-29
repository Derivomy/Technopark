#include <iostream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

vector<string> generate_vector(int n, int lenght){
    vector<string> v1;
    for (int i = 0; i < n; i++){
        string temp;
        for (int j = 0; j < lenght; j++){
            temp += rand() % 128;
        }
        v1.push_back(temp);
    }
    return v1;
}

long long hash_code(string s){
    const int k = 31, mod = 1e9+7;
    long long h;
     for (char c : s) {
        int x = (int) (c - 'a' + 1);
        h = (h * k + x) % mod;
    }
    return h;
}

vector<string> delete_duplicates(vector<string> s){
    vector<string> s2;
    for (int i = 0; i < s.size(); i++){
        bool flag = true;
        for (string c: s2){
            if (c == s[i]){
                flag = false;
                break;
            }
        }
        if (flag){
            s2.push_back(s[i]);
        }
    }
    return s2;
}

vector<long long> delete_duplicates_hash(vector<long long> s){
    vector<long long> s2;
    for (int i = 0; i < s.size(); i++){
        bool flag = true;
        for (long long c: s2){
            if (c == s[i]){
                flag = false;
                break;
            }
        }
        if (flag){
            s2.push_back(s[i]);
        }
    }
    return s2;
}

int main() {
    vector<string> s;
    s = generate_vector(10000, 3);
    vector<long long> s2;
    for (string c: s){
        s2.push_back(hash_code(c));
    }
    unsigned __int64 now = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    s = delete_duplicates(s);
    unsigned __int64 string_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count() - now;
    now = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    s2 = delete_duplicates_hash(s2);
    unsigned __int64 hash_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count() - now;
    cout << "Strings take " << (float) string_time / hash_time << " times more time to sort than hash codes.";
}