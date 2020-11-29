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

NeuralNetwork::NeuralNetwork(int inputnodes, int hiddennodes, int outputnodes) {
    inputsize=inputnodes; hidden_nodes=hiddennodes; output_nodes=outputnodes;
    input_vector=new double[inputsize];
    hidden_activations=new double[hidden_nodes];
    sigmoid_der=new double[output_nodes]; //memory allocation for derivatives for output layer
    sigmoid_hidden_der=new double[hidden_nodes]; //memory allocation for derivatives for hidden layer
    
    der_cost=new double[output_nodes];
    delta=new double[output_nodes];
    delta_hidden=new double[hidden_nodes];
    hidden_activation=new double[hidden_nodes];
    output_activation=new double[output_nodes];
    hidden_bias=new double[hidden_nodes];
    output_bias=new double[output_nodes];
    
    input_weights=new double *[hidden_nodes];
    for(int i=0; i<hidden_nodes;i++){
        input_weights[i]=new double[inputsize];
    }
    
     hidden_weights=new double *[output_nodes];
    for(int i=0; i<output_nodes;i++){
        hidden_weights[i]=new double[hidden_nodes];
    }
     init_network_parameters();
     hidden_value_vector=new double [hidden_nodes];
     output_value_vector=new double[output_nodes];
}

NeuralNetwork::NeuralNetwork(const NeuralNetwork& orig) {
};

//this method initialialises the values for the parameters, i.e. weights and biases
void NeuralNetwork::init_network_parameters(){
    for(int i=0;i<hidden_nodes;i++){
        for(int j=0;j<inputsize;j++){
            input_weights[i][j]=(float)rand()/RAND_MAX;
            //cout<<input_weights[i][j]<<endl;
            //cout<<static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
//cout<<1.2 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(3.4-1.2)));
        }
    }
    
    for(int i=0;i<output_nodes;i++){
        for(int j=0;j<hidden_nodes;j++){
            hidden_weights[i][j]=(float)rand()/RAND_MAX;
        }
    }
    
    for(int i=0;i<output_nodes;i++)
        output_bias[i]=1;
    
     for(int i=0;i<hidden_nodes;i++)
        hidden_bias[i]=1;
    
    
}

void NeuralNetwork::compute_hidden_activation(double*input_vector){
    for(int i=0; i<hidden_nodes;i++){
        hidden_value_vector[i]=0.0; 
        for(int j=0;j<inputsize;j++){
            hidden_value_vector[i]+=input_weights[i][j]*input_vector[j];
        }
        hidden_value_vector[i]+=hidden_bias[i];
    }
    
   hidden_activation =sigmoid_function(hidden_value_vector, hidden_nodes);
   sigmoid_hidden_der=compute_derivatves_sigmoid(hidden_value_vector,hidden_nodes);
   
}

double* NeuralNetwork::compute_output_activation(){
     for(int i=0; i<output_nodes;i++){
        output_value_vector[i]=0.0; 
        for(int j=0;j<hidden_nodes;j++){
            output_value_vector[i]+=hidden_weights[i][j]*hidden_value_vector[j];
        }
        output_value_vector[i]+=output_bias[i];
    }
   output_activation= sigmoid_function(output_value_vector, output_nodes);  
   sigmoid_der=compute_derivatves_sigmoid(output_value_vector,output_nodes);
   return output_activation;
}

double *NeuralNetwork::sigmoid_function(double *sum_weights_values, int num_nodes){
    
    for(int i=0;i<num_nodes;i++){
        sum_weights_values[i]=1/1+exp(-sum_weights_values[i]);
    }
    return sum_weights_values;
}

void NeuralNetwork::compute_derivatves_cost_act(double *actual, double *desire){
    for(int i=0; i<output_nodes;i++){
        der_cost[i]=actual[i]-desire[i];
    }
}

double* NeuralNetwork::compute_derivatves_sigmoid(double *sum_params, int nodes){
    double sigmoid_derivatives[nodes];
    for(int i=0; i<hidden_nodes;i++){
       sigmoid_derivatives[i]=-(2/1+exp(-sum_params[i]));
    }
    return sigmoid_derivatives;
    
}

void NeuralNetwork::measure_error(){
    
    for(int i=0; i<hidden_nodes;i++){
        delta[i]=der_cost[i]*sigmoid_der[i];
    }
    
     
                                   
    
}

void NeuralNetwork::measure_hidden_error(){
    double transposed_hidden_weights [output_nodes][hidden_nodes];
    
     for(int i=0;i<output_nodes;i++){
        for(int j=0;j<hidden_nodes;j++){
            transposed_hidden_weights[j][i]=hidden_weights[i][j];
        }
    }
    
    for(int i=0;i<output_nodes;i++){
        delta_hidden[i]=0.0;
        for(int j=0;j<hidden_nodes;j++){
           delta_hidden[j]+= transposed_hidden_weights[i][j]*delta[i];
        }
    }
    for(int i=0;i<hidden_nodes;i++){
        delta_hidden[i]=delta_hidden[i]*sigmoid_hidden_der[i];
    } 
}


void NeuralNetwork::compute_opt_output_weights(){
    for(int i=0;i<output_nodes;i++){
        int k=0;
        for(int j=0;j<hidden_nodes;j++){
            hidden_weights[i][j]-=hidden_activation[j]*delta[k];
        }
        k++;
        output_bias[i]-=delta[i];
    }
}

void NeuralNetwork::compute_opt_hidden_weights(){
    for(int i=0;i<hidden_nodes;i++){
        int k=0;
        for(int j=0;j<inputsize;j++){
            input_weights[i][j]-=input_vector[j]*delta_hidden[k];
        }
        k++;
        hidden_bias[i]-=delta_hidden[i];
        
    }
}


void NeuralNetwork::step(double*input_values,double*desire){
    compute_hidden_activation(input_values);
    double*actual=compute_output_activation();
    cout<<"actual output="<<" "<<actual<<endl;
    compute_derivatves_cost_act(actual,desire);
    measure_error();
    compute_opt_output_weights();
     measure_hidden_error();
     compute_opt_hidden_weights();
}



NeuralNetwork::~NeuralNetwork() {
    delete [] input_vector;
    delete[] hidden_activations;
    delete [] sigmoid_der;
    delete [] sigmoid_hidden_der;
    delete [] delta;
    delete [] delta_hidden;
    delete [] der_cost;
    delete [] hidden_value_vector;
    delete [] output_value_vector;
    delete [] hidden_activation;
    delete [] output_activation;
    delete [] hidden_bias;
    delete [] output_bias;
    for(int i=0; i<hidden_nodes;i++){
        delete [] input_weights[i];
    }
    delete [] input_weights;
    
        for(int i=0; i<output_nodes;i++){
        delete [] hidden_weights[i];
    }
    delete [] hidden_weights;
    
}

