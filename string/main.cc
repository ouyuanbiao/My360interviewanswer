#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qh_string.h"


int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
	char* test[5] = {"Just for Test!","Construction","Assignment","Destruction",""};
	printf("---------test for construction method----------\n");
    qh::string a(test[0]);
	if(strcmp(a.data(),test[0]) && a.size() == strlen(test[0]))
		printf("a test is OK: %s,%d\n", a.c_str(), a.size());
	qh::string aa(test[4]);
	if(aa.size() == 0)
		printf("aa test is OK: %s,%d\n", aa.c_str(), aa.size());

	qh::string b(test[1],strlen(test[1]));
    if(strcmp(b.data(),test[1]) && b.size() == strlen(test[1]))
		printf("b test is OK: %s,%d\n", b.c_str(), b.size());
    qh::string c(test[1], 2*strlen(test[1]));
    if(strcmp(c.data(),test[1]) && c.size() == strlen(test[1]))
		printf("c test is OK: %s,%d\n", c.c_str(), c.size());
	qh::string d(test[1], 0);
	if(d.c_str()==NULL && d.size() == 0)
		printf("d test is OK: %s,%d\n", d.c_str(), d.size());

    qh::string e(b);
    if(strcmp(e.data(),b.data()) && e.size() == b.size())
		printf("e test is OK: %s,%d\n", e.data(), e.size());

    
    printf("---------test for assign operation----------\n");
    qh::string f = b;
    if(strcmp(f.data(),test[1]) && f.size() == b.size())
		printf("f=b test is OK: %s,%d\n", f.c_str(), f.size());
    f = f;
    if(strcmp(f.data(),test[1]) && f.size() == b.size())
		printf("f=f test is OK: %s,%d\n", f.c_str(), f.size());
	f = aa;
    if(f.size() == 0)
		printf("f=aa test is OK: %s,%d\n", f.c_str(), f.size());

	f = a;
    int index = 0;
    int end = f.size() - 1;
	bool indextest = true;
	for(index = 0;index<=end;index++){
		if(*f[index] != test[0][index])
			indextest = false;
	}
	if(indextest)
		printf("f[] index test is OK: %s,%d\n",f.data(),f.size());
    
    const char* c_str = f.c_str(); 
    printf("f.c_str() = %s\n", c_str);

    //----------------test for destruction function---------------
	printf("---------test for destruction function----------\n");
    qh::string* ps1 = new qh::string(test[3]);
    delete ps1;
    ps1 = NULL;

    qh::string* ps2 = new qh::string();
    delete ps2;
    ps2 = NULL;

	printf("Destruction test is OK!\n");



#ifdef WIN32
    system("pause");
#endif

	return 0;
}

