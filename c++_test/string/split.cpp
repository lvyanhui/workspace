#include <string>
#include <iostream>
#include <vector>

/*
std::vector<std::string> split(const std::string &str, const std::string &pattern)
{
	std::vector<std::string> res;
	if(str == "")
		return res;
	//在字符串末尾也加入分隔符，方便截取最后一段
	std::string strs = str + pattern;
	size_t pos = strs.find(pattern);

	while(pos != strs.npos)
	{
		std::string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已分割的字符串,在剩下的字符串中进行分割
		strs = strs.substr(pos+1, strs.size());
		pos = strs.find(pattern);
	}

	return res;
}*/

std::vector<int> split(const std::string &str, const std::string &pattern)
{
	std::vector<int> res;
	if(str == "")
		return res;
	//在字符串末尾也加入分隔符，方便截取最后一段
	std::string strs = str + pattern;
	size_t pos = strs.find(pattern);

	while(pos != strs.npos)
	{
		std::string temp = strs.substr(0, pos);
		if(!temp.empty()) 
			res.push_back(std::stoi(temp));
		    
		//去掉已分割的字符串,在剩下的字符串中进行分割
	    strs = strs.substr(pos+1, strs.size());
	    pos = strs.find(pattern);
	}

	return res;
}


int main(int argc, char** argv) {

	std::string str = "1,21,22,23";
	//std::vector<std::string > res;
	std::vector<int > res;
	res = split(str, ",");

	if(res.size()>0) {
		for(int i=0; i<res.size(); i++)
			std::cout << res[i] << std::endl;
	}

}
