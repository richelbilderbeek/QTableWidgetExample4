#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include <QDebug>
#include "qtdialog.h"
#include "ui_qtdialog.h"
#pragma GCC diagnostic pop

QtWidget::QtWidget(
  const QVector<QString>& text,
  QWidget *parent
) : QTableWidget(parent)
{
  const int n_lines = text.size();
  this->setColumnCount(1);
  this->setRowCount(n_lines);
  this->horizontalHeader()->setStretchLastSection(true);
  //this->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
  this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
  this->setSizeAdjustPolicy(SizeAdjustPolicy::AdjustToContents);
  for (int i = 0; i != n_lines; ++i)
  {
    this->setItem(i, 0, new QTableWidgetItem(text[i]));
  }
  connect(
    horizontalHeader(),
    SIGNAL(sectionResized(int, int, int)),
    this,
    SLOT(resizeRowsToContents())
  );
}

QtWidget::~QtWidget() noexcept
{

}
