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
    NeuralNetwork*neural;
    neural=new NeuralNetwork();
// double result=square(5);
    cout<<"result="<<" "<<neural->square(5)<<endl;
    return 0;
}

