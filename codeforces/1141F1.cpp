#include <iostream>
#include <vector>
using namespace std;

bool somaJaVerificada(int soma, vector<int> somasTestadas)
{
    for (int i = 0; i < somasTestadas.size(); i++)
        if (somasTestadas[i] == soma)
            return true;
    return false;
}

int main()
{
    vector<pair<int, int> > solucao, solucaoTmp;
    vector<int> set, somasTestadas;
    int n, k, aux;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &aux);
        set.push_back(aux);
    }

    int qteBlocosMax = 0;
    int Li, Ri; //L e R do bloco inicial
    for (int tamBlocoInicial = 1; tamBlocoInicial < 2; tamBlocoInicial++)
    // for (int tamBlocoInicial = 1; tamBlocoInicial < set.size(); tamBlocoInicial++)
    {
        for (Li = 0; Li+tamBlocoInicial-1 < set.size(); Li++)
        {    
            int somaBlocoInicial = 0;
            for (Ri = Li; Ri-Li < tamBlocoInicial; Ri++)
                somaBlocoInicial += set[Ri]; 
            Ri--; //volta ao valor de Ri da última iteração

            printf("\nBLOCO inicial: [%d, %d]\n", Li, Ri);


            if (!somaJaVerificada(somaBlocoInicial, somasTestadas))
                somasTestadas.push_back(somaBlocoInicial);
            else continue;

            solucaoTmp.clear();
            solucaoTmp.push_back(make_pair(Li+1, Ri+1)); //bloco inicial

            
            //procura por novos blocos de mesma soma em todo o conjunto
            for (int init = 0; init < set.size(); init++)
            {
                printf("\ninit = %d", init);

                int l = init, r = l, qteBlocos = 1, somaBlocoTmp = 0;
                while (r < set.size())
                {
                    printf("\n(%d, %d)", l, r);

                    if (r >= Li && r <= Ri) //desconsidera se r pertencer ao subconjunto bloco inicial
                    {
                        l = Ri+1; r = l; somaBlocoTmp = 0; //ajusta indices para o imediatamente posterior
                        continue;
                    }

                    somaBlocoTmp += set[r];
                    if (somaBlocoTmp == somaBlocoInicial)
                    {
                        printf(" = %d", somaBlocoTmp);
                        qteBlocos++;
                        solucaoTmp.push_back(make_pair(l+1, r+1));
                        l = r+1; r = l; somaBlocoTmp = 0; //ajusta indices para o imediatamente posterior
                        continue;
                    }
                    r++;
                }
                if (qteBlocos > qteBlocosMax) //atualiza solucão com a solução temporária
                {
                    qteBlocosMax = qteBlocos;
                    solucao = solucaoTmp;
                }
            }
        }
    }
    printf("%d\n", k = solucao.size());
    for (int i = 0; i < k; i++)
        printf("%d %d\n", solucao[i].first, solucao[i].second);
    return 0;
}