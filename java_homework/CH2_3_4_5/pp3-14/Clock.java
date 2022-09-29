public class Clock {
    private int hour;
    private int minute;
    private int second;

    public Clock(int hour, int minute, int second){
        if ((hour > 23) && (minute > 59) && (second > 59)){
            this.hour = 0;
            this.minute = 0;
            this.second = 0;
        }
        else{
            this.hour = hour;
            this.minute = minute;
            this.second = second;
        }
    }
    public int getHour() {return hour;}
    public int getMinute() {return minute;}
    public int getSecond() {return second;}
    public void setHour(int hour) {this.hour = hour;}
    public void setMinute(int minute) {this.minute = minute;}
    public void setSecond(int second) {this.second = second;}

    public void print_clock(){
        System.out.printf("%2d:%2d:%2d\n", getHour(), getMinute(), getSecond());
    }
}
