class NumMatrix {
    private int[][] rangeSum;
    private int rows;
    private int cols;
    public NumMatrix(int[][] matrix) {
        this.rows = matrix.length;
        this.cols = matrix[0].length;
        
        rangeSum = new int[rows+1][cols+1];
        
        calculateRangeSum(rangeSum,matrix);
        
    }
    public void calculateRangeSum(int[][] rangeSum , int[][] matrix){
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                rangeSum[i+1][j+1] = rangeSum[i+1][j] + rangeSum[i][j+1] - rangeSum[i][j] + matrix[i][j];
            }
        }
        
        for(int i = 0;i<=rows;i++){
            for(int j = 0;j<=cols;j++){
                System.out.print(rangeSum[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
       int x = rangeSum[row2 + 1][col2 + 1];
        int y = rangeSum[row1][col1];
        int w = rangeSum[row1][col2 + 1];
        int z = rangeSum[row2 + 1][col1];
        
        return x - w - z + y;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */