#include<bits/stdc++.h> 
using namespace std; 

class Solution
{   
private:
    int N, target;
    vector<int> arr, subset;
    unordered_set<string> ans;

    void addSolution()
    {
        vector<int> temp(subset);
        sort(temp.begin(), temp.end());
        string solution = "[ ";
        for(int i = 0; i < temp.size()-1; i++) {
            solution += to_string(temp[i]) + ", ";
        }
        solution += to_string(temp[temp.size()-1]) + " ]";

        if(ans.find(solution) == ans.end())
        {
            ans.insert(solution);
            noOfSolution++;
        }
    }

public:
    int noOfSolution = 0;
    void takeInput()
    {
        cout << "Enter the number of elements in the array: ";
        cin >> N;
        arr.resize(N);
        cout << "Enter the elements of the array: ";
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cout << "Enter the target sum: ";
        cin >> target;
    }

    void printSolution()
    {
        cout << "Solutions: " << endl;
        for(auto it : ans)
        {
            cout << it << endl;
        }
    }

    void isSubsetSum(int sum=0, int i=0)
    {
        // if target is zero then there exist a subset.
        if(target == sum) 
        {
            addSolution();
        }
    
        // return if we have reached at the end of the array
        if(i == N) 
        {
            return;
        }
    
        // Not considering current element
        isSubsetSum(sum, i+1);
    
        // consider current element if it is less than or equal to target
        if(sum + arr[i] <= target) 
        {
            // push the current element in subset
            subset.push_back(arr[i]);
    
            // Recursive call for consider current element
            isSubsetSum(sum + arr[i], i+1);
    
            // pop-back element after recursive call to restore subsets original configuration
            subset.pop_back();
        }
    }
    
};

int main() 
{ 
    Solution ob;
    ob.takeInput();
    ob.isSubsetSum();
    
    if(!ob.noOfSolution)
        cout << "No subset found with the given sum.";
    else 
        ob.printSolution();
    return 0; 
}
