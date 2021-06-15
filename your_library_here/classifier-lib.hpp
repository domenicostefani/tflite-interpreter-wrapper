/*
 * TFlite Classifier library
 * Author: Domenico Stefani (domenico.stefani96@gmail.com)
*/
#pragma once

#include <string>
#include <vector>
#include <array>
#include <cstdio>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <utility>
#include <limits>       // std::numeric_limits

/** Opaque pointer for classifier object */
class Classifier;
using ClassifierPtr = Classifier* ;

/** Dynamically allocate an instance of a classifier object (do not use in real time threads) */
ClassifierPtr createClassifier(const std::string &filename, bool verbose = false);

// /** Feed the feature vector to the model, execute and return the prediction */
int classify(ClassifierPtr cls, const std::vector<float>& featureVector, std::vector<float>& outVector);

int classify(ClassifierPtr cls, const float featureVector[], size_t numFeatures, float outputVector[], size_t numClasses);

template<std::size_t IN_SIZE, std::size_t OUT_SIZE>
int classify(ClassifierPtr cls, std::array<float,IN_SIZE>& featureArray, std::array<float,OUT_SIZE>& outputArray)
{
    const float* fa = &(featureArray[0]);
    float* oa = &(outputArray[0]);
    return classify(cls, fa , (size_t)IN_SIZE, oa, (size_t)OUT_SIZE);
}

/** Free the classifier memory (do not use in real time threads) */
void deleteClassifier(ClassifierPtr cls);





