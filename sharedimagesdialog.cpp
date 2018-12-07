#include "sharedimagesdialog.h"
#include "ui_sharedimagesdialog.h"
#include <string>
#include "viewimagedialog.h"

SharedImagesDialog::SharedImagesDialog(QWidget *parent, Peer *peer)
    : QDialog(parent), ui(new Ui::SharedImagesDialog), peer(peer) {
  ui->setupUi(this);
  ui->lbl_result->setVisible(false);
  string imagename, ownername, fullname;
  for (auto const &x : peer->sharedimgs) {
      fullname = x.first;
      for (int j = fullname.length() - 1; j > 0; j--) {
        if (fullname[j] == '_') {
          ownername = fullname.substr(0, j);
          imagename = fullname.substr(j+1, fullname.length() - 1);
          break;
        }
      }
    ui->listWidget->addItem(QString::fromStdString("Owner: " + ownername + ". Img: " + imagename + ". Views Left: " + std::to_string(x.second)));
  }
}

SharedImagesDialog::~SharedImagesDialog() { delete ui; }

void SharedImagesDialog::on_push_view_clicked()
{
    int i=0;
    int views = 0;
    string imagename, ownername, fullname, img, cover;
    for (auto const &x : peer->sharedimgs) {
        fullname = x.first;
        for (int j = fullname.length() - 1; j > 0; j--) {
          if (fullname[j] == '_') {
            ownername = fullname.substr(0, j);
            imagename = fullname.substr(j+1, fullname.length() - 1);
            break;
          }
        }
        if(ui->listWidget->currentRow() == i){ img = imagename; cover = fullname; views = x.second; break;}
        else i++;
    }
    if(views > 0){
        ui->lbl_result->setVisible(false);
        peer->sharedimgs[cover]--;
        ViewImageDialog secd(this, peer, cover, img);
        secd.setWindowFlags(Qt::Dialog | Qt::WindowTitleHint |
                            Qt::CustomizeWindowHint);
        secd.setModal(true);
        secd.exec();
    }
    else{
        ui->lbl_result->setVisible(true);
        ui->lbl_result->setText(QString("You don't have enough views!"));
        ui->lbl_result->setStyleSheet("QLabel { color : red; }");

        // get any updates before displaying image
        ui->listWidget->clear();
        for (auto const &x : peer->sharedimgs) {
            fullname = x.first;
            for (int j = fullname.length() - 1; j > 0; j--) {
              if (fullname[j] == '_') {
                ownername = fullname.substr(0, j);
                imagename = fullname.substr(j+1, fullname.length() - 1);
                break;
              }
            }
            ui->listWidget->addItem(QString::fromStdString("Owner: " + ownername + ". Img: " + imagename + ". Views Left: " + std::to_string(x.second)));
        }
    }
}

void SharedImagesDialog::on_push_refresh_clicked()
{
    // get any updates
    ui->listWidget->clear();
    string fullname, imagename, ownername;
    for (auto const &x : peer->sharedimgs) {
        fullname = x.first;
        for (int j = fullname.length() - 1; j > 0; j--) {
          if (fullname[j] == '_') {
            ownername = fullname.substr(0, j);
            imagename = fullname.substr(j+1, fullname.length() - 1);
            break;
          }
        }
      ui->listWidget->addItem(QString::fromStdString("Owner: " + ownername + ". Img: " + imagename + ". Views Left: " + std::to_string(x.second)));
    }
}
