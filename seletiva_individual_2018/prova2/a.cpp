#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 55;
const int inf = 100;

struct Card {
    int rank, suit, id;

    Card() {};
    Card(int _rank, int _suit, int _id) : rank(_rank), suit(_suit), id(_id) {};
};

int n;
int freq[5];
int pos[N]; // índice: i-ésima carta em card, valor: posição dela no deck
//Card card[N]; // índice: i-ésima carta a ser usada, valor: a carta
Card deck[N]; // índice: posição no deck, valor: a carta

bool check(int s) {
    int pat = 0, count = (deck[0].suit == s ? 1 : 0);
    //printf("count %d\n", count);
    for (int i = 1; i < n; i++) {
        if (deck[i].suit == s) 
            count++;
        else 
            count = 0;
        if (deck[i].suit == s && deck[i - 1].suit == s) {
            if (!pat) {
                if (deck[i].rank > deck[i - 1].rank) {
                    pat = 1;
                } else {
                    pat = -1;
                }
            } else {
                if (deck[i].rank > deck[i - 1].rank && pat == -1) 
                    return false;
                if (deck[i].rank < deck[i - 1].rank && pat == 1) 
                    return false;
            }
        } 
        if (count == freq[s]) 
            return true;
        //printf("i %d count %d freq[%d] %d\n", i, count, s, freq[s]);
    }
    if (count < freq[s]) 
        return false;
    return true;
}

bool ok() {
    //printf("Em ok\n");
    bool ans = true;
    for (int i = 0; i < 4; i++) {
        if (freq[i]) {
      //      printf("i %d : %d\n", i, check(i));
            ans &= check(i);
        }
    }
    return ans;
}

int move(int prev, int next) {
    if (prev == next) 
        return 0;
    Card c = deck[prev];
    if (next > prev) {
        for (int i = prev + 1; i <= next; i++) {
            pos[deck[i].id]--;
            deck[i - 1] = deck[i];
        }  
    } else {
        for (int i = prev - 1; i >= next; i--) {
            pos[deck[i].id]++;
            deck[i + 1] = deck[i];
        }
    }
    deck[next] = c;
    pos[c.id] = next;
    return 1;
}

void print_deck() {
    for (int i = 0; i < n; i++) {
        if (deck[i].rank <= 9) 
            printf("%d", deck[i].rank);
        else {
            int r = deck[i].rank;
            if (r == 10) printf("T");
            else if (r == 11) printf("J");
            else if (r == 12) printf("Q");
            else if (r == 13) printf("K");
            else printf("A");
        }
        int s = deck[i].suit;
        if (s == 0) printf("s");
        else if (s == 1) printf("h");
        else if (s == 2) printf("d");
        else printf("c");
        printf(" ");
    }
    printf("\n");
}

int sort_deck(int c) {
    if (c == n) { 
        //printf("caso base c\n", c);
        //print_deck();
        //if (ok())
          //  return 0;
        return inf;
    }
    int prev = pos[c];
    int cost = inf;
    int aux = 0;
    //printf("c %d\n", c);
    for (int next = 0; next < n; next++) {
        //printf("next %d\ndeck atual: ", next);
       // print_deck();
        //aux = move(prev, next);
        //printf("next %d deck após mov(%d -> %d): ", next, prev, next);
       // print_deck();
        cost = min(cost, aux + sort_deck(c + 1));
        //move(next, prev);
        //printf("next %d deck antes do mov, fazendo %d -> %d ", next, next, prev);
       // print_deck();
    }
    //printf("\n");
    return cost;
}

int find_rank(char r) {
    if (r >= '2' && r <= '9') 
        return r - '0';
    if (r == 'T') 
        return 10;
    if (r == 'J')
        return 11;
    if (r == 'Q') 
        return 12;
    if (r == 'K')
        return 13;
    return 14; // ace
}

int find_suit(char s) {
    if (s == 's') 
        return 0;
    if (s == 'h')
        return 1;
    if (s == 'd') 
        return 2;
    return 3;
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        char r, s;
        scanf(" %c %c", &r, &s);
        int rank = find_rank(r);
        int suit = find_suit(s);
        //printf("%c%c -> %d%d\n", r, s, rank, suit);
        //card[i] = Card(rank, suit);
        deck[i] = Card(rank, suit, i);
        pos[i] = i;
    }

    for (int i = 0; i < n; i++) 
        freq[deck[i].suit]++;
    printf("%d\n", sort_deck(0));
}

