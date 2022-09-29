#include <iostream>
using namespace std;

class Television{
    public:
        Television();
        Television(string newDisplayType, double newDimension, string newConnectivitySupport[]);
        Television(Television& Object);
        void setDisplayType(string newDisplayType){displayType = newDisplayType;};
        void setDimension(double newDimension){dimension = newDimension;};
        string getDisplayType() const {return displayType;};
        double getDimension() const {return dimension;};
        int getString_size() const {return string_size;};
        void output();

        ~Television(){delete [] connectivitySupport;};
    private:
        string displayType;
        double dimension;
        string* connectivitySupport;
        int string_size;
};

int main(){
    Television* TV;
    Television* TV_list;
    int TV_num;
    string display_type;
    double dimension;
    string connectivityList[50];
    string connectivity;
    int index = 0;
    char yes_or_no;
    char clear;
    cout << "Enter the number of TV >> ";
    cin >> TV_num;
    TV_list = new Television[TV_num];


    cout << "Enter the display type value by default >> ";
    cin >> display_type;
    cout << "Enter the dimension value by default >> ";
    cin >> dimension;
    cout << "Enter the connectivity array >> ";
    do{
        cin >> connectivity;
        connectivityList[index++] = connectivity;
        cin.get(clear);
        if(clear == '\n'){
            break;
        }
    }while(1);
    for(int i=index;i<50;i++)
        connectivityList[i] = " ";
    
    TV = new Television(display_type, dimension, connectivityList);
    TV_list[0] = *TV;
    TV_list[0].output();
    for (int i=0;i<TV_num;i++){
        TV_list[i] = *TV;
    }
    cout << "Do you need a custom TV settings? (y/n)>> ";
    cin >> yes_or_no;
    if (yes_or_no == 'y' || yes_or_no == 'Y'){
        cout << "Enter the display type value by default >> ";
        cin >> display_type;
        cout << "Enter the dimension value by default >> ";
        cin >> dimension;
        cout << "Enter the connectivity array >> ";
        do
        {
            cin >> connectivity;
            connectivityList[index++] = connectivity;
            cin.get(clear);
            if (clear == '\n')
            {
                break;
            }
        } while (1);
        for (int i = index; i < 50; i++)
            connectivityList[i] = " ";
    }

    delete TV;
    delete [] TV_list;
    return 0;
}

Television::Television():displayType("LCD"), dimension(8), string_size(5){
    connectivitySupport = new string[5];
}
Television::Television(string newDisplayType, double newDimension, string newConnectivitySupport[])
:displayType(newDisplayType), dimension(newDimension){
    int index;
    for (int i=0;i<50;i++){
        if(newConnectivitySupport[i] == " "){
            cout << "index: " << index << endl;
            index = i;
            break;
        }
    }
    string_size = index+1;
    connectivitySupport = new string[string_size];
    for(int i=0;i<index+1;i++){
        connectivitySupport[i] = newConnectivitySupport[i];
    }
}
Television::Television(Television& Object)
:displayType(Object.displayType), dimension(Object.dimension), string_size(Object.string_size){
    connectivitySupport = new string[Object.string_size];
    for(int i=0;i<string_size;i++)
        connectivitySupport[i] = Object.connectivitySupport[i];
}
void Television::output(){
    cout << endl;
    cout << "The display type: " << displayType << endl;
    cout << "The dimension: " << dimension << endl;
    cout << "The connectivity list: " << endl;
    for (int i=0;i<string_size;i++){
        cout << connectivitySupport[i] << endl;
    }
}