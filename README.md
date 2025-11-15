# Randommer
api for site randommer.io random tools site 
# main
```cpp
#include "Randommer.h"
#include <iostream>

int main() {
   Randommer api;

    auto username = api.username_generator("en_US","nikolai","lebedev").then([](json::value result) {
        std::cout << "Search results: " << result.serialize() << std::endl;
    });
    username.wait();
    
    return 0;
}
```

# Launch (your script)
```
g++ -std=c++11 -o main main.cpp -lcpprest -lssl -lcrypto -lpthread -lboost_system -lboost_chrono -lboost_thread
./main
```
