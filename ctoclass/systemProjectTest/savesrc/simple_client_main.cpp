#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int main ( int argc, int argv[] )
{
	ClientSocket client_socket ( "localhost", 30010 );
        std::string reply;
	while(1){
	  try
	  {      
	      try
	      {
		std::cin >> reply;
		client_socket<<reply;
		client_socket >> reply;
	      }
	      catch ( SocketException& ) {
		std::cout<< "rise exception" <<std::endl;
	      }
		std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;

	  }
	  catch ( SocketException& e )
	  {
	      std::cout << "Exception was caught:" << e.description() << "\n";
	  }
	}
 	 return 0;
}
