#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Array2D {
public:
    Array2D(unsigned n = 0, unsigned m = 0, int bi = 0, int bj = 0)
            : data(new T[n * m]), baseRow(bi), baseCol(bj), numRows(n), numCols(m) {}

    Array2D(const Array2D &a)
            : data(new T[a.numRows * a.numCols]), baseRow(a.baseRow),
              baseCol(a.baseCol), numRows(a.numRows), numCols(a.numCols) {
        for (unsigned i = 0; i < numRows * numCols; ++i)
            data[i] = a.data[i];
    }

    ~Array2D() {
        delete[] data;
    }
    Array2D &operator=(const Array2D &a) {
        if (this != &a) {
            delete[] data;
            baseRow = a.baseRow;
            baseCol = a.baseCol;
            numRows = a.numRows;
            numCols = a.numCols;
            data = new T[numRows * numCols];
            for (unsigned i = 0; i < numRows * numCols; ++i)
                data[i] = a.data[i];
        }
        return *this;
    }
    T &select(int i, int j) {
        return data[loc(i, j)];
    }
    const T &select(int i, int j) const {
        return data[loc(i, j)];
    }
    class Row {
    public:
        Row(Array2D &a, int i) : array2D(a), row(i) {}
        T &operator[](int i) const {
            return array2D.select(row, i);
        }
    private:
        Array2D &array2D;
        int row;
    };
    class ConstRow {
    public:
        ConstRow(const Array2D &a, int i) : array2D(a), row(i) {}
        const T &operator[](int i) const {
            return array2D.select(row, i);
        }
    private:
        const Array2D &array2D;
        int row;
    };
    Row operator[](int i) {
        return Row(*this, i);
    }
    ConstRow operator[](int i) const {
        return ConstRow(*this, i);
    }
private:
    T *data;
    int baseRow, baseCol;
    unsigned numRows, numCols;
    unsigned loc(int i, int j) const {
        int di = i - baseRow;
        int dj = j - baseCol;
        if (di < 0 || di >= (int)numRows || dj < 0 || dj >= (int)numCols)
            throw out_of_range("Invalid index");
        return di * numCols + dj;
    }
};

int main() {
    try {
        Array2D<int> array(3, 3);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                array.select(i, j) = i * 3 + j + 1;
        cout << "Array2D contents:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                cout << array[i][j] << " ";
            cout << endl;
        }
    } catch (const out_of_range &e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
