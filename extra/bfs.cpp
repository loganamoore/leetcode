#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

// Always look for target "Taco"
bool isTarget(string& name){
	return (name == "Taco");
}

int main(){

	/* == Creating a graph with a hashmap: == */

	// A simple graph to traverse.
	map<string, vector<string> > neighbors;

	// 1st level connections
	vector<string> me = { "Anna", "Abby", "Alex", "Aaron" };
	neighbors.insert(pair<string, vector<string> >("Me", me));

	// 2nd level connections
	vector<string> anna = {"Betty", "Beatrix", "Benjamin", "Bobby"};
	neighbors.insert(pair<string, vector<string> >("Anna", anna));
	vector<string> abby = {"Benson", "Billy", "Brian", "Berry"};
	neighbors.insert(pair<string, vector<string> >("Abby", abby));
	vector<string> alex = {"Bert", "Brandon", "Becky", "Bishop"};
	neighbors.insert(pair<string, vector<string> >("Alex", alex));
	vector<string> aaron = {"Betty", "Beatrix", "Blackie", "Bramble"};
	neighbors.insert(pair<string, vector<string> >("Aaron", aaron));

	// 3rd level connections
	vector<string> betty = {"Carl", "Curtis", "Catherine", "Carson"};
	neighbors.insert(pair<string, vector<string> >("Betty", betty));
	vector<string> billy = {"Canton", "Capital", "Corridor", "Credit"};
	neighbors.insert(pair<string, vector<string> >("Billy", billy));
	vector<string> becky = {"Cleveland", "Chicago", "Carolina", "Conneticut"};
	neighbors.insert(pair<string, vector<string> >("Becky", becky));
	vector<string> bramble = {"Crest", "Curve", "Taco", "Crumpet"};
	neighbors.insert(pair<string, vector<string> >("Bramble", bramble));

	/* == Breadth-First Search: == */

	// Keep a list of all visited nodes.
	map<string, char> visited;
	visited.insert(pair<string, char>("Me", '*'));

	// The list of nodes to check.
	queue<string> check;
	check.push("Me");

	int length = 0;

	while(check.size()){
		// Iterate through all nodes in this layer of the queue.
		int s = check.size();
		for(int i = 0; i < s; i++){
			string c = check.front();
			check.pop();

			// Check if this is the target.
			if(isTarget(c)){
				cout << "It took " << length << " steps." << endl;
				return 0;
			}

			// Iterate through all this node's neighbors
			for(int j = 0; j < neighbors[c].size(); j++){
				// Add them to the queue if they haven't been visited.
				if(visited.find(neighbors[c][j]) == visited.end()){
					check.push(neighbors[c][j]);
					visited.insert(pair<string, char>(neighbors[c][j], '*'));
				}
			}
		}	

		// Iterated through an entire level, add to the length.
		length++;
	}

	cout << "A path could not be found!" << endl;
	return 1;
}

