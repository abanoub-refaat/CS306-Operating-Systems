package labs.java_labs.lab10;

public class TestB implements Runnable {
    public static void main(String[] args) {
        new TestB();
    }

    public TestB() {
        Thread t = new Thread(this);
        t.start();
        t.start();
    }

    public void run() {
        System.out.println("test");
    }
}