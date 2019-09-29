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
> design_pattern.singleton pattern

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
    
> 얕은 복사, 깊은 복사
    
    - ?   

> Builder pattern

```java
    Member customer = Member.design_pattern.builder()
    .name("keelim")
    .age(30)
    .build();
```

    - 인자가 많을 떄는 design_pattern.builder pattern
    - 생성자를 굳이 많이 만들 이유가 없다.
    - design_pattern.builder 는 setter 의 반환 형식을 design_pattern.builder 로 바꾼다. 

## 2019 08 03

> design_pattern.adapter pattern == wrapper pattern
    
    - class, instance
    - 이미 존재하는 클래스가 많은 경우도 있다. 
    - 기존 클래스를 개조해서 필요한 클래스를 만드는 것
    - 프로그램 검사도 쉬워진다.
    - interface 개조를 해야 한다.
    - 기존 클래스의 사양만 하면 새로운 클래스를 만들 수 있다.
    - interface를 사용을 하여 코드의 수정을 최소화 하는 것이다.
    - abstract 클래스르 활용하여 사용 할 수 있다. 

## 2019 08 04 

> design_pattern.facade pattern

    - 파사드 패턴
    - 하위시스템을 보다 쉽게 사용할 수 있게 해주는 고급 인터페이스 정의
    - design_pattern.adapter --> 다른 코드를 사용할 수 있게 하는 것
    - design_pattern.facade --> 좀더 쉽세 사용하는 wrapper를 제공하는 것
    - 캡슐화되지 않은 코드를 처리
    - 최소 단위 클래스를 설계할 수 있다.
    - 최소 클래스를 만들고 그것을 종합하는 것을 만든다.
    
> Bridge pattern

    - 기능 클래스 계층
    - interaface 기능을 추가하는 것
    - 모든 클래스를 수정을 해야 한다.
    - 새로운 기능이 필요가 없을 수 도 있다.  
    - 구현 클래스 계층 
    - interface의 수정 없이 클래스를 하나를 더 만들어서 생성을 한다.

## 2019 08 05 
> Observer pattern

    - 값을 반영을 하는 것을 객체로 표현
    - Subject 객체과 Observer 객체의 관계
    - Observable sub class 를 만들어야 한다.
    - 재사용성 제한이 생긴다.
    - protected으로 구현이 되어 있다.  
    - 이벤트 Listener 같은 것들은 observer pattern 으로 사용이 된다.


## 2019 08 09 
> Decorator pattern

## 2019 08 13
> Decorator pattern

    - 기본 기능을 확장을 할 수 있게 한다.
    - 기존 코드 행동 확장
    - 상속 대신 사용 
    - 필터 스트림
    - 자잘한 객체가 많이 추가될 수 있다. 
    - 코드가 필요이상 복잡
    - decorator, factory, builder
    - 추상 클래스를 정의를 하고 상속을 받아서 사용을 하는 것
    
    
    
    
```java
BufferedReader br = null;
br = new BufferedReader(new FileReader(new File("test.txt")));

```

## 2019 08 19
> strategy pattern

    - 여러 알고리즘을 인터페이스를 만들어 알고리즘이 교환가능
    - 동일 목적 알고리즘의 선택 적용 문제
    - 워드 문서에서 프린터 폰트
    - 정수 배열에 대해 사용하는 정렬 알고리즘
    - 게임 캐릭터의 무기 사용 

## 2019 09 29
> sum 문제 풀기

    - C++ 도 같이 작성을 할 것
    - 회로?, 칩설계