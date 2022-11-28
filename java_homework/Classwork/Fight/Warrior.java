public class Warrior extends Role{
	
	Warrior(){}
	Warrior(String Name) {
		super(Name, 400, 100);
	}
	
	public void NewMoon(Role role) {
		if (getMagic() < 10) {
			System.out.print("魔力小於10，攻擊無效\n");
			return;
		} else {
			if (role instanceof Mage) {
				role.setLife(role.getLife() - 40);
			}
			else if (role instanceof Warrior){
				role.setLife(role.getLife() - 25);
			}
			setMagic(getMagic() - 10);
		}
		
		if (role.getLife() <= 0) {
			System.out.printf("%s 死亡%n", role.getName());
		}
	}
	
	@Override
	public String toString() {
		return String.format("戰士: %nName: %s, Life: %d, magic: %d%n", getName(), getLife(), getMagic());
	}
}