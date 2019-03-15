#include "dispatch.h"
#include <thread>
#include <unistd.h>

void randomEvent() {
	srand((unsigned)time(NULL));
	Dispatch& dis = Dispatch::instance();
	do {
		EventData *ed = dis.newED();
		ed->ev = rand()%5;
		ed->op = rand()%10;
		ed->data = rand() % 9999;
		dis.assign(ed);
		sleep(1);
	}while(true);
}

int main() {
	Dispatch& dis = Dispatch::instance();
	std::thread t(randomEvent);

	EventData *ed = nullptr;
	while(ed = dis.get()) {
		dis.dispatch(ed);
		dis.freeED(ed);
	}

	return 0 ;
}	

