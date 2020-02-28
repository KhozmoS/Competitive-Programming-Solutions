#include <bits/stdc++.h>

using namespace std;

int F[10];

void cuenta(int x){
    if(x < 10){
        F[0]++;
        F[x]++;
    }
    else{
        while(x > 0){
            F[x % 10]++;
            x /= 10;
        }
    }
}

int main()
{
    int h1, m1, s1, h2, m2, s2;
    while(scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2) != EOF){

        fill(F, F + 10, 0);

        int t1 = h1 * 3600 + m1 * 60 + s1;
        int t2 = h2 * 3600 + m2 * 60 + s2;
        if(t1 > t2){
            swap(h1, h2);
            swap(m1, m2);
            swap(s1, s2);
        }

        while(true){
            while(true){
                while(true){
                    F[s1 / 10]++;F[s1 % 10]++;
                    F[m1 / 10]++;F[m1 % 10]++;
                    F[h1 / 10]++;F[h1 % 10]++;
                    if(h1 == h2 && m1 == m2) {
                        if(s1 < s2)
                            s1++;
                        else
                            break;
                    }
                    else if(s1 < 59)
                        s1++;
                    else{
                        s1 = 0;
                        break;
                    }
                }
                if(h1 == h2) {
                    if(m1 < m2)
                        m1++;
                    else
                        break;
                }
                else if(m1 < 59)
                    m1++;
                else{
                    m1 = 0;
                    break;
                }
            }
            if(h1 < h2)
                h1++;
            else
                break;
        }

        printf("%d", F[0]);
        for(int i = 1; i < 10; i++)
            printf(" %d", F[i]);
        printf("\n");
    }

    return 0;
}
