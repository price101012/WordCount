#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
   
    FILE *fp;
    int count = 0;  
    if ((fp=fopen(argv[2], "r"))==NULL)
    {
        puts("��������Ҫ�����ı�!\n");
        return 0;
    }
    if (argv[1][1]=='w') 
    {
        char ars[1024];
        while (fscanf(fp, "%s", ars)!=EOF)
        {
            count ++;
            for (int i=1; i < strlen(ars) - 1; i ++)
            	if(ars[i-1]!=','&&ars[i]==','&&ars[i+1]!=',') 
                    count++;
        }
        printf("������=%d\n", count);
    }
    else if (argv[1][1]=='c') 
    {
        char kato;
        while ((kato = fgetc(fp)) != EOF) count++;
        printf("�ַ���=%d", count);
    }
    fclose(fp);
    return 0;
}


