#include<iostream>
#include<fstream>
using namespace std;

class Dijkstra {
   public:
      int numNodes;
      int sourceNode;
      int minNode;
      int currentNode;
      int newCost;
      int** costMatrix;
      int* fatherArray;
      int* markedArray;
      int* bestCostArray;

   	 Dijkstra(int amntOfNodes) {
   	 	numNodes = amntOfNodes;
   	 	costMatrix = new int*[19];
      fatherArray = new int[amntOfNodes];
      bestCostArray = new int[amntOfNodes];
      markedArray   = new int[amntOfNodes];
   	 	for(int i = 0; i < 19; ++i)
   	 		costMatrix[i] = new int[19]();
   	 	sourceNode = 1;

   	 	for(int i = 0; i < amntOfNodes; ++i) {
   	 		bestCostArray[i] = 9999;
   	 		markedArray[i] = 0;
   	 		fatherArray[i] = i;
   	 	}
   	 }

      void loadCostMatrix(ifstream& readFromFile) {
        int rowValue, colValue, costValue;
        while(readFromFile >> rowValue >> colValue >> costValue) {
            costMatrix[rowValue][colValue] = costValue;
        }
        
        cout << endl;
        loadBestCostArray(1);
        debugPrint();
      }

      void debugPrint() {
        cout << "This is CostMatrix " << endl;
      	for(int row = 0; row < 19; ++row) {
      		for(int col = 0; col < 19; ++col) {
      			if(costMatrix[row][col] != 0) 
      				cout << row << " " << col << " " << costMatrix[row][col] << endl;
      		}
      	}
        cout << "This is bestCostArray" << endl;
        for(int k = 0; k < numNodes; k++) 
          cout << bestCostArray[k] << "  ";
        cout << endl;
        
        cout << "This is fatherArray" << endl; 
        for(int k = 0; k < numNodes; k++) 
          cout << fatherArray[k] << "  ";
        cout << endl;

        cout << "This is markedArray" << endl;
        for(int k = 0; k < numNodes; k++) 
          cout << markedArray[k] << "  ";
        cout << endl;

      }

      //how to load the best cost matrix
        //find all the nodes that a node connects to 
        //load the value into the array 

      void loadBestCostArray(int src) {
        int counter = 0;
        for(int i = 0; i < 19; i++) {
          for(int j = 0; j < 19; j++) {
            if(src == i) {
              bestCostArray[counter++] = costMatrix[i][j];
              cout << costMatrix[i][j] << endl;
            }  
          }
        } 
      }    	
};

int main (int argc, char** argv) {
	ifstream readAmntOfNodes(argv[1]);
	//ofstream outputDataToFile(argv[2]);
    
    int numberOfNodes = 0;
    readAmntOfNodes >> numberOfNodes;
    Dijkstra Dobject(numberOfNodes);
    Dobject.loadCostMatrix(readAmntOfNodes);

} 