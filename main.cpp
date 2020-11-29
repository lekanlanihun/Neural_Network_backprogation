/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lekan
 *
 * Created on 08 September 2020, 11:51
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

/*
 * 
 */

#include "NeuralNetwork.h"

int main(int argc, char** argv) {
// values for input, hidden and output nodes;
int input nodes=20; int hidden_nodes=5; output nodes=2;
int rows; int cols;int num_outputs;
        double inputs[rows][cols];
    double outputs[1];
    double desired_outputs[num_outputs];
    NeuralNetwork*neural;
    neural=new NeuralNetwork(input_nodes,hidden_nodes,output_nodes);
    

    int epochs =1000; int num_steps=4;
    
    //for(int i=0;i<epochs;i++){
            for (int steps = 0; steps < num_steps; steps++) {  
                neural->step(inputs[steps], desired_outputs);
               // cout<<steps<<" "<<outputs[0]<<endl;
            }//end of steps
    //}
    return 0;
}

