#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
	int ch, count = 1;
	FILE* fp;
	if ((fp = fopen(argv[2], "r")) == NULL)
    {
		printf("Document %s open failed\n", argv[2]);
		exit(1);
	}
	if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-C") == 0)
    {
		count = 0;
		while ((ch = getc(fp)) != EOF)
        {
			count++;
		}
		printf("The total %d characters\n", count);
	}
	else if (strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "-W") == 0)
    {
		while ((ch = getc(fp)) != EOF)
        {
			if ((ch == ' ') || (ch == ',') || (ch == '.') || (ch == ';'))
            {
				count++;
			}
		}
		printf("The total %d words\n", count);
	}
	else
    {
		printf("USEAGE:\nwordcount [parameter] [input_file_name]\n[parameter]:-c计算字母数；-w计算单词数\n[input_file_name]：文件名");
	}
	fclose(fp);
	return 0;
}
