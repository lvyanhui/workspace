#pragma once
#include "blockQueue.h"
#include "event.h"

class Dispatch{
	public:
		static Dispatch& instance() {
			static Dispatch g_dis;
			return g_dis;
		}
		~Dispatch() {
		}

	void assign(EventData *e) {
		bq_.push(e);	
	}

	EventData *get(){
		return bq_.pop();	
	}

	int dispatch(EventData* ed) {
		Event* e = EventFactory::instance()->createEvent(ed->ev);
		int ret = e->operate(ed->op, ed->data);
		delete e;
		return ret;
	}

	EventData *newED() {
		return new EventData;	
	}

	void freeED(EventData *ed) {
		delete ed;	
	}

private:
	Dispatch():bq_() {}

private:
	BlockQueue<EventData* > bq_;
};	
