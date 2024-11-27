/*
 * Author: Armaan Hajar and Suhas Makineni
 * Program: A graph creator program that uses Dijkstra's algorithm to find the shortest path between nodes.
 * Date: November 7, 2024
 */

#include <iostream>
#include <cstring>

struct Node{
    char* name;
    Node(char* newName) {
        name = newName;
    }
};

void addNode(Node** nodeList, int adjMatrix[21][21]);
void remNode(Node** nodeList, int adjMatrix[21][21]);
void addEdge(Node** nodeList, int adjMatrix[21][21]);
void remEdge(Node** nodeList, int adjMatrix[21][21]);
void printAdjMatrix(int adjMatrix[21][21]);
void findShortestPath(Node** nodeList, int adjMatrix[21][21]);

using namespace std;

int main() {
    int input;
    bool running = true;

    Node** nodeList = new Node*[21];
    int adjMatrix[21][21];
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    while (running == true) { // loops until user quits the program
        cout << "-------------------------------------------" << endl;
        cout << "What Would You Like To Do? (Type a Number):" << endl;
        cout << "1. Add Node" << endl;
        cout << "2. Add Edge" << endl;
        cout << "3. Remove Node" << endl;
        cout << "4. Remove Edge" << endl;
        cout << "5. Find Shortest Path" << endl;

        cin >> input;
        cin.ignore(1, '\n');
        cout << "-------------------------------------------" << endl;

        if (input == 1) { // add node
            addNode(nodeList, adjMatrix);
        }
        else if (input == 2) { // add edge
            addEdge(nodeList, adjMatrix);
        }
        else if (input == 3) { // remove node
            remNode(nodeList, adjMatrix);
        }
        else if (input == 4) { // remove edge
            remEdge(nodeList, adjMatrix);
        }
        else if (input == 5) { // find shortest path
            findShortestPath(nodeList, adjMatrix);
        }
        else if (input == 6) { // debugging, prints adjacency matrix
            printAdjMatrix(adjMatrix);
        }
        else {
            cout << "Sorry, Please Try Again" << endl;

        }
    }
}

void addNode(Node** nodeList, int adjMatrix[21][21]) { // adds a node to the graph
    char* name = new char[4];
    cout << "What Is The Name of the Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name, 4);
    cin.ignore(1, '\n');

    for (int i = 0; i < 21; i++) { // finds the first empty spot in the array and adds the node there
        if (nodeList[i] == NULL) {
            nodeList[i] = new Node(name);
            break;
        }
    }
}

void remNode(Node** nodeList, int adjMatrix[21][21]) { // removes a node from the graph
    char* name = new char[4];
    cout << "What Is The Name of the Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name, 4);
    cin.ignore(1, '\n');

    int index = -1;
    for (int i = 0; i < 21; i++) { // finds the node in the array and deletes it
        if (strcmp(nodeList[i]->name, name) == 0) {
            delete(nodeList[i]);
            nodeList[i] = NULL;
            index = i;
            break;
        }
    }

    for (int i = 0; i < 21; i++) { // removes all edges connected to the node
        adjMatrix[i][index] = 0;
        adjMatrix[index][i] = 0;
  }
}

void addEdge(Node** nodeList, int adjMatrix[21][21]) { // adds an edge to the graph
    char* name1 = new char[4];
    char* name2 = new char[4];
    int edgeWeight;
    cout << "What Is The Name of the First Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name1, 4);
    cin.ignore(1, '\n');
    cout << "What Is The Name of the Second Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name2, 4);
    cin.ignore(1, '\n');
    cout << "What Is The Weight of the Edge?" << endl;
    cin >> edgeWeight;
    cin.ignore(1, '\n');

    int index1 = 398121;
    int index2 = 398121;
    for (int i = 0; i < 21; i++) { // finds the index of the two nodes
        if (nodeList[i] != NULL) {
            if (strcmp(nodeList[i]->name, name1) == 0) {
                index1 = i;
            }
            else if (strcmp(nodeList[i]->name, name2) == 0) {
                index2 = i;
            }
        }
    }

    if (index1 != 398121 && index2 != 398121) { // adds edge weight to the edge
        adjMatrix[index1][index2] = edgeWeight;
        adjMatrix[index2][index1] = edgeWeight;
    }
    else {
        cout << "Sorry, Please Try Again" << endl;
    }
}

