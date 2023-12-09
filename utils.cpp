#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/**
 * @brief This file contains functions that may be useful accross the project
 * 
 */

vector<string> reverseVectorString(vector<string> v){
    /**
     * @brief This function is used to reverse the order of a vector of strings
     * 
     * @param v The vector to reverse
     * @return The reverse vector
     */
    stack<string> stack;

    for(int i = 0; i < v.size();i++){

        stack.push(v[i]);
    }
    for(int i = 0; i < v.size(); i++){
        v[i] = stack.top();
        stack.pop();
    }
    return v;

}