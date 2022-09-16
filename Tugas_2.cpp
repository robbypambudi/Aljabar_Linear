
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

void PrintNumber(float **ar, int n, int m, float lastNumber[20])
{
  float sum;
  int loop = 0;
  cout << "\n=== Nilai tiap variabel ===\n";
  for (int i = 0; i < n; i++)
  {
    loop = 0;
    sum = 0;
    for (int j = n; j < m; j++)
    {
      sum += ar[i][j] * lastNumber[loop++];
    }
    cout << "Nilai X" << i << " : " << sum << endl;
  }
}

void PrintMatrix(float **ar, int n, int m)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << ar[i][j] << "  ";
    }
    printf("\n");
  }
  return;
}

// Function to Print inverse matrix
void PrintInverse(float **ar, int n, int m)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = n; j < m; j++)
    {
      printf("%.3f  ", ar[i][j]);
    }
    printf("\n");
  }
  return;
}

void InverseOfMatrix(float **matrix, int order, float lastMatrix[20])
{

  float temp;

  printf("=== Matrix ===\n");
  PrintMatrix(matrix, order, order);

  for (int i = 0; i < order; i++)
  {

    for (int j = 0; j < 2 * order; j++)
    {

      if (j == (i + order))
        matrix[i][j] = 1;
      else if (j > order && j != (i + order))
      {
        matrix[i][j] = 0;
      }
    }
  }

  for (int i = order - 1; i > 0; i--)
  {

    if (matrix[i - 1][0] < matrix[i][0])
    {
      float *temp = matrix[i];
      matrix[i] = matrix[i - 1];
      matrix[i - 1] = temp;
    }
  }

  printf("\n=== Augmented Matrix ===\n");
  PrintMatrix(matrix, order, order * 2);

  for (int i = 0; i < order; i++)
  {

    for (int j = 0; j < order; j++)
    {

      if (j != i)
      {

        temp = matrix[j][i] / matrix[i][i];
        for (int k = 0; k < 2 * order; k++)
        {

          matrix[j][k] -= matrix[i][k] * temp;
        }
      }
    }
  }

  for (int i = 0; i < order; i++)
  {

    temp = matrix[i][i];
    for (int j = 0; j < 2 * order; j++)
    {

      matrix[i][j] = matrix[i][j] / temp;
    }
  }

  printf("\n=== Inverse Matrix ===\n");
  PrintInverse(matrix, order, 2 * order);

  PrintNumber(matrix, order, 2 * order, lastMatrix);

  return;
}

int main()
{

  float **matrix = new float *[20];
  for (int i = 0; i < 20; i++)
    matrix[i] = new float[20];

  int num;
  cout << "Masukan Jumlah Variabel (Jumlah variabel = Jumlah persamaan linear) : ";
  cin >> num;
  cout.precision(2);
  float lastMatrixs[20];
  memset(lastMatrixs, 0, sizeof(lastMatrixs));
  for (int i = 0; i < num; i++)
  {
    cout << "Masukan Persamaan Linear " << i + 1 << " (Dalam bentuk matriks) : ";
    for (int j = 0; j < num; j++)
    {
      cin >> matrix[i][j];
    }
    cin >> lastMatrixs[i];
  }
  // Get the inverse of matrix
  InverseOfMatrix(matrix, num, lastMatrixs);

  system("pause");

  return 0;
}