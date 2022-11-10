#include <fstream>
#include <iostream>
#include <map>
#include "markov/markov.h"

bool cmdOptionExists(char**, char**, const std::string&);
std::string getCmdOption(char** , char**, const std::string&);

int main(int argc, char * argv[]) {
    std::srand(std::time(nullptr));
    std::rand();

    std::string filename = "";
    std::cout << filename << std::endl;
    if (cmdOptionExists(argv, argv+argc, "-f")) {
        filename = getCmdOption(argv, argv+argc, "-f");
    } else {
        std::cout << "-f parameter is required" << std::endl;
        return 1;
    }

    std::cout << "Open file " << filename << std::endl;

    std::ifstream file(filename);
    std::string str;

    Markov *M = new Markov;

    while (std::getline(file, str)) {
        M->CollectWordRelation(str);
    }

    std::string sentence;
    std::string current_word;
    for (int i; i <= 50; i++) {
        current_word = M->GetRandomNextWord(current_word);
        if (current_word == "." || current_word == "," || current_word == "!" || current_word == "?"){
            sentence += current_word;
        } else if (!sentence.empty()){
            sentence += " " + current_word;
        } else {
            sentence += current_word;
        }

        if (current_word.empty()) {
            break;
        }
    }

    std::cout << sentence << std::endl;
    return 0;
}

bool cmdOptionExists(char** begin, char** end, const std::string& option) {
    return std::find(begin, end, option) != end;
}

std::string getCmdOption(char ** begin, char ** end, const std::string & option) {
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end) {
        return *itr;
    }
    return "";
}
