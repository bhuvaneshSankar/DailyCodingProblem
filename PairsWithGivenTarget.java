public class PairsWithGivenTarget{
    public void mergeSort(int[] arr, int start, int end){
        if(start<end){
            int mid = (start+end)/2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid+1, end);
            merge(arr, start, mid, end);
        }
    }
    public void merge(int[] arr, int start, int mid, int end){
        int i, j,k=start, n1, n2;
        n1 = mid-start+1;
        n2 = end-mid;
        int[] a1 = new int[n1];
        int[] a2 = new int[n2];
        for(i=0; i<n1; i++)
            a1[i]=arr[i+start];
        for(j=0; j<n2; j++)
            a2[j]=arr[j+1+mid];
        i=0;
        j=0;
        while(i<n1 && j<n2){
            if(a1[i]<=a2[j])
                arr[k++] = a1[i++];
            else
                arr[k++] = a2[j++];
        }
        while(i<n1)
            arr[k++] = a1[i++];
        while(j<n2)
            arr[k++] = a2[j++];
    }
    public void  printArr(int[] arr, int length){
        for(int i=0; i<length; i++)
            System.out.print(arr[i]+" ");
    }
    public void findPairsMatrix(int[] arr, int target){
        int length = arr.length;
        mergeSort(arr, 0, length-1);
        printArr(arr, length);
        int i=0, j= length-1;
        for(i=0, j=length-1; i<j;){
            int sum = arr[i]+arr[j];
            if(sum<target){
                i++;
            }
            else if(sum==target){
                System.out.println("pair = "+arr[i]+" "+arr[j]);
                i++;
                j--;
            }
            else if(sum>target){
                j--;
            }
        }
    }
    public void findPairsHashing(int[] arr, int target){  //o(n) using hashing
        int max = 1000000;
        boolean[] flagArr = new boolean[max];
        int i;
        for(i=0; i<max; i++)
            flagArr[i] = false;
        for(i=0; i<arr.length; i++){
            int temp = target-arr[i];
            if(temp>=0 && flagArr[temp]==true)
                System.out.println("pair = "+arr[i]+" "+temp);
            flagArr[arr[i]] = true;
        }
    }
    public static void main(String[] args){
        int[] arr= {1,4,45,6,10,8, 15};
        int target = 16;
        PairsWithGivenTarget object = new PairsWithGivenTarget();
        object.findPairsMatrix(arr, target);
    }
}