class Solution {
public:
    string getHint(string secret, string guess) {// TC : O(N) & SC : O(1)

        int n = secret.size();// N
        
        int bulls = 0;
        int cows = 0;

        vector<int>secretCount(10,0);// SC : O(10) = O(1)
        vector<int>guessCount(10,0);// SC : O(10) = O(1)

        for(int i=0;i<n;i++){// TC : O(N)

            if(secret[i] == guess[i]){
                bulls++;
            }else{
                secretCount[secret[i]-'0']++;
                guessCount[guess[i]-'0']++;
            }
        }

        for(int i=0;i<10;i++){// TC : O(10) = O(1)

            if(secretCount[i] > 0 && guessCount[i] > 0){
                cows += min(secretCount[i],guessCount[i]);
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";// TC : O(4) = O(1)

        // TC : for to_string(x) is O(no. of digits in x) = O(log(x))
    }
};