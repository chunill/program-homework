public class Mage extends Role{
    Mage(){}
    Mage(String name){
        super(name, 280, 200);
    }

    public void SmallFire(Role role){
        if (getMagic() < 25){
            System.out.printf("魔力小於25，攻擊無效%n");
        }
        else {
            setMagic(getMagic() - 25);
        }
        if (role instanceof Warrior){
            role.setLife(role.getLife() - 40);
        }
        else if (role instanceof Mage){
            role.setLife(role.getLife() - 60);
        }
        if(role.getLife() <= 0){
            System.out.printf("%n%s 死亡%n", role.getName());
        }
    }

    @Override
    public String toString(){
        return String.format("法師: %nname: %s, life: %d, magic: %d", getName(), getLife(), getMagic());
    }
    
}
