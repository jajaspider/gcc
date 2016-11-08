#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
#include <pthread.h>

ServerSocket new_sock[3];
int count =0;
pthread_mutex_t mutx;
void * handle_clnt(void * arg);
int main ( int argc, char ** argv )
{
  std::cout << "running....\n";
  pthread_t t_id;

  try{
    // Create the socket
    ServerSocket server ( 30010 );
    while ( true ){
      	std::cout<< count<<std::endl;
	server.accept ( new_sock[count] );
	pthread_create(&t_id, NULL, handle_clnt,(void *)&new_sock[count]);
	pthread_detach(t_id);

	pthread_mutex_lock(&mutx);
	count++;
	pthread_mutex_unlock(&mutx);
	
	std::cout<<"conect"<<std::endl;
    }
  }
  catch ( SocketException& e ){
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
  }

  return 0;
}
	
void * handle_clnt(void * arg)
{	
	ServerSocket clnt_sock=*((ServerSocket*)arg);
	try
        {
        	while ( true )
        	{
			std::string data;
			clnt_sock >> data;
			
			std::cout<< data<<std::endl;
			clnt_sock <<  data;
		}
	}
	catch(SocketException& ){}
	
	pthread_mutex_lock(&mutx);
	count--;
	pthread_mutex_unlock(&mutx);
	close()
	return NULL;
}


