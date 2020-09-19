package design_pattern.singleton;

public class TestPattern4 {
    public static void main(String[] args) {
        for (int i = 0; i < 50; i++) {
            Thread time = new ThreadSub(i);
            time.start();
        }
    }
}

class ThreadSub extends Thread{
    int map;

    public ThreadSub(int map) {
        this.map = map;
    }

    @Override
    public void run() {
        LogWriter logger = LogWriter.getInstance();
        if(map <10)
            logger.log("*** 0"  + map + "***");
        else
            logger.log("***" + map + "***");
    }
}
