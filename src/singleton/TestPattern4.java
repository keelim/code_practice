package singleton;

import java.util.logging.Logger;

public class TestPattern4 {
    public static void main(String[] args) {
        for (int i = 0; i < 50; i++) {
            Thread t = new ThreadSub(i);
            t.start();
        }
    }
}

class ThreadSub extends Thread{
    int num;

    public ThreadSub(int num) {
        this.num = num;
    }

    @Override
    public void run() {
        LogWriter logger = LogWriter.getInstance();
        if(num <10)
            logger.log("*** 0"  + num + "***");
        else
            logger.log("***" + num + "***");
    }
}
