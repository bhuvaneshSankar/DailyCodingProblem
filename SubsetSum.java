public class SubsetSum{     //{1,5,11,5} sum of {5,5,1} == {11}
    boolean isSubsetsEqual=false;
    void generateSubSeq(int[] arr, int index, int n, int[] tempArr){ //generating all the subsets
        if(!isSubsetsEqual){
        if(index==n){
            printArr(arr, tempArr, n);
            if(checkEqualSubsets(arr, tempArr, n)){
                isSubsetsEqual=true;
            }
        }
        else{
            tempArr[index]=1;
            generateSubSeq(arr, index+1, n, tempArr);
            tempArr[index]=0;           //backtrack and generate subarrays (an index can be either selected or not selected 0=>not selected, 1=>selected)
            generateSubSeq(arr, index+1, n, tempArr);
        }
        }
    }
    void printArr(int[] arr, int[] tempArr, int n){
        
        for(int i=0; i<n; i++){
            if(tempArr[i]==1){
                System.out.print(arr[i]+" ");
            }
        }
        System.out.println();
    }
    boolean checkEqualSubsets(int arr[], int tempArr[], int  n){   //calc sum of the subset and sum of the elements not in the subset and check for their equality
        int s1=0, s2=0;
        for(int i=0; i<n; i++){
            if(tempArr[i]==0){
                s1+=arr[i];
            }
            else{
                s2+=arr[i];
            }
        }
        if(s1==s2)
            return true;
        else
            return false;
    }
    public boolean dynamicApproach(int[] arr, int n){       //idea is: if the entire sum of the array can be formed by two subsets then YES else NO
        int sum=0, i;
        for(i=0; i<n; i++){
            sum += arr[i];
        }
        if(sum%2!=0)                    // if the sum is odd then false as a+b is always even and we cant get oddsum unless a,b are decimal(e.g. sum=9, a=5.5, b=3.5 where if sum=8, a=5, b=3 => true)
            return false;
        sum = sum/2;                       //as sum = sum1 + sum2 (sum1 = sum/2 and sum2 = sum/2) so checking whether sum/2 satisfies is enough
        boolean[][] flagArr = new boolean[n][sum];
        int arrSum=0;                   
        for(i=0; i<n; i++){
            arrSum += arr[i];               // sum of the elements in the subset upto ith index
            for(int j=0; j<sum; j++){
                if(j+1==arr[i])             //j+1 indicates the sum as array indexing starts from 0
                    flagArr[i][j]=true;
                else if(j+1>arrSum)         //if the sum is above than the sum of all the included indices in array simply we cant get the sum by adding them all too
                    flagArr[i][j]=false;
                else if(i>0 && j+1<arr[i])  //if the sum(j+1) is less than current arr[i] we check whether the sum can be formed by previous subset by excluding the current element
                    flagArr[i][j]=flagArr[i-1][j];
                else{
                    if(i>0 && flagArr[i-1][j]==true)    //simply if we can get the sum by previous subset itself without including the current elem then we can get by including the current also
                        flagArr[i][j] = true;
                    else if(i>0 && flagArr[i-1][(j+1)-arr[i]-1]==true)  //if we can get sum(j+1) - arr[i] on the previous subset then eventually we can get the sum by adding current element
                        flagArr[i][j] = true;
                    else
                        flagArr[i][j] = false;
                }
            }
        }
        for(i=0; i<n; i++){
            for(int j=0; j<sum; j++){
                System.out.print(flagArr[i][j]+" ");
            }
            System.out.println();
        }   
        return flagArr[n-1][sum-1];

    }
    public static void main(String[] args){
        SubsetSum obj = new SubsetSum();
        int[] arr= new int[]{1, 3, 5};
        int n = arr.length;
        int[] tempArr = new int[n];
        for(int i=0; i<n; i++)
            tempArr[i]=0;
        obj.generateSubSeq(arr, 0, n, tempArr);
    /*    if(obj.isSubsetsEqual==true){
            System.out.println("equal");
        }
        else{
            System.out.println("not equal");
        }  */
        if(obj.dynamicApproach(arr, n)==true)
            System.out.println("YES");
        else 
            System.out.println("NO");
    }
}