//This code is written by Piyush Pratap Singh
#include <bits/stdc++.h>
using namespace std;

bool validCC(string s)
{
    if (s.size() != 16)
    {
        return false;
    }
    for (auto v : s)
    {
        if (v < '0' || v > '9')
        {
            return false;
        }
    }
    return true;
}

bool LuhnCheck(string s){
    int evensum = 0;
    int oddsum = 0;
    int n = s.size();
    for(int i = n-1; i>=0; i-=2){
        oddsum += (s[i]-'0');
    }
    for (int i = n - 2; i >= 0; i -= 2)
    {
        int dbl = 2 * (s[i] - '0');
        if(dbl>9){
            dbl = dbl/10 + dbl%10;
        }
        evensum += dbl;
    }
    int sum = evensum+oddsum;
    if(sum%10==0){
        return true;
    }
    else return false;
}

int main(){
    while(true){
        cout<<"Enter 1 to register your Credit Card Number"<<endl;
        cout<<"Enter 2 to get your Credit Card Number if registered"<<endl;
        cout << "Enter 3 to EXIT" << endl;
        int choice;
        cin>>choice;
        if(choice==1){
            string s, us, pas;
            cout<<"Enter Username: "; cin>>us;
            cout << "Enter Password: "; cin >> pas;
            cout<<"Enter you Credit Card Number: "; cin >> s;
            if (!validCC(s))
            {
                cout << "Not a valid Credit Card Number" << endl;
                continue;
            }
            if (LuhnCheck(s))
            {
                ofstream out;
                out.open(("C://Users//Lenovo//OneDrive//OneDrive - iitkgp.ac.in//Desktop//C++//Credit Card Validator//" + us + ".txt"));
                out << us << endl << pas << endl << s <<endl;
                out.close();
                cout<<"Yay! You are registered in our database"<<endl;
            }
            else
            {
                cout << "Not valid Credit Card Number! Try Again" << endl;
            }
            cout<<endl;
        }
        else if (choice == 2)
        {
            string s, us, pas, u, p;
            cout << "Enter Username: ";
            cin >> us;
            cout << "Enter Password: ";
            cin >> pas;
            ifstream read("C://Users//Lenovo//OneDrive//OneDrive - iitkgp.ac.in//Desktop//C++//Credit Card Validator//" + us + ".txt");
            getline(read, u);
            getline(read, p);
            getline(read, s);
            if(u==us && pas==p){
                cout<<"You are registerd in our database!"<<endl;
                cout<<"Here is your Credit Card Number: " <<s<<endl;
            }
            else{
                cout << "You are NOT registerd in our database or You are entering incorrect credentials" << endl;
                cout<<"Kindly register first or Try Again"<<endl;
            }
            cout<<endl;
        }
        else if(choice==3){
            break;
        }
        else{
            cout<<"Please enter a valid choice!"<<endl;
            cout<<endl;
        }
    }
    return 0;
}