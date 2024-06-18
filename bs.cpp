
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,vector<int>& worker) {
        int len = difficulty.size(); // Length of the difficulty and profit vectors, assuming both are the same size
        
        // Create a pair vector to combine difficulty and profit
        vector<pair<int, int>> dp;
        for (int i = 0; i < len; i++) {
            dp.push_back({difficulty[i], profit[i]});
        }
        
        // Sort the dp vector based on difficulty
        sort(dp.begin(), dp.end());
        
        // Pre-process to find the maximum profit up to each index
        for (int i = 1; i < dp.size(); i++) {
            dp[i].second = max(dp[i].second, dp[i - 1].second);
        }
        
        int total_profit = 0; // Initialize total profit
        
        // Iterate over each worker
        for (int i = 0; i < worker.size(); i++) {
            int ability = worker[i];
            int low = 0;
            int high = dp.size() - 1;
            int max_profit = 0;
            
            // Perform binary search
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (dp[mid].first <= ability) {
                    max_profit = max(max_profit, dp[mid].second);
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            // Add the maximum profit found for the current worker to the total profit
            total_profit += max_profit;
        }
        
        return total_profit; // Return the total profit
    }
};
