
#include <iostream>

class DBServer {

	private: 
		DBServer();
		DBServer(const DBServer&);
		DBServer& operator=(const DBServer&);
		~DBServer();

	public:
		static DBServer* getInstance();
	
	private:
		static DBServer* instance;

};

DBServer* DBServer::instance = new DBServer();

DBServer::DBServer() {
}

DBServer::~DBServer() {
	std::cout << "destroy DBServer" << std::endl;
	//delete instance;
}

DBServer::DBServer(const DBServer&) {
}

DBServer& DBServer::operator=(const DBServer&) {
}

DBServer* DBServer::getInstance() { 
	return instance;
}


int main(int argc, char** argv) {
	DBServer* dbs_ = DBServer::getInstance();
	//delete dbs_;	

}
