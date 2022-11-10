#include <iterator>

#include "markov.h"

Markov::Markov() {}

Markov::~Markov() {}

void Markov::Add(const std::string &word) {
    this->counter[word]++;
    if (!this->last_word.empty()) {
        this->collection[last_word][word]++;
    }
    this->last_word = word;
}

std::string Markov::GetRandomNextWord(std::string &word) {
    if (word.empty()) {
        uint i = 0;
        uint len_collection = this->collection.size();
        uint random_number = std::rand()/((RAND_MAX + 1u)/len_collection);
        for (auto const& w: this->collection) {
            if (i == random_number) {
                return w.first;
            }
            i++;
        }
    }

    const std::map<std::string, uint> applicant = this->collection[word];
    uint count_words = 0, current_count = 0;

    for (auto const& w: applicant) {
        count_words += w.second;
    }

    uint random_number = 1 + std::rand()/((RAND_MAX + 1u)/count_words);

    for (auto const& w: applicant) {
        // Они все меньше max value
        current_count += w.second;
        if (random_number <= current_count) {
            return w.first;
        }
    }
    return "";
}

void Markov::CollectWordRelation(const std::string &str) {
    std::string word;
    char prev_char = ' ';

    for (char x : str) {
        if (x == '.' && prev_char == '.') {
            continue;
        } else if (x == '-' && prev_char == ' ') {
            prev_char = x;
            continue;
        } else if (x == ';' || x == ':' || x == '\"' || x == '\'' || x == '"' || x == '(' || x == ')') {
            continue;
        }

        if (!word.empty()) {
            if (x == '.' || x == ',' || x == '!' || x == '?') {
                this->Add(word);
                word = "";

                std::string s(1, x);
                this->Add(s);
            } else if (x == ' ') {
                this->Add(word);
                word = "";
            } else {
                word += x;
            }
        } else if (x != ' ' ) {
            word += x;
        }
        prev_char = x;
    }
}
