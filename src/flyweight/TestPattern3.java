package flyweight;

public class TestPattern3 {
    public static void main(String[] args) {
        FlyweightFactory flyweightFactory = new FlyweightFactory();
        flyweightFactory.getSubject("a");
        flyweightFactory.getSubject("a");
        flyweightFactory.getSubject("b");
        flyweightFactory.getSubject("b");
    }
}
