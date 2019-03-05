package DesignPattern;

public class AInterfaceImpl implements AInterface{

    public static void main(String[] args) {
            AInterface aInterface = new AInterfaceImpl();
            //인터페이스를 선언을 하고 객페를 만든다.
            aInterface.funcA();
    }

    AObj aObj = new AObj();

    public void funcA() {
        System.out.println("AAA");

    }
}
