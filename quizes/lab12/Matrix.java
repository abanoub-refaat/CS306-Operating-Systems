package quizes.lab12;

import java.util.concurrent.*;

public class Matrix {
    private static int sum = 0;
    private static final int[][] mat = new int[4][4];
    private static final Semaphore semaphore = new Semaphore(2);

    public static int getSum() {
        return sum;
    }

    public static void main(String[] args) {
        initialize();

        ExecutorService executor = Executors.newFixedThreadPool(4);

        for (int i = 0; i < 4; i++) {
            executor.execute(new SumTask(i));
        }

        executor.shutdown();

        try {
            executor.awaitTermination(5, TimeUnit.SECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Matrix:");
        for (int[] row : mat) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }

        System.out.println("\nThe total Sum: " + getSum());
    }

    public static void initialize() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                mat[i][j] = (int) (Math.random() * 5);
            }
        }
    }

    public static class SumTask implements Runnable {
        private final int row;

        public SumTask(int row) {
            this.row = row;
        }

        @Override
        public void run() {
            int rowSum = 0;
            for (int j = 0; j < 4; j++) {
                rowSum += mat[row][j];
            }

            try {
                semaphore.acquire();
                sum += rowSum;
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                semaphore.release();
            }
        }
    }
}
