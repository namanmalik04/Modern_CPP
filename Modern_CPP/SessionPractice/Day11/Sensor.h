#ifndef SENSOR_H
#define SENSOR_H

#include<iostream>
#include<string>

class Sensor {
private:
    std:: string m_name;
    int m_priority;
    double m_reading;

    public:
    Sensor()=default; // Default constructor
    Sensor(const std::string& name, int priority, double reading);

    Sensor(const Sensor& other)=default; // Copy constructor
    Sensor& operator=(const Sensor& other)=default; // Copy assignment operator     
    Sensor(Sensor&& other) = default; // Move constructor
    Sensor& operator=(Sensor&& other) = default; // Move assignment operator 
    ~Sensor(); // Destructor

    void setName(const std::string& name);
    std::string getName() const;    
    void setPriority(int priority);

    int getPriority() const;
    void setReading(double reading);
    double getReading() const;
    void display() const;

};

#endif // SENSOR_H