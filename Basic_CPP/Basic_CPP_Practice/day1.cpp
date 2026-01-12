#include<bits/stdc++.h>
using namespace std;

class Vehicle{

    private:
    string m_make;
    string m_model;
    int m_yearofManufacturing;
    double m_exshowroomPrice;

    public:
    	// Defaut Constructor
        Vehicle(){
            this->m_model = "";
            this->m_yearofManufacturing = 0;
            this->m_exshowroomPrice = 0.0;
    }

     Vehicle(string model_, int year_, double exshowroomPrice_){
            this->m_model = model_;
            this->m_yearofManufacturing = year_;
            this->m_exshowroomPrice = exshowroomPrice_;
    }

    void display()
    {
        cout << m_model << m_yearofManufacturing << m_exshowroomPrice;
    }




};

int main()
{
    Vehicle myobject1;
    Vehicle myobject2("Tata Nexon",2024,12.56 );

    myobject2.display();
}