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

作者：lllllustrator
链接：https ://www.zhihu.com/question/57087067/answer/151582611
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。