#include "blockQueue.h"

class Event {
	public:
		virtual ~Event() {
		}

		virtual int operate(int op, int data) = 0;
	private:

};

class EmptyEvent : public Event {
	public:
		const static int EVENT_VALUE = 0;
		virtual int operate(int op, int data) {
			std::cout << "EmptyEvent op = " << op << ", data = " << data << std::endl;
			return 0;
		}
	private:

};

class PrintEvent : public Event {
	public:
		const static int EVENT_VALUE = 1;
		virtual int operate(int op, int data) {
			std::cout << "PrintEvent op = " << op << ", data = " << data << std::endl;
			return 0;
		}
	private:
};

class TestEvent : public Event {
	public:
		const static int EVENT_VALUE = 2;
		virtual int operate(int op, int data) {
			std::cout << "TestEvent op = " << op << ", data = " << data << std::endl;
			return 0;
		}
	private:
};

class QuitEvent : public Event {
	public:
		const static int EVENT_VALUE = 3;
		virtual int operate(int op, int data) {
			std::cout << "QuitEvent op = " << op << ", data = " << data<< std::endl;
			return 0;
		}
	private:
};

typedef struct EventData_ {
	int ev;
	int op;
	int data;
}EventData;

class EventFactory {
public:
	static EventFactory *instance() {
		static EventFactory * g_ef = nullptr;
		if(nullptr == g_ef) {
			g_ef = new EventFactory;	
		}
		return g_ef;
	}

	Event* createEvent(int ev) {
		switch(ev) {
			case PrintEvent::EVENT_VALUE:
				return new PrintEvent;

			case TestEvent::EVENT_VALUE:
				return new TestEvent;
			
			case QuitEvent::EVENT_VALUE:
				return new QuitEvent;

			default:
				return new EmptyEvent;
		}	
	}
};
