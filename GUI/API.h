#ifndef API
#define API

#include <iostream>
#include <cstring>      // Needed for memset
#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
using namespace std;

void sendCommand(string s);
const string getResult();
void initAPI(const char *IP);

#endif
