public class BlueDrug extends Drug{
    int addMagic;
    BlueDrug(){}
    BlueDrug(String size, int addMagic){
        super(size);
        switch(getSize()){
            case "large":
                addMagic = 100;
                break;
            case "medium":
                addMagic = 60;
                break;
            case "small":
                addMagic = 30;
                break;
            default:
                System.out.printf("No such RedDrug size.");
                addMagic = 0;
        }
    }
	public int getAddLife() {return addMagic;}
}
