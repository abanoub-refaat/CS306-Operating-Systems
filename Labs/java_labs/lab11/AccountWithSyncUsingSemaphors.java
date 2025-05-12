package labs.java_labs.lab11;

import java.util.concurrent.*;

public class AccountWithSyncUsingSemaphors {
    private static Account account = new Account();

    public static void main(String[] args) {
        ExecutorService executor = Executors.newCachedThreadPool();

        for (int i = 0; i < 100; i++) {
            executor.execute(new AddPennyTask());
        }

        executor.shutdown();

        while (!executor.isTerminated()) {
        }

        System.out.println("What is balance? " + account.getBalance());
    }

    public static class AddPennyTask implements Runnable {
        @Override
        public void run() {
            account.deposite(1);
        }
    }

    // A new inner class for Account
    public static class Account {
        // Initializing a lock
        private static Semaphore semaphore = new Semaphore(1);
        private int balance = 0;

        public int getBalance() {
            return balance;
        }

        public void deposite(int amount) {
            try {
                semaphore.acquire(); // Acquire the semaphore
                int newBalance = balance + amount;
                Thread.sleep(5);
                balance = newBalance;
            } catch (InterruptedException e) {
            } finally {
                semaphore.release(); // release the semaphore
            }
        }
    }
}
