
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
// 3353 3353
// trocar pela quantidade de vertices da sua matriz/grafo
#define tamanho_matriz 3353
int min_e_max(int n, int n1);
int grau_do_maior_vertice(int **matriz);
void mostra_matriz(int **matriz);
void ler_arquivo(const char *nome_arquivo, int **matriz);
int main()
{
    int maior_grau;
    int **matriz = (int **)malloc(tamanho_matriz * sizeof(int *));
    int i;
    for (i = 0; i < tamanho_matriz; i++)
        matriz[i] = (int *)malloc(tamanho_matriz * sizeof(int));
    ler_arquivo("/home/felipehidequel/Pictures/grafos/dadosmatriz.txt", matriz);
    // mostra_matriz(matriz);

    maior_grau = grau_do_maior_vertice(matriz);
    printf("\nO vertice com maior grau eh: %i\n", maior_grau);
    return 0;
}



void mostra_matriz(int **matriz)
{
    int i, j;

    for (i = 0; i < tamanho_matriz; i++)
    {
        for (j = 0; j < tamanho_matriz; j++)
        {

            printf(" %i ", matriz[i][j]);
        }
        printf("\n");
    }
}

int grau_do_maior_vertice(int **matriz)
{
    int i, j, maior_grau, aux = 0, vertice_com_maior_grau;
    for (i = 0; i < tamanho_matriz; i++)
    {
        for (j = 0; j < tamanho_matriz; j++)
        {
            if (matriz[i][j] == 1)
            {
                aux++;
            }
        }
        if (aux > maior_grau)
        {
            maior_grau = aux;
            vertice_com_maior_grau = i;
        }
        aux = 0;
    }
    return vertice_com_maior_grau;
}


void ler_arquivo(const char *nome_arquivo, int **matriz)
{
    std::ifstream arquivo(nome_arquivo);
    if (!arquivo)
    {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return;
    }
    std::string ignorar;
    for (int i = 0; i < tamanho_matriz; i++)
    {
        for (int j = 0; j < tamanho_matriz; j++)
        {
            arquivo >> matriz[i][j];
            arquivo >> ignorar;
        }
    }

    arquivo.close();

#ifdef DEBUG
    // std::cout << "Matriz lida do arquivo: " << std::endl;
    // for (int i = 0; i < tamanho_matriz; i++)
    // {
    //     for (int j = 0; j < tamanho_matriz; j++)
    //     {
    //         std::cout << matriz[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::ofstream output_file("/home/felipehidequel/Pictures/grafos/matriz_teste.txt");
    if (!output_file)
    {
        std::cout << "Erro ao criar o arquivo." << std::endl;
        return;
    }
    for (int i = 0; i < tamanho_matriz; i++)
    {
        for (int j = 0; j < tamanho_matriz; j++)
        {
            output_file << matriz[i][j] << " ";
        }
        output_file << std::endl;
    }
    output_file.close();
#endif
}