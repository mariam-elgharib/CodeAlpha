#include "Task3GUI.h"
#include <QtWidgets/QApplication>
#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

// Your Sudoku solving logic and MainWindow class here

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("Sudoku Solver");
    window.show();

    return app.exec();
}

