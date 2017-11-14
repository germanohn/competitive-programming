#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main () {
    int t;
    cin >> t;
    while(t--){
        int lin1, col1, lin2, col2;
        cin >> lin1 >> col1 >> lin2 >> col2;
        vector<string> figura(lin1);
        int countX = 0;
        for(int i = 0; i < lin1; ++i)
        {
            cin >> figura[i];
            for(auto v : figura[i]) if (v == 'x') countX++;
        }
        if(countX == 0)
        {
            cout << "ANO" << endl;
            continue;
        }
        vector<vector<bool> > marked(lin1, vector<bool>(col1, false));
        vector<string> carimbo(lin2);
        for(int i = 0; i < lin2; ++i)
        {
            cin >> carimbo[i];
        }

        int topoCarimboLin = -1;
        int topoCarimboCol = -1;
        
        vector<pair<int, int> > coordPretaCarimbo;
        for(int i = 0; i < lin2; ++i)
        {
            for(int j = 0; j < col2; ++j)
            {
                if(carimbo[i][j] == 'x')
                {
                    if(topoCarimboLin == -1 && topoCarimboCol == -1)
                    {
                        topoCarimboLin = i;
                        topoCarimboCol = j;
                    }
                    coordPretaCarimbo.pb(mp(i, j));
                } 
            }
        }
        int diffProInicioLin = topoCarimboLin;
        int diffProInicioCol = topoCarimboCol; 

        //aqui vamos carimbar a matriz da forma necessaria
        bool fail = false;
        for(int i = 0; i < lin1; ++i)
        {
            for(int j = 0; j < col1; ++j)
            {
                if(figura[i][j] == 'x' && marked[i][j] == false)
                {
                    // i e j devem coincidir com o canto superior esquerdo do carimbo
                    int inicioDoCarimboLin = i - diffProInicioLin;
                    int inicioDoCarimboCol = j - diffProInicioCol;
                    for(auto coord : coordPretaCarimbo)
                    {
                        if(carimbo[coord.ff][coord.ss] == 'x')
                        {
                            if(inicioDoCarimboLin + coord.ff >= lin1 || inicioDoCarimboLin + coord.ff < 0)
                            {
                                fail = true;
                                goto END;
                            }
                            if(inicioDoCarimboCol + coord.ss >= col1 || inicioDoCarimboCol + coord.ss < 0)
                            {
                                fail = true;
                                goto END;

                            }
                            if(figura[inicioDoCarimboLin + coord.ff][inicioDoCarimboCol + coord.ss] == '.')
                            {
                                fail = true;
                                goto END;
                            }
                            if(figura[inicioDoCarimboLin + coord.ff][inicioDoCarimboCol + coord.ss] == 'x')
                            {
                                if(marked[inicioDoCarimboLin + coord.ff][inicioDoCarimboCol + coord.ss] == true)
                                {
                                    fail = true;
                                    goto END;
                                }
                                else marked[inicioDoCarimboLin + coord.ff][inicioDoCarimboCol + coord.ss] = true;
                            }
                        }
                    }
                }
            }
        }
END:
        for(int i = 0; i < lin1; ++i)
        {
            for(int j = 0; j < col1; ++j)
            {
                if(figura[i][j] == 'x')
                {
                    if(marked[i][j] = false)
                    fail = true;
                    break;
                }
            }
        }
        if(fail) cout << "NIE" << endl;
        else cout << "ANO" << endl; 
    }
    return 0;
}

