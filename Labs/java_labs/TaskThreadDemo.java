package labs.java_labs;

public class TaskThreadDemo {
    public static void main(String[] args) {
        /* Create tasks */
        Runnable printA = new PrintChar('a', 100);
        Runnable printB = new PrintChar('b', 100);
        Runnable print100 = new PrintNum(100);

        /* Create threads */
        Thread thread1 = new Thread(printA);
        Thread thread2 = new Thread(printB);
        Thread thread3 = new Thread(print100);

        /* Changing the priority */
        thread1.setPriority(Thread.MAX_PRIORITY);

        thread1.start();
        thread2.start();
        thread3.start();
    }
}

class PrintChar implements Runnable {
    private char charToPrint;
    private int times;

    // constructor
    public PrintChar(char c, int n) {
        charToPrint = c;
        times = n;
    }

    @Override
    public void run() {
        for (int i = 0; i < times; i++) {
            System.out.print(charToPrint);
        }
    }
}

class PrintNum implements Runnable {
    private int lastNum;

    public PrintNum(int n) {
        lastNum = n;
    }

    @Override
    public void run() {
        Thread thread4 = new Thread(new PrintChar('c', 40));
        thread4.start();
        try {
            for (int i = 0; i <= lastNum; i++) {
                System.out.print(" " + i);
                if (i == 50)
                    thread4.join();
            }
        } catch (InterruptedException ex) {
        }
    }
}