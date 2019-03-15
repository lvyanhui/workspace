#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char** argv) {
	
	std::string speech = "北京。";
	//std::string speech = "";
	std::cout << "out: " << speech <<std::endl;

	int length = speech.length();
	std::cout << "length: " << length <<std::endl;
	
	for(int i=0; i<length; i++)
		printf("%x, %c\n", speech.at(i),speech.at(i));
	

	//if(speech.at(length-3)==0xE3 && speech.at(length-2)==0x80 && speech.at(length-1)==0x82)
	//    speech = speech.substr(0, length-3);
	if(speech.substr(length-3,3) == "。")
	    speech = speech.substr(0, length-3);

	std::cout << "in: " << speech <<std::endl;


}
