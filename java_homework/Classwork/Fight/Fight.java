public class Fight {
	public static void main(String[] args) {
		Role[] RoleArray = {new Warrior("Warrior A"), new Warrior("Warrior B"), new Warrior("Warrior C"), 
							new Mage("Mage A"), new Mage("Mage B"), new Mage("Mage C")};

		boolean run = true;

		for (int i=0;i<6;i++) {
			System.out.println(RoleArray[i]);
		}
		System.out.println();
		while(run) {
			int random_role_A, random_role_B;
			random_role_A = (int)((Math.random() * 10) % 6);
			random_role_B = (int)((Math.random() * 10) % 6);
			while (random_role_A == random_role_B) {
				random_role_B = (int)((Math.random() * 10) % 6);
			}
			if (run == true) {
				if (RoleArray[random_role_A] instanceof Warrior) {
					((Warrior)RoleArray[random_role_A]).newMoon(RoleArray[random_role_B]);
				}
				else if (RoleArray[random_role_A] instanceof Mage) {
					((Mage)RoleArray[random_role_A]).SmallFire(RoleArray[random_role_B]);
				}
				
				if (RoleArray[random_role_B].getLife() <= 0) {
					System.out.print("戰鬥結束\n");
					run = false;
				}
				else {
					System.out.printf("%s 打了 %s%n", RoleArray[random_role_A].getName(), RoleArray[random_role_B].getName());
				}
			}
		}
	}
}