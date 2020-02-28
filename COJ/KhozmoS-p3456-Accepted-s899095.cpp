#include <bits/stdc++.h>

using namespace std;
const int MAXN = 150;
int freq[31];
int pos ,t;
char c;
char q[MAXN];
char p[MAXN];
int main()
{

      scanf("%d", &t);
      scanf("%c", &c);
    while(t--){
    //memset ( freq , 0 , sizeof(freq));
     scanf("%[^\n]", p);scanf("%c", &c);
     scanf("%[^\n]", q);scanf("%c", &c);
    int tq = strlen(q);
    int tp = strlen(p);
     for(int i = 0 ; i < tq ; i++)
     {
         if(q[i] != ' ')
         {
            freq[q[i] - 'a']++;
         }
     }
      for(int i = 0 ; i < tp ; i++)
     {
         if(p[i] != ' ')
         {
            freq[p[i] - 'a']--;
         }
     }
     bool flag = false;
     for(int i = 0 ; i < 31 ; i++)
     {
         if(freq[i] != 0)
           flag = true;
           freq[i] = 0;
     }
     /*for(int i = 0 ; i < 31 ; i ++)
     {
         printf("%d\n",freq[i]);
     }*/
     if(flag)
       printf("no\n");
     else
        printf("yes\n");
    }
    return 0;
}
