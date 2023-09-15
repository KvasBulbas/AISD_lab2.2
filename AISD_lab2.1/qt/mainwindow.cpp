#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QMessageBox>
#include <iostream>
#include <vector>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->nodeKey->setValidator(new QIntValidator {INT_MIN, INT_MAX});
    ui->nodeKey->setText("0");

    ui->button_deleteNode->setEnabled(false);

    QObject::connect(ui->button_addNode, &QPushButton::clicked, this, &MainWindow::on_clicked_addNode);
    QObject::connect(ui->button_deleteNode, &QPushButton::clicked, this, &MainWindow::on_clicked_deleteNode);
    QObject::connect(ui->nodeList, &QListWidget::currentRowChanged, this, &MainWindow::onLvNodeListCurrentRowChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clicked_addNode()
{
    bool ok;
    int key = ui->nodeKey->text().toInt(&ok);

    if(ok)
    {
        tree.addNode(selectedNode,key);
        ui->button_deleteNode->setEnabled(true);
        onTreeUpdate();
    }
    else
    {
        displayError(QString {"invalid key value: must be an integer"});
    }

}
void MainWindow::on_clicked_deleteNode()
{
    auto selectedNodeParent = tree.findParent(selectedNode);
    tree.deleteNode(selectedNode);
    selectedNode = selectedNodeParent;

    if (tree.isEmpty())
    {
         ui->button_deleteNode->setEnabled(false);
    }



    onTreeUpdate();
}

void MainWindow::onLvNodeListCurrentRowChanged(int currentRow) {
    auto const nodes = tree.getNodes();

    if (currentRow >= 0 && currentRow < nodes.size())
    {
        selectedNode = nodes[currentRow];
    }
}


void MainWindow::onTreeUpdate() {
    tree.printTree();

    ui->nodeList->clear();

    for (auto node: tree.getNodes())
    {
        ui->nodeList->addItem( "id: " + QString::number((uintptr_t) node) + " key = " + QString::number(node->key));
    }

    selectedNode = tree.getRoot();
    ui->nodeList->setCurrentRow(0);
}

void MainWindow::displayError(QString const& msg) {
    QMessageBox::warning(this, "error", msg);

}

