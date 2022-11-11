#include <map>
#include <queue>
#include <algorithm>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Verify endWord is in wordList
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        
        // Add the beginning word to the list
        wordList.push_back(beginWord);
        
        // Create a graph linking single transform words together via a hashmap
        map<string, vector<string>> graph;
        for(int i = 0; i < wordList.size(); i++){
            string word = wordList[i];
            
            // Replace every character in the word with *, one by one to create a pattern
            for(int j = 0; j < word.size(); j++){
                string p = word;
                p[j] = '*';
        
                // Map this word to this newly created pattern
                if(graph.find(p) != graph.end())
                    graph[p].push_back(word);
                else
                    graph.insert(pair<string, vector<string>>(p, { word }));
            }
            
        }
        
        // Create a list of words already checked and add beginWord
        map<string, char> visited;
        visited.insert(pair<string, char>(beginWord, '*'));
        
        // Create a queue of words to check and add beginWord
        queue<string> check;
        check.push(beginWord);
            
        // How many levels it takes to reach endWord in the graph
        int length = 1;
        while(check.size()){
            
            // Iterate over and pop all the words in this level
            int s = check.size();
            for(int i = 0; i < s; i++){
                string word = check.front();
                check.pop();
                
                // Check if this word is the endWord
                if(word == endWord)
                    return length;
                
                // Generate a pattern for this word
                for(int j = 0; j < word.size(); j++){
                    string p = word;
                    p[j] = '*';
                    
                    // Iterate over all the words mapped to this pattern
                    for(int k = 0; k < graph[p].size(); k++){
                        // Add the mapped word to be checked if it hasn't already been visited.
                        if(visited.find(graph[p][k]) == visited.end()){
                            check.push(graph[p][k]);
                            visited.insert(pair<string, char>(graph[p][k], '*'));
                        }
                    }
                }
            }
            
            // A whole level has been checked, increment the length
            length++;
        }
        
        return 0;
    }
};