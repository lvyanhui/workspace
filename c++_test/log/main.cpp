#include <stdio.h>

#define LOG(level, format, ...) \
do { \
	fprintf(stderr, "[%s|%s@%s,%d] " format "/n", \
			level, __func__, __FILE__, __LINE__, ##__VA_ARGS__ ); \
} while (0)

#define INFO "info"
int main()
{
	LOG("info", "a=%d", 10);
	return 0;
}
