#include <iostream>

// Matrix input
void mat_input(double **mat, int row, int col) {
  std::cout << "\nEnter matrix elements:\n";
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      std::cin >> mat[i][j];
    }
  }
}

// Matrix out
void mat_out(double **mat, int row, int col) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      std::cout << mat[i][j] << "    ";
    }
    std::cout << std::endl;
  }
}

// Identity matrix
void mat_i(int n, double **mat) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        mat[i][j] = (i == j) ? 1 : 0;
    }
  }
}

// addition
void mat_addition(double **mat1, double **mat2, int row, int col, double **mat3) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      mat3[i][j] = mat1[i][j] + mat2[i][j];
    }
  }
}

// subtraction
void mat_subtraction(double **mat1, double **mat2, int row, int col, double **mat3) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      mat3[i][j] = mat1[i][j] - mat2[i][j];
    }
  }
}

// multiplication
void mat_multiplication(double **mat1, double **mat2, int r1, int c1,
                        int r2, int c2, double **mat3) {
  
  if(c1 != r2) {
    std::cout << "\nThe multiplication is not possible.\n";
    return;
  }  
  
  for(int i = 0; i < r1; i++)
    for(int j = 0; j < c2; j++)
      mat3[i][j] = 0;
  
  for(int i = 0; i < r1; i++) {
    for(int j = 0; j < c2; j++) {
      for(int k = 0; k < c1; k++) {
        mat3[i][j] += (mat1[i][k] * mat2[k][j]);
      }
    }
  }
}

// Transpose
void transpose(double **mat, int row, int col, double **tp) {
  
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      tp[j][i] = mat[i][j]; 
    }
  }
}

// Idempotent (A^2 = A)
int idempotent(double **mat, int row, int col) {
  
  if(row != col) {
    return 0;
  }
  
  double **b = new double*[row];      // mat b declaration by double pointer
  for(int i = 0; i < row; i++) {
    b[i] = new double[col];
  }
  
  
 mat_multiplication(mat, mat, row, col, row, col, b); 
    
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        if(b[i][j] != mat[i][j]) {
          for(int k = 0; k < row; k++) delete[] b[k];
          delete[] b;
          return 0;
        }
      }
    }
    for(int i = 0; i < row; i++) delete[] b[i];
    delete[] b;
    return 1;
}

//Involutory (A^2 = I)
int involutory(double **mat, int row, int col) {
  
  if(row != col) {
    return 0;
  }
  
  double **b = new double*[row];      // mat b declaration by double pointer
  double **c = new double*[row];
  for(int i = 0; i < row; i++) {
    b[i] = new double[col];
    c[i] = new double[col];
  }
  
  mat_multiplication(mat, mat, row, col, row, col, b); 
  mat_i(row, c);
  
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(b[i][j] != c[i][j]) {
        for(int k = 0; k < row; k++) {
         delete[] b[k];
         delete[] c[k];
        }
        delete[] b;
        delete[] c;
        return 0;
      }
    }
  }
  for(int i = 0; i < row; i++) {
    delete[] b[i];
    delete[] c[i];
  }
  delete[] b;
  delete[] c;
  return 1;
}

// symmetric (A' = A)
int symmetric(double **mat, int row, int col) {
  if(row != col) {
    return 0;
  }
  double **b = new double*[col];    // transpose swaps the num of row and col
  for(int i = 0; i < row; i++) {
    b[i] = new double[row];
  }
  
  transpose(mat, row, col, b);
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(b[i][j] != mat[i][j]) {
        for(int k = 0; k < col; k++) {
          delete[] b[k];
        }
        delete[] b;
        return 0;
      }
    }
  }
  for(int i = 0; i < col; i++) {
    delete[] b[i];
  }
  delete[] b;
  return 1;
}


