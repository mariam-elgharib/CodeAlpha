#include "Task3GUI.h"
#include <QMessageBox>

bool isValid(int grid[9][9], int row, int col, int num) {
    // Check current row
    for (int x = 0; x < 9; x++)
        if (grid[row][x] == num)
            return false;

    // Check current column
    for (int x = 0; x < 9; x++)
        if (grid[x][col] == num)
            return false;

    // Check current 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solve(int grid[9][9], int row, int col) {
    if (row == 8 && col == 9)
        return true;

    if (col == 9) {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0)
        return solve(grid, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {

    QVBoxLayout* layout = new QVBoxLayout;

    tableWidget = new QTableWidget(9, 9, this);
    layout->addWidget(tableWidget);

    QPushButton* solveButton = new QPushButton("Solve", this);
    layout->addWidget(solveButton);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(solveButton, &QPushButton::clicked, this, &MainWindow::solveSudoku);
}

void MainWindow::solveSudoku() {
    int grid[9][9];
    bool initialEmptyCells[9][9] = { false };

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            QTableWidgetItem* item = tableWidget->item(i, j);
            if (item && !item->text().isEmpty()) {
                grid[i][j] = item->text().toInt();
            }
            else {
                grid[i][j] = 0;
                initialEmptyCells[i][j] = true; // Mark this cell as initially empty
            }
        }
    }

    if (solve(grid, 0, 0)) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                QTableWidgetItem* item = new QTableWidgetItem(QString::number(grid[i][j]));

                if (initialEmptyCells[i][j]) {
                    item->setForeground(QBrush(Qt::red));  // Set color to red for added numbers
                }

                tableWidget->setItem(i, j, item);
            }
        }
    }
    else {
        QMessageBox::information(this, "Sudoku Solver", "Solution isn't available.");
    }
}

