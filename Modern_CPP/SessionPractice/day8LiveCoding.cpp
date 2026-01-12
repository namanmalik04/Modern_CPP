//Naman Malik

//Device.h file

#include<iostream>
#include<string>

enum class Status{
  Active,
  Inactive
};

class Device {
  
  private:
  int m_id;
  std:: string m_name;
  Status m_status;


public:

Device();

Device(int id, std:: string name, Status status);

//copy const copy assi
Device(Device&) = delete;
Device& operator=(Device& other) = delete;

// Move cons Move assign

Device(Device&& other);
Device& operator=(Device&& other);

void display() const;

static std::string statusTostring(Status string);
};

//Global Fun
std::vector<std::unique_ptr<Device>> createDevice();

Device searchDevice(std::vector<std::unique_ptr<Device>> & devices, const std::string& name);




// Device.cpp
#include"Device.h"

Device::Device(){
  m_id = 0;
  m_name = "";
  m_status = Inactive;
  
}

Device::Device(int id, std:: string name, Status status)
{
  m_id = id;
  m_name = name;
  m_status = status;
}

Device::Device(Device&& other)
{
  m_id = other.m_id;
  m_name = other.m_name;
  m_status = other.m_status;
}

Device& Device::operator=(Device&& other){
  m_id = other.m_id;
  m_name = std::move(other.m_name);
  m_status = other.m_status;
  
  return *this;
}

void Device::display() {
  std::cout<<"Id " << m_id
    <<"name" <<m_name;
  <<"m_status" << m_status;
  
}

std::vector<std::unique_ptr<Device>>createDevice() {
  std::vector<std::unique_ptr<Device>> devices;
  devices.push_back(std::make_unique<Device>(1,"Sensor" , Status::Active));
return devices;
}

Device searchDevice(std::vector<std::unique_ptr<Device>> & devices, const std::string& name){
  for(auto i: devices)
  {
    if()
  }
  
  
}


//main.cpp
#include "Device.h"
#include <algorithm>
int main(){
  
  //1 test case
  auto devices = createDevices();
  
  // 2 test case
  for(auto i: devices) {
    i->display();
  }
  
  // 3 prompt user for name
  std::string name;
  std:: cin>>name;
  
  // 4 Search 
  
  
  
}




  

