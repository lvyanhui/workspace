#include <iostream>
#include <functional>

class A{
	public:
		A(){}
		~A(){}

		int update(std::string text){
			std::cout << "A::update " << text << std::endl;
			return -1;
		}
};

class B{
	public:
		B(){}
		~B(){}

		void register_update(std::function<int(std::string) > cb){update_cb_ = cb;}

		void test(){
			std::cout << update_cb_("good") << std::endl;	
		}
	private:
		std::function<int(std::string ) > update_cb_;
};

int main(int argc, char** agrv) {
	A a;
	B b;
	b.register_update(std::bind(&A::update, &a, std::placeholders::_1));
    b.test();
}
