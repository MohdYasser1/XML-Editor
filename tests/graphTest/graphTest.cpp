#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "../../graph.cpp"

using namespace std;

int main(void){
    //sample graph test
    Graph SN(4); //4 users
    SN.follow(1, 2); //1 has 2 as a follower
    SN.follow(1, 4); //1 has 4 as a follower
    SN.follow(2, 3); //2 has 3 as a follower
    SN.follow(2, 4); //2 has 4 as a follower
    SN.follow(3, 2); //3 has 2 as a follower
    SN.follow(4, 1); //4 has 1 as a follower
    SN.follow(4, 3); //4 has 3 as a follower

    vector<int> follwers1 = SN.getFollower(1);
    cout << "User1 Followers: " << endl;
    for(int i = 0; i < follwers1.size(); i++){
        cout << "User" << follwers1[i] << endl;
    }
    cout << "\nUser1 following:" << endl;
    vector<int> following1 = SN.getFollowing(1);
    for(int i = 0; i < following1.size(); i++){
        cout << "User" << following1[i] << endl;
    }
}