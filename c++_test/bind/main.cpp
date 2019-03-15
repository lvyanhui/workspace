#include <iostream>
#include <functional>

class A{
	public:
		A(){}
		~A(){}

		void update(std::string text){
			std::cout << "A::update " << text << std::endl;
		}
};

class B{
	public:
		B(){}
		~B(){}

		void register_update(std::function<void(std::string) > cb){update_cb_ = cb;}

		void test(){
			update_cb_("good");	
		}
	private:
		std::function<void(std::string ) > update_cb_;
};

int main(int argc, char** agrv) {
	A a;
	B b;
	b.register_update(std::bind(&A::update, &a, std::placeholders::_1));
    b.test();
}
