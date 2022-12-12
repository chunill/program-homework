public class RedDrug extends Drug{
    int addLife;
    RedDrug(){}
    RedDrug(String size, int addLife){
        super(size);
        switch(getSize()){
            case "large":
                addLife = 120;
                break;
            case "medium":
                addLife = 80;
                break;
            case "small":
                addLife = 50;
                break;
            default:
                System.out.printf("No such RedDrug size.");
                addLife = 0;
        }
    }
	public int getAddLife() {return addLife;}
}
