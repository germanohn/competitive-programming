#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;

int t;
int freq[10];
char s[N];

int main () {
    scanf(" %d", &t);
    while (t--) {
        for (int i = 0; i < 10; i++) 
            freq[i] = 0;
        scanf(" %s", s);
        int len = strlen(s);

        if (len >= 21) {
            for (int i = 9; i >= 0; i--) {
                printf("%d%d", i, i);
            }
            printf("\n");
        } else {
            int st = len;
            for (int i = 0; s[i] != 0; i++) {
                int a = s[i] - '0';
                freq[a]++;
                if (freq[a] == 3) {
                    st = i;
                    break;
                }
            }

            if (st == len) {
                printf("%s\n", s);
            } else {
                bool ok = false;
                for (int i = st; !ok && i >= 0; i--) {
                    int cur = s[i] - '0';
                    int sub = -1;
                    for (int j = cur - 1; j >= 0; j--) {
                        if (freq[j] < 2) {
                            if (cur == 1 && !i) 
                                continue;
                            sub = j;
                            break;
                        }
                    }

                    if (sub == -1) {
                        //printf("cur %d i %d freq[cur] %d\n", cur, i, freq[cur]);
                        freq[cur]--;
                    } else {
                        ok = true;
                        s[i] = sub + '0';
                        freq[sub]++;
                        freq[cur]--;
                        int nx = 9;
                        for (int j = i + 1; j < len; j++) {
                            while (freq[nx] == 2) 
                                nx--;
                            freq[nx]++;
                           // printf("nx %d\n", nx);
                            s[j] = nx + '0';
                            //printf("j %d s[j] %c s %s\n", j, s[j], s);
                        }
                    }
                }

                if (ok) printf("%s\n", s);
                else {
                    for (int i = 0; i < 10; i++)
                        freq[i] = 0;
                    int nx = 9;
                    for (int i = 0; i < len - 1; i++) {
                        while (freq[nx] == 2) 
                            nx--;
                        freq[nx]++;
                        printf("%d", nx);
                    }
                    printf("\n");
                }
            }
        }
    }
}

