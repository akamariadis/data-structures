#include <iostream>
using namespace std;

template <typename T>

class Array2D {
public:
    Array2D(unsigned n = 0, unsigned m = 0,
            int bi = 0, int bj = 0)
            : data(new T[n*m]), baseRow(bi),
              baseCol(bj), numRows(n), numCols(m) {}
    Array2D(const Array2D &a)
            : data(new T[a.numRows * a.numCols]),
              baseRow(a.baseRow), baseCol(a.baseCol),
              numRows(a.numRows), numCols(a.numCols) {
        for (unsigned i = 0;
             i < numRows * numCols; ++i)
            data[i] = a.data[i];
    }
    ~Array2D() { delete [] data; }    Array2D & operator=(const Array2D &a);
    Array2D & operator=(const Array2D &a) {
        delete [] data;
        baseRow = a.baseRow;
        baseCol = a.baseCol;
        numOfRows = a.numRows;
        numOfCols = a.numCols;
        data = new T[numRows * numCols];
        for (unsigned i = 0;
             i < numRows * numCols; ++i)
            data[i] = a.data[i];
        return *this;
    }
    T & select(int i, int j) {
        return data[loc(i, j)];
    }
    const T & select(int i, int j) const {
        return data[loc(i, j)];
    }
    Row operator [] (int i) {
        return Row(*this, i);
    }
    ConstRow operator[](int i) const {
        return Row(*this, i);
    }
protected:
    T *data;
    int baseRow, baseCol;
    unsigned numRows, numCols;
    unsigned loc(int i, int j) const
    throw(out_of_range) {
        int di = i – baseRow, dj = j - baseCol;
        if (di < 0 || di >= numRows ||
            dj < 0 || dj >= numCols)
            throw out_of_range("invalid index");
        return di * numCols + dj;
    }
    throw(out_of_range);
};

class Row {
public:
    Row(Array2D &a, int i)
            : array2D(a), row(i) {}
    T & operator[](int i) const {
        return array2D.select(row, i);
    }
private:
    Array2D &array2D;
    int row;
};
ConstRow operator[](int i) const {
    return ConstRow(*this, i);
}
class ConstRow {
public:
    ConstRow(const Array2D &a, int i)
            : array2D(a), row(i) {}
    const T & operator[](int i) const {
        return array2D.select(row, i);
    }
private:
    const Array2D &array2D;
    int row;
};
