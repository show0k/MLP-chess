#include "API.h"

int status;
struct addrinfo host_info;       // The struct that getaddrinfo() fills up with data.
struct addrinfo *host_info_list;
int socketfd;

void sendCommand(string s){
	cout<<"envoi commande:"<<s<<"\n";
	char *msg = new char [s.length()+1];
 	 strcpy (msg, s.c_str());
	int len;
	ssize_t bytes_sent;
	len = strlen(msg);
	bytes_sent = send(socketfd, msg, len, 0);
}	

const string getResult(){
	cout << "Waiting to recieve data..."  << endl;
	ssize_t bytes_recieved;
	char incoming_data_buffer[1000];
	bytes_recieved = recv(socketfd, incoming_data_buffer,1000, 0);
	// If no data arrives, the program will just wait here until some data arrives.
	if (bytes_recieved == 0) cout << "host shut down." << endl ;
	if (bytes_recieved == -1)cout << "recieve error!" << endl ;
	cout << incoming_data_buffer << endl;
	return string(incoming_data_buffer);
}

void initAPI(const char *IP){
	memset(&host_info, 0, sizeof host_info);
	host_info.ai_family = AF_UNSPEC;
  	host_info.ai_socktype = SOCK_STREAM;
  	status = getaddrinfo(IP, "4692", &host_info, &host_info_list);
	if (status != 0)  cout << "getaddrinfo error" << gai_strerror(status)<<"\n" ;

	socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype, host_info_list->ai_protocol);
	if (socketfd == -1)  cout << "socket error "<<"\n" ;

	status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
	if (status == -1)  cout << "connect error"<<"\n" ;
}
