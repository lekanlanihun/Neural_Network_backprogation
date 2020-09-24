/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NeuralNetwork.h
 * Author: lekan
 *
 * Created on 08 September 2020, 11:58
 */

#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#define inputsize 100
#define hidden_nodes 10
#define output_nodes 5
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <vector>

class NeuralNetwork {
public:
    NeuralNetwork();
    NeuralNetwork(const NeuralNetwork& orig);
    double *compute_hidden_activation(double*);
    double *compute_output_activation(double*);
    double*sigmoid_function(double*,int);
    void step(double*, double*);
    double square(double val);
    
    
    //vector<double>weight;
    virtual ~NeuralNetwork();
private: 
    double result;
    //vector<int>inputs;
    double*input_vector;
    double *hidden_value_vector;
    double*output_value_vector;
    double**input_weights;
    double**hidden_weights;
    double*sigmoid_result;
    
   

};

#endif /* NEURALNETWORK_H */

