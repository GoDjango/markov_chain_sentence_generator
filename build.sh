#!/bin/bash

BUILD_DIR=./build
EXECUTABLE_FILE=markov_sentence_generator

mkdir -pv ${BUILD_DIR} && cd ${BUILD_DIR}

cd ${BUILD_DIR}
cmake ..
make all
cd ..
