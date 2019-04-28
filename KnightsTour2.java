public class KnightsTour2{
    int n=8;
    boolean isSafe(boolean[][] flagArr, int x, int y){
        if(flagArr[x][y]==true)
            return false;
        else
            return true;
    }
    boolean computeTour(boolean[][] flagArr, int[][] board, int x, int y, int count){
        
        flagArr[x][y] = true;
        if(count==n*n){
            board[x][y]=count;
        //    System.out.println(x+" "+y);
            return true;
        }
        else{
            if(x-2>=0 && y+1< n && isSafe(flagArr, x-2, y+1)==true){
                if(computeTour(flagArr, board, x-2, y+1, count+1)==true){
                //    System.out.println(x+" "+y);
                    board[x][y]=count;
                    return true;
                }
            }
            if(x-2>=0 && y-1>=0 && isSafe(flagArr, x-2, y-1)==true){
                if(computeTour(flagArr, board, x-2, y-1, count+1)==true){
                //    System.out.println(x+" "+y);
                    board[x][y]=count;
                    return true;
                }
            }
            if(x-1>=0 && y+2<n && isSafe(flagArr, x-1, y+2)==true){
                if(computeTour(flagArr, board, x-1, y+2, count+1)==true){
                //    System.out.println(x+" "+y);
                    board[x][y]=count;
                    return true;
                }
            }
            if(x-1>=0 && y-2>=0 && isSafe(flagArr, x-1, y-2)==true){
              
                if(computeTour(flagArr, board, x-1, y-2, count+1)==true){
                //    System.out.println(x+" "+y);
                    board[x][y]=count;
                    return true;
                }
            }
            if(x+1<n && y+2< n && isSafe(flagArr, x+1, y+2)==true){
            
                if(computeTour(flagArr, board, x+1, y+2, count+1)==true){
                //    System.out.println(x+" "+y);
                    board[x][y]=count;
                    return true;
                }
            }
            if(x+1<n && y-2>=0 && isSafe(flagArr, x+1, y-2)==true){
           
                if(computeTour(flagArr, board, x+1, y-2, count+1)==true){
                //    System.out.println(x+" "+y);
                    board[x][y]=count;
                    return true;
                }
            }
            if(x+2<n && y+1<n && isSafe(flagArr, x+2, y+1)==true){
           
                if(computeTour(flagArr, board, x+2, y+1, count+1)==true){
                //    System.out.println(x+" "+y);
                    board[x][y]=count;
                    return true;
                }
            }
            if(x+2<n && y-1>=0 && isSafe(flagArr, x+2, y-1)==true){
           
                if(computeTour(flagArr, board, x+2, y-1, count+1)==true){
                //    System.out.println(x+" "+y);
                    board[x][y]=count;
                    return true;
                }
            }
            flagArr[x][y]=false;
        }
        return false;
    }
    void printArr(int[][] arr){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args){
        KnightsTour2 obj = new KnightsTour2();
        boolean[][] flagArr = new boolean[obj.n][obj.n];
        int[][] board = new int[obj.n][obj.n];
        int count=1;
        for(int i=0; i<obj.n; i++){
            for(int j=0; j<obj.n; j++){
                flagArr[i][j] = false;
                board[i][j] = -1;
            }
        }
        if(obj.computeTour(flagArr, board, 0, 0, count)==true){
            System.out.println("YES");
            obj.printArr(board);
        }
        else{
            System.out.println("NO");
        }
    }
}