#include <iostream>

class ConsultService {
	public:
		ConsultService() {
			this->person_id_ = -1;	
		}
		
		virtual ~ConsultService() {
		}

		//virtual void click_listen_button() = 0;
	private:
		int person_id_;
};

class SingleCousultService : public ConsultService {
	public:
		SingleConsultService();
		virtual ~SingleConsultService();

		/*virtual void click_listen_button() {
			//consult_->start_listen();
		}*/
};

class ContinuousCousultService : public ConsultService {
	public:
		ContinuousConsultService();
		virtual ~ContinuousConsultService();

		/*virtual void click_listen_button() {
			//stop speak;
			//consult_->stop_speak();
		}*/

};

