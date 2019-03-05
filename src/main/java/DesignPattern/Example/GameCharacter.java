package DesignPattern.Example;

public class GameCharacter {

    //접근점.
    private Weapon weapon;


    //교환 가능
    public void setWeapon(Weapon weapon) {
        this.weapon = weapon;
    }


    public void attack(){// 델리게이트 위임을 하는 것이다.
        if (weapon == null)
            System.out.println("맨손");
        else
            weapon.attack();
    }
}
