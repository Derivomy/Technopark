#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    vector<char> used_letters;
    string word, letter; 
    bool guessed = false, wait = true;
    int lives = 7;
    cout << "ENTER A WORD (LOWERCASE)" << endl;
    cin >> word;
    for (int i = 0; i < 200; i ++){
        cout << endl;
    }
    cout << "THIS WORD HAS " << word.length() << " LETTERS" << endl;
    while (lives > 0 && guessed == false){
        wait = true;
        while (wait == true){
            wait = false;
            cout << "ENTER A LETTER (LOWERCASE)" << endl;
            cin >> letter;
            if (letter.length() != 1){
                cout << "ONE LETTER!" << endl;
                wait = true;
            }
            else{
                for (auto i: used_letters){
                    if (i == letter[0]){
                        cout << "THIS LETTER HAS ALREADY BEEN USED. USE ANOTHER ONE" << endl;
                        wait = true;
                        break;
                    }
                }
            }
        }
        used_letters.push_back(letter[0]);
        wait = false;
        for (auto i: word){
            if (i == letter[0]){
                cout << "THIS LETTER IS IN THE WORD! YOUR PROGRESS: " << endl;
                wait = true;
                break;
            }
        }
        if (wait == false){
            cout << "NO! YOU LOST A LIFE! YOUR PROGRESS: " << endl;
            lives --;
        }
        int counter = 0;
        for (int i = 0; i < word.length(); i++){
            wait = true;
            for (auto l: used_letters){
                if (l == word[i]){
                    cout << l;
                    counter ++;
                    wait = false;
                    break;
                }
            }
            if (wait == true){
                cout << "_";
            }
        }
        cout << endl << "NUMBER OF LIVES: " << lives << endl;
        if (counter == word.length()){
            guessed = true;
        }
    }
    if (lives == 0){
        cout << "YOU LOST!";
    }
    else{
        cout << "YOU WON!";
    }
    cout << " THE WORD WAS: " << word << endl;
    return 0;
}