#include <stdlib.h>
#include <stdio.h>
#include "qh_vector.h"


int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��

	qh::vector<int> num_vect(16, 0);
    num_vect.push_back(1);
    printf("Hello\n");

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

