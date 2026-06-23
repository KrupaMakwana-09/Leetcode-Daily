class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;

        // applying binary search on row first
        int lowr = 0, highr = m-1;
        while(lowr<highr){
            int midr = lowr + ((highr-lowr)/2);
            if(matrix[midr][0] == target) return true;
            else if(matrix[midr][0]<target && matrix[midr][n-1]>=target){
                lowr = midr;
                // found the row
                break;
            }
            else if(matrix[midr][0]<target) lowr = midr+1;
            else highr = midr-1;
        }

        // correct row is lowr
        // search in rowr
        // apply binsearch on columns
        int lowc = 0, highc = n-1;
        while(lowc<=highc){
            int midc = lowc + ((highc-lowc)/2);
            if(matrix[lowr][midc] == target) return true;
            else if(matrix[lowr][midc]>target) highc = midc-1;
            else lowc = midc+1;
        }
        return false;
    }
}