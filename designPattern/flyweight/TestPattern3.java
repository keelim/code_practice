package design_pattern.flyweight;

public class TestPattern3 {
    public static void main(String[] args) {
        FlyweightFactory flyweightFactory = new FlyweightFactory();
        flyweightFactory.getSubject("map");
        flyweightFactory.getSubject("map");
        flyweightFactory.getSubject("b");
        flyweightFactory.getSubject("b");
    }
}