int main() {
  
  int r1, c1, r2, c2, choice;
  
  std::cout << "Enter matrix A rows and columns: ";
  std::cin >> r1 >> c1;
  
  // Matrix A
  double **A = new double*[r1];
  for(int i = 0; i < r1; i++)
    A[i] = new double[c1];
  
  mat_input(A, r1, c1);
  
  std::cout << "\nMatrix A:\n";
  mat_out(A, r1, c1);
  
  std::cout << "\n========= Matrix Operations =========\n";
  
  while(true) {
    
    std::cout << "\n1. Matrix Addition\n";
    std::cout << "2. Matrix Subtraction\n";
    std::cout << "3. Matrix Multiplication\n";
    std::cout << "4. Matrix Transpose\n";
    std::cout << "5. Matrix Idempotent (A^2 = A)\n";
    std::cout << "6. Matrix Involutory (A^2 = I)\n";
    std::cout << "7. Matrix Symmetric (A' = A)\n";
    std::cout << "0. Exit\n";
    
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;
    
    if(choice == 0) break;
    
    if(choice < 0 || choice > 7) {
      std::cout << "Invalid choice!\n";
      continue;
    }
    
    /* ---------- ADDITION / SUBTRACTION ---------- */
    if(choice == 1 || choice == 2) {
      
      double **B = new double*[r1];
      double **C = new double*[r1];
      
      for(int i = 0; i < r1; i++) {
        B[i] = new double[c1];
        C[i] = new double[c1];
      }
      
      std::cout << "\nEnter Matrix B:\n";
      mat_input(B, r1, c1);
      
      std::cout << "\nMatrix B:\n";
      mat_out(B, r1, c1);
      
      if(choice == 1) {
        mat_addition(A, B, r1, c1, C);
        std::cout << "\nA + B =\n";
      } else {
        mat_subtraction(A, B, r1, c1, C);
        std::cout << "\nA - B =\n";
      }
      
      mat_out(C, r1, c1);
      
      // free B & C
      for(int i = 0; i < r1; i++) {
        delete[] B[i];
        delete[] C[i];
      }
      delete[] B;
      delete[] C;
    }
    
    /* ---------- MULTIPLICATION ---------- */
    else if(choice == 3) {
      
      std::cout << "Enter matrix B rows and columns: ";
      std::cin >> r2 >> c2;
      
      double **B2 = new double*[r2];
      for(int i = 0; i < r2; i++)
        B2[i] = new double[c2];
      
      double **C2 = new double*[r1];
      for(int i = 0; i < r1; i++)
        C2[i] = new double[c2];
      
      mat_input(B2, r2, c2);
      
      std::cout << "\nMatrix B:\n";
      mat_out(B2, r2, c2);
      
      mat_multiplication(A, B2, r1, c1, r2, c2, C2);
      
      std::cout << "\nA x B =\n";
      mat_out(C2, r1, c2);
      
      for(int i = 0; i < r2; i++) delete[] B2[i];
      for(int i = 0; i < r1; i++) delete[] C2[i];
      delete[] B2;
      delete[] C2;
    }
    
    /* ---------- TRANSPOSE ---------- */
    else if(choice == 4) {
      
      double **tp = new double*[c1];
      for(int i = 0; i < c1; i++)
        tp[i] = new double[r1];
      
      transpose(A, r1, c1, tp);
      
      std::cout << "\nTranspose of A:\n";
      mat_out(tp, c1, r1);
      
      for(int i = 0; i < c1; i++) delete[] tp[i];
      delete[] tp;
    }
    
    /* ---------- PROPERTY CHECKS ---------- */
    else if(choice == 5) {
      std::cout << "\nIdempotent: "
           << (idempotent(A, r1, c1) ? "YES" : "NO") << std::endl;
    }
    else if(choice == 6) {
      std::cout << "\nInvolutory: "
           << (involutory(A, r1, c1) ? "YES" : "NO") << std::endl;
    }
    else if(choice == 7) {
      std::cout << "\nSymmetric: "
           << (symmetric(A, r1, c1) ? "YES" : "NO") << std::endl;
    }
  }
  
  // free A
  for(int i = 0; i < r1; i++) delete[] A[i];
  delete[] A;
  
  std::cout << "\nProgram terminated successfully.\n";
  return 0;
}