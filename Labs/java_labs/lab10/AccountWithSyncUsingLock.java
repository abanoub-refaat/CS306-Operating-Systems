package labs.java_labs.lab10;

import java.util.concurrent.*;
import java.util.concurrent.locks.*;

public class AccountWithSyncUsingLock {
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

    // A thread for adding a penny to the account
    public static class AddPennyTask implements Runnable {
        @Override
        public void run() {
            account.deposite(1);
        }
    }

    // An inner class for Account
    public static class Account {
        // Initializing a lock
        private static Lock lock = new ReentrantLock();
        private int balance = 0;

        public int getBalance() {
            return balance;
        }

        public void deposite(int amount) {
            lock.lock(); // Acquire the lock

            try {
                int newBalance = balance + amount;
                Thread.sleep(5);
                balance = newBalance;
            } catch (InterruptedException e) {
            } finally {
                lock.unlock(); // release the lock
            }
        }
    }
}
