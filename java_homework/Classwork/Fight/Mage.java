public class Mage extends Role{

	public Mage(String Name) {
		super(Name, 280, 100);
	}
	
	public void SmallFire(Role role) {
		if (getMagic() < 25) {
			System.out.print("魔力小於25，攻擊無效\n");
		}
		else {
			if (role instanceof Mage) {
				setLife(getLife() - 60);
			}
			else if (role instanceof Warrior) {
				setLife(getLife() - 40);
			}
			setMagic(getMagic() - 10);
		}
		
		if (role.getLife() <= 0) {
			System.out.printf("%s 死亡%n", role.getName());
		}
	}
	
	@Override
	public String toString() {
		return String.format("法師: %nName: %s, Life: %d, magic: %d%n", getName(), getLife(), getMagic());
	}
	
}