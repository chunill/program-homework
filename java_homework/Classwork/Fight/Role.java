public class Role {
	private String Name;
	private int Life;
	private int Magic;
	
	Role() {}
	Role(String Name, int Life, int Magic){
		this.Name = Name;
		this.Life = Life;
		this.Magic = Magic;
	}
	
	public String getName() {return Name;}
	public int getLife() {return Life;}
	public int getMagic() {return Magic;}
	public void setName(String Name) {this.Name = Name;}
	public void setLife(int Life) {this.Life = Life;}
	public void setMagic(int Magic) {this.Magic = Magic;}
	
	public void Drink(Drug D){
		
	}
}