#include <cstdio>
#include <algorithm>
using namespace std;

double matrix[11][11], rest_matrix[11][2], det[11], temp_matrix[11][11], temp_date;

void matrixReduction(int variableAmount)
{
  for (int a = 1; a <= variableAmount - 1; a++)
  { // variable that will be eliminated
    for (int b = a + 1; b <= variableAmount; b++)
    { // the equation
      if (temp_matrix[b][a] == 0.00)
        continue;
      double multiplier = temp_matrix[b][a] / temp_matrix[a][a];
      for (int c = a; c <= variableAmount + 1; c++)
      {
        temp_matrix[b][c] -= (temp_matrix[a][c] * multiplier);
      }
    }
  }
}

int main()
{
  int variableAmount;
  printf("Masukkan jumlah variabel (Jumlah variabel = Jumlah persamaan linear) : ");
  scanf("%d", &variableAmount);
  for (int equation = 1; equation <= variableAmount; equation++)
  {
    printf("Masukkan Persamaan Linear %d (Dalam bentuk matriks) : ", equation);
    for (int variable = 1; variable <= variableAmount; variable++)
    {
      scanf("%lf", &matrix[equation][variable]);
    }
    scanf("%lf", &rest_matrix[equation][1]);
  }

  for (int i = 0; i <= variableAmount; i++)
  {
    temp_date = 1.00;
    // det for matrix before changed
    if (i == 0)
    {
      for (int j = 1; j <= variableAmount; j++)
      {
        for (int k = 1; k <= variableAmount; k++)
        {
          temp_matrix[j][k] = matrix[j][k];
        }
      }
    }
    else
    {
      for (int j = 1; j <= variableAmount; j++)
      {
        for (int k = 1; k <= variableAmount; k++)
        {
          if (k == i)
          {
            temp_matrix[j][k] = rest_matrix[j][1];
          }
          else
          {
            temp_matrix[j][k] = matrix[j][k];
          }
        }
      }
    }
    matrixReduction(variableAmount);
    for (int a = 1; a <= variableAmount; a++)
      temp_date *= temp_matrix[a][a];
    det[i] = temp_date;
  }
  printf("\n");
  for (int i = 0; i <= variableAmount; i++)
  {
    if (i == 0)
      printf("det A = %.2lf\n", det[i]);
    else
      printf("det A%d = %.2lf\n", i, det[i]);
  }
  printf("\n");
  for (int i = 1; i <= variableAmount; i++)
  {
    printf("X%d = %.2lf\n", i, det[i] / det[0]);
  }
  system("pause");
}