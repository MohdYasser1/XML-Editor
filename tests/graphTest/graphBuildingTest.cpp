#include "../../graph.cpp"

int main(void){
    string xmlData = R"(
        <users>
            <user>
                <id>1</id>
                <name>Ahmed Ali</name>
                <posts>
                    <post>
                        <body> Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. </body>
                        <topics>
                            <topic> economy </topic>
                            <topic> finance </topic>
                        </topics>
                    </post>
                    <post>
                        <body> Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. </body>
                        <topics>
                            <topic> solar_energy </topic>
                        </topics>
                    </post>
                </posts>
                <followers>
                    <follower>
                        <id>2</id>
                    </follower>
                    <follower>
                        <id>3</id>
                    </follower>
                </followers>
            </user>
            <user>
                <id>2</id>
                <name>Yasser Ahmed</name>
                <posts>
                    <post>
                        <body> Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. </body>
                        <topics>
                            <topic> education </topic>
                        </topics>
                    </post>
                </posts>
                <followers>
                    <follower>
                        <id>1</id>
                    </follower>
                </followers>
            </user>
            <user>
                <id>3</id>
                <name>Mohamed Sherif</name>
                <posts>
                    <post>
                        <body> Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. </body>
                        <topics>
                            <topic> sports </topic>
                        </topics>
                    </post>
                </posts>
                <followers>
                    <follower>
                        <id>1</id>
                    </follower>
                </followers>
            </user>
        </users>
    )";

    Graph SN = buildGraph(xmlData);

    vector<int> follwers1 = SN.getFollower(1);
    cout << "User1 Followers: " << endl;
    for(int i = 0; i < follwers1.size(); i++){
        cout << "User" << follwers1[i] << endl;
    }

}