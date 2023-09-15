#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <iostream>
#include "binarytree.h"
#include <QMainWindow>
#include<QListWidget>
#include<QLineEdit>
#include <QPushButton>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_clicked_addNode();
    void on_clicked_deleteNode();
    void onTreeUpdate();
    void onLvNodeListCurrentRowChanged(int currentRow);

private:
    void displayError(QString const& msg);
    Ui::MainWindow *ui;
    BinaryTree tree;
    BinaryTree::Node* selectedNode = tree.getRoot();

};
#endif // MAINWINDOW_H
