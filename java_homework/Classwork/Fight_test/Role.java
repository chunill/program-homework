public class Role {
    String name;
    int life;
    int magic;

    Role(){}
    Role(String name, int life, int magic){
        this.name = name;
        this.life = life;
        this.magic = magic;
    }
    public String getName() {return name;}
    public int getLife() {return life;}
    public int getMagic() {return magic;}
    public void setName(String name) {this.name = name;}
    public void setLife(int life) {this.life = life;}
    public void setMagic(int magic) {this.magic = magic;}

}
