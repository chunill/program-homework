public class Warrior extends Role{

    Warrior(){}
    Warrior(String name){
        super(name, 400, 100);
    }
    public void newMoon(Role role){
        if (getMagic() < 10){
            System.out.printf("魔力小於10，攻擊無效%n");
        }
        else {
            setMagic(getMagic() - 10);
        }
        if (role instanceof Warrior){
            role.setLife(getLife() - 25);
        }
        else if (role instanceof Mage){
            role.setLife(getLife() - 40);
        }
        if(role.getLife() <= 0){
            System.out.printf("%n%s 死亡%n", role.getName());
        }
    }

    @Override
    public String toString(){
        return String.format("戰士: %nname: %s, life: %d, magic: %d", getName(), getLife(), getMagic());
    }
    
}
