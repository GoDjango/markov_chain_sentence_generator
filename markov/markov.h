#ifndef MARKOV_SENTENCE_GENERATOR_MARKOV_H
#define MARKOV_SENTENCE_GENERATOR_MARKOV_H

#include <iostream>
#include <map>

class Markov {
private:
    std::map<std::string, std::map<std::string, uint>> collection;
    std::map<std::string, uint> counter;
    std::string last_word;
public:
    Markov();
    ~Markov();
    void Add(const std::string &word);

    std::string GetRandomNextWord(std::string &word);

    void CollectWordRelation(const std::string &str);
};

#endif //MARKOV_SENTENCE_GENERATOR_MARKOV_H
