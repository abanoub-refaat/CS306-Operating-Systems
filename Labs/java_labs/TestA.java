package labs.java_labs;

/*
 * This code will throw stackoverflow exception since it will call the
 * constructor recursivly and new Thread(task).start() will never be reached.
 * 
 * public class TestA implements Runnable {
 * public static void main(String[] args) {
 * new Test();
 * }
 * 
 * public TestA() {
 * TestA task = new TestA();
 * new Thread(task).start();
 * }
 * 
 * public void run() {
 * System.out.println("test");
 * }
 * }
 */

// The solution is to remove the consturctor and invoke the task in the main method.
public class TestA implements Runnable {
    public static void main(String[] args) {
        TestA task = new TestA();
        new Thread(task).start();
    }

    public void run() {
        System.out.println("test");
    }
}