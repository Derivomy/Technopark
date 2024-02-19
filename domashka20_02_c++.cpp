#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct weight_to_age{
    int age = 0, weight = 0;
    int get_age(){
        return age;
    }
    int get_weight(){
        return weight;
    }
    void print_info(){
        cout << "AGE: " << age << ". WEIGHT = " << weight << endl;
    }
};

float get_average_weight_of_age(vector<weight_to_age> v1, int what_age){
        float sum_of_all = 0;
        int number_of_people = 0;
        for (auto i: v1){
            if (i.get_age() == what_age){
                number_of_people ++;
                sum_of_all += i.get_weight();
            }
        }
        if (sum_of_all == 0){
            return 0;
        }
        else{
            return sum_of_all / number_of_people;
        }
    }

int main(){
    vector<weight_to_age> v1;
    int n = 0, min_age = 1, max_age = 2, min_weight = 1, max_weight = 2;
    cout << "ENTER NUMBER OF PEOPLE FOR SIMULATION" << endl;
    cin >> n;
    cout << "ENTER MINIMAL AND MAXIMAL AGE OF PEOPLE IN SIMULATION" << endl;
    cin >> min_age >> max_age;
    cout << "ENTER MINIMAL AND MAXIMAL WEIGHT OF PEOPLE IN SIMULATION" << endl;
    cin >> min_weight >> max_weight;
    for (int i = 0; i < n; i ++){
        weight_to_age Person;
        Person.age = rand() % max_age + min_age;
        Person.weight = rand() % max_weight + min_weight;
        v1.push_back(Person);
    }
    int age_asked = 0;
    cout << "ENTER AGE TO GET AVERAGE WEIGHT OF PEOPLE IN SIMULATION" << endl;
    cin >> age_asked;
    float average_weight_ = 0;
    average_weight_ = get_average_weight_of_age(v1, age_asked);
    if (average_weight_ == 0){
        cout << "No data" << endl;
    }
    else{
        cout << "Average weight of people aged " << age_asked << " is equal to " << average_weight_ << " kg" << endl;
    }
    string wait_for_input;
    cout << "ENTER ANYTHING TO PRINT DATA (CHANGES). IT WILL PRINT ONE BY ONE, YOU NEED TO ENTER ANYTHING EACH TIME TO CONTINUE" << endl;
    cin >> wait_for_input;
    float last_weight = 0;
    average_weight_ = get_average_weight_of_age(v1, min_age);
    cout << "People at age " << min_age << " weigh on average " << average_weight_ << " kg" << endl;
    last_weight = average_weight_;
    cin >> wait_for_input;
    for (int i = min_age + 1; i <= max_age; i ++){
        average_weight_ = get_average_weight_of_age(v1, i);
        float change_weight = average_weight_ - last_weight;
        cout << "People at age " << i << " are on average " << change_weight << " kg heavier than the average person in the previous year";
        cin >> wait_for_input;
        last_weight = average_weight_;
    }
    cout << endl << "----------------------STATISTICS HAVE ENDED----------------------" << endl << endl;
    cout << "ENTER ANYTHING TO PRINT ALL OF THE GENERATED DATA" << endl;
    cin >> wait_for_input;
    for (auto i: v1){
        i.print_info();
    }
    return 0;
}