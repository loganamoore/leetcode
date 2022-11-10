// O(n)
class Solution {
public:
    int calPoints(vector<string>& operations) {
        // stack to hold scores
        std::stack<int> s;
        
        // iterate through each of the operations
        for(int i = 0; i < operations.size(); i++){
            string op = operations[i];
            
            // handle the operation
            if(op == "+"){
                int t = s.top();
                s.pop();
                int n = t + s.top();
                s.push(t);
                s.push(n);
            }
            else if(op == "D")
                s.push(s.top() * 2);
            else if(op == "C")
                s.pop();
            else
                s.push(std::stoi(op));  // score
        }
        
        int total = 0;
        // sum up the scores in the stack
        while(s.size()){
            total += s.top();
            s.pop();
        }
        
        // return the total
        return total;
        
    }
};