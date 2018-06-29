#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e9;

struct camera {
    int p, c, id;
    double z;

    camera() {}
    camera(int pi, double zi, int ci, int idi) : p(pi), z(zi), c(ci), id(idi) {} 

    bool operator< (camera a) const {
        if (p != a.p)
            return p < a.p;
        return z > a.z;
    }
};

struct pii {
    int c, id;

    pii() {}
    pii(int ci, int idi) : c(ci), id(idi) {}

    bool operator< (pii a) const {
        if (c != a.c)
            return c < a.c;
        return id < a.id;
    }
};

set<camera> pareto;
set<pii> optimum;

void status_iterator(auto it) {
    if (it == pareto.begin()) {
        printf("it == pareto.begin()\n");
    } else {
        printf("it != pareto.begin()\n");
    }

    if (it == pareto.end()) {
        printf("it == pareto.end()\n");
    } else {
        printf("it != pareto.end()\n");
        printf("p %d z %lf c %d id %d\n", (*it).p, (*it).z, (*it).c, (*it).id);
    }
}


int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        int n;
        scanf(" %d", &n);
        for (int i = 0; i < n; i++) {
            char action;
            scanf(" %c", &action);
            if (action == 'P') {
                int pi, ci, idi;
                double zi;
                scanf(" %d %lf %d", &pi, &zi, &ci);
                idi = i + 1;

                // insert pareto
                bool in = true;
                if (!pareto.empty()) {
                    auto it = pareto.upper_bound(camera(pi, 200, MAX, MAX));
                    if (camera(MAX, MAX, MAX, MAX) < *it)
                        printf("é menor\n");
                    status_iterator(it);
                    if (it != pareto.begin()) {
                        printf("-> it != pareto.begin()\n");
                        auto pre = prev(it);
                        status_iterator(it);
                        if ((*pre).p == pi && (*pre).z > zi) {
                            in = false;
                            printf("prev.p %d pi %d prev.z %lf zi %lf\n", (*pre).p, pi, (*pre).z, zi);
                        }
                    }
                    if (it != pareto.end()) {
                        printf("-> it != pareto.end()\n");
                        status_iterator(it);
                        auto next = it;
                        if ((*next).z >= zi) {
                            printf("next.p %d pi %d next.z %lf zi %lf\n", (*next).p, pi, (*next).z, zi);
                            in = false;
                        }
                    }
                }
                if (in) {
                    printf("vai inserir %d %lf %d %d\n", pi, zi, ci, idi); 
                    pareto.insert(camera(pi, zi, ci, idi));
                    optimum.insert(pii(ci, idi));

                    // delete from pareto
                    auto it = pareto.find(camera(pi, zi, ci, idi));
                    if (it == pareto.begin())
                        continue;
                    it--;
                    while (true) {
                        printf("%d %d\n", (*it).c, (*it).id);
                        if ((*it).z <= zi) {
                            printf("vai apagar\n");
                            optimum.erase(pii((*it).c, (*it).id));
                            if (it != pareto.begin()) {
                                it--;
                                pareto.erase(next(it));
                            } else {
                                pareto.erase(it);
                                break;
                            }
                        } else {
                            break;
                        }
                    } 
                    for (it = pareto.begin(); it != pareto.end(); it++) {
                        printf("%d %lf %d %d\n", (*it).p, (*it).z, (*it).c, (*it).id);
                    }
                }
            } else {
                if (!optimum.empty()) {
                    int choice = (*optimum.begin()).id;
                    printf("%d ", choice);
                } else {
                    printf("-1 ");
                }
            }
            /*for (auto a = pareto.begin(); a != pareto.end(); a++) {
                printf("cost %
            }*/
        }
        printf("\n");
        pareto.clear();
        optimum.clear();
    }
}

