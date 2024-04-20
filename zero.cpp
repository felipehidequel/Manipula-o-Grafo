#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
// 3353 3353

#define N 3353 // tamanho_matriz

std::vector<std::vector<int>> lerGrafo(const std::string &nomeArquivo) {
  std::ifstream arquivo(nomeArquivo);
  std::vector<std::vector<int>> matriz;
  std::string linha;

  while (std::getline(arquivo, linha)) {
    std::vector<int> linhaMatriz;
    std::istringstream streamLinha(linha);
    int valor;

    while (streamLinha >> valor) {
      linhaMatriz.push_back(valor);
    }

    matriz.push_back(linhaMatriz);
  }

  return matriz;
}

int grauVertice(const std::vector<std::vector<int>> &matriz, int vertice) {
  int grau = 0;

  for (int i = 0; i < N; i++) {
    grau += matriz[vertice][i];
  }

  return grau;
}

void imprimirGrafo(const std::vector<std::vector<int>> &matriz) {
  std::ofstream arquivo("teste.txt", std::ios::app);
  for (const auto &linha : matriz) {
    for (int valor : linha) {
      std::cout << valor << " ";
      arquivo << valor << " ";
    }
    arquivo << std::endl;
    std::cout << std::endl;
  }

  arquivo.close();
}

void maiorGrau(std::vector<std::vector<int>> matriz) {

  std::vector<int> verticesComMaiorGrau;
  int maiorGrau = 0;

  for (int i = 0; i < N; i++) {
    int grau = grauVertice(matriz, i);
    if (grau > maiorGrau) {
      maiorGrau = grau;
      verticesComMaiorGrau.clear();
      verticesComMaiorGrau.push_back(i);
    } else if (grau == maiorGrau) {
      verticesComMaiorGrau.push_back(i);
    }
  }

  std::cout << "Vertice com maior grau: ";
  for (int vertex : verticesComMaiorGrau) {
    std::cout << vertex << " ";
  }
  std::cout << std::endl;

  std::cout << "Maior grau: " << maiorGrau << std::endl;
}

void salvarVerticeGrau(std::vector<std::vector<int>> matriz) {
  std::ofstream arquivo("dados_grafos_graus.txt", std::ios::app);
  for (int i = 0; i < N; i++) {
    arquivo << "Vertice: " << i << " Grau: " << grauVertice(matriz, i)
            << std::endl;
  }
  arquivo.close();
}

void verticesIsolados(const std::vector<std::vector<int>> &matriz) {
  std::vector<int> verticesIsolados;
  for (int i = 0; i < N; i++) {
    if (grauVertice(matriz, i) == 0) {
      verticesIsolados.push_back(i);
    }
  }
  if (verticesIsolados.empty()) {
    std::cout << "Não existem vértices isolados." << std::endl;
  } else {
    std::cout << "Vértices isolados: ";
    for (int vertex : verticesIsolados) {
      std::cout << vertex << " ";
    }
    std::cout << std::endl;
  }
}

bool verticeSumidouro(const std::vector<std::vector<int>> &matriz) {
  for (int i = 0; i < N; i++) {
    bool isSumidouro = true;
    for (int j = 0; j < N; j++) {
      if (matriz[i][j] != 0) {
        isSumidouro = false;
        break;
      }
    }
    if (isSumidouro) {
      return true;
    }
  }
  return false;
}

int main() {
  std::vector<std::vector<int>> matriz = lerGrafo("dadosmatriz.txt");
  maiorGrau(matriz);         // QUESTÃO 1
  salvarVerticeGrau(matriz); // QUESTÃO 2
  verticesIsolados(matriz);  // QUESTÃO 3
  // QUESTÃO 4
  if (verticeSumidouro(matriz))
    std::cout << "Existe um vertice sumidouro" << std::endl;
  else
    std::cout << "Não existe um vertice sumidouro" << std::endl;
  return 0;
}