#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <unordered_set>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , graph(new Graph("path.csv")) // Datasheet path
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete graph;
    delete ui;
}

void MainWindow::on_solveButton_clicked()
{
    // User input
    QString startPage = ui->startingPageLineEdit->text();
    QString endPage = ui->endingPageLineEdit->text();
    QString algorithm = ui->algorithmComboBox->currentText();

    if (startPage.isEmpty() || endPage.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both starting and ending pages.");
        return;
    }

    // Sets start and end points for the graph
    graph->setFromTo(startPage.toStdString(), endPage.toStdString());

    // Runs the algorithm function
    bool result = false;
    if (algorithm == "Breadth-First Search") {
        result = graph->bfs();
    } else if (algorithm == "Depth-First Search") {
        result = graph->dfs();
    } else if (algorithm == "Dijkstra's Algorithm") {
        // Make result = the Dijkstra graph function
    }

    if (!result) {
        QMessageBox::information(this, "No Path Found", "No path exists between the selected pages.");
    } else {
        // Draws the graph solution
        std::vector<std::pair<std::string, std::string>> edges;
        std::unordered_set<std::string> visited;
        std::vector<std::pair<std::string, std::string>> solution;

        std::string outputFile = "solution.dot";
        DrawSolution(outputFile, edges, visited, solution);

        system(("dot -Tpng " + outputFile + " -o solution.png").c_str());

        drawGraphVisualization("solution.png");
    }
}

void MainWindow::drawGraphVisualization(QString filePath)
{
    QPixmap graphImage(filePath);
    if (graphImage.isNull()) {
        QMessageBox::warning(this, "Error", "Failed to load graph visualization.");
    } else {
        ui->graphLabel->setPixmap(graphImage);
    }
}
