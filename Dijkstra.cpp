#include<iostream>
#include<fstream>
using namespace std;

class Dijkstra {
   private:
      int numNodes;
      int sourceNode;
      int minNode;
      int currentNode;
      int newCost;
      int** costMatrix;
      int* fatherArray;
      int* markedArray;
      int* bestCostArray;

   public:

   	 Dijkstra(int amntOfNodes) {
   	 	numNodes = amntOfNodes;
   	 	costMatrix = new int*[19];
   	 	for(int i = 0; i < 19; ++i)
   	 		costMatrix[i] = new int[19]();
   	 	bestCostArray = new int[amntOfNodes];
   	 	markedArray   = new int[amntOfNodes];
   	 	bestCostArray = new int[amntOfNodes];
   	 	sourceNode = 1;

   	 	for(int i = 0; i < amntOfNodes; ++i) {
   	 		bestCostArray[i] = 9999;
   	 		markedArray[i] = 0;
   	 		bestCostArray[i] = i;
   	 	}
   	 }

      void loadCostMatrix(ifstream& readFromFile) {
        int rowValue, colValue, costValue;
        while(readFromFile >> rowValue >> colValue >> costValue) {
            costMatrix[rowValue][colValue] = costValue;
        }
        debugPrint();
      }

      void debugPrint() {
      	for(int row = 0; row < 19; ++row) {
      		for(int col = 0; col < 19; ++col) {
      			if(costMatrix[row][col] != 0) 
      				cout << row << " " << col << " " << costMatrix[row][col] << endl;
      		}
      	}
      }

      void loadBestCostArray(int srcNode) {
        //how to load the best cost matrix
        //find all the nodes that a node connects to 
        //load the value into the array 
      	
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