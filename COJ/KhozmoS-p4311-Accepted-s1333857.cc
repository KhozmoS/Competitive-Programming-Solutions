#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll mcd(ll x, ll y){
    return __gcd(x, y);
}

struct Fracc{
    ll p, q;
    Fracc(ll p = 0, ll q = 1): p(p), q(q) { norm(); }
    void norm(){
        ll a = mcd(p, q);
        if(a) p /= a, q /= a;
        else q = 1;
        if (q < 0) q = -q, p = -p;}
    Fracc operator + (const Fracc& o) const{
        ll a = mcd(q, o.q);
        return Fracc(p * (o.q/a) + o.p*(q/a), q*(o.q/a));
    }
    Fracc operator - (const Fracc& o) const{
        ll a = mcd(q, o.q);
        return Fracc(p * (o.q/a) - o.p*(q/a), q*(o.q/a));
    }
    Fracc operator * (Fracc o){
        ll a = mcd(q, o.p), b = mcd(o.q, p);
        return Fracc((p/b) * (o.p/a), (q/a) * (o.q/b));
    }
    Fracc operator / (Fracc o){
        ll a = mcd(q, o.q), b = mcd(o.p, p);
        return Fracc((p/b)*(o.q/a), (q/a)*(o.p/b));
    }
    bool operator < (const Fracc &o) const{return p*o.q < o.p*q;}
    bool operator == (Fracc o) const{return p == o.p && q == o.q;}
};


struct Poll{
    Fracc x, y;
    Poll(Fracc xx, Fracc yy){
        x = xx;
        y = yy;
    }
    Poll(){
        x = Fracc();
        y = Fracc();
    }

    Poll operator + (const Poll &p) const{return {x + p.x, y + p.y};}
    Poll operator - (const Poll &p) const{return {x - p.x, y - p.y};}


    bool operator == (const Poll &p1) const{
        return p1.x == x && p1.y == y;
    }
};

Fracc cross(Poll a, Poll b) {return a.x * b.y - a.y * b.x;} // |a|*|b| * sin(&)
Fracc dot(Poll a, Poll b) {return a.x * b.x + a.y * b.y;} // |a|*|b| * cos(&)

const ll MAX = 1e6 + 5;
const ull B = 1e9 + 7;

ull h1X[MAX], h1Y[MAX], pot[MAX];
ull h2X[MAX], h2Y[MAX];

void built1(vector<Fracc> &T){
    pot[0] = 1;
    h1X[0] = T[0].p;
    h1Y[0] = T[0].q;
    for(ll i = 1; i < T.size(); i++){
        pot[i] = pot[i-1]*B;
        h1X[i] = h1X[i-1]*B + ull(T[i].p);
        h1Y[i] = h1Y[i-1]*B + ull(T[i].q);
    }
}

void built2(vector<Fracc> &T){
    h2X[0] = T[0].p;
    h2Y[0] = T[0].q;
    for(ll i = 1; i < T.size(); i++){
        h2X[i] = h2X[i-1]*B + ull(T[i].p);
        h2Y[i] = h2Y[i-1]*B + ull(T[i].q);
    }
}

pair<ull, ull> hashe1(ll a, ll b){
    if(a == 0) return make_pair(h1X[b], h1Y[b]);
    ll e = b - a + 1;
    return make_pair(h1X[b] - h1X[a - 1]*pot[e], h1Y[b] - h1Y[a - 1]*pot[e]);
}

pair<ull, ull> hashe2(ll a, ll b){
    if(a == 0) return make_pair(h2X[b], h2Y[b]);
    ll e = b - a + 1;
    return make_pair(h2X[b] - h2X[a - 1]*pot[e], h2Y[b] - h2Y[a - 1]*pot[e]);
}

Poll ptoMedio(Poll a, Poll b){
    return Poll( (a.x + b.x)/Fracc(2) , (a.y + b.y)/Fracc(2) );
}

Fracc anguloEntre3Puntos(Poll a, Poll o, Poll b){
    Poll oa = a - o, ob = b - o;
    return Fracc(cross(oa, ob).p, dot(oa, ob).p);
}

Fracc sq(Fracc x){
    return x*x;
}

Fracc distance(Poll a, Poll b){
    return sq(a.x - b.x) + sq(a.y - b.y);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >>T;

    while(T--){
        int Q; cin >>Q;
        int sol = 0, scont = 0;

        for(int q = 1; q <= Q; q++){
            ll N; cin >>N;

            vector<Poll> aux;

            for(ll i = 1; i <= N; i++){
                ll x, y; cin >>x >>y;
                aux.push_back( Poll(Fracc(x), Fracc(y)) );
            }

            aux.push_back(aux[0]);

            vector<Poll> pol;

            for(ll i = 0; i < aux.size() - 1; i++){
                pol.push_back(aux[i]);
                pol.push_back(ptoMedio(aux[i], aux[i+1]));
            }

            pol.push_back(aux[0]);

            vector<Fracc> lados;
            vector<Fracc> angs;

            for(ll i = 0; i < pol.size() - 1; i++){
                lados.push_back( distance(pol[i], pol[i+1]) );
            }

            ll NA = lados.size();

            for(ll i = 0; i < NA; i++){
                lados.push_back(lados[i]);
            }

            built1(lados);
            reverse(lados.begin(), lados.end());
            built2(lados);

            ll tam = NA / 2;
            ll cont = 0;
            for(ll i = 0; i < NA; i++){
                pair<ull, ull> h1 = hashe1(i, i + tam - 1);
                pair<ull, ull> h2 = hashe2(N - i + tam, N - i + NA-1);
                if(h1 == h2) cont++;
            }

            cont /= 2;

            if(cont > sol){
                scont = 1;
                sol = cont;
            }else if(cont == sol){
                scont++;
            }

            cout <<cont <<"\n";
        }
        cout <<sol <<" " <<scont <<"\n";
    }
    return 0;
}