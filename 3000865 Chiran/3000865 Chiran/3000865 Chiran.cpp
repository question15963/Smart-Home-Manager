//3000865 Chiran Ekanayake g21270374
#include "DeviceManager.hpp"
#include <iostream>
#include <cstdlib>//to check memory leaks
#include <crtdbg.h>//to checck memory leaks
#define _CRTDBG_MAP_ALLOC

//main function
int main() {
    std::cout << "Starting Device Home Manager..." << std::endl;
    DeviceHomeManager manager;
    manager.Run();
    std::cout << "Closing Device Home Manager..." << std::endl;
    _CrtDumpMemoryLeaks();
    return 0;
}

 