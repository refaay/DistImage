#ifndef SHAREDIMAGESDIALOG_H
#define SHAREDIMAGESDIALOG_H
#include "Peer.h"
#include <QDialog>

namespace Ui {
class SharedImagesDialog;
}

class SharedImagesDialog : public QDialog {
  Q_OBJECT

public:
  explicit SharedImagesDialog(QWidget *parent = nullptr, Peer *peer = nullptr);
  ~SharedImagesDialog();

private slots:
  void on_push_view_clicked();

  void on_push_refresh_clicked();

  void on_push_request_clicked();

private:
  Ui::SharedImagesDialog *ui;
  Peer *peer;
};

#endif // SHAREDIMAGESDIALOG_H
