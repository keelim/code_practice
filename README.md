## 2019 06 22
code practice plan 

1 day no fewer than 1 practice

## 2019 06 23
1. Binary tree height

## 2019 07 20
1. java + kotlin write code
 
2. leet code daily 1 problem

3. today: L1108 

## 2019 07 21
1. today: 

2. Regex regular expression

## 2019 08 01
1. 하위 클래스 객체를 상위 클래스 객체 대입 가능

2. 상위는 하위에 대입을 안된다.

> dependency injection (di)

> 객체를 사용하는 방법

    - 객체를 직접적으로 생성하여 사용
    - 외부 생성된 객체를 주입을 하는 것
    - 주입 받은 것은 약한 결합
    - 약한 결합이 프로그래밍으로 유리한 이유
    - 강한 결합의 경우 


```
    public static void memberUser2(Meerber m ){
        Member m2 = m //약한 결합
    }
```

## 2019 08 02
> singleton pattern

    - 객체의 생성 개수 제한
    - 최대 객체 개수를 제한
    - 객체의 생성을 요청 하는 쪽에서는 신경을 쓰면 안된다.
    - ex> 데이터베이스 커넥션 풀, 로그라이터, 사운드 매니저, 스코어 매니저
    - 데이터를 일관되게 유지
    - static 이라서 가능한 부분
    - 생성자를 private 으로 설정을 하는 것이 접근을 하기 어렵다.
    - 이미 member로 선언을 하면 굳이 synchronized 를 할 필요가 없다.
    - 줄을 세워야 하기 때문에 비용이 많이 든다.
    - getinstance로 만들면 된다.

## 2019 08 03
> Flyweight Pattern

    - 위치 정보에 대한 객체를 모두 가지는 경우 메모리가 많이 소모가 된다.
    - 중복이 되는 것들을 모델을 통하여 공유를 하는 방식으로 구성을 할 수 있다. 
    - 공통된 것을 만들어 놓고 위치 정보만 다르게 하여
     
```java
public class TreeModel{
    Mesh mesh;
    Texture bark;
    Texture leaves;
    public TreeModel(){
    mesh = new Mesh();
    bark = new Texture("bark");
    leaves = new Texture("leaves");
    }
}

public class Tree {
    TreeModel treeModel;
    Position position;
    double height;
    double thickness;
}

public class TreeFactory{
    private static final TreeModel sharedTreeModel = new TreeModel();
    public static Tree create(Position position, duoblie height, double thickness){
        Tree tree = new Tree();
        tree.setPosition(position);
        tree.setHeight(height);
        tree.setThickness(thickness);
        tree.setTreeModel(sharedTreeModel);
    } 
}
```
    - 미리 정의 한 TreeModel 를 사용한다.
    - 많은 객체를 만들 때 성능 향상
    - 메모리 줄임
    - state pattern 잘 어울린다.
    - 워드프로세서 문자들의 그래픽적 표현 자료구조
    - jdk(String, valueOf
    
   
