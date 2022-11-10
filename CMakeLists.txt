cmake_minimum_required(VERSION 3.23)
project(markov_sentence_generator)

set(CMAKE_CXX_STANDARD 14)

add_executable(markov_sentence_generator main.cpp markov/markov.cpp markov/markov.h)
