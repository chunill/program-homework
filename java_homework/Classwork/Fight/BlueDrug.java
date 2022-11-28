
public class BlueDrug extends Drug{
	private int addMagic;
	
	BlueDrug(){}
	BlueDrug(String size){
		super(size);
		
		switch(size) {
		case "large" :
			addMagic = 100;
			break;
		case "medium" :
			addMagic = 60;
			break;
		case "small" :
			addMagic = 30;
			break;
		default:
			System.out.println("No such BlueDrug size.");
			addMagic = 0;
		}
	}
	
	public int getAddMagic() {return addMagic;}
}
