class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        //approach socho 

        //if there are odd no. of negative no then the matrix can be converted to a matrix
        //where only the smallest absoluute value will have the negative sign so as to maximize sum

        //if there anre even no. of elements then the matrix can be converted to a matrix 
        //where no element has negative sign all no. are positive

        //try some examples to think about this how it is working

        int count=0;//store the no. of negative integers
        int absolutesmallest=INT_MAX;; //stored the smallest absolute value

        //find the sum of all elements of matrix considering all positive
        long long sum=0;

        for(vector<int> v: matrix){
            for(int i: v){

                if(i<0) count++;
                
                absolutesmallest=min(absolutesmallest, abs(i));

                if(i<0) sum-=i;
                else    sum+=i;
            }
        }

        //if count even return sum as it as answer
        if(count%2==0)  return sum;

        //if count odd then minus the smallest element twice from the sum 
        //as it is added in the sum whereas it should be subtracted

        return sum-2*absolutesmallest;
    }
};