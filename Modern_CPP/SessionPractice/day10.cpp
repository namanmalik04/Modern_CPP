#include<iostream>
#include<unordered_map>
#include<string>

class CanHandler{
    private:
    std::unordered_map<int, std::string> myHandler;

    public:
    void addHandler(int messageKey, const std::string messageValue){
        myHandler[messageKey] = messageValue;

        std::cout << "Handler added: " << messageKey << " -> " << messageValue << std::endl;
    }

    void removeHandler(int messageKey){
        if(myHandler.erase(messageKey))
            std::cout << "Handler removed: " << messageKey << std::endl;

        else
            std::cout << "Handler not found KEY: " << messageKey << std::endl;
    }

    void findHandler(int messageKey) const{
        auto it = myHandler.find(messageKey);
        if(it != myHandler.end())
            std::cout << "Handler found: " << messageKey << " -> " << it->second << std::endl;
        else
            std::cout << "Handler not found KEY: " << messageKey << std::endl;
    }
    void displayHandlers() const{
        for(const auto& [key, value] : myHandler){
            std::cout << key << " : " << value << std::endl;
        }
    }
};
int main()
{
    CanHandler handler;

    handler.addHandler(100, "Engine Data");
    handler.addHandler(200, "Brake Data");
    handler.addHandler(300, "Steering Data");

    handler.displayHandlers();
    handler.findHandler(200);
    handler.removeHandler(100);
    handler.displayHandlers(); 

    return 0;
}