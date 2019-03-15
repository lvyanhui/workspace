#include <iostream>
#include <vector>

#define M_PI 3.1415926

class SearchOrientations{
	public:
		SearchOrientations(float visualradian, float firstradian, float lradian, float rradian) {
			this->first_radian_ = firstradian;	
			this->camera_visual_radian_ = visualradian;
			init_radians(lradian, rradian);
		}

		~SearchOrientations(){}

        void show_all_orientations() {
			std::vector<float>::iterator it;
			for(it = radians_.begin(); it!=radians_.end(); it++) {
				//logi("radians: %f", *it);	
				std::cout<<"radians: " << *it << std::endl;	
			}
		}


	private:
		
		int move_times(float max_radian) {
			if(max_radian/this->camera_visual_radian_ < 0.51)  //todo:...
				return 0;
			else
				return (int)((max_radian/this->camera_visual_radian_)+0.49);
		}
	
		float get_valid_radian(float radian) {
			while(radian > M_PI) {
				radian -= 2*M_PI;	
			}
			
			while(radian < -M_PI) {
				radian += 2*M_PI;	
			}
			return radian;
		}
		
		float fun(float radian_to_move, float& cur_radian, bool left_rotate){
			int mix = (left_rotate ? 1:-1);

			int times = move_times(radian_to_move);
			float every_move_radian = (radian_to_move-this->camera_visual_radian_/2)/times;
			
			int count = 0;
			while(count < times) {
				if(count == times-1) {
					cur_radian = cur_radian + (mix) * (every_move_radian - (this->camera_visual_radian_-every_move_radian)/2);
					//cur_radian = first_radian_+lradian-this->camera_visual_radian/2;
				} else if(count == 0) 
					cur_radian = cur_radian + (mix) * (this->camera_visual_radian_ + every_move_radian)/2;
				else
					cur_radian = cur_radian + (mix) * every_move_radian;
					
				this->radians_.push_back(get_valid_radian(cur_radian));	
				count++;
			}

			return cur_radian;
		} 
	
		void init_radians(float lradian, float rradian) {
			this->radians_.clear();
			float cur_radian = first_radian_;
			this->radians_.push_back(cur_radian);
			
			std::cout << "size " << this->radians_.size() << std::endl;
			float radian_to_move = lradian;
			fun(radian_to_move, cur_radian, true);
			
			std::cout << "size " << this->radians_.size() << std::endl;
			radian_to_move = rradian + lradian - this->camera_visual_radian_/2;
			fun(radian_to_move, cur_radian, false);

			std::cout << "size " << this->radians_.size() << std::endl;
			if(cur_radian > this->first_radian_) {
				this->radians_.push_back(this->first_radian_);
			} else {
				radian_to_move = rradian ;
				fun(radian_to_move, cur_radian, true);
			}
			std::cout << "size " << this->radians_.size() << std::endl;
		}

	private:
		float camera_visual_angle_;
		std::vector<float > radians_;
		float first_radian_; 
		float camera_visual_radian_;
};


int main(int argc, char** argv) {
	SearchOrientations search(1.047, 0.3, 0.32, 1.0);
	search.show_all_orientations();
}
