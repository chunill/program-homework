
public class Fight {
    public static void main(String[] args){
        Role[] roleArray = {new Warrior("warrior_A"), new Warrior("warrior_B"), new Warrior("warrior_C"), 
                                new Mage("mage_A"), new Mage("mage_B"), new Mage("mage_C")};
        boolean run = true;
        Role attacker, defender;
        while(run){
            attacker = roleArray[(int)(Math.random() * 10) % 6];
            defender = roleArray[(int)(Math.random() * 10) % 6];
            if (attacker == defender){
                continue;
            }
            System.out.printf("%s 打了 %s%n", attacker.getName(), defender.getName());
            if (attacker instanceof Warrior){
                ((Warrior)attacker).newMoon(defender);
            }
            else if (attacker instanceof Mage){
                ((Mage)attacker).SmallFire(defender);
            }
            if (defender.getLife() < 0){
                System.out.printf("%n遊戲結束%n", defender.getName());
                break;
            }
        }
    }
}
