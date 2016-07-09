#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize


int n;
vector<psi> ans;

int main () {
    scanf ("%d", &n);
    multiset<int> heap;
    int a;
    char s[15];
    for (int i = 0; i < n; i++) {
        scanf (" %s", s);
        if (strcmp (s, "insert") == 0) {
            scanf ("%d", &a);
            heap.insert (a);
            ans.pb (psi (string (s), a));
        } else if (strcmp (s, "getMin") == 0) {
            scanf ("%d", &a);
            multiset<int>::iterator it;
            bool equal = false;;
            for (it = heap.begin (); it != heap.end () && *it <= a; it++) {
                if (*it == a) {
                    equal = true;
                    break;
                }
                ans.pb (psi ("removeMin", 0));
            }
            heap.erase (heap.begin (), it);
            if (!equal) {
                heap.insert (a);
                ans.pb (psi ("insert", a));
            }
            ans.pb (psi (string (s), a));
        } else {
            if (heap.size () != 0) 
                heap.erase (heap.begin ());
            else {
                ans.pb (psi ("insert", 1));
            }
            ans.pb (psi ("removeMin", 0));
        }
    }

    int tam = ans.size ();
    printf ("%d\n", tam);
    for (int i = 0; i < ans.size (); i++) {
        string aux = "removeMin";
        if (aux.compare (ans[i].ff) == 0) {
            cout << ans[i].ff << "\n";
        } else {
            cout << ans[i].ff << " " << ans[i].ss << "\n";
        }
    }
}
/* solucao usando priority_queue
int n;
vector<psi> ans;

int main () {
    ios::sync_with_stdio (false);
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq;
    string s;
    int a;
    while (n--) {
        cin >> s;
        if (s != "removeMin")
            cin >> a;
        if (s == "insert") {
            pq.push (a);
            ans.pb (mp (s, a));
        } else if (s == "removeMin") {
            if (pq.empty ()) {
                pq.push (1);
                ans.pb (mp ("insert", 1));
            }
            ans.pb (mp (s, 0));
            pq.pop ();
        } else {
            while (!pq.empty () && pq.top () < a) {
                ans.pb (mp ("removeMin", 0));
                pq.pop ();
            }
            if (pq.empty () || pq.top () > a) {
                ans.pb (mp ("insert", a));
                pq.push (a);
            }
            ans.pb (mp (s, a));
        }
    }

    cout << ans.size () << "\n";
    for (int i = 0; i < ans.size (); i++) {
        cout << ans[i].ff << " ";
        if (ans[i].ff != "removeMin")
            cout << ans[i].ss;
        cout << "\n";
    }
}
*/
