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
};

int main (int argc, char** argv) {
	ifstream readAmntOfNodes(argv[1]);
	//ofstream outputDataToFile(argv[2]);
    
    int numberOfNodes = 0;
    readAmntOfNodes >> numberOfNodes;
    Dijkstra Dobject(numberOfNodes);
    Dobject.loadCostMatrix(readAmntOfNodes);

} 