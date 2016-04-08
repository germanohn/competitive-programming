#include <bits/stdc++.h>
#define price first
#define share second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t, n;
char order[100], pal[100];
char c;

int main () {
    // bid no topo tera o maior price
    // ask no topo tera o menor price
    priority_queue<pii> buy, sell;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        int share, price, stock;
        for (int i = 0; i < n; i++) {
            stock = 0;
            scanf (" %s %d %s %s %d", order, &share, pal, pal, &price);
            if (order[0] == 'b') {
                buy.push (pii (price, share));   
            } else {
                sell.push (pii (-price, share));
            }
            pii bid = pii (0, 0), ask = pii (0, 0);
            int tamb = buy.size (), tams = sell.size ();
            printf ("buy.size %d sell.size %d\n", tamb, tams);
            if (buy.size () > 0) 
                bid = buy.top (), buy.pop ();
            if (sell.size () > 0)
                ask = sell.top (), sell.pop ();
            ask.price = -ask.price;
            int transf = 0;
            if (bid.price >= ask.price) {
                printf ("oi\n");
                transf = min (bid.share, ask.share);
                bid.share -= transf;
                ask.share -= transf;
                stock = ask.price; 
                if (bid.share > 0) buy.push (pii (bid.price, bid.share));
                if (ask.share > 0) sell.push (pii (-ask.price, ask.share));
            }
            if (buy.size () > 0) 
                printf ("%d ", buy.top ().price);
            else 
                printf ("- ");
            if (sell.size () > 0) 
                printf ("%d ", -sell.top ().price);
            else 
                printf ("- ");
            if (!transf) 
                printf ("-\n");
            else 
                printf ("%d\n", stock);
        }
    }
}

