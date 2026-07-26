class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i=0;
        int j=citations.size()-1;
        int mid=i+(j-i)/2;
        int answer=0;
        while(i<=j){
            mid=i+(j-i)/2;
            if (citations[mid]>=citations.size()-mid){
                answer =citations.size()-mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return answer;
    }
};