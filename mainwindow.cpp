#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ouverture de la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../etudiant.data");
    db.open();

    //chargement des données
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("etudiant");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, tr("prenom"));

    //affichage des données
    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0);
    ui->tableView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
