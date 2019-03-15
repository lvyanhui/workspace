#include <ratio>
#include <chrono>
#include <iostream>

std::time_t getTimeStamp()
{
	std::chrono::time_point<std::chrono::system_clock,std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
	auto tmp=std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
	std::time_t timestamp = tmp.count();
	//std::time_t timestamp = std::chrono::system_clock::to_time_t(tp);
	return timestamp;
}
/*
   std::tm* gettm(int64 timestamp)
   {
   int64 milli = timestamp+ (int64)8*60*60*1000;//此处转化为东八区北京时间，如果是其它时区需要按需求修改
   auto mTime = std::chrono::milliseconds(milli);
   auto tp=std::chrono::time_point<std::chrono::system_clock,std::chrono::milliseconds>(mTime);
   auto tt = std::chrono::system_clock::to_time_t(tp);
   std::tm* now = std::gmtime(&tt);
   printf("%4d年%02d月%02d日 %02d:%02d:%02d\n",now->tm_year+1900,now->tm_mon+1,now->tm_mday,now->tm_hour,now->tm_min,now->tm_sec);
   return now;
   }*/


int main ()
{
	using namespace std::chrono;
	typedef duration<int,std::ratio<60*60*24>> days_type;
	time_point<system_clock,days_type> today = time_point_cast<days_type>(system_clock::now());
	std::cout << today.time_since_epoch().count() << " days since epoch" << std::endl;

	std::cout<< "time is: " << getTimeStamp()<< std::endl;

	using namespace std;
	steady_clock::duration d = steady_clock::now().time_since_epoch();
	minutes min = duration_cast<minutes>(d);
	seconds sec = duration_cast<seconds>(d);
	milliseconds mil = duration_cast<milliseconds>(d);
	microseconds mic = duration_cast<microseconds>(d);
	nanoseconds nan = duration_cast<nanoseconds>(d);
	cout << min.count() << "分钟" << endl;
	cout << sec.count() << "秒" << endl;
	cout << mil.count() << "毫秒" << endl;
	cout << mic.count() << "微妙" << endl;
	cout << nan.count() << "纳秒" << endl;


	return 0;
}
