/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NeuralNetwork.cpp
 * Author: lekan
 * 
 * Created on 08 September 2020, 11:58
 */

#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork() {
    input_vector=new double[inputsize];
    
    input_weights=new double *[hidden_nodes];
    for(int i=0; i<hidden_nodes;i++){
        input_weights[i]=new double[inputsize];
    }
    
     hidden_weights=new double *[output_nodes];
    for(int i=0; i<output_nodes;i++){
        hidden_weights[i]=new double[hidden_nodes];
    }
     
     hidden_value_vector=new double [hidden_nodes];
     output_value_vector=new double[output_nodes];
}

NeuralNetwork::NeuralNetwork(const NeuralNetwork& orig) {
};

double *NeuralNetwork::compute_hidden_activation(double*input_vector){
    for(int i=0; i<hidden_nodes;i++){
        hidden_value_vector[i]=0.0;
        for(int j=0;j<inputsize;j++){
            hidden_value_vector[i]=input_weights[i][j]*input_vector[j];
        }
    }
    
   hidden_value_vector= sigmoid_function(hidden_value_vector, hidden_nodes);
}

double *NeuralNetwork::compute_output_activation(double*outputs){
     for(int i=0; i<output_nodes;i++){
        output_value_vector[i]=0.0;
        for(int j=0;j<hidden_nodes;j++){
            output_value_vector[i]=hidden_weights[i][j]*hidden_value_vector[j];
        }
    }
   output_value_vector= sigmoid_function(output_value_vector, output_nodes);  
}

double *NeuralNetwork::sigmoid_function(double *sum_weights_values, int num_nodes){
    double sigmoid_result [num_nodes];
    for(int i=0;i<num_nodes;i++){
        sigmoid_result[i]=1/1+exp(-sum_weights_values[i]);
    }
    //return sigmoid_result;
}

void NeuralNetwork::step(double*input_values,double *outputs){
    compute_hidden_activation(input_values);
    compute_output_activation(outputs);
}

double NeuralNetwork::square(double val){
    return val*val;
}

NeuralNetwork::~NeuralNetwork() {
    delete [] input_vector;
    delete [] hidden_value_vector;
    delete [] output_value_vector;
    for(int i=0; i<hidden_nodes;i++){
        delete [] input_weights[i];
    }
    delete [] input_weights;
    
        for(int i=0; i<output_nodes;i++){
        delete [] hidden_weights[i];
    }
    delete [] hidden_weights;
    
}

