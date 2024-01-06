#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "../../graph.cpp"

using namespace std;

int main(void){
    //sample graph test
    Graph SN(11); //4 users
    SN.follow(1, 2); //1 has 2 as a follower
    SN.follow(1, 4); //1 has 4 as a follower
    SN.follow(1, 7);
    SN.follow(1, 6);
    SN.follow(2, 3); //2 has 3 as a follower
    SN.follow(2, 5); //2 has 5 as a follower
    SN.follow(2, 4);
    SN.follow(2, 6);
    SN.follow(2, 7); //2 has 4 as a follower
    SN.follow(3, 2); //3 has 2 as a follower
    SN.follow(4, 1); //4 has 1 as a follower
    SN.follow(4, 3); //4 has 3 as a follower
    SN.follow(4, 8);
    SN.follow(4, 9);
    SN.follow(3, 10);
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
    vector<int> followers2 = SN.getFollower(2);
    cout << "User2 Followers: " << endl;
    for(int i = 0; i < followers2.size(); i++){
        cout << "User" << followers2[i] << endl;
    }

    int influencer= SN.getMostInfluencerUser(SN);
    int active= SN.getMostActiveUser(SN);
    vector<int> suggest1 = SN.suggestUsersToFollow(1);
    vector<int> mutual = SN.getMutualFollowers(1,2);
    cout<<"influencer"<<influencer<<endl;
    cout<<"active"<< active<<endl;
    cout<<"mutual users"<<endl;
    for(int i = 0; i < mutual.size(); i++){
        cout<<mutual[i]<<endl;
    }
    cout<<"suggested users"<<endl;
    for(int i = 0; i < suggest1.size(); i++){
        cout<<suggest1[i]<<endl;
    }

    string text = "Mutual Followers:\r\n";
    for(int i = 0; i < mutual.size(); i++){
        text += ("User" + to_string(mutual[i]) + "\r\n");
    }
    cout<<text<<endl;
    GraphViz(SN);
}