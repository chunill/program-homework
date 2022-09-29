#include <iostream>
#include <string>
using namespace std;

class Subscriber{
    public:
        Subscriber();
        Subscriber(string newName, int newNumChannels);
        Subscriber(const Subscriber& newObject);
        void setName(string newName){name = newName;};
        void setNumChannels(int newNumChannels) {numChannels = newNumChannels;};
        void setChannelList();
        string getName() const {return name;};
        int getNumChannels() const {return numChannels;};
        string* getChannelList() const {return channelList;};
        void outputChannel() const;
        void reset();
        Subscriber& operator =(const Subscriber& rightObject);
        ~Subscriber(){delete [] channelList;};
    private:
        string name;
        int numChannels;
        string* channelList;
};

int main(){
    Subscriber channel_user, channel_2("su3cl3", 3), channel_3("yl30", 4);
    string name;
    int numChannels;

    cout << "Enter channel name >> ";
    cin >> name;
    channel_user.setName(name);
    cout << "Enter channel num >> ";
    cin >> numChannels;
    channel_user.setNumChannels(numChannels);
    cout << "Enter channel list >> ";
    channel_user.setChannelList();
    cout << endl;
    channel_user.outputChannel();

    // channel_user.setNumChannels(numChannels);
    // cout << channel_user.getName() << endl;
    // cout << channel_2.getNumChannels() << endl;

}

Subscriber::Subscriber(): name("null"), numChannels(5){
    channelList = new string[numChannels];
}
Subscriber::Subscriber(string newName, int newNumChannel)
:name(newName), numChannels(newNumChannel){
    channelList = new string[numChannels];
}
Subscriber::Subscriber(const Subscriber& Object)
:name(Object.getName()), numChannels(Object.getNumChannels()){
    channelList = new string[numChannels];
    for(int i=0;i<numChannels;i++)
        channelList[i] = Object.channelList[i];
}
void Subscriber::setChannelList(){
    string s;
    char c;
    int index = 0;
    delete [] channelList;
    channelList = new string[numChannels];
    do{
        cin >> s;
        channelList[index++] = s;
        cin.get(c);
        if (c == '\n')
            break;
    }while(1);
}
void Subscriber::reset(){
    name = "NULL";
    numChannels = 0;
    delete [] channelList;
    channelList = new string[0];
}
Subscriber& Subscriber::operator =(const Subscriber& rightObject){
    if (numChannels != rightObject.getNumChannels()){
        delete [] channelList;
        channelList = new string[rightObject.getNumChannels()];
    }
    name = rightObject.getName();
    numChannels = rightObject.getNumChannels();
    for(int i=0;i<numChannels;i++)
        channelList[i] = rightObject.channelList[i];

    return *this;
}
void Subscriber::outputChannel()const{
    cout << "channel name: " << name << endl;
    cout << "channel  number: " << numChannels << endl;
    cout << "channel list: " << endl;
    for (int i=0;i<numChannels;i++)
        cout << channelList[i] << endl;
    cout << endl;
}
