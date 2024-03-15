#include <iostream>
#include <vector>

using namespace std;

// Транспонування двовимірного масиву
vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> result(cols, vector<int>(rows));

    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            result[i][j] = matrix[j][i];
        }
    }

    return result;
}

// Сума елементів на головній та побічній діагоналях
pair<int, int> diagonalSum(const vector<vector<int>>& matrix) {
    int main_diag_sum = 0;
    int anti_diag_sum = 0;
    int n = matrix.size();

    for (int i = 0; i < n; ++i) {
        main_diag_sum += matrix[i][i];
        anti_diag_sum += matrix[i][n - i - 1];
    }

    return make_pair(main_diag_sum, anti_diag_sum);
}

// Пошук елементів у заданому діапазоні
vector<int> findInRange(const vector<vector<int>>& matrix, int min_val, int max_val) {
    vector<int> result;
    for (const auto& row : matrix) {
        for (int num : row) {
            if (num >= min_val && num <= max_val) {
                result.push_back(num);
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = { {1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9} };

    // Транспонування масиву
    cout << "Транспонована матриця:" << endl;
    vector<vector<int>> transposed = transpose(matrix);
    for (const auto& row : transposed) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Сума елементів на головній та побічній діагоналях
    auto diag_sums = diagonalSum(matrix);
    cout << "Сума елементів на головній діагоналі: " << diag_sums.first << endl;
    cout << "Сума елементів на побічній діагоналі: " << diag_sums.second << endl;

    // Пошук елем у знадан репоз.
    int min_val = 3;
    int max_val = 7;
    vector<int> in_range = findInRange(matrix, min_val, max_val);
    cout << "Елементи у діапазоні [" << min_val << ", " << max_val << "]: ";
    for (int num : in_range) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
