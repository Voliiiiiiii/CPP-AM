#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
    //1
    vector<string> fruits{"melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"};

    auto it = find_if(fruits.begin(), fruits.end(), [](const string& fruit){
        //return fruit.contains("berry");
        return fruit.find("berry")!= string::npos;
    });

    if (it != fruits.end()) {
        cout << "Found: " << *it << endl;
    } else {
        cout << "Not found" << endl;
    }
    cout<<endl;
    cout<<endl;



    //2
    vector<int> numbers = {25, 64, 12, 89, 47, 3, 71, 56, 38, 92};
    auto even = all_of(numbers.begin(), numbers.end(), [](const int& e){
        return e%2==0;
    });
    if (even) {
        cout << "even vector " << endl;
    } else {
        cout << "Not even vector" << endl;
    }
    cout<<endl;
    cout<<endl;


    //3
    for_each(numbers.begin(),numbers.end(), [](int& e){ e = e*2;});


    //4
    vector<string> months {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
    int count=0;
    for_each(months.begin(), months.end(),[&count](const string& e){
        if(e.size()==5){
            count++;
        };
    });
    cout<<"5 betus honap: "<<count<<endl;
    cout<<endl;
    cout<<endl;



    //5

    vector<double> numberss = {3.14, 2.71, 1.41, 1.61, 0.57, 4.67, 9.81, 2.54, 6.28, 1.73};
    sort(numberss.begin(),numberss.end(), [](const double& num1, const double& num2){
        return num1>num2;
    });

    for_each(numberss.begin(),numberss.end(), [](const auto& a){
        cout<<a<<" ";
    });
    cout<<endl;
    cout<<endl;


    //6
    vector<pair<string,double>> months_and_temp =
        {{"January",3.14},
        {"February",2.71},
        {"March",1.41}, 
        {"April",1.61},
        {"May",0.57},
        {"June",4.68},
        {"July",9.81}, 
        {"August",2.51},
        {"September",2.68},
        {"October",1.34},
        {"November",12.33},
        {"December",33.22}
    };
    sort(months_and_temp.begin(),months_and_temp.end(), [](const pair<string,double>& num1, const pair<string,double>& num2){
        return num1.second>num2.second;
    });

    for_each(months_and_temp.begin(),months_and_temp.end(), [](const pair<string,double>& a){
        cout<<a.first<<" "<<a.second<< " -- ";
    });
    cout<<endl;
    cout<<endl;

    //7
    sort(numberss.begin(),numberss.end(), [](const double& num1, const double& num2){
        return abs(num1)>abs(num2);
    });

    for_each(numberss.begin(),numberss.end(), [](const auto& a){
        cout<<a<<" ";
    });
    cout<<endl;
    cout<<endl;


    //8
    for_each(months_and_temp.begin(),months_and_temp.end(), [](pair<string,double>& a){
        a.first[0] = tolower(a.first[0]);
    });
    for_each(months_and_temp.begin(),months_and_temp.end(), [](const pair<string,double>& a){
        cout<<a.first<<" "<<a.second<< " -- ";
    });
    cout<<endl;
    cout<<endl;



    //9
    vector<char> abc_lower = {'a','b','c','d','e','f','g','h','i','j',
                             'k','l','m','n','o','p','q','r','s','t',
                             'u','v','w','x','y','z'};


    //std::shuffle(abc_lower.begin(), abc_lower.end(), rng);

    for_each(abc_lower.begin(),abc_lower.end(), [](const char& c){
        cout<<c<<" "<<endl;
    });
    cout<<endl;
    cout<<endl;


    return 0;
}