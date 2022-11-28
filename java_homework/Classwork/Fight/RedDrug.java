
public class RedDrug extends Drug{
	private int addLife;
	
	RedDrug(){}
	RedDrug(String size){
		super(size);
		
		switch(size) {
		case "large" :
			addLife = 120;
			break;
		case "medium" :
			addLife = 80;
			break;
		case "small" :
			addLife = 50;
			break;
		default:
			System.out.println("No such RedDrug size.");
			addLife = 0;
		}
	}
	
	public int getAddLife() {return addLife;}
}
