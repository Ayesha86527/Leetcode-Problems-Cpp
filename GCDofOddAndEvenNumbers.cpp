class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd=0;
        int sumEven=0;

        int OddC=0;
        int EvenC=0;
        
        int i = 1;

        while (OddC < n || EvenC < n){
            if (i%2==0 && EvenC < n){
                sumEven+=i;
                EvenC++;
            }
            else if (i%2!=0 && OddC < n){
                sumOdd+=i;
                OddC++;
            }
            i++;
        }
        
        if (sumOdd==0){
            return sumEven;
        }

        if (sumEven==0){
            return sumOdd;
        }

        while (sumEven!=sumOdd){
            if (sumEven>sumOdd){
                sumEven=sumEven-sumOdd;
            }
            else{
                sumOdd=sumOdd-sumEven;
            }
        }
        return sumEven;
    }
};