void remEdge(Node** nodeList, int adjMatrix[21][21]) { // removes an edge from the graph
    char* name1 = new char[4];
    char* name2 = new char[4];
    cout << "What Is The Name of the First Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name1, 4);
    cin.ignore(1, '\n');
    cout << "What Is The Name of the Second Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name2, 4);
    cin.ignore(1, '\n');

    int index1 = 398121;
    int index2 = 398121;
    for (int i = 0; i < 21; i++) { // finds the index of the two nodes
        if (nodeList[i] != NULL) {
            if (strcmp(nodeList[i]->name, name1) == 0) {
                index1 = i;
            }
            else if (strcmp(nodeList[i]->name, name2) == 0) {
                index2 = i;
            }
        }
    }

    if (index1 != 398121 && index2 != 398121) { // removes the edge weight from the edge
        adjMatrix[index1][index2] = 0;
        adjMatrix[index2][index1] = 0;
    }
    else {
        cout << "Sorry, Please Try Again" << endl;
    }
}

void printAdjMatrix(int adjMatrix[21][21]) { // prints the adjacency matrix
    cout << "   ";
    for (int i = 0; i < 21; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < 21; i++) {
        if (i < 10) {
            cout << i << "  ";
        }
        else {
            cout << i << " ";
        }
        for (int j = 0; j < 21; j++) {
            if (j < 9) {
                cout << adjMatrix[i][j] << " ";
            }
            else {
                cout << adjMatrix[i][j] << "  ";
            }
        }
        cout << endl;
    }
}

void findShortestPath(Node** nodeList, int adjMatrix[21][21]) { // finds the shortest path between two nodes using Dijkstra's Algorithm
    char* name1 = new char[4];
    char* name2 = new char[4];
    cout << "What Is The Name of the Starting Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name1, 4);
    cin.ignore(1, '\n');
    cout << "What Is The Name of the Ending Node? (ie. A, B, AB, AC)" << endl;
    cin.get(name2, 4);
    cin.ignore(1, '\n');

    int index1 = 398121;
    int index2 = 398121;
    for (int i = 0; i < 21; i++) { // finds the index of the two nodes
        if (nodeList[i] != NULL) {
            if (strcmp(nodeList[i]->name, name1) == 0) {
                index1 = i;
            }
            else if (strcmp(nodeList[i]->name, name2) == 0) {
                index2 = i;
            }
        }
    }

    if (index1 != 398121 && index2 != 398121) { // Dijkstra Algorithm
        int dist[21];
        bool visited[21];
        int prev[21];
        for (int i = 0; i < 21; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
            prev[i] = -1;
        }
        dist[index1] = 0;

        for (int i = 0; i < 21; i++) { // finds the shortest path
            int min = INT_MAX;
            int minIndex = -1;
            for (int j = 0; j < 21; j++) { // finds the next node to visit
                if (visited[j] == false && dist[j] <= min) {
                    min = dist[j];
                    minIndex = j;
                }
            }
            visited[minIndex] = true;
            for (int j = 0; j < 21; j++) { // updates the distance of the nodes
                if (visited[j] == false && adjMatrix[minIndex][j] != 0 && dist[minIndex] != INT_MAX && dist[minIndex] + adjMatrix[minIndex][j] < dist[j]) {
                    dist[j] = dist[minIndex] + adjMatrix[minIndex][j];
                    prev[j] = minIndex;
                }
            }
        }

        cout << "The Shortest Path From " << name1 << " to " << name2 << " is: " << dist[index2] << endl;
        cout << "The Path is: ";
        int path[21];
        int pathIndex = 0;
        int curr = index2;
        while (curr != -1) { // finds the path
            path[pathIndex] = curr;
            pathIndex++;
            curr = prev[curr];
        }
        for (int i = pathIndex - 1; i >= 0; i--) { // prints the path
            cout << nodeList[path[i]]->name << " ";
        }
        cout << endl;
    }
    else {
        cout << "Sorry, Please Try Again" << endl;
    }
}
