package DesignPattern;

public class AObj {

    AInterface aInterface;


    public AObj() {
        aInterface = new AInterfaceImpl();
    }

    public void funcAA() {


        //다른 객체의 기능을 구현 하는 것
        aInterface.funcA();
        aInterface.funcA();

//        System.out.println("AAA");
//        System.out.println("AAA");
//        System.out.println("AAA");
        //~~ 기능이 필요
    }
}
