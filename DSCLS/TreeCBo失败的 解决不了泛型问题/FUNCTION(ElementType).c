#include <stdio.h>
#include <stdlib.h>

#define FUNCTION(ElementType)

ElementType function_##ElementType(ElementType a, ElementType b) {
	ElementType c = a + b;
	return c;
}

FUNCTION(int)
FUNCTION(double)

int main() {
	printf("%d\n", function_int(1, 2));
	printf("%f\n", function_double(3.6, 4.4));
	system("pause");
}

���ߣ�lllllustrator
���ӣ�https ://www.zhihu.com/question/57087067/answer/151582611
��Դ��֪��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������