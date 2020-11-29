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
/*#define inputsize 100
#define hidden_nodes 10
#define output_nodes 5*/
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
using namespace std;

class NeuralNetwork {
public:
    NeuralNetwork(int, int, int);
    NeuralNetwork(const NeuralNetwork& orig);
    void init_network_parameters();
    void compute_hidden_activation(double*);
    double* compute_output_activation();
    void compute_derivatves_cost_act(double*,double*);
    double* compute_derivatves_sigmoid(double*,int);
    double*sigmoid_function(double*,int);
    void step(double*,double*);
    void measure_error();
    void measure_hidden_error();
    void compute_opt_output_weights(); //optimised output weights
    void compute_opt_hidden_weights(); //optimised hidden weights
    void der_cost_to_output_weights();
    void der_cost_to_hidden_weights();
    
    
    //vector<double>weight;
    virtual ~NeuralNetwork();
private: 
    double result;
    //vector<int>inputs;
    double*sigmoid_der;double*sigmoid_hidden_der;
    double*input_vector;
    double*der_cost;
    double*delta; double *delta_hidden;
    double *hidden_value_vector;
    double*hidden_activations;
    double*output_value_vector;
    double*hidden_activation;
    double*output_activation;
    double**input_weights;
    double**hidden_weights;
    double*hidden_bias;
    double*output_bias;
    double*sigmoid_result;
    
    int inputsize;int hidden_nodes; int output_nodes;

};

#endif /* NEURALNETWORK_H */

