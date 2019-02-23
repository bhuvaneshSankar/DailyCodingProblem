public class MatrixProdExcep{
    public static void printProd(int[] arr, int length){
        int[] leftArr = new int[length-1];
        int[] rightArr = new int[length-1];
        leftArr[0] = arr[0];
        rightArr[0] = arr[length-1];
        int i;
        int leftMul=leftArr[0];
        int rightMul = rightArr[0];
        for(i=1; i<length-1; i++){
            leftArr[i] = leftMul * arr[i];
            leftMul = leftArr[i];
            rightArr[i] = rightMul * arr[length-1-i];
            rightMul = rightArr[i];
        }
     //   printArr(leftArr, length-1);
     //   printArr(rightArr, length-1);
        for(i=0; i<length; i++){
            if(i==0)
                System.out.print(rightArr[length-2]+" ");
            else if(i==length-1)
                System.out.print(leftArr[length-2]+" ");
            else 
                System.out.print(leftArr[i-1] * rightArr[length-2-i]+" ");
        }
        
    }
    public static void printArr(int[] arr, int length){
        System.out.println();
        for(int i=0; i<length; i++)
            System.out.print(arr[i]+" ");
    }
    public static void main(String[] args){
        int[] arr = {1,2,3,4,5};
        printProd(arr, arr.length);
    }
}