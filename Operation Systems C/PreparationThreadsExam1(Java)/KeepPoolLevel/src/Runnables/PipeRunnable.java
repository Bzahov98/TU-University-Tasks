package Runnables;

import static java.lang.Thread.sleep;

public class PipeRunnable implements Runnable {
    final int pipeDebit;
    boolean iSFillingPipe = false;

    public PipeRunnable(final int pipeDebit) {
        this.pipeDebit = pipeDebit;
        if (pipeDebit >= 0) {
            iSFillingPipe = true;
        }
    }

    @Override
    public void run() {
        try {
            while (true) {

                synchronized (PoolManagement.poolMutex) {
                    if (iSFillingPipe) { // for In pipe
                        if (PoolManagement.currentCapacity <= 700) {
                            System.out.println("Fill Pool (" + PoolManagement.currentCapacity + ") with " + pipeDebit);
                            PoolManagement.currentCapacity += pipeDebit;
                        } else sleep(400); // sleep thread when pool is more than 700
                    } else if (PoolManagement.currentCapacity >= 600) { // for Out pipe
                        PoolManagement.currentCapacity += pipeDebit; // decrease pipe Debit
                        System.out.println("Fill Pool (" + PoolManagement.currentCapacity + ") with " + pipeDebit);
                    } else sleep(400); // sleep thread when pool is less than 600
                }
                sleep(400);
            }
        } catch (InterruptedException e) {
            System.out.println("interupt + " + pipeDebit);
            return;
        }
    }
}
