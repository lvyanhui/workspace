#include <iostream>
#include <thread>

class Work;

class State {
public:
	virtual void operation(Work * work) = 0;	
};

class WaitingState : public State {
	void operation(Work* work);
};

class WakeupState : public State {
	void operation(Work* work);
};

class GuideState : public State {
	void operation(Work* work);
};

class ServingState : public State {
	void operation(Work* work);
};

class Work {
		
	public:
		enum StateType{
			ST_WAKEUP = 0,
			ST_GUIDING,
			ST_WAITFORSERVER,
			ST_SERVING,
		};	

	public:
		Work(){state_ = NULL;}

	public:
		void set_value(int value) {this->value_ = value;}
		int get_value() const {return this->value_;}
		
		void set_state(State* st) {
			if(state_ != NULL)   
				delete state_;

			this->state_ = st;
		}

		void operation() {
			state_->operation(this);	
		}

	private:
		int value_;
		State* state_;
};


void GuideState::operation(Work* work) {
	if(work->get_value() == 10)	
		work->set_state(new WaitingState());
	else 
		std::cout << "state: guide"<< std::endl;
}	

void WakeupState::operation(Work* work) {
	if(work->get_value() == 30)	
		work->set_state(new GuideState());
	else 
		std::cout << "state: wakeup"<< std::endl;
}

void ServingState::operation(Work* work) {
	if(work->get_value() == 40)	
		work->set_state(new WaitingState());
	else 
		std::cout << "state: serving"<< std::endl;
}	

void WaitingState::operation(Work* work) {
	if(work->get_value() == 20)	
		work->set_state(new ServingState());
	else 
		std::cout << "state: waiting"<< std::endl;
}	

int main(int argc, char** argv) {
	Work work;
	work.set_state(new WaitingState());

	for(int i=0; i<50; i+=5) {
		work.set_value(i);
		std::this_thread::sleep_for(std::chrono::seconds(1));
		work.operation();
	}
}
