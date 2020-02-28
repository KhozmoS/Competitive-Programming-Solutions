#include <bits/stdc++.h>

using namespace std;

int deg = 0;
int last = 0;

int x = 10;
int y = 900;

void mov(){
    assert(x >= 0 && x < 5000 && y >= 0 && y < 1000);

    if(last == 0){
        if(deg == 0){
            x++;
        }else if(deg == 60){
            x++;
        }else if(deg == 120){
            assert(0);
        }else if(deg == 180){
            assert(0);
        }else if(deg == 240){
            y++;
        }else if(deg == 300){
            x++;
            y++;
        }
    }

    if(last == 60){
        if(deg == 0){
            x++;
            y--;
        }else if(deg == 60){
            x++;
            y--;
        }else if(deg == 120){
            y--;
        }else if(deg == 180){
            y--;
        }else if(deg == 240){
            assert(0);
        }else if(deg == 300){
            x++;
        }
    }


    if(last == 120){
        if(deg == 0){
            y--;
        }else if(deg == 60){
            y--;
        }else if(deg == 120){
            x--;
            y--;
        }else if(deg == 180){
            x--;
            y--;
        }else if(deg == 240){
            x--;
        }else if(deg == 300){
            assert(0);
        }
    }

    if(last == 180){
        if(deg == 0){
            assert(0);
        }else if(deg == 60){
            x--;
        }else if(deg == 120){
            x--;
        }else if(deg == 180){
            x--;
        }else if(deg == 240){
            x--;
            y++;
        }else if(deg == 300){
            y++;
        }
    }

    if(last == 240){
        if(deg == 0){
            assert(0);
        }else if(deg == 60){
            assert(0);
        }else if(deg == 120){
            x--;
        }else if(deg == 180){
            x--;
        }else if(deg == 240){
            x--;
            y++;
        }else if(deg == 300){
            y++;
        }
    }

    if(last == 300){
        if(deg == 0){
            x++;
        }else if(deg == 60){
            x++;
        }else if(deg == 120){
            assert(0);
        }else if(deg == 180){
            x--;
        }else if(deg == 240){
            y++;
        }else if(deg == 300){
            x++;
            y++;
        }
    }
}

void b(){
    deg = (60 + deg) % 360;
}
void c(){
    deg = (deg-60+360)%360;
}

char arr[5000][5000];

void a(){
    mov();
    last = deg;

    if(deg == 60 || deg == 240){
        arr[y][x] = '/';
    }
    if(deg == 120 || deg == 300){
        arr[y][x] = '\\';
    }
    if(deg == 0 || deg == 180){
        arr[y][x] = '_';
    }
}

void f(int n){
    if(n == 0){
        a();
    }else{
         f(n - 1);
         b();
         f(n - 1);
         c();
         c();
         f(n - 1);
         b();
         f(n - 1);
    }
}

void show(){


    int y1 = 10001;
    int x1 = 10001;
    int y2 = 0;
    int x2 = 0;


    for(int i = 0; i < 4000; i++){
        for(int j = 0; j < 4000; j++){
            if(arr[i][j] != 0){
                y1 = min(y1, i);
                y2 = max(y2, i);
                x1 = min(x1, j);
                x2 = max(x2, j);
            }
        }

    }
    for(int i = y1; i <= y2; i++){
        for(int j = x1; j <= x2; j++){
            if(!arr[i][j]) cout <<".";
            else cout <<arr[i][j];
        }
        cout <<"\n";
    }

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;

    vector<int> Q;

    while(cin >>n){
        Q.push_back(n);
    }



    for(int i = 0; i < Q.size(); i++){
        x = 10;
        y = 900;
        deg = 0;
        last = 0;
        memset(arr, 0, sizeof arr);
        f(Q[i]);
        show();
        if(i != Q.size() - 1) cout <<" \n";
    }



    return 0;
}
