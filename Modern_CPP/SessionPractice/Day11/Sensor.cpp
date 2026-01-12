#include "Sensor.h"

Sensor::Sensor(const std::string& name, int priority, double reading)
    : m_name(name), m_priority(priority), m_reading(reading) {}

Sensor::~Sensor() {}        

void Sensor::setName(const std::string& name) {
    m_name = name;
}
std::string Sensor::getName() const {
    return m_name;
}
void Sensor::setPriority(int priority) {
    m_priority = priority;
}
int Sensor::getPriority() const {
    return m_priority;
}

void Sensor::setReading(double reading) {
    m_reading = reading;
}
double Sensor::getReading() const {
    return m_reading;
}
void Sensor::display() const {
    std::cout << "Sensor Name: " << m_name << "\n";
    std::cout << "Priority: " << m_priority << "\n";
    std::cout << "Reading: " << m_reading << "\n";
}

