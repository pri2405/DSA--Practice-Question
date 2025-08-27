// Leetcode q no. - 2073 (Time Needed to Buy Tickets)

// 1st Approach
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {     // T.C. - O(n^2)  & S.C. - O(1)
        int n = tickets.size();
        int time=0;
    
        if(tickets[k]==1) return k+1;

        while(tickets[k] > 0){
            for(int i=0; i<n; i++){
                if(tickets[i] == 0) continue;
                tickets[i] = tickets[i] - 1;
                time++;
                if(tickets[k] == 0) break;
            }
        }
        return time;
    }
};

// 2nd Approach - without using extra space
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {         // T.C. - O(n) & S.C. - O(1)
        int n = tickets.size();
        int time = 0;
        
        for(int i = 0; i < n; i++) {
            if(i <= k)
                time += min(tickets[k], tickets[i]);
            else
                time += min(tickets[k] - 1, tickets[i]);
        }

        return time;
    }
};

// 2nd Approach    -    using queue
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {       // T.C. - O(n * max(tickets)) & S.C. - O(n)
        int n = tickets.size();
        queue<int> q;
        for(int i = 0; i < n; i++) {
            q.push(i);
        }

        int time = 0;

        while(tickets[k] > 0) {
            int person = q.front();
            q.pop();

            tickets[person]--;

            if(tickets[person] > 0) q.push(person);

            time++;
        }

        return time;
    }
};