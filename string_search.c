#include <stdio.h>
#include <string.h>
char *my_strstr(const char* dic,const char* needle)
{
    if (dic==NULL||needle==NULL){
        return NULL;
    }
    if (*needle=='\0')
    return (char*)dic;
    while (*dic!='\0')
    {
        const char*start_dic=dic;
        while (*dic==*needle&&*dic!='\0'&&*needle!='\0')
        {
            needle++;
            dic++;
        }
        if (*needle=='\0')
        return (char*)start_dic;
        dic=start_dic+1;
    }
    return 0;
}