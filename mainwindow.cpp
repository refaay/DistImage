#include "mainwindow.h"
#include "seconddialog.h"
#include "ui_mainwindow.h"
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), peer(new Peer) {
  ui->setupUi(this);
  ui->line_dos_ip->setPlaceholderText("0.0.0.0");
  ui->line_dos_port->setPlaceholderText("0000");
  ui->line_login_usr->setPlaceholderText("Username");
  ui->line_login_pass->setPlaceholderText("Password");
  ui->line_signup_usr->setPlaceholderText("Username");
  ui->line_signup_pass->setPlaceholderText("Password");
  QPixmap pm("logo.png");
  ui->label->setPixmap(
      pm.scaled(200, 200, Qt::IgnoreAspectRatio, Qt::FastTransformation));
  ui->lbl_time->setText(
      QString::fromStdString("Program Launched: " + peer->getCurrentTime()));
  ui->lbl_time->setStyleSheet("QLabel { color : white; }");
  ui->lbl_login_wrong->setVisible(false);
  ui->lbl_signup_welcome->setVisible(false);
  ui->lbl_dos_error->setVisible(false);
  ui->line_dos_port->setValidator(new QIntValidator); // only numbers
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_push_login_clicked() {
  // Fill DoS info
  string dos_ip_string = ui->line_dos_ip->text().toStdString();

  peer->dos_ip = new char[dos_ip_string.size() + 1];
  dos_ip_string.copy(peer->dos_ip, dos_ip_string.size() + 1);
  peer->dos_ip[dos_ip_string.size()] = '\0';

  peer->dos_port = 0;
  if (ui->line_dos_port->text().toStdString() != "")
    peer->dos_port = ui->line_dos_port->text().toInt();

  if (dos_ip_string == "" || peer->dos_port == 0) {
    ui->lbl_dos_error->setVisible(true);
  } else {
    ui->lbl_dos_error->setVisible(false);
    string username = ui->line_login_usr->text().toStdString();
    string password = ui->line_login_pass->text().toStdString();
    if (username == "" || password == "") {
      ui->lbl_login_wrong->setVisible(true);
      ui->lbl_login_wrong->setText(QString("Fill all info!"));
      ui->lbl_login_wrong->setStyleSheet("QLabel { color : red; }");
    } else {

      int sign_result = peer->login(username, password);

      if (sign_result == 1) { // Login correctly
        peer->username = username;
        peer->password = password;
        ui->lbl_login_wrong->setVisible(true);
        ui->lbl_login_wrong->setText(QString("Welcome!"));
        ui->lbl_login_wrong->setStyleSheet("QLabel { color : green; }");
        // Open the next window
        SecondDialog secdia(this, peer);
        secdia.setWindowFlags(Qt::Dialog | Qt::WindowTitleHint |
                              Qt::CustomizeWindowHint);
        secdia.setModal(true);
        secdia.exec();
      } else if (sign_result == 3) {
        ui->lbl_login_wrong->setVisible(true);
        ui->lbl_login_wrong->setText(QString("No Special Characters!"));
        ui->lbl_login_wrong->setStyleSheet("QLabel { color : red; }");
      } else if (sign_result == 0) {
        ui->lbl_login_wrong->setVisible(true);
        ui->lbl_login_wrong->setText(QString("You are not registered!"));
        ui->lbl_login_wrong->setStyleSheet("QLabel { color : red; }");
      } else if (sign_result == 5) {
        ui->lbl_login_wrong->setVisible(true);
        ui->lbl_login_wrong->setText(QString("Wrong Password!"));
        ui->lbl_login_wrong->setStyleSheet("QLabel { color : red; }");
      } else if (sign_result == 4) {
        ui->lbl_login_wrong->setVisible(true);
        ui->lbl_login_wrong->setText(QString("Username already logged in!"));
        ui->lbl_login_wrong->setStyleSheet("QLabel { color : red; }");
      } else if (sign_result == 2) { // Timeout
        ui->lbl_login_wrong->setVisible(true);
        ui->lbl_login_wrong->setText(QString("DoS Offline!"));
        ui->lbl_login_wrong->setStyleSheet("QLabel { color : red; }");
      } else {
        ui->lbl_login_wrong->setVisible(true);
        ui->lbl_login_wrong->setText(QString("Check your internet connection!"));
        ui->lbl_login_wrong->setStyleSheet("QLabel { color : red; }");
      }
    }
  }
}

void MainWindow::on_push_signup_clicked() {
  // Fill DoS info
  string dos_ip_string = ui->line_dos_ip->text().toStdString();

  peer->dos_ip = new char[dos_ip_string.size() + 1];
  dos_ip_string.copy(peer->dos_ip, dos_ip_string.size() + 1);
  peer->dos_ip[dos_ip_string.size()] = '\0';

  peer->dos_port = 0;
  if (ui->line_dos_port->text().toStdString() != "")
    peer->dos_port = ui->line_dos_port->text().toInt();

  if (dos_ip_string == "" || peer->dos_port == 0) {
    ui->lbl_dos_error->setVisible(true);
  } else {
    ui->lbl_dos_error->setVisible(false);

    string username = ui->line_signup_usr->text().toStdString();
    string password = ui->line_signup_pass->text().toStdString();
    int sign_result = peer->sign_up(username, password);
    if (sign_result == 1) { // Signed up correctly
      ui->lbl_signup_welcome->setVisible(true);
      ui->lbl_signup_welcome->setText(QString("Welcome!"));
      ui->lbl_signup_welcome->setStyleSheet("QLabel { color : green; }");
    } else if (sign_result == 3) {
      ui->lbl_signup_welcome->setVisible(true);
      ui->lbl_signup_welcome->setText(QString("No Special Characters!"));
      ui->lbl_signup_welcome->setStyleSheet("QLabel { color : red; }");
    } else if (sign_result == 5) {
      ui->lbl_signup_welcome->setVisible(true);
      ui->lbl_signup_welcome->setText(QString("You are already a member!"));
      ui->lbl_signup_welcome->setStyleSheet("QLabel { color : red; }");
    } else if (sign_result == 7) {
      ui->lbl_signup_welcome->setVisible(true);
      ui->lbl_signup_welcome->setText(QString("Check your internet connection!")); // Select error!
      ui->lbl_signup_welcome->setStyleSheet("QLabel { color : red; }");
    } else if (sign_result == 6) {
      ui->lbl_signup_welcome->setVisible(true);
      ui->lbl_signup_welcome->setText(QString("Check your internet connection!")); // Signup Send Failed!
      ui->lbl_signup_welcome->setStyleSheet("QLabel { color : red; }");
    } else { // Timeout
      ui->lbl_signup_welcome->setVisible(true);
      ui->lbl_signup_welcome->setText(QString("DoS Offline!"));
      ui->lbl_signup_welcome->setStyleSheet("QLabel { color : red; }");
    }
  }
}
