package Runnables;

import java.util.ArrayList;
import java.util.List;

import static java.lang.Thread.sleep;

public class PoolManagement {
    final static int POOL_CAPACITY_MIN = 600;
    final static int POOL_CAPACITY_NORMAL = 700;
    final static int POOL_CAPACITY_TOTAL = 800;

    final static int POOL_PIPES_IN_NUMBER = 2;
    final static int POOL_PIPES_OUT_NUMBER = 1;
    final static int POOL_PIPES_TOTAL_NUMBER = POOL_PIPES_IN_NUMBER + POOL_PIPES_OUT_NUMBER; // 3

    final static int PIPE_DEBIT_IN_FIRST = 100;
    final static int PIPE_DEBIT_IN_SECOND = 80;
    final static int PIPE_DEBIT_OUT = -110;

    public final static Object poolMutex = new Object();
    public static int currentCapacity = 650;

    public static void main(String[] args) throws InterruptedException {
        List<Thread> runnableList = new ArrayList<>();

        Thread inPipeFirst  = new Thread(new PipeRunnable(PIPE_DEBIT_IN_FIRST));
        runnableList.add(inPipeFirst);
        Thread inPipeSecond = new Thread(new PipeRunnable(PIPE_DEBIT_IN_SECOND));
        runnableList.add(inPipeSecond);
        Thread outPipe      = new Thread(new PipeRunnable(PIPE_DEBIT_OUT));
        runnableList.add(outPipe);

        runnableList.stream().forEach(thread -> thread.start());

        int timeElapsed = 0;
        while (timeElapsed < 10000){
            synchronized (poolMutex){
                System.out.println("Time: "+timeElapsed+" -> Pool Capacity: "+ currentCapacity);
            }
            timeElapsed++;
        }
        runnableList.stream().forEach(thread -> {
            try {
                thread.join();
            } catch (InterruptedException e) {
                System.out.println("aaaa");
            }
        });
        System.out.println("begining of the end");
        inPipeFirst.interrupt();
        runnableList.forEach(thread -> thread.interrupt());
        System.out.println("end");
    }
}
