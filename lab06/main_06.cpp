#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "QuizItem.h"
#include "Quiz.h"
#include "User.h"
#include "QuizGame.h"
using namespace std;

int main() {
    ifstream fin("a.txt");
    if (!fin) {
        throw runtime_error("Could not open file a.txt");
    }
    Quiz FirstQuiz(1, string("Fist Quiz"));
    string line;
    while (getline(fin, line)) {
        if(line.empty()) continue;
        if(line[0] == 'Q'){
            string question = line.substr(2);
            vector<string> answers;
            for(int i = 0; i < 4; ++i){
                getline(fin, line);
                if(line[0]=='A'){
                    answers.push_back(line.substr(2));
                }
            }
            int correct_index;
            fin>>correct_index;
            QuizItem item(question, answers, correct_index);
            FirstQuiz.addItem(item);
        }
    }
    FirstQuiz.finalize();
    //printquiz(FirstQuiz);
    User user1(1, "Badogos");
    QuizGame game(user1, FirstQuiz);
    game.run(); 
    user1.print_results();

    return 0;
}